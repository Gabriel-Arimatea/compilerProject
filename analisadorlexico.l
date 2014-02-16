%option noyywrap
%{
#include <stdio.h>
#include "referenciabibliografica.h"
#include "analsint.h"
int comments = 0;
%}
%x COMENT
%x STRING
%{
/*  DEFINITIONS  */
%}
operadores1 [\+|\-]
operadores2 [\*|\/]
digito [0-9]+
letra [a-z|A-Z]+
%%
%{
/* RULES */
%}
%{
//PALAVRAS RESERVADAS
%}
"int" {printf("PALAVRARESERVADA: %s\n",yytext); return INT;}
"string" {printf("PALAVRARESERVADA: %s\n",yytext);return STRNG;}
"else" {printf("PALAVRARESERVADA: %s\n",yytext);return ELSE;}
"if" {printf("PALAVRARESERVADA: %s\n",yytext);return IF;}
"return" {printf("PALAVRARESERVADA: %s\n",yytext);return RETURN;}
"void" {printf("PALAVRARESERVADA: %s\n",yytext);return VOID;}
"while" {printf("PALAVRARESERVADA: %s\n",yytext);return WHILE;}

%{
//OPERADORES MATEMATICOS
%}
"," {printf("OPERADOR: %s\n", yytext);return VIRG;}
"=="|"!="|"<="|">=" {printf("OPERADOR: %s\n", yytext);return OP4;}
"<"|">" {printf("OPERADOR: %s\n", yytext);return OP3;}
"=" {printf("OPERADOR: %s\n", yytext);return IGUAL;}
{operadores1} {printf("OPERADOR: %s\n", yytext);return OP1;}
{operadores2} {printf("OPERADOR: %s\n", yytext);return OP2;}

%{
//SIMBOLOS OPERADORES
%}
"(" {printf("ABREPARENTESES\n");return ABPAR;}
")" {printf("FECHAPARENTESES\n");return FEPAR;}
"[" {printf("ABRECOLCHETES\n");return ABCOL;}
"]" {printf("FECHACOLCHETES\n");return FECOL;}
"{" {printf("ABRECHAVES\n");return ABCHAV;}
"}" {printf("FECHACHAVES\n");return FECHAV;}

%{
//NUM
%}
{digito} {printf("NUM: %s\n",yytext);return NUM;}

%{
//ID
%}
{letra} {printf("ID %s\n",yytext);return ID;}
({digito}{letra}({digito}|{letra})*) {printf("erro lexico");}
({letra}{digito}({letra}|{digito})*) {printf("erro lexico");}

%{
//TRATAMENTO STRING
%}
[\"][^\n]*[\"] {printf("String: %s\n",yytext );return SV;}
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
//FIM DE ARQUIVO
%}

<<EOF>> {printf(" \nTERMINOU \n"); return 0;}

";" {printf("FIM DE OPERACAO (;)\n");return PV;}

.|\n|\r

%%
