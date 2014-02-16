#ifndef REFERENCIABIBLIOGRAFICA_H
#define REFERENCIABIBLIOGRAFICA_H
/*Gramática Abstrata:

programa : declaracao_lista
;

declaracao_lista : declaracao_lista declaracao	 | declaracao
;

declaracao : var_declaracao	  | fun_declaracao
;

var_declaracao	: tipo_especificador ID PV  | tipo_especificador ID [ NUM ] PV
;

tipo_especificador : INT | VOID | STRING		
;

fun_declaracao : tipo_especificador ID (params) composto_declaracao			
;

params : param_lista | VOID				
;

param_lista: | param_lista VIRG param | param
;

param: tipo_especificador ID | tipo_especificador ID []
;

composto_decl: ABCHAV local_declaracoes statement_lista FECHAV
;

local_declaracoes: local_declaracoes var_declaracoes | vazio
;

statement_lista: statement_lista statement | vazio
;

statement: expressao_decl | composto_decl | selecao_decl | iteracao_decl | retorno_decl
;

expressao_decl: expressao PV | PV
;

selecao_decl: IF ABPAR expressao FEPAR statement | IF ABPAR expressao FEPAR statement ELSE statement
;

iteracao_decl: WHILE ABPAR expressao FEPAR statement
;

retorno_decl: RETURN PV | RETURN expressao PV
;

expressao: var IGUAL expressao | simples_expressao
;

var: ID	| ID ABCOL expressao FECOL
;

simples_expressao: soma_expressao relacional soma_expressao | soma_expressao
;

relacional: OP4 | OP3
;

soma_expressao: soma_expressao soma termo | termo
;

soma: OP1
;

termo: termo mult fator | fator
;

mult: OP2
;

fator: ABPAR expressao FEPAR | var | ativacao | NUM
;

ativacao: ID ABPAR args FEPAR
;

args: arg_lista | vazio
;

arg_lista: arg_lista VIRG expressao | expressao
;
*/

typedef char* string;

typedef struct A_programa_ *A_programa; 
/* antes estava    
	typedef struct A_programa_ A_programa; 
(sem o asterisco! Para alocar um espaço variável de memória, 
é necessário que este objeto seja um ponteiro.
Não é a toa que você usa malloc lá no arquivo.c para cada objeto declarado aqui
dos typedefs) 

Adicionei em todos para você. */
typedef struct A_declaracao_lista_ *A_declaracao_lista;
typedef struct A_declaracao_ *A_declaracao;
typedef struct A_var_declaracao_ *A_var_declaracao;
typedef struct A_tipo_especificador_ *A_tipo_especificador;
typedef struct A_fun_declaracao_ *A_fun_declaracao;
typedef struct A_params_ *A_params;
typedef struct A_param_lista_ *A_param_lista;
typedef struct A_param_ *A_param;
typedef struct A_composto_decl_ *A_composto_decl;
typedef struct A_local_declaracoes_ *A_local_declaracoes;
typedef struct A_statement_lista_ *A_statement_lista;
typedef struct A_statement_ *A_statement;
typedef struct A_expressao_decl_ *A_expressao_decl;
typedef struct A_selecao_decl_ *A_selecao_decl;
typedef struct A_iteracao_decl_ *A_iteracao_decl;
typedef struct A_retorno_decl_ *A_retorno_decl;
typedef struct A_expressao_ *A_expressao;
typedef struct A_var_ *A_var;
typedef struct A_simples_expressao_ *A_simples_expressao;
typedef struct A_relacional_ *A_relacional;
typedef struct A_soma_expressao_ *A_soma_expressao;
typedef struct A_soma_ *A_soma;
typedef struct A_termo_ *A_termo;
typedef struct A_mult_ *A_mult;
typedef struct A_fator_ *A_fator;
typedef struct A_ativacao_ *A_ativacao;
typedef struct A_args_ *A_args;
typedef struct A_arg_lista_ *A_arg_lista;
typedef struct A_vazio_ *A_vazio;

