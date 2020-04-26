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
     struct stmt_t stmtval;
     struct call callval;
     struct symbol symval;
     struct prefix prefval;
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

%type <stmtval> stmt stmts loopstmt ifstmt whilestmt forstmt returnstmt break continue

%type <exprval> lvalue member primary assignexpr call term objectdef const expr elist comma_elist indexed

%type <callval> callsuffix normcall methodcall

%type <symval> funcdef funcprefix

%type <prefval> forprefix

%type <intval> N M funcbody whilestart ifprefix elseprefix whilecond

%type <strval>	indexedelem  rec_stmt block idlist
%type <strval> funcname funcargs
%type <strval> funcblockend funcblockstart

%%
program:	stmt program {;}
          | {;}
          ;

stmts: 	stmts stmt {
               
               $$.breaklist = mergelist($1.breaklist, $2.breaklist);
               $$.contlist = mergelist($1.contlist, $2. contlist);
          }
          | stmt { $$ = $1; }

stmt: 	expr SEMI {
               resettemp();
               if ($1->type == 5) {
                    emit(assign, newexpr_constbool(1), NULL, $$, nextquad(), yylineno);
                    emit(jump, NULL, NULL, NULL, nextquad() + 2, yylineno);
                    emit(assign, newexpr_constbool(0), NULL, $$, nextquad(), yylineno);
                    backpatch($1->truelist, nextquad() - 3);
                    backpatch($1->falselist, nextquad() - 1);
               }
          }
          | ifstmt
          | whilestmt {;}
          | forstmt {;}
          | returnstmt {;}
          | break SEMI {
               make_stmt(&$1);
               $$.breaklist = newlist(nextquad());
               emit(jump, NULL, NULL, NULL, 0, yylineno);
               if (gloop == 0) Error(3, yytext, yylineno);
          }
          | continue SEMI {
               make_stmt(&$1);
               $$.contlist = newlist(nextquad());
               emit(jump, NULL, NULL, NULL, 0, yylineno);
               if (gloop == 0) Error(4, yytext, yylineno);
          }
          | block {;}
          | funcdef {;}
          | SEMI {;}
          ;

