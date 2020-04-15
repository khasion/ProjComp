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

%type <exprval> primary lvalue

%type <intval> expr  assignexpr N M 
%type <strval> term  member call callsuffix normcall elist objectdef 
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
		| break SEMI {
				//$$.breaklist = newlist(nextquad()); 
				//emit(jump, NULL, NULL, NULL, NULL, yylineno);  
				if (gloop == 0) Error(3, yytext, yylineno);
		}
		| continue SEMI {
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

term: 	L_PAR expr R_PAR {$$=$2;}
		| UMINUS expr %prec UMINUS {
		checkuminus($2);   
		$$ = newexpr(arithexpr_e);   
		$$->sym = istempexpr($2)? $2->sym : newtemp();   
		emit(uminus, $2, $$); }
		| NOT expr {
		$$ = newexpr(boolexpr_e);   
		$$->sym = newtemp();   
		emit(not, $2, $term); 
		}
		| D_PLUS lvalue {
			if($2 != NULL && $2->type == programfunc_e) Error(0, yytext, yylineno);
			else if($2 != NULL && $2->type == libraryfunc_e) Error(1, yytext, yylineno);
			if ($2->type = tableitem_e){ 
				$$ = emit_iftableitem($2); 
				emit(add, $term, newexpr_constnum(1), $$); 
				emit( tablesetelem, $2, $2->index, $$); }
			else { 
				emit(add, $lvalue, newexpr_constnum(1), $lvalue); 
				$$ = newexpr(arithexpr_e); 
				$$->sym = newtemp(); 
				emit(assign, $lvalue, $term); 
			}


		}
		| lvalue D_PLUS {
			if($1 != NULL && $2->type == programfunc_e) Error(0, yytext, yylineno);
			else if($1 != NULL && $2->type == libraryfunc_e) Error(1,yytext, yylineno);
			$$ = newexpr(var_e); 
			$$->sym= newtemp();
			if ($1->type= tableitem_e){ 
				Expr* value = emit_iftableitem($lvalue); 
				emit(assign, value, $$); 
				emit(add, value, newexpr_constnum(1), value); 
				emit( tablesetelem, $1, $1->index, value); 
			} 
			else { 
				emit(assign, $lvalue, $term); 
				emit(add, $lvalue, newexpr_constnum(1), $lvalue); 
			}

		}
		| D_MINUS lvalue {
			if($2 != NULL && $2->type == programfunc_e) Error(0, yytext, yylineno);
			else if($2 != NULL && $2->type == libraryfunc_e) Error(1, yytext, yylineno);
			if ($2->type = tableitem_e){ 
				$$ = emit_iftableitem($2); 
				emit(add, $term, newexpr_constnum(1), $$); 
				emit( tablesetelem, $2, $2->index, $$); }
			else { 
				emit(add, $2, newexpr_constnum(1), $2); 
				$term = newexpr(arithexpr_e); 
				$term->sym = newtemp(); 
				emit(assign, $2, $term); 
			}
		}
		| lvalue D_MINUS {
			if($1 != NULL && $1->type == programfunc_e) Error(0, yytext, yylineno);
			else if($1 != NULL && $1->type == libraryfunc_e) Error(1, yytext, yylineno);
			$$ = newexpr(var_e); 
			$$->sym= newtemp();
			if ($1->type= tableitem_e){ 
				Expr* value = emit_iftableitem($1); 
				emit(assign, value, $$); 
				emit(add, value, newexpr_constnum(1), value); 
				emit( tablesetelem, $lvalue, $1->index, value); 
			} 
			else { 
				emit(assign, $1, $$); 
				emit(add, $1, newexpr_constnum(1), $1); 
			}

		}
		| primary {$$=$1;}
		;

assignexpr:	lvalue ASSIGN expr {
      			if($1 != NULL && $1->type == programfunc_e) Error(0, yytext, yylineno);
				else if($1 != NULL && $1->type == libraryfunc_e) Error(1, yytext, yylineno);
				  if  $1->type = tableitem_e then {   
					  emit(tablesetelem, $lvalue, $1->index, $3);
					  $$ = emit_iftableitem ($1); 
					  $$->type = assignexpr_e; 
				}     
				else {   
					emit(assign, $3,(Expr*) 0, $1, 0, yylineno);   
					$$ = newexpr(assignexpr_e); 
					$$->sym = newtemp();
					emit(assign, $1, (Expr*) 0, $$ , 0 ,yylineno);     
					} 
			}
			;

primary: lvalue { $$ = emit_iftableitem($1);}
       	| call {;}
       	| objectdef {;}
       	| L_PAR funcdef R_PAR {
		$$= newexpr(programfunc_e); 
		$$->sym= $2;
		}
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
			$$.sval=lvalue_expr(item); */
          	$$ = item->type;
        	}
      		| LOCAL ID {
        			DataItem* item = lvalue_localid(yytext, yylineno);
				/*if(item == NULL){
					item = create_item(var_s, item->sym->name, currscopespace(), currscopespaceoffset(), currscope(), currfuncscope(), yylineno); 
					item->sym->space = currscopespace(); 
				  	item->sym->offset = currscopespaceoffset(); 
					incurrscopeoffset(); 
				}else{…warningifsymisafunction…}
				$$.sval=lvalue_expr(item); */
        			$$ = item->type;
      		}
      		| D_COLON ID {
        			DataItem* tmp = lvalue_dcolonid(yytext, yylineno);
        			$$ = tmp->type;
      		}
      		| member {$$ = $1;}
      		;

