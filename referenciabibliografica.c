#include <stdlib.h>
#include "referenciabibliografica.h"

//prograna: declaracao_lista
A_programa A_Producao1(A_declaracao_lista declaracaolista){
	A_programa p = malloc(sizeof(*p));
	p->u.regra1.declaracaolista = declaracaolista;
	p->kind = A_regra1;
	return p;
}

//-- declaracao_lista: declaracao_lista declaracao | declaracao ----------------------
A_declaracao_lista A_Producao2(A_declaracao_lista declaracaolista, A_declaracao declaracao){
	A_declaracao_lista p = malloc(sizeof(*p));
	p->u.regra2.declaracaolista = declaracaolista;
	p->u.regra2.declaracao = declaracao;
	p->kind = A_regra2;
	return p;
}
A_declaracao_lista A_Producao3(A_declaracao declaracao){
	A_declaracao_lista p = malloc(sizeof(*p));
	p->u.regra3.declaracao = declaracao;
	p->kind = A_regra3;
	return p;
}

//-- declaracao: var_declaracao | fun_declaracao ----------------------
A_declaracao A_Producao4(A_var_declaracao vardeclaracao){
	A_declaracao p = malloc(sizeof(*p));
	p->u.regra4.vardeclaracao = vardeclaracao;
	p->kind = A_regra4;
	return p;
}

A_declaracao A_Producao5(A_fun_declaracao fundeclaracao){
	A_declaracao p = malloc(sizeof(*p));
	p->u.regra5.fundeclaracao = fundeclaracao;
	p->kind = A_regra5;
	return p;
}

//--var_declaracao: tipo_especificador ID PV | tipo_especificador ID ABCOL NUM FECOL PV
A_var_declaracao A_Producao6(A_tipo_especificador tipoespecificador, string ID){
	A_var_declaracao p = malloc(sizeof(*p));
	p->u.regra6.tipoespecificador = tipoespecificador;
	p->u.regra6.ID = ID;
	p->kind = A_regra6;
	return p;
}
A_var_declaracao A_Producao7(A_tipo_especificador tipoespecificador, string ID, int NUM){
	A_var_declaracao p = malloc(sizeof(*p));
	p->u.regra7.tipoespecificador = tipoespecificador;
	p->u.regra7.ID = ID;
	p->u.regra7.NUM = NUM;
	p->kind = A_regra7;
	return p;
}

//--tipo_especificador: INT | VOID | STRING
A_tipo_especificador A_Producao8(){
	A_tipo_especificador p = malloc(sizeof(*p));
	p->kind = A_regra8;
	return p;
}
A_tipo_especificador A_Producao9(){
	A_tipo_especificador p = malloc(sizeof(*p));
	p->kind = A_regra9;
	return p;
}
A_tipo_especificador A_Producao10(){
	A_tipo_especificador p = malloc(sizeof(*p));
	p->kind = A_regra10;
	return p;
}

//--fun_declaracao: tipo_especificador ID ABPAR params FEPAR composto_decl
A_fun_declaracao A_Producao11(A_tipo_especificador tipoespecificador, string ID, A_params params, A_composto_decl compostodecl){
	A_fun_declaracao p = malloc(sizeof(*p));
	p->u.regra11.tipoespecificador = tipoespecificador;
	p->u.regra11.ID = ID;
	p->u.regra11.params = params;
	p->u.regra11.compostodecl= compostodecl;
	p->kind = A_regra11;
	return p;
}

//--params: param_lista | VOID
A_params A_Producao12(A_param_lista paramlista){
	A_params p = malloc(sizeof(*p));
	p->u.regra12.paramlista = paramlista;
	p->kind = A_regra12;
	return p;
}
A_params A_Producao13(){
	A_params p = malloc(sizeof(*p));
	p->kind = A_regra13;
	return p;
}