expr: 	assignexpr { $$ = $1; }
          | expr PLUS expr {
               $$ = newexpr(arithexpr_e);
               $$->sym = newtemp();
               emit(op_add, $1, $3, $$, nextquad() + 1, yylineno);
          }
          | expr MINUS expr {
               $$ = newexpr(arithexpr_e);
               $$->sym = newtemp();
               emit(op_sub, $1, $3, $$, nextquad() + 1, yylineno);
          }
          | expr MUL expr {
               $$ = newexpr(arithexpr_e);
               $$->sym = newtemp();
               emit(op_mul, $1, $3, $$, nextquad() + 1, yylineno);
          }
          | expr DIV expr {
               $$ = newexpr(arithexpr_e);
               $$->sym = newtemp();
               emit(op_div, $1, $3, $$, nextquad() + 1, yylineno);
          }
          | expr MOD expr {
               $$ = newexpr(arithexpr_e);
               $$->sym = newtemp();
               emit(op_mod, $1, $3, $$, nextquad() + 1, yylineno);
          }
          | expr GREATER expr {
               $$ = newexpr(boolexpr_e);
               $$->sym = newtemp();
               $$->truelist = newlist(nextquad());
               $$->falselist = newlist(nextquad() + 1);
               emit(if_less, $1, $3, $$, 0, yylineno);
               //emit(assign, newexpr_constbool('0'), NULL, $$, nextquad() + 1, yylineno);
               emit(jump, NULL, NULL, NULL , 0, yylineno);
               //emit(assign, newexpr_constbool('1'), NULL, $$, nextquad() + 1, yylineno);
          }
          | expr GREATER_EQ expr {
               $$ = newexpr(boolexpr_e);
               $$->sym = newtemp();
               $$->truelist = newlist(nextquad());
               $$->falselist = newlist(nextquad()+1);
               emit(if_lesseq, $1, $3, $$, 0, yylineno);
               //emit(assign, newexpr_constbool('0'), NULL, $$, 69, yylineno);
               emit(jump, NULL, NULL, NULL , 0, yylineno);
               //(assign, newexpr_constbool('1'), NULL, $$, 69 ,yylineno);
          }
          | expr LESS expr {
               $$ = newexpr(boolexpr_e);
               $$->sym = newtemp();
               $$->truelist = newlist(nextquad());
               $$->falselist = newlist(nextquad()+1);
               emit(if_less, $1, $3, $$, 0, yylineno);
               //emit(assign, newexpr_constbool('0'), NULL, $<exprval>$, 69,yylineno);
               emit(jump, NULL, NULL, NULL , 0, yylineno);
               //emit(assign, newexpr_constbool('1'), NULL, $<exprval>$, 69 , yylineno);
           }
          | expr LESS_EQ expr {
               $$ = newexpr(boolexpr_e);
               $$->sym = newtemp();
               $$->truelist = newlist(nextquad());
               $$->falselist = newlist(nextquad()+1);
               emit(if_greatereq, $1, $3, $$, 0, yylineno);
               //emit(assign, newexpr_constbool('0'), NULL, $<exprval>$, 69,yylineno);
               emit(jump, NULL, NULL, NULL , 0, yylineno);
               //emit(assign, newexpr_constbool('1'), NULL, $<exprval>$, 69 , yylineno);
          }
          | expr EQ expr {
               $$ = newexpr(boolexpr_e);
               $$->sym = newtemp();
               $$->truelist = newlist(nextquad());
               $$->falselist = newlist(nextquad()+1);
               emit(if_eq, $1, $3, $$, 0, yylineno);
               //emit(assign, newexpr_constbool('0'), NULL, $<exprval>$, 69,yylineno);
               emit(jump, NULL, NULL, NULL , 0, yylineno);
               //emit(assign, newexpr_constbool('1'), NULL, $<exprval>$, 69 , yylineno);
           }
          | expr NOT_EQ expr {
               $$ = newexpr(boolexpr_e);
               $$->sym = newtemp();
               $$->truelist = newlist(nextquad());
               $$->falselist = newlist(nextquad()+1);
               emit(if_noteq, $1, $3, NULL, 0, yylineno);
               //emit(assign, newexpr_constbool('0'), NULL, $<exprval>$, 69,yylineno);
               emit(jump, NULL, NULL, NULL , 0, yylineno);
               //emit(assign, newexpr_constbool('1'), NULL, $<exprval>$, 69 , yylineno);
           }
          | expr AND M expr {
               backpatch($1->truelist, $3);
               backpatch($1->falselist, nextquad() + 1);

               backpatch($4->truelist, nextquad());
               backpatch($4->falselist, nextquad() + 1);

               //$$->truelist = $4->truelist;
               //$$->falselist = mergelist($1->falselist, $4->falselist);
               $$ = newexpr(boolexpr_e);
               $$->sym = newtemp();
               emit(assign, newexpr_constbool(1), NULL, $$, nextquad(), yylineno);
               emit(jump, NULL, NULL, NULL, nextquad() + 1, yylineno);
               emit(assign, newexpr_constbool(0), NULL, $$, nextquad() + 1, yylineno);
          }
          | expr OR M expr {
               backpatch($1->falselist, $3);
               backpatch($1->truelist, nextquad());

               backpatch($4->falselist, nextquad() + 2);
               backpatch($4->truelist, nextquad());
               //$$->truelist = mergelist($1->truelist, $4->truelist);
               //$1->falselist = $4->falselist;

               $$ = newexpr(boolexpr_e);
               $$->sym = newtemp();
               emit(assign, newexpr_constbool(1), NULL, $$, nextquad(), yylineno);
               emit(jump, NULL, NULL, NULL, nextquad() + 2, yylineno);
               emit(assign, newexpr_constbool(0), NULL, $$, nextquad() + 1, yylineno);
          }
          | term {$$ = $1;}
          ;

