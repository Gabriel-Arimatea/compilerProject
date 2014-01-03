%option noyywrap
%{
/* * * * * * * * * * * *
* * * DEFINITIONS * * *
* * * * * * * * * * * */
%}
%{
%}
operadores [\+|\-|\*|\/|\<|\<=|\>|\>=|\==|\!=|\=|\,]

digito [0-9]
letra  [a-z|A-Z]
%%
%{
/* * * * * * * * *
* * * RULES * * *
* * * * * * * * */
%}
\\n
\t
";" {printf("\n");}
{operadores} {printf(" OPERADOR ");}
^"int" {printf(" PALAVRARESERVADA ");}
^"str" {printf(" PALAVRARESERVADA ");}
^"else" {printf(" PALAVRARESERVADA ");}
^"if" {printf(" PALAVRARESERVADA ");}
^"return" {printf(" PALAVRARESERVADA ");}
^"void" {printf(" PALAVRARESERVADA ");}
^"while" {printf(" PALAVRARESERVADA ");}
^"string" {printf(" PALAVRARESERVADA ");}
["][^"]*["][";"] {printf(" STRING ");}
[\/*][^"]*[\*/] {printf(" COMMENT ");}
[\(] {printf(" ABREPARENTESES ");}
[\)] {printf(" FECHAPARENTESES ");}
[\[] {printf(" ABRECOLCHETES ");}
[\]] {printf(" FECHACOLCHETES ");}
[\{] {printf(" ABRECHAVES \n");}
[\}] {printf(" FECHACHAVES ");}
{letra}+ {printf(" ID ");}
{digito}+ {printf(" NUM ");}
<<EOF>> {printf(" \nTERMINOU \n"); return 0;}
%%
