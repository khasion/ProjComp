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
%type <strval> term  member call callsuffix methodcall normcall elist objectdef
%type <strval>	indexed indexedelem  rec_stmt block const idlist
%type <strval> funcname funcprefix funcargs funcbody funcdef  elseprefix forprefix
%type <strval> funcblockend funcblockstart  ifprefix whilestart whilecond

%%
program:	stmt program {;}
       	| {;}
       	;

stmts: 	stmts stmt {
 			//$<exprval>$.breaklist = merge($<exprval>1.breaklist, $<exprval>2.breaklist);
			//$<exprval>$.contlist  = merge($<exprval>1.contlist, $<exprval>2. contlist);
 		}
		| stmt { $<exprval>$ = $<exprval>1; }

stmt: 	expr SEMI {;}
		| ifstmt
		| whilestmt {;}
		| forstmt {;}
		| returnstmt {;}
		| break SEMI {
				//$<exprval>$.breaklist = newlist(nextquad());
				//emit(jump, NULL, NULL, NULL, NULL, yylineno);
				if (gloop == 0) Error(3, yytext, yylineno);
		}
		| continue SEMI {
				//$<exprval>$.contlist = newlist(nextquad());
				//emit(jump, NULL, NULL, NULL, NULL, yylineno);
				if (gloop == 0) Error(4, yytext, yylineno);
		}
		| block {;}
		| funcdef {;}
		| SEMI {;}
		;

expr: 	assignexpr
		| expr PLUS expr {
        		$<exprval>$ = newexpr(arithexpr_e);
        		$<exprval>$->sym = newtemp();
        		emit(op_add, $<exprval>1, $<exprval>3, $<exprval>$, 69, yylineno);

		}
		| expr MINUS expr {
        		$<exprval>$ = newexpr(arithexpr_e);
        		$<exprval>$->sym = newtemp();
        		emit(op_sub, $<exprval>1, $<exprval>3, $<exprval>$, 69, yylineno);

		}
		| expr MUL expr {
        		$<exprval>$ = newexpr(arithexpr_e);
        		$<exprval>$->sym = newtemp();
        		emit(op_mul, $<exprval>1, $<exprval>3, $<exprval>$, 69, yylineno);

		}
		| expr DIV expr {
        		$<exprval>$ = newexpr(arithexpr_e);
        		$<exprval>$->sym = newtemp();
        		emit(op_div, $<exprval>1, $<exprval>3, $<exprval>$, 69, yylineno);

		}
		| expr MOD expr {
        		$<exprval>$ = newexpr(arithexpr_e);
        		$<exprval>$->sym = newtemp();
        		emit(op_mod, $<exprval>1, $<exprval>3, $<exprval>$, 69, yylineno);

		}
		| expr GREATER expr {
        		$<exprval>$ = newexpr(boolexpr_e);
        		$<exprval>$->sym = newtemp();
        		emit(if_greater, $<exprval>1, $<exprval>3, NULL, nextquad()+3, yylineno);
        		emit(assign, newexpr_constbool('0'), NULL, $<exprval>$, 69,yylineno);
        		emit(jump, NULL, NULL, NULL , nextquad()+2, yylineno);
        		emit(assign, newexpr_constbool('1'), NULL, $<exprval>$, 69 , yylineno);

        	}
		| expr GREATER_EQ expr {
        		$<exprval>$ = newexpr(boolexpr_e);
        		$<exprval>$->sym = newtemp();
        		emit(if_greater, $<exprval>1, $<exprval>3, NULL, nextquad()+3, yylineno);
        		emit(assign, newexpr_constbool('0'), NULL, $<exprval>$, 69,yylineno);
        		emit(jump, NULL, NULL, NULL , nextquad()+2, yylineno);
        		emit(assign, newexpr_constbool('1'), NULL, $<exprval>$, 69 , yylineno);

        	}
		| expr LESS expr {
        		$<exprval>$ = newexpr(boolexpr_e);
        		$<exprval>$->sym = newtemp();
        		emit(if_greater, $<exprval>1, $<exprval>3, NULL, nextquad()+3, yylineno);
        		emit(assign, newexpr_constbool('0'), NULL, $<exprval>$, 69,yylineno);
        		emit(jump, NULL, NULL, NULL , nextquad()+2, yylineno);
        		emit(assign, newexpr_constbool('1'), NULL, $<exprval>$, 69 , yylineno);

      	}
		| expr LESS_EQ expr {
        		$<exprval>$ = newexpr(boolexpr_e);
        		$<exprval>$->sym = newtemp();
        		emit(if_greater, $<exprval>1, $<exprval>3, NULL, nextquad()+3, yylineno);
        		emit(assign, newexpr_constbool('0'), NULL, $<exprval>$, 69,yylineno);
        		emit(jump, NULL, NULL, NULL , nextquad()+2, yylineno);
        		emit(assign, newexpr_constbool('1'), NULL, $<exprval>$, 69 , yylineno);

      	}
		| expr EQ expr {
        		$<exprval>$ = newexpr(boolexpr_e);
        		$<exprval>$->sym = newtemp();
        		emit(if_greater, $<exprval>1, $<exprval>3, NULL, nextquad()+3, yylineno);
        		emit(assign, newexpr_constbool('0'), NULL, $<exprval>$, 69,yylineno);
        		emit(jump, NULL, NULL, NULL , nextquad()+2, yylineno);
        		emit(assign, newexpr_constbool('1'), NULL, $<exprval>$, 69 , yylineno);

      	}
		| expr NOT_EQ expr {
        		$<exprval>$ = newexpr(boolexpr_e);
        		$<exprval>$->sym = newtemp();
        		emit(if_greater, $<exprval>1, $<exprval>3, NULL, nextquad()+3, yylineno);
        		emit(assign, newexpr_constbool('0'), NULL, $<exprval>$, 69,yylineno);
        		emit(jump, NULL, NULL, NULL , nextquad()+2, yylineno);
        		emit(assign, newexpr_constbool('1'), NULL, $<exprval>$, 69 , yylineno);

      	}
		| expr AND expr {
       		$<exprval>$ = newexpr(boolexpr_e);
        		$<exprval>$->sym = newtemp();
        		emit(con_and,$<exprval>1, $<exprval>3, $<exprval>$, 69, yylineno);

      	}
		| expr OR expr {
        		$<exprval>$ = newexpr(boolexpr_e);
        		$<exprval>$->sym = newtemp();
        		emit(con_or ,$<exprval>1, $<exprval>3, $<exprval>$, 69, yylineno);

      	}
		| term {;}
		;

