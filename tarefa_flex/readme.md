## para compilar rode os comandos no terminal:
flex -DYY_DECL="Token * yylex()" exp.lex

gcc -o exp lexer.c exp.c

## para executar rode:
./exp 