//--param_lista: param_lista VIRG param | param
A_param_lista A_Producao14(A_param_lista paramlista, A_param param){
	A_param_lista p = malloc(sizeof(*p));
	p->u.regra14.paramlista = paramlista;
	p->u.regra14.param = param;
	p->kind = A_regra14;
	return p;
}
A_param_lista A_Producao15(A_param param){
	A_param_lista p = malloc(sizeof(*p));
	p->u.regra15.param = param;
	p->kind = A_regra15;
	return p;
}

//--param: tipo_especificador ID | tipo_especificador ID ABCOL FECOL
A_param A_Producao16(A_tipo_especificador tipoespecificador, string ID){
	A_param p = malloc(sizeof(*p));
	p->u.regra16.tipoespecificador = tipoespecificador;
	p->u.regra16.ID = ID;
	p->kind = A_regra16;
	return p;
}
A_param A_Producao17(A_tipo_especificador tipoespecificador, string ID){
	A_param p = malloc(sizeof(*p));
	p->u.regra17.tipoespecificador = tipoespecificador;
	p->u.regra17.ID = ID;
	p->kind = A_regra17;
	return p;
}

//--composto_decl: ABCHAV local_declaracoes statement_lista FECHAV
A_composto_decl A_Producao18(A_local_declaracoes localdeclaracoes, A_statement_lista statementlista){
	A_composto_decl p = malloc(sizeof(*p));
	p->u.regra18.localdeclaracoes = localdeclaracoes;
	p->u.regra18.statementlista = statementlista;
	p->kind = A_regra18;
	return p;
}

//--local_declaracoes: local_declaracoes var_declaracao | vazio
A_local_declaracoes A_Producao19(A_local_declaracoes localdeclaracoes, A_var_declaracao vardeclaracao){
	A_local_declaracoes p = malloc(sizeof(*p));
	p->u.regra19.localdeclaracoes = localdeclaracoes;
	p->u.regra19.vardeclaracao = vardeclaracao;
	p->kind = A_regra19;
	return p;
}
A_local_declaracoes A_Producao20(A_vazio vazio){
	A_local_declaracoes p = malloc(sizeof(*p));
	p->u.regra20.vazio = vazio;
	p->kind = A_regra20;
	return p;
}

//--statement_lista: statement_lista statement | vazio
A_statement_lista A_Producao21(A_statement_lista statementlista, A_statement statement){
	A_statement_lista p = malloc(sizeof(*p));
	p->u.regra21.statementlista = statementlista;
	p->u.regra21.statement = statement;
	p->kind = A_regra21;
	return p;
}
A_statement_lista A_Producao22(A_vazio vazio){
	A_statement_lista p = malloc(sizeof(*p));
	p->u.regra22.vazio = vazio;
	p->kind = A_regra22;
	return p;
}

//--statement : expressao_decl | composto_decl | selecao_decl | iteracao_decl | retorno_decl
A_statement A_Producao23(A_expressao_decl expressaodecl){
	A_statement p = malloc(sizeof(*p));
	p->u.regra23.expressaodecl = expressaodecl;
	p->kind = A_regra23;
	return p;
}
A_statement A_Producao24(A_composto_decl compostodecl){
	A_statement p = malloc(sizeof(*p));
	p->u.regra24.compostodecl = compostodecl;
	p->kind = A_regra24;
	return p;
}
A_statement A_Producao25(A_selecao_decl selecaodecl){
	A_statement p = malloc(sizeof(*p));
	p->u.regra25.selecaodecl = selecaodecl;
	p->kind = A_regra25;
	return p;
}
A_statement A_Producao26(A_iteracao_decl iteracaodecl){
	A_statement p = malloc(sizeof(*p));
	p->u.regra26.iteracaodecl = iteracaodecl;
	p->kind = A_regra26;
	return p;
}
A_statement A_Producao27(A_retorno_decl retornodecl){
	A_statement p = malloc(sizeof(*p));
	p->u.regra27.retornodecl = retornodecl;
	p->kind = A_regra27;
	return p;
}

