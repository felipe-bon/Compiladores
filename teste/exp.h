// constantes booleanas
#define TRUE 1
#define FALSE 0

// constantes para nome de token
#define TOK_NUM_INT    0
#define TOK_OP         1
#define TOK_PONT       2
#define TOK_ERRO       3
#define TOK_IF         4
#define TOK_THEN       5
#define TOK_ELSE       6
#define TOK_WHILE      7
#define TOK_REPEAT     8
#define TOK_UNTIL      9
#define TOK_ID         10
#define TOK_RELOP      11
#define TOK_SEPARATORS 12
#define TOK_NUM_FLOAT  13
#define TOK_EOF        14
#define TOK_ASSIGN     15

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