//-- programa: declaracao_lista ------------------------------------------------------
struct A_programa_ {
					enum{A_regra1} kind;
					union{	struct {A_declaracao_lista declaracaolista;} regra1;
					} u;
};
A_programa A_Producao1(A_declaracao_lista declaracaolista);

//-- declaracao_lista: declaracao_lista declaracao | declaracao ----------------------
struct A_declaracao_lista_ {	enum {A_regra2, A_regra3} kind;
						union{	struct {A_declaracao_lista declaracaolista; A_declaracao declaracao;} regra2;
								struct {A_declaracao declaracao;} regra3;
					} u;
};
A_declaracao_lista A_Producao2(A_declaracao_lista declaracaolista, A_declaracao declaracao);
A_declaracao_lista A_Producao3(A_declaracao declaracao);

//-- declaracao: var_declaracao | fun_declaracao ----------------------
struct A_declaracao_ {	enum {A_regra4, A_regra5} kind;
						union{	struct {A_var_declaracao vardeclaracao;} regra4;
								struct {A_fun_declaracao fundeclaracao;} regra5;
					} u;
};
A_declaracao A_Producao4(A_var_declaracao vardeclaracao);
A_declaracao A_Producao5(A_fun_declaracao fundeclaracao);

//--var_declaracao: tipo_especificador ID PV | tipo_especificador ID ABCOL NUM FECOL PV
struct A_var_declaracao_ {	enum{A_regra6, A_regra7} kind;
							union{
								struct{ A_tipo_especificador tipoespecificador; string ID;} regra6;
								struct{ A_tipo_especificador tipoespecificador; string ID; int NUM;} regra7;
					} u;
};
A_var_declaracao A_Producao6(A_tipo_especificador tipoespecificador, string ID);
A_var_declaracao A_Producao7(A_tipo_especificador tipoespecificador, string ID, int NUM);

//--tipo_especificador: INT | VOID | STRING
struct A_tipo_especificador_ {	enum{A_regra8, A_regra9, A_regra10} kind;
						        union{
									struct{ } regra8;
									struct{ } regra9;
									struct{ } regra10;
					} u;
};
A_tipo_especificador A_Producao8();
A_tipo_especificador A_Producao9();
A_tipo_especificador A_Producao10();

//--fun_declaracao: tipo_especificador ID ABPAR params FEPAR composto_decl
struct A_fun_declaracao_ {	enum{A_regra11} kind;
							union{
							struct {A_tipo_especificador tipoespecificador; string ID; A_params params; A_composto_decl compostodecl;} regra11;
					} u;
};
A_fun_declaracao A_Producao11(A_tipo_especificador tipoespecificador, string ID, A_params params, A_composto_decl compostodecl);

//--params: param_lista | VOID
struct A_params_ 	{	enum{A_regra12, A_regra13} kind;
						union{
							struct{A_param_lista paramlista; } regra12;
							struct{} regra13;
						} u;
};
A_params A_Producao12(A_param_lista paramlista);
A_params A_Producao13();

//--param_lista: param_lista VIRG param | param
struct A_param_lista_ 	{	enum{A_regra14, A_regra15} kind;
						union{
							struct{A_param_lista paramlista; A_param param;} regra14;
							struct{A_param param;} regra15;
						} u;
};
A_param_lista A_Producao14(A_param_lista paramlista, A_param param);
A_param_lista A_Producao15(A_param param);

//--param: tipo_especificador ID | tipo_especificador ID ABCOL FECOL
struct A_param_{	enum{A_regra16, A_regra17} kind;
						union{
							struct{A_tipo_especificador tipoespecificador; string ID;} regra16;
							struct{A_tipo_especificador tipoespecificador; string ID;} regra17;
						} u;
};
A_param A_Producao16(A_tipo_especificador tipoespecificador, string ID);
A_param A_Producao17(A_tipo_especificador tipoespecificador, string ID);

//--composto_decl: ABCHAV local_declaracoes statement_lista FECHAV
struct A_composto_decl_{	enum{A_regra18} kind;
							union{
								struct{A_local_declaracoes localdeclaracoes; A_statement_lista statementlista;} regra18;
						} u;
};
A_composto_decl A_Producao18(A_local_declaracoes localdeclaracoes, A_statement_lista statementlista);

