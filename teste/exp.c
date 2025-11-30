#include "lexer.h"
#include "exp.h"

Token *proximo_token() {
	return yylex();
}

// Funcao para obter o nome de um token
char *get_token_name(int tipo) {
    switch (tipo) {
        case TOK_NUM_INT:    return "TOK_NUM_INT";
        case TOK_NUM_FLOAT:  return "TOK_NUM_FLOAT";
        case TOK_OP:         return "TOK_OP";
        case TOK_PONT:       return "TOK_PONT";
        case TOK_ERRO:       return "TOK_ERRO";
        case TOK_IF:         return "TOK_IF";
        case TOK_THEN:       return "TOK_THEN";
        case TOK_ELSE:       return "TOK_ELSE";
        case TOK_WHILE:      return "TOK_WHILE";
        case TOK_REPEAT:     return "TOK_REPEAT";
        case TOK_UNTIL:      return "TOK_UNTIL";
        case TOK_ID:         return "TOK_ID";
        case TOK_RELOP:      return "TOK_RELOP";
        case TOK_SEPARATORS: return "TOK_SEPARATORS";
        case TOK_EOF:        return "TOK_EOF";
        case TOK_ASSIGN:     return "TOK_ASSIGN";
        default:             return "UNKNOWN";
    }
}

// Funcao para obter o nome de um operador
char *get_operator_name(int operador) {
    switch (operador) {
        case SOMA: return "SOMA";
        case SUB:  return "SUB";
        case MULT: return "MULT";
        case DIV:  return "DIV";
    }
    return "UNKNOWN";
}

// Funcao para obter o nome de um parentese
char *get_parenthesis_name(int parentese) {
    switch (parentese) {
        case PARESQ: return "(";
        case PARDIR: return ")";
    }
    return "UNKNOWN";
}
// Funcao para obter o atributo de um token
char *get_token_attribute(Token *tok) {
    switch (tok->tipo) {
        case TOK_NUM_INT:    return yytext;
        case TOK_NUM_FLOAT:  return yytext;
        case TOK_OP:         return get_operator_name(tok->atributo);
        case TOK_PONT:       return get_parenthesis_name(tok->atributo);
        case TOK_ERRO:       return "ERRO";
		case TOK_IF:         return "none";
		case TOK_THEN:       return "none";
		case TOK_ELSE:       return "none";
		case TOK_WHILE:      return "none";
		case TOK_REPEAT:     return "none";
		case TOK_UNTIL:      return "none";
		case TOK_ID:         return yytext;
		case TOK_RELOP:      return yytext;
        case TOK_SEPARATORS: return "none";
        case TOK_ASSIGN:     return "none";
        case TOK_EOF:        return "none";
    }
    return "UNKNOWN";
}
void imprime_token( Token *tok) {
/* Aqui deve implementar a lógica para mostrar na tela o token
retornado pelo analisador léxico <token, atributo> de acordo com o tipo
do token (obs: lembre-se que alguns tokens não possuem atributo)*/
	printf("< %s, %s >\n", get_token_name(tok->tipo), get_token_attribute(tok));
}

int main(int argc, char **argv) {
    char nome_arquivo[256];
    FILE *f;
    Token *tok;
    int c, opcao = -1;

    printf("Nome do arquivo com o código fonte: ");
    scanf("%255s", nome_arquivo);

    while (opcao < 1 || opcao > 3) {
        system("cls || clear");
        printf("Menu:\n");
        printf("1 - Mostrar todos os tokens\n");
        printf("2 - Mostrar um token por vez\n");
        printf("3 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
    }
    system("cls || clear");

    if (opcao == 3) {
        printf("Encerrando programa...\n");
        return 0;
    }

    f = fopen(nome_arquivo, "r");
    if (!f) {
        perror("Erro ao abrir arquivo");
        return 1;
    }

    yyin = f;

    if (opcao == 1) {
        do {
            tok = proximo_token();
            if (tok == NULL) {
                break;
            }
            imprime_token(tok);
        } while (tok->tipo != TOK_EOF);
        return 0;
    }

    /* limpa o '\n' que fica no buffer após o scanf */
    while ((c = getchar()) != '\n' && c != EOF) {}


    /* Printa um token por vez*/
    do {
        printf("Pressione ENTER para obter o próximo token...");
        while ((c = getchar()) != '\n' && c != EOF) {}
        system("cls || clear");
        tok = proximo_token();
        if (tok == NULL) {
            break;
        }
        printf("--------------------------------\n");
        imprime_token(tok);
        printf("--------------------------------\n\n");
        if (tok->tipo == TOK_EOF) {
            break;
        }
    } while (tok->tipo != TOK_EOF);

    fclose(f);
    return 0;
}
