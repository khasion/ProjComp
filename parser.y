%{
	#include <stdio.h>
  	#include <unistd.h>
  	#include <stdlib.h>
  	#include <string.h>
  	#include "quads.h"

  	#define  YY_DECL int alpha_yylex (void* yylval)
  	void yyerror (char* yaccProovidedMessage);
  	int yylex();
	extern int yylineno;
  	extern char* yytext;
  	extern FILE* yyin;
	unsigned gloop = 0;
	unsigned loopcounter = 0;
%}

%start program

%union {
  	int intval;
  	char* strval;
  	float floatval;
	struct expr* exprval;
	struct stmt_t* stmtval;
}

%right ASSIGN
%left OR
%left AND
%nonassoc EQ NOT_EQ
%nonassoc GREATER GREATER_EQ LESS LESS_EQ
%left PLUS MINUS
%left MUL DIV MOD
%right NOT D_PLUS D_MINUS UMINUS
%left DOT D_DOT
%left L_BRA R_BRA
%left L_PAR R_PAR

%token <intval> INT
%token <floatval> REAL
%token <strval> ID
%token <strval> STRING
%token <strval> IF ELSE WHILE FOR FUNC RETURN BREAK CONTINUE AND OR LOCAL TRUE FALSE NIL UMINUS
%token <strval> ASSIGN PLUS MINUS MUL DIV MOD EQ NOT_EQ D_PLUS D_MINUS LESS GREATER LESS_EQ GREATER_EQ
%token <strval> LC_BRA RC_BRA L_BRA R_BRA L_PAR R_PAR SEMI COMMA COLON D_COLON DOT D_DOT

%type <stmtval> stmt stmts loopstmt ifstmt whilestmt forstmt returnstmt

%type <intval> expr  assignexpr N M 
%type <strval> term  lvalue primary member call callsuffix normcall elist objectdef 
%type <strval>	indexed indexedelem  rec_stmt block const idlist 
%type <strval> funcname funcprefix funcargs funcbody funcdef  elseprefix forprefix 
%type <strval> funcblockend funcblockstart  ifprefix whilestart whilecond
 
%%
program:	stmt program {;}
       	| {;}
       	; 

stmts: 	stmts stmt { 
 			//$$.breaklist = merge($1.breaklist, $2.breaklist); 
			//$$.contlist  = merge($1.contlist, $2. contlist); 
 		}
		| stmt { $$ = $1; } 

stmt: 	expr SEMI {;}
		| ifstmt
		| whilestmt {;}
		| forstmt {;}
		| returnstmt {;}
		| BREAK SEMI {
				//$$.breaklist = newlist(nextquad()); 
				//emit(jump, NULL, NULL, NULL, NULL, yylineno);  
				if (gloop == 0) Error(3, yytext, yylineno);
		}
		| CONTINUE SEMI {
				//$$.contlist = newlist(nextquad()); 
				//emit(jump, NULL, NULL, NULL, NULL, yylineno); 
				if (gloop == 0) Error(4, yytext, yylineno);
		}
		| block {;}
		| funcdef {;}
		| SEMI {;}
		;