//--local_declaracoes: local_declaracoes var_declaracao | vazio
struct A_local_declaracoes_{ 	enum{A_regra19, A_regra20} kind;
								union{
									struct{A_local_declaracoes localdeclaracoes; A_var_declaracao vardeclaracao;} regra19;
									struct{A_vazio vazio;} regra20;
							} u;						
};

A_local_declaracoes A_Producao19(A_local_declaracoes localdeclaracoes, A_var_declaracao vardeclaracao);
A_local_declaracoes A_Producao20(A_vazio vazio);

//--statement_lista: statement_lista statement | vazio
struct A_statement_lista_{ 	enum{A_regra21, A_regra22} kind;
								union{
									struct{A_statement_lista statementlista; A_statement statement;} regra21;
									struct{A_vazio vazio;} regra22;
							} u;						
};

A_statement_lista A_Producao21(A_statement_lista statementlista, A_statement statement);
A_statement_lista A_Producao22(A_vazio vazio);

//--statement : expressao_decl | composto_decl | selecao_decl | iteracao_decl | retorno_decl
struct A_statement_ { 	enum{A_regra23, A_regra24, A_regra25, A_regra26, A_regra27} kind;
					union{
						struct{A_expressao_decl expressaodecl;} regra23;
						struct{A_composto_decl compostodecl;} regra24;
						struct{A_selecao_decl selecaodecl;} regra25;
						struct{A_iteracao_decl iteracaodecl;} regra26;
						struct{A_retorno_decl retornodecl;} regra27;
					} u;
};
A_statement A_Producao23(A_expressao_decl expressaodecl);
A_statement A_Producao24(A_composto_decl compostodecl);
A_statement A_Producao25(A_selecao_decl selecaodecl);
A_statement A_Producao26(A_iteracao_decl iteracaodecl);
A_statement A_Producao27(A_retorno_decl retornodecl);

//--expressao_decl: expressao PV | PV
struct A_expressao_decl_ {enum{A_regra28,A_regra29} kind;
					union{
						struct{A_expressao expressao;} regra28;
						struct{} regra29;
					} u;
};
A_expressao_decl A_Producao28(A_expressao expressao);
A_expressao_decl A_Producao29();

//--selecao_decl: IF ABPAR expressao FEPAR statement | IF ABPAR expressao FEPAR statement ELSE statement
struct A_selecao_decl_{	enum{A_regra30,A_regra31} kind;
						union{
							struct{A_expressao expressao; A_statement statement;} regra30;
							struct{A_expressao expressao; A_statement statement; A_statement statement2;} regra31;
						} u;
};
A_selecao_decl A_Producao30(A_expressao expressao, A_statement statement);
A_selecao_decl A_Producao31(A_expressao expressao, A_statement statement, A_statement statement2);

//--iteracao_decl: WHILE ABPAR expressao FEPAR statement
struct A_iteracao_decl_{	enum{A_regra32} kind;
							union{
								struct{A_expressao expressao; A_statement statement;} regra32;
					} u;
};
A_iteracao_decl A_Producao32(A_expressao expressao, A_statement statement);

//--retorno_decl: RETURN PV | RETURN expressao PV
struct A_retorno_decl_ {	enum{A_regra33,A_regra34} kind;
							union{
								struct{}regra33;
								struct{A_expressao expressao;}regra34;
					} u;
};
A_retorno_decl A_Producao33();
A_retorno_decl A_Producao34(A_expressao expressao);

//--expressao: var IGUAL expressao | simples_expressao | var IGUAL STR
struct A_expressao_ {	enum{A_regra35,A_regra36,A_regra58} kind;
							union{
								struct{A_var var; A_expressao expressao;}regra35;
								struct{A_simples_expressao simplesexpressao;}regra36;
					} u;
};
A_expressao A_Producao35(A_var var, A_expressao expressao);
A_expressao A_Producao36(A_simples_expressao simplesexpressao);