term: 	L_PAR expr R_PAR {$<exprval>$=$<exprval>2;}
		| UMINUS expr %prec UMINUS {
		check_arith($<exprval>2);
		$<exprval>$ = newexpr(arithexpr_e);
		//$<exprval>$->sym = istempexpr($<exprval>2)? $<exprval>2->sym : newtemp();
		emit(uminus, $<exprval>2, $<exprval>$,NULL, 0 , yylineno);
	}
		| NOT expr {
		$<exprval>$ = newexpr(boolexpr_e);
		$<exprval>$->sym = newtemp();
		emit(con_not, $<exprval>2, $<exprval>$,NULL,  0 , yylineno);
		}
		| D_PLUS lvalue {
			if($<exprval>2 != NULL && $<exprval>2->type == programfunc_e) Error(0, yytext, yylineno);
			else if($<exprval>2 != NULL && $<exprval>2->type == libraryfunc_e) Error(1, yytext, yylineno);
			if ($<exprval>2->type == tableitem_e){
				$<exprval>$ = emit_iftableitem($<exprval>2);
				emit(op_add, $term, newexpr_constnum(1), $<exprval>$, 0 , yylineno);
				emit(tablesetelem, $<exprval>2, $<exprval>2->index, $<exprval>$, 0 , yylineno); }
			else {
				emit(op_add, $lvalue, newexpr_constnum(1), $lvalue);
				$<exprval>$ = newexpr(arithexpr_e);
				$<exprval>$->sym = newtemp();
				emit(assign, $lvalue, $term, NULL, 0 , yylineno);
			}


		}
		| lvalue D_PLUS {
			if($<exprval>1 != NULL && $<exprval>2->type == programfunc_e) Error(0, yytext, yylineno);
			else if($<exprval>1 != NULL && $<exprval>2->type == libraryfunc_e) Error(1,yytext, yylineno);
			$<exprval>$ = newexpr(var_e);
			$<exprval>$->sym= newtemp();
			if ($<exprval>1->type== tableitem_e){
				Expr* value = emit_iftableitem($lvalue);
				emit(assign, value, $<exprval>$);
				emit(op_add, value, newexpr_constnum(1), value);
				emit( tablesetelem, $<exprval>1, $<exprval>1->index, value,  0 , yylineno);
			}
			else {
				emit(assign, $lvalue, $term,NULL, 0 , yylineno);
				emit(op_add, $lvalue, newexpr_constnum(1), $lvalue, 0 , yylineno);
			}

		}
		| D_MINUS lvalue {
			if($<exprval>2 != NULL && $<exprval>2->type == programfunc_e) Error(0, yytext, yylineno);
			else if($<exprval>2 != NULL && $<exprval>2->type == libraryfunc_e) Error(1, yytext, yylineno);
			if ($<exprval>2->type == tableitem_e){
				$<exprval>$ = emit_iftableitem($<exprval>2);
				emit(op_sub, $<exprval>$, newexpr_constnum(1), $<exprval>$, 0 , yylineno);
				emit( tablesetelem, $<exprval>2, $<exprval>2->index, $<exprval>$, 69, yylineno); }
			else {
				emit(op_sub, $<exprval>2, newexpr_constnum(1), $<exprval>2);
				$<exprval>$ = newexpr(arithexpr_e);
				$<exprval>$->sym = newtemp();
				emit(assign, $<exprval>2, $term);
			}
		}
		| lvalue D_MINUS {
			if($<exprval>1 != NULL && $<exprval>1->type == programfunc_e) Error(0, yytext, yylineno);
			else if($<exprval>1 != NULL && $<exprval>1->type == libraryfunc_e) Error(1, yytext, yylineno);
			$<exprval>$ = newexpr(var_e);
			$<exprval>$->sym= newtemp();
			if ($<exprval>1->type== tableitem_e){
				Expr* value = emit_iftableitem($<exprval>1);
				emit(assign, value, $<exprval>$, NULL, 0 , yylineno);
				emit(op_sub, value, newexpr_constnum(1), value, 0 , yylineno);
				emit( tablesetelem, $<exprval>1, $<exprval>1->index, value, 0 , yylineno);
			}
			else {
				emit(assign, $<exprval>1, $<exprval>$, NULL, 0 , yylineno);
				emit(op_sub, $<exprval>1, newexpr_constnum(1), $<exprval>1, 0 , yylineno);
			}

		}
		| primary {$<exprval>$=$<exprval>1;}
		;