member: 	lvalue DOT ID {$$ = member_item($1, yytext);}
      		| lvalue L_BRA expr R_BRA {
				  $1 = emit_iftableitem($1); 
				  $$ = newexpr(tableitem_e); 
				  $$->sym = $1->sym; 
				  $$->index = $3; }
      		| call DOT ID {;}
      		| call L_BRA expr R_BRA {;}
      		;

call: 		call L_PAR elist R_PAR { $$ = make_call($$, $3);} 
    		| lvalue callsuffix {
				$1= emit_iftableitem($1); 
				if (callsuffix.method){ 
					Expr* self = $1; 
					$1 = emit_iftableitem(member_item(self, $2.name)); 
					self->next = $2;  
					$2= self;
				} 
				$$ = make_call($1, $2);}
    		| L_PAR funcdef R_PAR L_PAR elist R_PAR {
				Expr* func = newexpr(programfunc_e); 
				func->sym = $2; 
				$$ = make_call(func, $elist);
			}
    		;

callsuffix: normcall { $$= $1; }
          	| methodcall {$$= $1;}
          	;

normcall: 	L_PAR elist R_PAR {
			$$.elist = $2; 
			$$.method = false; 
			$$.name = nil;
			};

methodcall: D_DOT ID L_PAR elist R_PAR {
			$$.elist = $4; 
			$$.method = true; 
			$$.name     = $2.val;
		};

elist: 		expr {;}
      		| elist COMMA expr {;}
      		|{;}
      		;

objectdef: 	L_BRA elist R_BRA {
			Expr* t = newexpr(newtable_e); 
			t->sym = newtemp(); 
			emit(tablecreate, t, NULL, NULL); 
			for (int i = 0; $2; $2 = $2->next)  emit(tablesetelem, t, newexpr_constnum(i++), $2); 
			$$ = t;}
         	| L_BRA indexed R_BRA {
			Expr* t = newexpr(newtable_e); 
			t->sym = newtemp(); 
			emit(tablecreate, t, NULL, NULL); 
			//foreach<index, value> in $indexed do emit(tablesetelem, t, index, value); 
			$$ = t;}
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
			

 
whilestmt: 	whilestart whilecond {
            		gloop--;
      			//emit(jump, $1);   
      			//patchlabel($2, nextquad());   
      			//patchlabel($3->breaklist, nextquad());   
      			//patchlabel($3->contlist, $1);
			} 
      		;
loopstart:	{ ++loopcounter;};
loopend:	{ --loopcounter;};
      	;
loopstmt: loopstart stmt loopend { $$ = $2;}
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

break: BREAK {
	//emit(jump, NULL, NULL, NULL, 69, yylineno);
};

continue: CONTINUE {
	//emit(jump, NULL, NULL, NULL, 69, yylineno);
};


returnstmt: RETURN SEMI { if (currfuncscope() == 0) Error(2, yytext, yylineno);
			emit(ret, NULL, NULL, NULL, 69, yylineno); }
        | RETURN expr SEMI { if (currfuncscope() == 0) Error(2, yytext, yylineno); }
		emit(ret, NULL, NULL, $<exprval>2, 69, yylineno);
        ;

%%

void yyerror(char* yaccProovidedMessage) {
  	fprintf(stderr, "%s: at line %d, before token: %s\n",yaccProovidedMessage, yylineno, yytext);
  	fprintf(stderr, "INPUT NOT VALID\n");
}

int main(int argc, char** argv) {
  	symtable = create_new_symtable();
	init_quad();
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