//--var: ID | ID ABCOL expressao FECOL
struct A_var_{	enum{A_regra37,A_regra38} kind;
					union{
						struct{string ID;}regra37;
						struct{string ID;A_expressao expressao;}regra38;
					} u;
};
A_var A_Producao37(string ID);
A_var A_Producao38(string ID, A_expressao expressao);

//--simples_expressao: soma_expressao relacional soma_expressao | soma_expressao
struct A_simples_expressao_{enum{A_regra39,A_regra40} kind;
					union{
						struct{A_soma_expressao somaexpressao;A_relacional relacional;A_soma_expressao somaexpressao2;}regra39;
						struct{A_soma_expressao somaexpressao;}regra40;
					} u;
};
A_simples_expressao A_Producao39(A_soma_expressao somaexpressao,A_relacional relacional,A_soma_expressao somaexpressao2);
A_simples_expressao A_Producao40(A_soma_expressao somaexpressao);

//--relacional: OP3 | OP4 
struct A_relacional_{	enum{A_regra41,A_regra42} kind;
				union{
					struct{char OP3;}regra41;
					struct{string OP4;}regra42;
				} u;
};
A_relacional A_Producao41(char OP3);
A_relacional A_Producao42(string OP4);

//--soma_expressao: soma_expressao soma termo | termo
struct A_soma_expressao_{	enum{A_regra43,A_regra44} kind;
				union{
					struct{A_soma_expressao somaexpressao; A_soma soma ; A_termo termo;}regra43;
					struct{A_termo termo;}regra44;
				} u;
};
A_soma_expressao A_Producao43(A_soma_expressao somaexpressao,A_soma soma,A_termo termo);
A_soma_expressao A_Producao44(A_termo termo);

//--soma: OP1
struct A_soma_{	enum{A_regra45} kind;
				union{
					struct{char OP1;}regra45;
				} u;
};
A_soma A_Producao45(char OP1);

//--termo: termo mult fator | fator
struct A_termo_{enum{A_regra46,A_regra47} kind;
				union{
					struct{A_termo termo;A_mult mult; A_fator fator;}regra46;
					struct{A_fator fator;}regra47;
				} u;
};
A_termo A_Producao46(A_termo termo,A_mult mult, A_fator fator);
A_termo A_Producao47(A_fator fator);

//--mult: OP2
struct A_mult_{	enum{A_regra48} kind;
				union{
					struct{char OP2;}regra48;
				} u;
};
A_mult A_Producao48(char OP2);

//--fator: ABPAR expressao FEPAR | var | ativacao | NUM
struct A_fator_{enum{A_regra49,A_regra50,A_regra51,A_regra52,A_regra59} kind;
				union{
					struct{A_expressao expressao;}regra49;
					struct{A_var var;}regra50;
					struct{A_ativacao ativacao;}regra51;
					struct{int NUM;}regra52;
					struct{string SV;}regra59;
				} u;
};
A_fator A_Producao49(A_expressao expressao);
A_fator A_Producao50(A_var var);
A_fator A_Producao51(A_ativacao ativacao);
A_fator A_Producao52(int NUM);
A_fator A_Producao59(string SV);

//--ativacao: ID ABPAR args FEPAR
struct A_ativacao_{enum{A_regra53} kind;
				union{
					struct{string ID; A_args args;}regra53;
				} u;
};
A_ativacao A_Producao53(string ID,A_args args);

//--args: arg_lista | vazio
struct A_args_{enum{A_regra54,A_regra55} kind;
				union{
					struct{A_arg_lista arglista;}regra54;
					struct{A_vazio vazio;}regra55;
				} u;
};
A_args A_Producao54(A_arg_lista arglista);
A_args A_Producao55(A_vazio vazio);

//--arg_lista: arg_lista VIRG expressao | expressao
struct A_arg_lista_{enum{A_regra56,A_regra57} kind;
				union{
					struct{A_arg_lista arglista; A_expressao expressao;}regra56;
					struct{A_expressao expressao;}regra57;
				} u;
};
A_arg_lista A_Producao56(A_arg_lista arglista,A_expressao expressao);
A_arg_lista A_Producao57(A_expressao expressao);

//--vazio
struct A_vazio_{};
A_vazio A_producaoVazio();
#endif