assignexpr:	lvalue ASSIGN expr {
      			if($<exprval>1 != NULL && $<exprval>1->type == programfunc_e) Error(0, yytext, yylineno);
				else if($<exprval>1 != NULL && $<exprval>1->type == libraryfunc_e) Error(1, yytext, yylineno);
				  if  ($<exprval>1->type == tableitem_e) {
					  emit(tablesetelem, $<exprval>1, $<exprval>1->index, $3, 0 , yylineno);
					  $<exprval>$ = emit_iftableitem ($<exprval>1);
					  $<exprval>$->type = assignexpr_e;
				}
				else {
					emit(assign, $<exprval>3,(Expr*) 0, $<exprval>1, 0, yylineno);
					$<exprval>$ = newexpr(assignexpr_e);
					$<exprval>$->sym = newtemp();
					emit(assign, $<exprval>1, (Expr*) 0, $<exprval>$ , 0 ,yylineno);
					}
			}
			;

primary: lvalue { $<exprval>$ = emit_iftableitem($<exprval>1);}
       	| call {;}
       	| objectdef {;}
       	| L_PAR funcdef R_PAR {
					$<exprval>$= newexpr(programfunc_e);
					$<exprval>$->sym= $<exprval>2;
				}
       	| const {;}
       	;

lvalue: 	ID {
          	DataItem* item = lvalue_id(yytext, yylineno);
			if(item == NULL){
				item = create_item(var_s, item->sym->name, currscopespace(), currscopespaceoffset(), currscope(), currfuncscope(), yylineno);
				item->sym->space = currscopespace();
				item->sym->offset = currscopespaceoffset();
				incurrscopeoffset();
			}
			//$<exprval>$.sval=lvalue_expr(item);
          	$<exprval>$ = item->type;
        	}
      		| LOCAL ID {
        			DataItem* item = lvalue_localid(yytext, yylineno);
				if(item == NULL){
					item = create_item(var_s, item->sym->name, currscopespace(), currscopespaceoffset(), currscope(), currfuncscope(), yylineno);
					item->sym->space = currscopespace();
				  item->sym->offset = currscopespaceoffset();
					incurrscopeoffset();}
				/*}else{…warningifsymisafunction…}
				$<exprval>$.sval=lvalue_expr(item); */
        			$<exprval>$ = (Expr*) item->type;
      		}
      		| D_COLON ID {
        			DataItem* tmp = lvalue_dcolonid(yytext, yylineno);
        			$<exprval>$ = tmp->type;
      		}
      		| member {$<exprval>$ = $<exprval>1;}
      		;