term: 	L_PAR expr R_PAR {$$ = $2;}
          | UMINUS expr %prec UMINUS {
               $$->truelist = $2->falselist;
               $$->falselist = $2->truelist;
               check_arith($2, $2->sym->name);
               $$ = newexpr(arithexpr_e);
               $$->sym = istempexpr($2) ? $2->sym : newtemp();
               emit(uminus, $2, $$, NULL, nextquad() + 1,yylineno); }
          | NOT expr {
               $$ = newexpr(boolexpr_e);
               $$->sym = newtemp();
               emit(op_not, $2, $$, NULL, 0, yylineno);
          }
          | D_PLUS lvalue {
               if($2 != NULL && $2->type == programfunc_e) Error(0, yytext, yylineno);
               else if($2 != NULL && $2->type == libraryfunc_e) Error(1, yytext, yylineno);
               check_arith($2, $2->sym->name);
               if ($2->type == tableitem_e) {
                    $$ = emit_iftableitem($2);
                    emit(op_add, $$, newexpr_constnum(1), $$,0,yylineno);
                    emit(tablesetelem, $2, $2->index, $$);
               }
               else {
                    emit(op_add, $2, newexpr_constnum(1), $2,0,yylineno);
                    $$ = newexpr(arithexpr_e);
                    $$->sym = newtemp();
                    emit(assign, $2, NULL, $$,0,yylineno);
               }
          }
          | lvalue D_PLUS {
               if($1 != NULL && $1->type == programfunc_e) Error(0, yytext, yylineno);
               else if($1 != NULL && $1->type == libraryfunc_e) Error(1,yytext, yylineno);
               check_arith($$, $1->sym->name);
               $$ = newexpr(var_e);
               $$->sym= newtemp();
               if ($1->type == tableitem_e){
                    Expr* value = emit_iftableitem($lvalue);
                    emit(assign, value, NULL,$$,0,yylineno);
                    emit(op_add, value, newexpr_constnum(1), value,0,yylineno);
                    emit( tablesetelem, $1, $1->index, value,0,yylineno);
               }
               else {
                    emit(assign, $1, NULL , $$, 0, yylineno);
                    emit(op_add, $1, newexpr_constnum(1), $1, 0, yylineno);
               }
          }
          | D_MINUS lvalue {
               if($2 != NULL && $2->type == programfunc_e) Error(0, yytext, yylineno);
               else if($2 != NULL && $2->type == libraryfunc_e) Error(1, yytext, yylineno);
               check_arith($2, $2->sym->name);
               if ($2->type == tableitem_e) {
                    $$ = emit_iftableitem($2);
                    emit(op_sub, $$, newexpr_constnum(1), $$, nextquad() + 1,yylineno);
                    emit(tablesetelem, $2, $2->index, $$);
               }
               else {
                    emit(op_sub, $2, newexpr_constnum(1), $2,0,yylineno);
                    $$ = newexpr(arithexpr_e);
                    $$->sym = newtemp();
                    emit(assign, $2, NULL, $$,0,yylineno);
               }
          }
          | lvalue D_MINUS {
               if($1 != NULL && $1->type == programfunc_e) {
                    Error(0, yytext, yylineno);
               }
               else if($1 != NULL && $1->type == libraryfunc_e) {
                    Error(1, yytext, yylineno);
               }
               check_arith($$, $1->sym->name);
               $$ = newexpr(var_e);
               $$->sym= newtemp();
               if ($1->type == tableitem_e){
                    Expr* value = emit_iftableitem($lvalue);
                    emit(assign, value, NULL,$$,0,yylineno);
                    emit(op_sub, value, newexpr_constnum(1), value,0,yylineno);
                    emit( tablesetelem, $1, $1->index, value,0,yylineno);
               }
               else {
                    emit(assign, $1, NULL, $$, nextquad() + 1,yylineno);
                    emit(op_sub, $1, newexpr_constnum(1), $1, nextquad() + 1,yylineno);
               }
          }
          | primary {$<exprval>$=$<exprval>1;}
          ;

assignexpr:	lvalue ASSIGN expr {
                    if($1 != NULL && $1->type == programfunc_e) Error(0, yytext, yylineno);
                    else if($1 != NULL && $1->type == libraryfunc_e) Error(1, yytext, yylineno);
                    if ($1->type == tableitem_e)  {
                         emit(tablesetelem, $lvalue, $1->index, $3, nextquad() + 1, yylineno);
                         $$ = emit_iftableitem ($1);
                         $$->type = assignexpr_e;
                    }
                    else {
                         emit(assign, $1, (Expr*) 0, $3, nextquad() + 1, yylineno);
                         $$ = newexpr(assignexpr_e);
                         $$->sym = newtemp();
                         emit(assign, $3, (Expr*) 0, $1, nextquad() + 1, yylineno);
                    }
               }
               ;

