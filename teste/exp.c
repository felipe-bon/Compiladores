#include "lexer.h"
#include "exp.h"

/* Carrega uma string como entrada */
YY_BUFFER_STATE buffer;

void inicializa(char *str) {
	buffer = yy_scan_string(str);
}

Token *proximo_token() {
	return yylex();
}

void imprime_token( Token *tok) {
/* Aqui deve implementar a lógica para mostrar na tela o token
retornado pelo analisador léxico <token, atributo> de acordo com o tipo
do token (obs: lembre-se que alguns tokens não possuem atributo)*/
	printf("<%d, %d>\n", tok->tipo, tok->atributo);
}

int main(int argc, char **argv) {
	Token *tok;
	// Definicao da entrada
	char entrada[200];
	printf("\nAnalise Lexica da expressao: ");
	fgets(entrada, 200, stdin);
	inicializa(entrada);
	tok = proximo_token();
	while (tok != NULL) {
		imprime_token(tok);
		tok = proximo_token();
	}
	return 0;
}