expr: 	assignexpr
		| expr PLUS expr { 
        		/*$<exprval>$ = newexpr(arithexpr_e);
        		$<exprval>$->sym = newtemp();
        		emit(op_add, $<exprval>1, $<exprval>3, $<exprval>$, 69, yylineno);
			*/
		}
		| expr MINUS expr { 
        		/*$<exprval>$ = newexpr(arithexpr_e);
        		$<exprval>$->sym = newtemp();
        		emit(op_sub, $<exprval>1, $<exprval>3, $<exprval>$, 69, yylineno);
			   */
		}
		| expr MUL expr { 
        		/*$<exprval>$ = newexpr(arithexpr_e);
        		$<exprval>$->sym = newtemp();
        		emit(op_mul, $<exprval>1, $<exprval>3, $<exprval>$, 69, yylineno);
			   */
		}
		| expr DIV expr { 
        		/*$<exprval>$ = newexpr(arithexpr_e);
        		$<exprval>$->sym = newtemp();
        		emit(op_div, $<exprval>1, $<exprval>3, $<exprval>$, 69, yylineno);
			   */
		}
		| expr MOD expr { 
        		/*$<exprval>$ = newexpr(arithexpr_e);
        		$<exprval>$->sym = newtemp();
        		emit(op_mod, $<exprval>1, $<exprval>3, $<exprval>$, 69, yylineno);
			   */
		}
		| expr GREATER expr { 
        		/*$<exprval>$ = newexpr(boolexpr_e);
        		$<exprval>$->sym = newtemp();
        		emit(if_greater, $<exprval>1, $<exprval>3, NULL, nextquad()+3, yylineno);
        		emit(assign, newexpr_constbool('0'), NULL, $<exprval>$, 69,yylineno);
        		emit(jump, NULL, NULL, NULL , nextquad()+2, yylineno);
        		emit(assign, newexpr_constbool('1'), NULL, $<exprval>$, 69 , yylineno);
			   */
        	}
		| expr GREATER_EQ expr {
        		/*$<exprval>$ = newexpr(boolexpr_e);
        		$<exprval>$->sym = newtemp();
        		emit(if_greater, $<exprval>1, $<exprval>3, NULL, nextquad()+3, yylineno);
        		emit(assign, newexpr_constbool('0'), NULL, $<exprval>$, 69,yylineno);
        		emit(jump, NULL, NULL, NULL , nextquad()+2, yylineno);
        		emit(assign, newexpr_constbool('1'), NULL, $<exprval>$, 69 , yylineno);
			   */
        	}
		| expr LESS expr { 
        		/*$<exprval>$ = newexpr(boolexpr_e);
        		$<exprval>$->sym = newtemp();
        		emit(if_greater, $<exprval>1, $<exprval>3, NULL, nextquad()+3, yylineno);
        		emit(assign, newexpr_constbool('0'), NULL, $<exprval>$, 69,yylineno);
        		emit(jump, NULL, NULL, NULL , nextquad()+2, yylineno);
        		emit(assign, newexpr_constbool('1'), NULL, $<exprval>$, 69 , yylineno);
			   */
      	}
		| expr LESS_EQ expr {
        		/*$<exprval>$ = newexpr(boolexpr_e);
        		$<exprval>$->sym = newtemp();
        		emit(if_greater, $<exprval>1, $<exprval>3, NULL, nextquad()+3, yylineno);
        		emit(assign, newexpr_constbool('0'), NULL, $<exprval>$, 69,yylineno);
        		emit(jump, NULL, NULL, NULL , nextquad()+2, yylineno);
        		emit(assign, newexpr_constbool('1'), NULL, $<exprval>$, 69 , yylineno);
			   */
      	}
		| expr EQ expr {
        		/*$<exprval>$ = newexpr(boolexpr_e);
        		$<exprval>$->sym = newtemp();
        		emit(if_greater, $<exprval>1, $<exprval>3, NULL, nextquad()+3, yylineno);
        		emit(assign, newexpr_constbool('0'), NULL, $<exprval>$, 69,yylineno);
        		emit(jump, NULL, NULL, NULL , nextquad()+2, yylineno);
        		emit(assign, newexpr_constbool('1'), NULL, $<exprval>$, 69 , yylineno);
			   */
      	}
		| expr NOT_EQ expr {
        		/*$<exprval>$ = newexpr(boolexpr_e);
        		$<exprval>$->sym = newtemp();
        		emit(if_greater, $<exprval>1, $<exprval>3, NULL, nextquad()+3, yylineno);
        		emit(assign, newexpr_constbool('0'), NULL, $<exprval>$, 69,yylineno);
        		emit(jump, NULL, NULL, NULL , nextquad()+2, yylineno);
        		emit(assign, newexpr_constbool('1'), NULL, $<exprval>$, 69 , yylineno);
			   */
      	}
		| expr AND expr {
       		/*$<exprval>$ = newexpr(boolexpr_e);
        		$<exprval>$->sym = newtemp();
        		emit(con_and,$<exprval>1, $<exprval>3, $<exprval>$, 69, yylineno);
			   */
      	}
		| expr OR expr {
        		/*$<exprval>$ = newexpr(boolexpr_e);
        		$<exprval>$->sym = newtemp();
        		emit(con_or ,$<exprval>1, $<exprval>3, $<exprval>$, 69, yylineno);
			   */
      	}
		| term {;}
		;

