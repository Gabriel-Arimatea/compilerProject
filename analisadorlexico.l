%{
/*
	O que falta: Underscore, id com letra e numero e vice versa
 */
%}
%option noyywrap
%{
#include <stdio.h>
int comments = 0;
%}
%x COMENT
%x STRING
%{
/* * * * * * * * * * * *
* * * DEFINITIONS * * *
* * * * * * * * * * * */
%}
%{
%}
operadores [\+|\-|\*|\/|\<|\>|\=|\,]
digito [0-9]
letra  [a-z|A-Z]
%%
%{
/* * * * * * * * *
* * * RULES * * *
* * * * * * * * */
%}
" "
\n
\t
";" {printf("FIM DE OPERAÇÃO (;)\n");}
%{
//OPERADORES MATEMATICOS
%}
"<="|">="|"=="|"!=" {printf("OPERADOR: %s\n", yytext);}
{operadores} {printf("OPERADOR: %s\n", yytext);}
%{
//PALAVRAS RESERVADAS
%}
"int" {printf("PALAVRARESERVADA: %s\n",yytext);}
"else" {printf("PALAVRARESERVADA: %s\n",yytext);}
"if" {printf("PALAVRARESERVADA: %s\n",yytext);}
"return" {printf("PALAVRARESERVADA: %s\n",yytext);}
"void" {printf("PALAVRARESERVADA: %s\n",yytext);}
"while" {printf("PALAVRARESERVADA: %s\n",yytext);}
"string" {printf("PALAVRARESERVADA: %s\n",yytext);}
%{
//TRATAMENTO STRING
%}
["] {BEGIN(STRING);printf("STRING: ");}
<STRING>[\\][\"] ECHO;
<STRING>[^"|\n] ECHO;
<STRING>["] {printf("\n");  BEGIN(INITIAL);}
<STRING>\n {printf("\nERRO: Falta fechar a aspa ou contém quebra de linha!\n");BEGIN(INITIAL);}
%{
//TRATAMENTO COMENTARIO
%}
"/*" {BEGIN(COMENT);comments++;}
<COMENT>"/*" {  comments++;}
<COMENT>"*/" {  comments--;
		if(comments == 0) {printf("COMMENT\n");BEGIN (INITIAL);}}
<COMENT><<EOF>> {if(comments != 0){printf("ERRO: Faltam fechar %d comentarios!\n",comments); return 0;}}
<COMENT>.|\n
%{
//SIMBOLOS OPERADORES
%}
"(" {printf("ABREPARENTESES\n");}
")" {printf("FECHAPARENTESES\n");}
"[" {printf("ABRECOLCHETES\n");}
"]" {printf("FECHACOLCHETES\n");}
"{" {printf("ABRECHAVES\n");}
"}" {printf("FECHACHAVES\n");}
%{
//ID E NUM
%}
{letra}+ {printf("ID: %s\n",yytext);}
{digito}+ {printf("NUM: %s\n",yytext);}
%{
//FIM DE ARQUIVO
%}
<<EOF>> {printf(" \nTERMINOU \n"); return 0;}
%%