member: 	lvalue DOT ID {$<exprval>$ = member_item($<exprval>1, yytext);}
      		| lvalue L_BRA expr R_BRA {
				  $<exprval>1 = emit_iftableitem($<exprval>1);
				  $<exprval>$ = newexpr(tableitem_e);
				  $<exprval>$->sym = $<exprval>1->sym;
				  $<exprval>$->index = $<exprval>3; }
      		| call DOT ID {;}
      		| call L_BRA expr R_BRA {;}
      		;

call: 		call L_PAR elist R_PAR { $<exprval>$ = (Expr*) make_call($<exprval>$, $<exprval>3);}
    		| lvalue callsuffix {
				$<exprval>1= emit_iftableitem($<exprval>1);
				if ($<exprval>2.method){
					Expr* self = $<exprval>1;
					//$<exprval>1 = emit_iftableitem(member_item(self, $<exprval>2.name));
					self->next = $<exprval>2;
					$<exprval>2= self;
				}}
				//$<exprval>$ = make_call($<exprval>1, $<exprval>2);}
    		| L_PAR funcdef R_PAR L_PAR elist R_PAR {
				Expr* func = newexpr(programfunc_e);
				func->sym = $<exprval>2;
				$<exprval>$ = (Expr*)make_call(func, $<exprval>3);
			}
    		;

callsuffix: normcall { $<exprval>$ = $<exprval>1; }
          	| methodcall {$<exprval>$ = $<exprval>1;}
          	;

normcall: 	L_PAR elist R_PAR {
			//$<exprval>$.elist = $<exprval>2;
			//$<exprval>$.method = false;
			//$<exprval>$.name = nil;
			};

methodcall: D_DOT ID L_PAR elist R_PAR {
			//$<exprval>$.elist = $4;
			//$<exprval>$.method = true;
			//$<exprval>$.name     = $<exprval>2.val;
		};

elist: 		expr {;}
      		| elist COMMA expr {;}
      		|{;}
      		;

objectdef: 	L_BRA elist R_BRA {
			Expr* t = newexpr(newtable_e);
			t->sym = newtemp();
			emit(tablecreate, t, NULL, NULL, 0 , yylineno);
			int i;
			for (i = 0; $<exprval>2; $<exprval>2 = $<exprval>2->next)  emit(tablesetelem, t, newexpr_constnum(i++), $<exprval>2, 69, yylineno);
			$<exprval>$ = t;}
         	| L_BRA indexed R_BRA {
			Expr* t = newexpr(newtable_e);
			t->sym = newtemp();
			emit(tablecreate, t, NULL, NULL, 0 , yylineno);
			//foreach<index, value> in $indexed do emit(tablesetelem, t, index, value);
			$<exprval>$ = t;}
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
    				//$<exprval>$ = $<exprval>1.value;
    			}
    			| {
				funcname_noname(yytext, yylineno);
      			//$<exprval>$ = newtempname();
    			}
          	;
funcprefix: 	FUNC funcname {
				/*
    				$<exprval>$ = create_item(programfunc_s, $<exprval>2, currscopespace(), currscopespaceoffset(), currscope(), currfuncscope(), yylineno)->sym->name;
    				$<exprval>$.iaddress = nextquadlabel();
    				emit(funcstart, $<exprval>$, NULL, NULL);
    				push(scopeoffsetstack, currscopeoffset());  */
    				enterscopespace();
    				resetformalargsoffset();

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
  				$<exprval>$ = currscopespaceoffset();
  				exitscopespace();
			}
      		;