term: 		L_PAR expr R_PAR {;}
			| UMINUS expr %prec UMINUS {;}
			| NOT expr {;}
			| D_PLUS lvalue {
				if($2 != NULL && strcmp($2,"[userfunc]") == 0) Error(0, yytext, yylineno);
				else if($2 != NULL && !strcmp($2,"[library function]")) Error(1, yytext, yylineno);
			}
			| lvalue D_PLUS {
				if($1 != NULL && strcmp($1,"[userfunc]") == 0) Error(0, yytext, yylineno);
				else if($1 != NULL && !strcmp($1,"[library function]")) Error(1,yytext, yylineno);
			}
			| D_MINUS lvalue {
				if($2 != NULL && strcmp($2,"[userfunc]") == 0) Error(0, yytext, yylineno);
				else if($2 != NULL && !strcmp($2,"[library function]")) Error(1, yytext, yylineno);
			}
			| lvalue D_MINUS {
				if($1 != NULL && strcmp($1,"[userfunc]") == 0) Error(0, yytext, yylineno);
				else if($1 != NULL && !strcmp($1,"[library function]")) Error(1, yytext, yylineno);
			}
			| primary {;}
			;

assignexpr:	lvalue ASSIGN expr {
      			if($1 != NULL && strcmp($1,"[userfunc]") == 0) Error(0, yytext, yylineno);
				else if($1 != NULL && strcmp($1,"[library function]") == 0) Error(0, yytext, yylineno);
      		}
			;

primary: 	lvalue {}
       	| call {;}
       	| objectdef {;}
       	| L_PAR funcdef R_PAR {;}
       	| const {;}
       	;

lvalue: 	ID {
          	DataItem* item = lvalue_id(yytext, yylineno);
			/*if(item == NULL){ 
				item = create_item(var_s, item->sym->name, currscopespace(), currscopespaceoffset(), currscope(), currfuncscope(), yylineno); 
				item->sym->space = currscopespace(); 
				item->sym->offset = currscopespaceoffset(); 
				incurrscopeoffset(); 
			} 
			//$$.sval=lvalue_expr(item); */
          	$$ = item->type;
        	}
      		| LOCAL ID {
        			DataItem* item = lvalue_localid(yytext, yylineno);
				/*if(item == NULL){ 
					item = create_item(var_s, item->sym->name, currscopespace(), currscopespaceoffset(), currscope(), currfuncscope(), yylineno); 
					item->sym->space = currscopespace(); 
				  	item->sym->offset = currscopespaceoffset(); 
					incurrscopeoffset(); 
				}else{…warningifsymisafunction…}*/ 
				//$$.sval=lvalue_expr(item);
        			$$ = item->type;
      		}
      		| D_COLON ID {
        			DataItem* tmp = lvalue_dcolonid(yytext, yylineno);
        			$$ = tmp->type;
      		}
      		| member {$$ = "NoError";}
      		;

member: 		lvalue DOT ID {;}
      		| lvalue L_BRA expr R_BRA {;}
      		| call DOT ID {;}
      		| call L_BRA expr R_BRA {;}
      		;

call: 		call L_PAR elist R_PAR {;}
    			| lvalue callsuffix {;}
    			| L_PAR funcdef R_PAR L_PAR elist R_PAR {;}
    			;

