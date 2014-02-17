%{
/************************************************************************/
/*                     ARQUIVO: analisadorsintatico.y                              */
/************************************************************************/

#include "referenciabibliografica.h"
#include "referenciabibliografica.c" /* faltou esse! */
/* #include "util.h" 
#include "stdlib.h" */

/* TAMBÉM FATOU A FUNÇÃO DE ERRO */
void yyerror(char *s);

A_programa p;
%}

%expect 1

%union {
int ival; 
string sval;
char cval; 
A_programa xprograma; 
A_declaracao_lista xdeclaracao_lista; 
A_declaracao xdeclaracao; 
A_var_declaracao xvar_declaracao; 
A_tipo_especificador xtipo_especificador; 
A_fun_declaracao xfun_declaracao; 
A_params xparams;
A_param_lista xparam_lista; 
A_param xparam; 
A_composto_decl xcomposto_decl; 
A_local_declaracoes xlocal_declaracoes;
A_statement_lista xstatement_lista; 
A_statement xstatement; 
A_expressao_decl xexpressao_decl; 
A_selecao_decl xselecao_decl;
A_iteracao_decl xiteracao_decl; 
A_retorno_decl xretorno_decl; 
A_expressao xexpressao; 
A_var xvar; 
A_simples_expressao xsimples_expressao;
A_relacional xrelacional; 
A_soma_expressao xsoma_expressao; 
A_soma xsoma; 
A_termo xtermo; 
A_mult xmult; 
A_fator xfator; 
A_ativacao xativacao;
A_args xargs; 
A_arg_lista xarg_lista; 
A_vazio xvazio; 	
};

%token ABPAR
%token FEPAR
%token ABCOL
%token FECOL
%token ABCHAV
%token FECHAV
%token IGUAL
%token VIRG
%token PV
%token INT
%token VOID
%token STRNG
%token ELSE
%token IF
%token RETURN
%token WHILE
%token <cval> OP1
%token <cval> OP2
%token <cval> OP3
%token <sval> OP4
%token <sval> SV
%token <sval> ID 
%token <ival> NUM

%type <xprograma> programa
%type <xdeclaracao_lista> declaracao_lista
%type <xdeclaracao> declaracao
%type <xvar_declaracao> var_declaracao
%type <xtipo_especificador> tipo_especificador
%type <xfun_declaracao> fun_declaracao
%type <xparams> params
%type <xparam_lista> param_lista 
%type <xparam> param
%type <xcomposto_decl> composto_decl
%type <xlocal_declaracoes> local_declaracoes 
%type <xstatement_lista> statement_lista
%type <xstatement> statement 
%type <xexpressao_decl> expressao_decl
%type <xselecao_decl> selecao_decl
%type <xiteracao_decl> iteracao_decl
%type <xretorno_decl> retorno_decl
%type <xexpressao> expressao
%type <xvar> var
%type <xsimples_expressao> simples_expressao
%type <xrelacional> relacional
%type <xsoma_expressao> soma_expressao
%type <xsoma> soma
%type <xtermo> termo
%type <xmult> mult
%type <xfator> fator
%type <xativacao> ativacao
%type <xargs> args
%type <xarg_lista> arg_lista
%type <xvazio> vazio


%start programa

//-- REGRAS DA GRAMATICA ---------------------------------------
%%

programa: declaracao_lista {p = A_Producao1($1); $$=p;}
;

declaracao_lista: declaracao_lista declaracao {$$ = A_Producao2($1,$2);} ;
declaracao_lista: declaracao {$$=A_Producao3($1);} 
;

declaracao: var_declaracao {$$=A_Producao4($1);};
declaracao: fun_declaracao {$$=A_Producao5($1);}
;

var_declaracao	: tipo_especificador ID PV  {$$=A_Producao6($1,$2);};
var_declaracao  : tipo_especificador ID ABCOL NUM FECOL PV  {$$=A_Producao7($1,$2,$4);}
;

tipo_especificador : INT    {$$=A_Producao8();};
tipo_especificador : VOID   {$$=A_Producao9();};
                   | STRNG  {$$=A_Producao10();}		
