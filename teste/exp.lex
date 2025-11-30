%option noyywrap
%option nodefault
%option outfile="lexer.c" header-file="lexer.h"
%x COMMENT
%{
#include "exp.h"
%}

DIGITO     [0-9]
DIGITOS    {DIGITO}+
PARTE_FRAC "."{DIGITOS}
PARTE_EXP  [eE][+-]?{DIGITOS}
NUM_INT    {DIGITOS}
NUM_FLOAT  {DIGITOS}{PARTE_FRAC}{PARTE_EXP}?|{DIGITOS}{PARTE_EXP}
ID         [a-zA-Z][a-zA-Z0-9]*
RELOP      "<="|">="|"<>"|"="|"<"|">"
SEPARATORS [ \t\n]+
ASSIGN     ":="

%%

[[:space:]]    { } /* ignora espaços */

{NUM_INT}      { return token(TOK_NUM_INT, atoi(yytext)); }
{NUM_FLOAT}    { return token(TOK_NUM_FLOAT, yytext); }
{RELOP}        { return token(TOK_RELOP, yytext); }
{SEPARATORS}   { return token(TOK_SEPARATORS, 0); }
{ASSIGN}       { return token(TOK_ASSIGN, "NONE"); }

\+             { return token(TOK_OP, SOMA); }
-              { return token(TOK_OP, SUB); }
\*             { return token(TOK_OP, MULT); }
\/             { return token(TOK_OP, DIV); }
\(             { return token(TOK_PONT, PARESQ); }
\)             { return token(TOK_PONT, PARDIR); }

if             { return token(TOK_IF, "NONE"); }
then           { return token(TOK_THEN, "NONE"); }
else           { return token(TOK_ELSE, "NONE"); }
while          { return token(TOK_WHILE, "NONE"); }
repeat         { return token(TOK_REPEAT, "NONE"); }
until          { return token(TOK_UNTIL, "NONE"); }

"/*"           { BEGIN(COMMENT); }
<COMMENT>"*/"  { BEGIN(INITIAL); }
<COMMENT>.|\n  { /* ignora o conteúdo do comentário */ }

{ID}           { return token(TOK_ID, yytext); }
<<EOF>>        { return token(TOK_EOF, 0); }
.              { return token(TOK_ERRO, 0); }

%%
/* variavel global para um token */
Token tok;
Token * token (int tipo, int valor) {
    tok.tipo = tipo;
    tok.atributo = valor;
    return &tok;
}