funcblockstart:{ /*push(loopcounterstack, loopcounter); loopcounter=0; */};
funcblockend:	{ /*loopcounter = pop(loopcounterstack);*/ }

funcdef: 	funcprefix funcargs funcblockstart funcbody funcblockend{
  			exitscopespace();
  			//$<exprval>1.totalLocals = $3;
  			//int offset = pop_and_top(scopeoffsetStack);
  			$<exprval>$ = $<exprval>1;
				//restorecurrscopeoffset(offset);
  			//emit(funcend, $<exprval>1,  NULL ,  NULL, 0, yylineno);
		}
     	;
const: 	INT{;}
		| REAL{;}
		| STRING{;}
		| NIL{;}
		| TRUE{$<exprval>$ = newexpr_constbool('1');}
		| FALSE{$<exprval>$ = newexpr_constbool('0');}
		;

idlist:	ID { idlist_id(yytext, yylineno);}
		|idlist COMMA ID { idlist_commaid(yytext, yylineno);}
		| {;}
		;

ifprefix:	IF L_PAR  expr R_PAR {
		      	emit(if_eq, $3, newexpr_constbool(1), nextquad()+2,0,yylineno);
		      	$<exprval>$ = nextquad();
	      		emit(jump, NULL , NULL, NULL, 0, yylineno);
		}
	     ;

elseprefix: 	ELSE {
      			$<exprval>$ = nextquad();
      			emit(jump, NULL, NULL, NULL, 0, yylineno);
			}
      		;

ifstmt: 	ifprefix stmt{
      			patchlabel($<exprval>1, nextquadlabel());
      		}
      		| ifprefix stmt elseprefix stmt {
      			patchlabel($<exprval>1, $<intval>3+1);
      			patchlabel($3, nextquadlabel());
			}
      		;


whilestart:	WHILE {
          		gloop++;
							nextquad();
      				$<intval>$ = nextquad();
			}
      		;

whilecond: 	L_PAR  expr R_PAR {
      			emit(if_eq, $<exprval>2, newexpr_constbool(1), nextquadlabel()+2,0,yylineno);
      			$<intval>$ = nextquad();
      			emit(jump, NULL, NULL, NULL, 0, yylineno);
			}



whilestmt: 	whilestart whilecond stmt{
            		gloop--;
						emit(jump, $<exprval>1,NULL,NULL,0,yylineno);
      			patchlabel($<exprval>2, nextquad());
      			//patchlabel($3->breaklist, nextquad());
      			//patchlabel($3->contlist, $<exprval>1);
			}
      		;
loopstart:	{ ++loopcounter;};
loopend:	{ --loopcounter;};
      	;
loopstmt: loopstart stmt loopend { $<exprval>$ = $<exprval>2;}
  		;
N: 	{
      	$<intval>$ = nextquad();
      	emit(jump, NULL, NULL, NULL, 0, yylineno);
	}
    	;
M:   {$<intval>$ = nextquad();}
     ;
forprefix:	FOR {gloop++;} L_PAR  elist SEMI M expr SEMI {
      			//$<exprval>$.test = $5;
      			//$<exprval>$.enter = nextquad();
      			emit(if_eq, $6, newexpr_constbool(1), NULL, 0, yylineno);
			}
      		;

forstmt:	forprefix N elist R_PAR N stmt {gloop--;} N {
        		atchlabel($<exprval>1.enter, $<intval>5+1);
        		patchlabel($<intval>2, nextquadlabel());
        		patchlabel($<intval>5, $<exprval>1.test);
        		patchlabel($<intval>7, $<intval>2+1);
		     //patchlabel($6->breaklist, nextquad());
		     //patchlabel($6->contlist, $<exprval>2+1);
		}
    		;

break: BREAK {
	emit(jump, NULL, NULL, NULL, 69, yylineno);
};

continue: CONTINUE {
	emit(jump, NULL, NULL, NULL, 69, yylineno);
};


returnstmt: RETURN SEMI { if (currfuncscope() == 0) Error(2, yytext, yylineno);
			emit(ret, NULL, NULL, NULL, 69, yylineno); }
        | RETURN expr SEMI { if (currfuncscope() == 0) Error(2, yytext, yylineno);
				emit(ret, NULL, NULL, $<exprval>2, 69, yylineno); }

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
