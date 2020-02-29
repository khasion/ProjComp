%{
  #include <stdio.h>
  #include <unistd.h>
  #include <stdlib.h>
  #include <string.h>
  #include "table.h"

  #define  YY_DECL int alpha_yylex (void* yylval)
  int yyerror (char* yaccProovidedMessage);
  extern int yylineno;
  int yylex();
  extern char* yytext;
  extern FILE* yyin;

 
  int globalscope = 0;
  int funcscope = 0;
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
%type <strval>indexed indexedelem comma_expr rec_stmt block const idlist ifstmt whilestmt forstmt returnstmt




%%
program: stmt rec_stmt{;}
       |{;}
       ;

stmt: expr SEMI{;}
   | ifstmt{;}
   | whilestmt{;}
   | forstmt{;}
   | returnstmt{;}
   | BREAK SEMI{;}
   | CONTINUE SEMI{;}
   | block{;}
   | funcdef{;}
   | SEMI{;}
   ;

expr: assignexpr{;}
    | expr PLUS expr{ $$ = $1 + $3;}
    | expr MINUS expr{ $$ = $1 - $3;}
    | expr MUL expr{ $$ = $1 * $3;}
    | expr DIV expr{$$ = $1 / $3;}
    | expr MOD expr{ $$ = $1 % $3;}
    | expr GREATER expr{if($1 > $3){$$ = 1;}else{$$ = 0;};}
    | expr GREATER_EQ expr{if($1 >= $3){$$ = 1;}else{$$ = 0;};}
    | expr LESS expr{if($1 < $3){$$ = 1;}else{$$ = 0;};}
    | expr LESS_EQ expr{if($1 <= $3){$$ = 1;}else{$$ = 0;};}
    | expr EQ expr{if($1 == $3){$$ = 1;}else{$$ = 0;};}
    | expr NOT_EQ expr{if($1 != $3){$$ = 1;}else{$$ = 0;};}
    | expr AND expr{if($1 && $3){$$ = 1;}else{$$ = 0;};}
    | expr OR expr{if($1 || $3){$$ = 1;}else{$$ = 0;};}
    | term{;}
    ;

term: L_PAR expr R_PAR{;}
    | UMINUS expr %prec UMINUS{;}
    | NOT expr{;}
    | D_PLUS lvalue{;}
    | lvalue D_PLUS{;}
    | D_MINUS lvalue{;}
    | lvalue D_MINUS{;}
    |primary{;}
    ;

assignexpr: lvalue ASSIGN expr{;};

primary: lvalue{;}
       | call{;}
       | objectdef{;}
       | L_PAR funcdef R_PAR{;}
       | const{;}
       ;

lvalue: ID{;}
      | LOCAL ID{;}
      | D_COLON ID{;}
      | member{;}
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

elist : expr comma_expr{;}
      | {;}
      ;

comma_expr : COMMA expr comma_expr{;}
            |{;}
            ;

objectdef: L_BRA elist R_BRA{;}
         | L_BRA indexed R_BRA{;}
         ;

indexed: indexedelem{;}
       | indexed COMMA indexedelem{;}
       ;

indexedelem: LC_BRA {globalscope++; } expr COLON expr RC_BRA{globalscope--;}

rec_stmt : rec_stmt stmt{;}
          | {;}
          ;


block:  LC_BRA{globalscope++;} RC_BRA{globalscope--;}
     | LC_BRA {globalscope++;} stmt  RC_BRA{globalscope--;}
     ;

funcdef: FUNC L_PAR {funcscope++;} idlist R_PAR {funcscope--;} block{;}
       | FUNC ID L_PAR{funcscope++;} idlist R_PAR {funcscope--;} block{;}
       ;

const: INT{;}
     | REAL{;}
     | STRING{;}
     | NIL{;}
     | TRUE{;}
     | FALSE{;}
     ;

idlist: ID{;}
      | idlist COMMA ID{;}
      |{;}
      ;

ifstmt: IF L_PAR expr R_PAR stmt {;}
        | IF L_PAR expr R_PAR  stmt ELSE stmt{;}
        ;

whilestmt: WHILE L_PAR {funcscope++;} expr R_PAR {funcscope--;} stmt{globalscope++;}
         ;

forstmt: FOR L_PAR {funcscope++;} elist SEMI expr SEMI elist R_PAR {funcscope--;} stmt{globalscope++;}
       ;

returnstmt: RETURN SEMI{;}
          | RETURN expr SEMI{;}
          ;

%%

int yyerror(char* yaccProovidedMessage){
  fprintf(stderr, "%s: at line %d, before token: %s\n",yaccProovidedMessage, yylineno, yytext);
  fprintf(stderr, "INPUT NOT VALID\n");
  return -1;
}

int main(int argc, char** argv){
  if(argc > 1){
    if(!(yyin = fopen(argv[1], "r"))){
      fprintf(stderr, "Cannot read  file: %s\n", argv[1]);
      return 1;
    }
  } else {
    yyin = stdin;
  }
  yyparse();
  return 0;
}