primary: 	lvalue { $$ = emit_iftableitem($1);}
          | call {;}
          | objectdef {;}
          | L_PAR funcdef R_PAR {
               $$ = newexpr(programfunc_e);
               $$->sym = &$2;
          }
          | const {;}
          ;

lvalue: 	ID {
               Symbol* item = lvalue_id(yytext, yylineno);
               $$ = lvalue_expr(item);
          }
          | LOCAL ID {
               Symbol* item = lvalue_localid(yytext, yylineno);
               if ( item && item->type == programfunc_s) {
                    fprintf(stderr, "Warning  :  %s is a function.", yytext);
               }
               $$ = lvalue_expr(item);
          }
          | D_COLON ID {
               Symbol* item = lvalue_dcolonid(yytext, yylineno);
               $$ = lvalue_expr(item);
          }
          | member {$$ = $1;}
          ;

member: 	lvalue DOT ID {$$ = member_item($1, yytext);}
          | lvalue L_BRA expr R_BRA {
               $1 = emit_iftableitem($1);
               $$ = newexpr(tableitem_e);
               $$->sym = $1->sym;
               $$->index = $3;
          }
          | call DOT ID {;}
          | call L_BRA expr R_BRA {;}
          ;

call: 	call L_PAR elist R_PAR { $$ = make_call($$, $3);}
          | lvalue callsuffix {
               $1 = emit_iftableitem($1);
               if ($2.method){
                    Expr* t = $1;
                    $1 = emit_iftableitem(member_item(t, $2.name));
                    $2.elist->next = t;
               }
               $$ = make_call($1, $2.elist);
          }
          | L_PAR funcdef R_PAR L_PAR elist R_PAR {
               Expr* func = newexpr(programfunc_e);
               func->sym = &$2;
               $$ = make_call(func, $elist);
          }
          ;

callsuffix: 	normcall { $$ = $1; }
               | methodcall {$$ = $1;}
               ;

normcall: 	L_PAR elist R_PAR {
                    $$.elist = $2;
                    $$.method = 0;
                    $$.name = NULL;
               };

methodcall: D_DOT ID L_PAR elist R_PAR {
               $$.elist = $4;
               $$.method = 1;
               $$.name = $2;
          };

elist: 	expr comma_elist {
               $$ = $1;
               $$->next = $2;
          }
          | {$$ = NULL;}
          ;
comma_elist: 	COMMA expr comma_elist{
                    $$ = $2;
                    $$->next = $3;
               }
               | {$$ = NULL;}
               ;

objectdef: 	L_BRA elist R_BRA {
                    int i;
                    Expr* t = newexpr(newtable_e);
                    t->sym = newtemp();
                    emit(tablecreate, t, NULL, NULL,0,yylineno);
                    for (i = 0; $2; $2 = $2->next)  {
                         emit(tablesetelem, t, newexpr_constnum(i++), $2,0,yylineno);
                    }
                    $$ = t;
               }
               | L_BRA indexed R_BRA {
                    Expr* t = newexpr(newtable_e);
                    t->sym = newtemp();
                    emit(tablecreate, t, NULL, NULL, nextquad() + 1,yylineno);
                    while ($2) {
                         emit(tablesetelem, t, $2, $2->index, nextquad() + 1, yylineno);
                         $2 = $2->next;
                    }
                    $$ = t;
               }
               ;

indexed: 		indexedelem {;}
               | indexed COMMA indexedelem {;}
               ;

indexedelem: 	LC_BRA  expr COLON expr RC_BRA
               ;


rec_stmt: 	rec_stmt stmt{;}
               | {;}
               ;

block:  	LC_BRA { nextscope();} rec_stmt RC_BRA{ hide(currscope()); exitscope();}
          ;

funcname:		ID {
                    funcname_id(yytext, yylineno);
                    $$ = $1;
                }
               | {
                    funcname_noname(yytext, yylineno);
                    $$ = newtempname();
               }
               ;
funcprefix: 	FUNC funcname {
                    $$ = *create_item(programfunc_s, $2, currscopespace(), currscopespaceoffset(), currscope(), currfuncscope(), yylineno);
                    $$.iaddress = nextquad();
                    emit(funcstart, $$, NULL, NULL, nextquad(), yylineno);
                    /*push(scopeoffsetstack, currscopeoffset());*/
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
                    $$ = currscopespaceoffset();
                    exitscopespace();
               }
               ;