;

fun_declaracao : tipo_especificador ID ABPAR params FEPAR composto_decl	{$$=A_Producao11($1,$2,$4,$6);}		
;

params: param_lista {$$=A_Producao12($1);};
params: VOID		 {$$=A_Producao13();}		
;

param_lista:   param_lista VIRG param {$$=A_Producao14($1,$3);}
             | param                  {$$=A_Producao15($1);}
;

param: tipo_especificador ID              {$$=A_Producao16($1,$2);};
param: tipo_especificador ID ABCOL FECOL  {$$=A_Producao17($1,$2);};
param: vazio                              
;

composto_decl: ABCHAV local_declaracoes statement_lista FECHAV {$$=A_Producao18($2,$3);}
;

local_declaracoes: local_declaracoes var_declaracao {$$=A_Producao19($1,$2);};
local_declaracoes: vazio                             {$$=A_Producao20($1);}
;

statement_lista: statement_lista statement  {$$=A_Producao21($1,$2);};
statement_lista: vazio                      {$$=A_Producao22($1);}  
;

statement: expressao_decl {$$=A_Producao23($1);};
statement: composto_decl {$$=A_Producao24($1);};
statement: selecao_decl  {$$=A_Producao25($1);};
statement: iteracao_decl {$$=A_Producao26($1);};
statement: retorno_decl  {$$=A_Producao27($1);}
;

expressao_decl: expressao PV {$$=A_Producao28($1);};
expressao_decl: PV           {$$=A_Producao29();}
;

selecao_decl: IF ABPAR expressao FEPAR statement                {$$=A_Producao30($3,$5);};
selecao_decl: IF ABPAR expressao FEPAR statement ELSE statement {$$=A_Producao31($3,$5,$7);}
;

iteracao_decl: WHILE ABPAR expressao FEPAR statement {$$=A_Producao32($3,$5);}
;

retorno_decl: RETURN PV              {$$=A_Producao33();};
retorno_decl: RETURN expressao PV    {$$=A_Producao34($2);}
;

expressao: var IGUAL expressao   {$$=A_Producao35($1,$3);};
expressao: simples_expressao     {$$=A_Producao36($1);};
;

var: ID	                         {$$=A_Producao37($1);};
var: ID ABCOL expressao FECOL    {$$=A_Producao38($1,$3);}
;

simples_expressao: soma_expressao relacional soma_expressao  {$$=A_Producao39($1,$2,$3);};
simples_expressao: soma_expressao                            {$$=A_Producao40($1);}
;

relacional: OP3   {$$=A_Producao41($1);};
relacional: OP4   {$$=A_Producao42($1);}
;

soma_expressao: soma_expressao soma termo  {$$=A_Producao43($1,$2,$3);};
soma_expressao: termo                      {$$=A_Producao44($1);}
;

soma: OP1   {$$=A_Producao45($1);}
;

termo: termo mult fator  {$$=A_Producao46($1,$2,$3);};
termo: fator             {$$=A_Producao47($1);}
;

mult: OP2  {$$=A_Producao48($1);}
;

fator: ABPAR expressao FEPAR {$$=A_Producao49($2);};
fator: var                   {$$=A_Producao50($1);};
fator: ativacao              {$$=A_Producao51($1);};
fator: NUM                   {$$=A_Producao52($1);}
fator: SV                    {$$=A_Producao59($1);}
;

ativacao: ID ABPAR args FEPAR  {$$=A_Producao53($1,$3);}
;

args: arg_lista  {$$=A_Producao54($1);};
args: vazio      {$$=A_Producao55($1);}
;

arg_lista: arg_lista VIRG expressao  {$$=A_Producao56($1,$3);};
arg_lista: expressao                 {$$=A_Producao57($1);}
;

vazio: {$$=A_producaoVazio();}
;
%%

/* Do jeito que estava, o seu programa não informava que havia erro sintático! */
#include <stdio.h>
void yyerror(char *s)
{
   fprintf(stderr,"Syntax error.");
   exit(1);
}

main(){
	yyparse();
	
	return 0;
}
