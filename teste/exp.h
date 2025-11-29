// constantes booleanas
#define TRUE 1
#define FALSE 0

// constantes para nome de token
#define TOK_NUM 0
#define TOK_OP 1
#define TOK_PONT 2
#define TOK_ERRO 3

// constantes para operadores
#define SOMA 0
#define SUB 1
#define MULT 2
#define DIV 3

// constantes para parenteses
#define PARESQ 0
#define PARDIR 1

// estrutura de um token
typedef struct {
    int tipo;
    int atributo;
} Token;

// funcao para criar um token
extern Token *token();

// funcao do analisador lexico
extern Token *yylex();