callsuffix: 	normcall {;}
          	| methodcall {;}
          	;

normcall: 	L_PAR elist R_PAR {;};

methodcall: 	D_DOT ID L_PAR elist R_PAR {;};

elist: 		expr {;}
      		| elist COMMA expr {;}
      		|{;}
      		;

objectdef: 	L_BRA elist R_BRA {;}
         		| L_BRA indexed R_BRA {;}
         		;

indexed: 		indexedelem {;}
       		| indexed COMMA indexedelem {;}
       		;

indexedelem: 	LC_BRA  expr COLON expr RC_BRA
            	;


rec_stmt: 	rec_stmt stmt{;}
          	| {;}
          	;

block:  	LC_BRA {nextscope();} rec_stmt RC_BRA{ hide(currscope()); exitscope();}
     	;

funcname:		ID {
				funcname_id(yytext, yylineno);
    				//$$ = $1.value;
    			}
    			| {
				funcname_noname(yytext, yylineno);
      			//$$ = newtempname();
    			}
          	;
funcprefix: 	FUNC funcname { 
				/*
    				$$ = create_item(programfunc_s, $2, currscopespace(), currscopespaceoffset(), currscope(), currfuncscope(), yylineno)->sym->name; 
    				$$.iaddress = nextquadlabel(); 
    				emit(funcstart, $$, NULL, NULL); 
    				push(scopeoffsetstack, currscopeoffset());  */
    				enterscopespace(); 
    				/*resetformalargsoffset();
				*/
			}
      		;
funcargs: 	L_PAR idlist R_PAR {
				enterfuncscope();
  				enterscopespace();
  				resetfunctionlocaloffset();
			}
      		;
funcbody: 	block {
				exitfuncscope();
				currscopespaceoffset();
  				/*$$ = currscopespaceoffset();*/
  				exitscopespace();
			}
      		;
       
funcblockstart:{ /*push(loopcounterstack, loopcounter); loopcounter=0; */}; 
funcblockend:	{ /*loopcounter = pop(loopcounterstack);*/ }

funcdef: 	funcprefix funcargs funcblockstart funcbody funcblockend{
  			exitscopespace();
  			//$1.totalLocals = $3;
  			//int offset = pop_and_top(scopeoffsetStack);
  			//$$ = $1;
			//restorecurrscopeoffset(offset); 
  			//emit(funcend, $1,  NULL ,  NULL, NULL, yylineno);
		}
     	;
const: 	INT{;}
		| REAL{;}
		| STRING{;}
		| NIL{;}
		| TRUE{;}
		| FALSE{;}
		;

idlist:	ID { idlist_id(yytext, yylineno);}
		|idlist COMMA ID { idlist_commaid(yytext, yylineno);}
		| {;}
		;

ifprefix:	IF L_PAR  expr R_PAR {    
		      	//emit(if_eq, $3, newexpr_constbool(1), nextquad()+2); 
		      	//$$ = nextquad();   
	      		//emit(jump, NULL , NULL, NULL, NULL, yylineno);
			    } 
	      	;

elseprefix: 	ELSE {
      			//$$ = nextquad();   
      			//emit(jump, NULL, NULL, NULL, NULL, yylineno);
			}
      		;

ifstmt: 	ifprefix stmt{   
      			//patchlabel($1, nextquad());  
      		} 
      		| ifprefix stmt elseprefix stmt {
      			//patchlabel($1, $3+1);   
      			//patchlabel($3, nextquad());
			}  
      		;


whilestart:	WHILE { 
          		gloop++;
				nextquad();
      			/*$$ = nextquad();*/
			} 
      		;

whilecond: 	L_PAR  expr R_PAR loopstmt{   
      			//emit(if_eq, $2, newexpr_constbool(1), nextquad()+2); 
      			//$$ = nextquad();   
      			//emit(jump, NULL, NULL, NULL, NULL, yylineno); 
			} 
			