//--expressao_decl: expressao PV | PV
A_expressao_decl A_Producao28(A_expressao expressao){
	A_expressao_decl p = malloc(sizeof(*p));
	p->u.regra28.expressao = expressao;
	p->kind = A_regra28;
	return p;
}
A_expressao_decl A_Producao29(){
	A_expressao_decl p = malloc(sizeof(*p));
	p->kind = A_regra29;
	return p;
}

//--selecao_decl: IF ABPAR expressao FEPAR statement | IF ABPAR expressao FEPAR statement ELSE statement
A_selecao_decl A_Producao30(A_expressao expressao, A_statement statement){
	A_selecao_decl p = malloc(sizeof(*p));
	p->u.regra30.expressao = expressao;
	p->u.regra30.statement = statement;
	p->kind = A_regra30;
	return p;
}
A_selecao_decl A_Producao31(A_expressao expressao, A_statement statement, A_statement statement2){
	A_selecao_decl p = malloc(sizeof(*p));
	p->u.regra31.expressao = expressao;
	p->u.regra31.statement = statement;
	p->u.regra31.statement2 = statement2;
	p->kind = A_regra31;
	return p;
}

//--iteracao_decl: WHILE ABPAR expressao FEPAR statement
A_iteracao_decl A_Producao32(A_expressao expressao, A_statement statement){
	A_iteracao_decl p = malloc(sizeof(*p));
	p->u.regra32.expressao = expressao;
	p->u.regra32.statement = statement;
	p->kind = A_regra32;
	return p;
}

//--retorno_decl: RETURN PV | RETURN expressao PV
A_retorno_decl A_Producao33(){
	A_retorno_decl p = malloc(sizeof(*p));
	p->kind = A_regra33;
	return p;
}
A_retorno_decl A_Producao34(A_expressao expressao){
	A_retorno_decl p = malloc(sizeof(*p));
	p->u.regra34.expressao = expressao;
	p->kind = A_regra34;
	return p;
}

//--expressao: var IGUAL expressao | simples_expressao | var IGUAL STR
A_expressao A_Producao35(A_var var, A_expressao expressao){
	A_expressao p = malloc(sizeof(*p));
	p->u.regra35.var = var;
	p->u.regra35.expressao = expressao;
	p->kind = A_regra35;
	return p;
}
A_expressao A_Producao36(A_simples_expressao simplesexpressao){
	A_expressao p = malloc(sizeof(*p));
	p->u.regra36.simplesexpressao = simplesexpressao;
	p->kind = A_regra36;
	return p;
}
//--var: ID | ID ABCOL expressao FECOL
A_var A_Producao37(string ID){
	A_var p = malloc(sizeof(*p));
	p->u.regra37.ID = ID;
	p->kind = A_regra37;
	return p;
}
A_var A_Producao38(string ID, A_expressao expressao){
	A_var p = malloc(sizeof(*p));
	p->u.regra38.ID = ID;
	p->u.regra38.expressao = expressao;
	p->kind = A_regra38;
	return p;
}

//--simples_expressao: soma_expressao relacional soma_expressao | soma_expressao
A_simples_expressao A_Producao39(A_soma_expressao somaexpressao,A_relacional relacional,A_soma_expressao somaexpressao2){
	A_simples_expressao p = malloc(sizeof(*p));
	p->u.regra39.somaexpressao = somaexpressao;
	p->u.regra39.relacional = relacional;
	p->u.regra39.somaexpressao = somaexpressao2;
	p->kind = A_regra39;
	return p;
}
A_simples_expressao A_Producao40(A_soma_expressao somaexpressao){
	A_simples_expressao p = malloc(sizeof(*p));
	p->u.regra40.somaexpressao = somaexpressao;
	p->kind = A_regra40;
	return p;
}

//--relacional: OP3 | OP4 
A_relacional A_Producao41(char OP3){
	A_relacional p = malloc(sizeof(*p));
	p->u.regra41.OP3 = OP3;
	p->kind = A_regra41;
	return p;
}
A_relacional A_Producao42(string OP4){
	A_relacional p = malloc(sizeof(*p));
	p->u.regra42.OP4 = OP4;
	p->kind = A_regra42;
	return p;
}