funcblockstart:{ /*push(loopcounterstack, loopcounter); loopcounter=0; */};
funcblockend:	{ /*loopcounter = pop(loopcounterstack);*/ }

funcdef: 	funcprefix funcargs funcblockstart funcbody funcblockend{
               /*int offset;*/
               exitscopespace();
               $1.totalLocals = $4;
               /*offset = pop_and_top(scopeoffsetStack);
               /restorecurrscopeoffset(offset);*/
               $$ = $1;
               emit(funcend, $1,  NULL ,  NULL, nextquad(), yylineno);
          }
          ;
const: 	INT { $$ = newexpr_constnum($1);}
          | REAL { $$ = newexpr_constnum($1);}
          | STRING { $$ = newexpr_conststring($1);}
          | NIL { $$ = newexpr(nil_e);}
          | TRUE { $$ = newexpr_constbool(1);}
          | FALSE { $$ = newexpr_constbool(0);}
          ;

idlist:	ID { idlist_id(yytext, yylineno);}
          | idlist COMMA ID { idlist_commaid(yytext, yylineno);}
          | {;}
          ;

ifprefix:	IF L_PAR expr R_PAR {
               emit(if_eq, $3, newexpr_constbool(1), NULL, nextquad() + 2, yylineno);
               $$ = nextquad();
               emit(jump, NULL , NULL, NULL, 0, yylineno);
          }
          ;

elseprefix: 	ELSE {
                     $$ = nextquad();
                     emit(jump, NULL, NULL, NULL, 0, yylineno);
               }
                ;

ifstmt: 		ifprefix stmt{
                     patchlabel($1, nextquad());
                }
                | ifprefix stmt elseprefix stmt {
                     patchlabel($1, ($3)+1);
                     patchlabel($3, nextquad());
               }
                ;

whilestart:	WHILE {
                    gloop++;
                    $$ = nextquad();
               }
               ;

whilecond: 	L_PAR  expr R_PAR{
                    emit(if_eq, $2, newexpr_constbool(1), nextquad()+2, NULL, 0, yylineno);
                    $$ = nextquad();
                    emit(jump, NULL, NULL, NULL, 0, yylineno);
               }



whilestmt: 	whilestart whilecond stmt loopstmt{
                    gloop--;
                    emit(jump, NULL, NULL, $1, 0, yylineno);
                    patchlabel($2, nextquad());
                    patchlist($3.breaklist, nextquad());
                    patchlist($3.contlist, $1);
               }
                ;
loopstart:	{ ++loopcounter;};
loopend:	     { --loopcounter;};

loopstmt: loopstart stmt loopend { $$ = $2;}
          ;
N: 	{
          $$ = nextquad();
          emit(jump, NULL, NULL, NULL, 0, yylineno);
     }
         ;
M:   {$$ = nextquad();}
     ;

forprefix:	FOR {gloop++;} L_PAR  elist SEMI M expr SEMI {
                    $$.test = $M;
                    $$.enter = nextquad();
                    emit(if_eq, $expr, newexpr_constbool(1), NULL, 0, yylineno);
               }
               ;

forstmt:	forprefix N elist R_PAR N stmt {gloop--;} N loopstmt {
               patchlabel($1.enter, $5+1);
               patchlabel($2, nextquad());
               patchlabel($5, $1.test);
               patchlabel($8, $2+1);

               patchlist($6.breaklist, nextquad());
               patchlist($6.contlist, $2+1);
          }
          ;

break: BREAK {};

continue: CONTINUE {};


returnstmt: 	RETURN SEMI { 
                    if (currfuncscope() == 0) Error(2, yytext, yylineno);
                    else {
                         emit(ret, NULL, NULL, NULL, nextquad() + 1, yylineno);
                    }
               }
                  | RETURN expr SEMI {
                    if (currfuncscope() == 0) Error(2, yytext, yylineno);
                    emit(ret, NULL, NULL, $2, nextquad() + 1, yylineno);
                  }
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
       //print_table();
     print_intermediate();
     free_table(symtable);
       return 0;
}