loopstart:	{ ++loopcounter;};
loopend:		{ --loopcounter;};
      		;
loopstmt: loopstart stmt loopend { $$ = $2;}
  		; 

 
whilestmt: 	whilestart whilecond loopstmt {
            		gloop--;
      			//emit(jump, $1);   
      			//patchlabel($2, nextquad());   
      			//patchlabel($3->breaklist, nextquad());   
      			//patchlabel($3->contlist, $1);
			} 
      		;

N: 	{ 
      	//$$ = nextquad();  
      	//emit(jump, NULL, NULL, NULL, NULL, yylineno); 
	}
    	;
M:   {/*$$ = nextquad();*/} 
     ;
forprefix:	FOR {gloop++;} L_PAR  elist SEMI M expr SEMI {   
      			//$$.test = $5;
      			//$$.enter = nextquad();   
      			//emit(if_eq, $6, newexpr_constbool(1), NULL, NULL, yylineno);
			} 
      		;

forstmt:	forprefix N elist R_PAR N stmt {gloop--;} N {
        		//patchlabel($1.enter, $5+1);   
        		//patchlabel($2, nextquad());   
        		//patchlabel($5, $1.test);   
        		//patchlabel($<intval>7, $2+1); 
		     //patchlabel($6->breaklist, nextquad());   
		     //patchlabel($6->contlist, $2+1);
		}
    		; 

returnstmt:RETURN SEMI { if (currfuncscope() == 0) Error(2, yytext, yylineno); }
        | RETURN expr SEMI { if (currfuncscope() == 0) Error(2, yytext, yylineno); }
        ;


%%

void yyerror(char* yaccProovidedMessage) {
  	fprintf(stderr, "%s: at line %d, before token: %s\n",yaccProovidedMessage, yylineno, yytext);
  	fprintf(stderr, "INPUT NOT VALID\n");
}

int main(int argc, char** argv) {
  	symtable = create_new_symtable();
  	table_insert(libraryfunc_s, "print", currscopespace(), currscopespaceoffset(), currscope(), currfuncscope(), 0);
  	table_insert(libraryfunc_s, "input", currscopespace(), currscopespaceoffset(), currscope(), currfuncscope(), 0);
  	table_insert(libraryfunc_s, "objectmemberkyes", currscopespace(), currscopespaceoffset(), currscope(), currfuncscope(), 0);
  	table_insert(libraryfunc_s, "objectotslmembers", currscopespace(), currscopespaceoffset(), currscope(), currfuncscope(), 0);
  	table_insert(libraryfunc_s, "objectcopy", currscopespace(), currscopespaceoffset(), currscope(), currfuncscope(), 0);
  	table_insert(libraryfunc_s, "totalarguments", currscopespace(), currscopespaceoffset(), currscope(), currfuncscope(), 0);
	table_insert(libraryfunc_s, "argument", currscopespace(), currscopespaceoffset(), currscope(), currfuncscope(), 0);
	table_insert(libraryfunc_s, "typeof", currscopespace(), currscopespaceoffset(), currscope(), currfuncscope(), 0);
	table_insert(libraryfunc_s, "strtonum", currscopespace(), currscopespaceoffset(), currscope(), currfuncscope(), 0);
  	table_insert(libraryfunc_s, "sqrt", currscopespace(), currscopespaceoffset(), currscope(), currfuncscope(), 0);
  	table_insert(libraryfunc_s, "cos", currscopespace(), currscopespaceoffset(), currscope(), currfuncscope(), 0);
  	table_insert(libraryfunc_s, "sin", currscopespace(), currscopespaceoffset(), currscope(), currfuncscope(), 0);
  	if(argc > 1){
    	if(!(yyin = fopen(argv[1], "r"))){
      	fprintf(stderr, "Cannot read  file: %s\n", argv[1]);
      	return 1;
    	}
  	} else {
    		yyin = stdin;
  	}
  	yyparse();
  	print_table();
	free_table(symtable);
  	return 0;
}
