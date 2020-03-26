%{
  #include <stdio.h>
  #include <unistd.h>
  #include <stdlib.h>
  #include <string.h>
  #include "table.h"

  #define  YY_DECL int alpha_yylex (void* yylval)
  void yyerror (char* yaccProovidedMessage);
  extern int yylineno;
  int yylex();
  extern char* yytext;
  extern FILE* yyin;

  int gloop = 0;
  int globalscope = 0;
  int funcscope = 0;
  int open_func =0;
%}

%start program

%union {
  int intval;
  char* strval;
  float floatval;
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

%type <strval> stmt
%type <intval> expr  assignexpr
%type <strval>  term  lvalue primary member call callsuffix normcall elist objectdef 
%type <strval>indexed indexedelem  rec_stmt block const idlist ifstmt whilestmt forstmt returnstmt




%%
program: stmt program{;}
       |{;}
       ;

stmt: expr SEMI{;}
   | ifstmt
   | whilestmt{;}
   | forstmt{;}
   | returnstmt{;}
   | BREAK SEMI{if (gloop == 0) printf("Use of 'break' while not in a loop at line %d\n" , yylineno);}
   | CONTINUE SEMI{if (gloop == 0) printf("Use of 'continue' while not in a loop at line %d\n" , yylineno);}
   | block{;}
   | funcdef{;}
   | SEMI{;}
   ;

expr: assignexpr
    | expr PLUS expr{ $$ = $1 + $3;}
    | expr MINUS expr{ $$ = $1 - $3;}
    | expr MUL expr{ $$ = $1 * $3;}
    | expr DIV expr{ $$ = $1 / $3;}
    | expr MOD expr{ $$ = $1 % $3;}
    | expr GREATER expr{ if($1 > $3){$$ = 1;}else{$$ = 0;};}
    | expr GREATER_EQ expr{ if($1 >= $3){$$ = 1;}else{$$ = 0;};}
    | expr LESS expr{ if($1 < $3){$$ = 1;}else{$$ = 0;};}
    | expr LESS_EQ expr{ if($1 <= $3){$$ = 1;}else{$$ = 0;};}
    | expr EQ expr{ if($1 == $3){$$ = 1;}else{$$ = 0;};}
    | expr NOT_EQ expr{ if($1 != $3){$$ = 1;}else{$$ = 0;};}
    | expr AND expr{ if($1 && $3){$$ = 1;}else{$$ = 0;};}
    | expr OR expr{ if($1 || $3){$$ = 1;}else{$$ = 0;};}
    | term{;}
    ;

term: L_PAR expr R_PAR{;}
    | UMINUS expr %prec UMINUS{;}
    | NOT expr{;}
    | D_PLUS lvalue{
      if($2 != NULL && !strcmp($2,"[userfunc]")){
        printf("ERROR: Using ProgramFunc as an lvalue at line: %d\n" , yylineno);
      }else if($2 != NULL && !strcmp($2,"[library function]")){
        printf("ERROR:Using LibFunc as an lvalue at line: %d\n" , yylineno);
      }
      }
    | lvalue D_PLUS{
      if($1 != NULL && !strcmp($1,"[userfunc]")){
            printf("ERROR:Using ProgramFunc as an lvalue at line: %d\n" , yylineno);
      }else if($1 != NULL && !strcmp($1,"[library function]")){
        printf("ERROR:Using LibFunc as an lvalue at line: %d\n" , yylineno);
      }
      }
    | D_MINUS lvalue{

      if($2 != NULL && !strcmp($2,"[userfunc]")){
            printf("ERROR:Using ProgramFunc as an lvalue at line: %d\n" , yylineno);
      }else if($2 != NULL && !strcmp($2,"[library function]")){
        printf("ERROR:Using LibFunc as an lvalue at line: %d\n" , yylineno);;
      }
      }
    | lvalue D_MINUS{
      if($1 != NULL && !strcmp($1,"[userfunc]")){
        printf("ERROR:Using ProgramFunc as an lvalue at line: %d\n" , yylineno);
      }else if($1 != NULL && !strcmp($1,"[library function]")){
        printf("ERROR:Using LibFunc as an lvalue at line: %d\n" , yylineno);
      }
      }
    |primary{;}
    ;

assignexpr: lvalue ASSIGN expr{
            //printf("%s yes\n",$1);
            if($1 != NULL && !strcmp($1,"[userfunc]")){
              printf("ERROR:Using ProgramFunc as an lvalue at line: %d\n" , yylineno);
            } else if($1 != NULL && !strcmp($1,"[library function]")){
              printf("ERROR:Using LibFunc as an lvalue at line: %d\n" , yylineno);
            }
            };

primary: lvalue{}
       | call{;}
       | objectdef{;}
       | L_PAR funcdef R_PAR{;}
       | const{;}
       ;

lvalue: ID{
          DataItem* tmp = table_lookup(yytext, "", 0, globalscope, funcscope, yylineno);
          /* printf("%s aleksi\n",tmp->type); */
          $$ = tmp->type;
        }
      | LOCAL ID{
        DataItem* tmp = table_lookup(yytext, "", 1 , globalscope, funcscope, yylineno);
        $$ = tmp->type;
      }
      | D_COLON ID{
        DataItem* tmp = table_lookup(yytext, "", 2 , globalscope, funcscope, yylineno);
        $$ = tmp->type;

      }
      | member{$$ = "NoError";}
      ;

member: lvalue DOT ID{;}
      | lvalue L_BRA expr R_BRA{;}
      | call DOT ID{;}
      | call L_BRA expr R_BRA{;}
      ;

call: call L_PAR elist R_PAR{;}
    | lvalue callsuffix{;}
    | L_PAR funcdef R_PAR L_PAR elist R_PAR{;}
    ;

callsuffix: normcall{;}
          | methodcall{;}
          ;

normcall: L_PAR elist R_PAR{;};

methodcall: D_DOT ID L_PAR elist R_PAR {;};

elist : expr {;}
      | elist COMMA expr {;}
      |{;}
      ;

objectdef: L_BRA elist R_BRA{;}
         | L_BRA indexed R_BRA{;}

         ;

indexed: indexedelem{;}
       | indexed COMMA indexedelem{;}
       ;

indexedelem: LC_BRA  expr COLON expr RC_BRA
            ;


 rec_stmt: rec_stmt stmt{;}
          | {;}
          ;

 block: /*LC_BRA{globalscope++;} RC_BRA{ hide(globalscope);globalscope--; }
     | */
     LC_BRA {globalscope++;} rec_stmt RC_BRA{ hide(globalscope); globalscope--;}
     ;

funcdef: FUNC {  table_lookup( yytext , "", 3 , globalscope, funcscope, yylineno);}
        L_PAR{funcscope++;}  idlist  R_PAR  block {funcscope--;}
       | FUNC ID{ table_lookup(yytext, "", 4 , globalscope, funcscope, yylineno);}
       L_PAR{funcscope++;} idlist R_PAR  block {funcscope--;}
       ; 

const: INT{;}
     | REAL{;}
     | STRING{;}
     | NIL{;}
     | TRUE{;}
     | FALSE{;}
     ;


idlist: ID{table_lookup( yytext , "", 5 , funcscope, funcscope  , yylineno);}
      | idlist COMMA ID{table_lookup( yytext , "", 6 , funcscope , funcscope, yylineno);}
      |{;}
      ;



ifstmt: IF L_PAR  expr R_PAR stmt
      | IF L_PAR expr R_PAR stmt ELSE stmt 
      ;

whilestmt: WHILE{gloop++;} L_PAR  expr R_PAR  stmt{gloop--; }
         ;

forstmt: FOR{gloop++;} L_PAR  elist SEMI expr SEMI elist R_PAR  stmt{gloop--;}
       ;

returnstmt: RETURN SEMI{if (funcscope == 0) printf("Use of 'return' while not in a function at line %d\n" , yylineno);}
          | RETURN expr SEMI{if (funcscope == 0) printf("Use of 'return' while not in a function at line %d\n" , yylineno);}
          ;

%%

void yyerror(char* yaccProovidedMessage){
  fprintf(stderr, "%s: at line %d, before token: %s\n",yaccProovidedMessage, yylineno, yytext);
  fprintf(stderr, "INPUT NOT VALID\n");
}

int main(int argc, char** argv){
  symtable = create_new_symtable();
  table_insert("print", "[library function]", 7, 0, 0, 0);
  table_insert("input", "[library function]", 7, 0, 0, 0);
  table_insert("objectmemberkyes", "[library function]", 7, 0, 0, 0);
  table_insert("objectotslmembers", "[library function]", 7, 0, 0, 0);
  table_insert("objectcopy", "[library function]", 7, 0, 0, 0);
  table_insert("totalarguments", "[library function]", 7, 0, 0, 0);
  table_insert("argument", "[library function]", 7, 0, 0, 0);
  table_insert("typeof", "[library function]", 7, 0, 0, 0);
  table_insert("strtonum", "[library function]", 7, 0, 0, 0);
  table_insert("sqrt", "[library function]", 7, 0, 0, 0);
  table_insert("cos", "[library function]", 7, 0, 0, 0);
  table_insert("sin", "[library function]", 7, 0, 0, 0);
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
  return 0;
}