//--soma_expressao: soma_expressao soma termo | termo
A_soma_expressao A_Producao43(A_soma_expressao somaexpressao,A_soma soma,A_termo termo){
	A_soma_expressao p = malloc(sizeof(*p));
	p->u.regra43.somaexpressao = somaexpressao;
	p->u.regra43.soma = soma;
	p->u.regra43.termo = termo;
	p->kind = A_regra43;
	return p;
}
A_soma_expressao A_Producao44(A_termo termo){
	A_soma_expressao p = malloc(sizeof(*p));
	p->u.regra44.termo = termo;
	p->kind = A_regra44;
	return p;
}

//--soma: OP1
A_soma A_Producao45(char OP1){
	A_soma p = malloc(sizeof(*p));
	p->u.regra45.OP1 = OP1;
	p->kind = A_regra45;
	return p;
}

//--termo: termo mult fator | fator
A_termo A_Producao46(A_termo termo,A_mult mult, A_fator fator){
	A_termo p = malloc(sizeof(*p));
	p->u.regra46.termo = termo;
	p->u.regra46.mult = mult;
	p->u.regra46.fator = fator;
	p->kind = A_regra46;
	return p;
}
A_termo A_Producao47(A_fator fator){
	A_termo p = malloc(sizeof(*p));
	p->u.regra47.fator = fator;
	p->kind = A_regra47;
	return p;
}

//--mult: OP2
A_mult A_Producao48(char OP2){
	A_mult p = malloc(sizeof(*p));
	p->u.regra48.OP2 = OP2;
	p->kind = A_regra48;
	return p;
}

//--fator: ABPAR expressao FEPAR | var | ativacao | NUM
A_fator A_Producao49(A_expressao expressao){
	A_fator p = malloc(sizeof(*p));
	p->u.regra49.expressao = expressao;
	p->kind = A_regra49;
	return p;
}
A_fator A_Producao50(A_var var){
	A_fator p = malloc(sizeof(*p));
	p->u.regra50.var = var;
	p->kind = A_regra50;
	return p;
}
A_fator A_Producao51(A_ativacao ativacao){
	A_fator p = malloc(sizeof(*p));
	p->u.regra51.ativacao = ativacao;
	p->kind = A_regra51;
	return p;
}
A_fator A_Producao52(int NUM){
	A_fator p = malloc(sizeof(*p));
	p->u.regra52.NUM = NUM;
	p->kind = A_regra52;
	return p;
}
A_fator A_Producao59(string SV){
	A_fator p = malloc(sizeof(*p));
	p->u.regra59.SV = SV;
	p->kind = A_regra59;
	return p;
}

//--ativacao: ID ABPAR args FEPAR
A_ativacao A_Producao53(string ID, A_args args){
	A_ativacao p = malloc(sizeof(*p));
	p->u.regra53.ID = ID;
	p->u.regra53.args = args;
	p->kind = A_regra53;
	return p;
}

//--args: arg_lista | vazio
A_args A_Producao54(A_arg_lista arglista){
	A_args p = malloc(sizeof(*p));
	p->u.regra54.arglista = arglista;
	p->kind = A_regra54;
	return p;
}
A_args A_Producao55(A_vazio vazio){
	A_args p = malloc(sizeof(*p));
	p->u.regra55.vazio = vazio;
	p->kind = A_regra55;
	return p;
}

//--arg_lista: arg_lista VIRG expressao | expressao
A_arg_lista A_Producao56(A_arg_lista arglista,A_expressao expressao){
	A_arg_lista p = malloc(sizeof(*p));
	p->u.regra56.arglista = arglista;
	p->u.regra56.expressao = expressao;
	p->kind = A_regra56;
	return p;
}
A_arg_lista A_Producao57(A_expressao expressao){
	A_arg_lista p = malloc(sizeof(*p));
	p->u.regra57.expressao = expressao;
	p->kind = A_regra57;
	return p;
}

//--vazio
A_vazio A_producaoVazio(){
	A_vazio v = malloc(sizeof(*v));
	return v;
}
