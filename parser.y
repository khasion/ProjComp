%{
  #include <stdio.h>
  #include <unistd.h>
  #include <stdlib.h>
  #include <string.h>

  int yyerror (char* yaccProovidedMessage);
  int yylex (void);
  extern int yylineno;
  extern char* yytext;
  extern FILE* yyin;

  int scopeval = 0;
%}
%start program
%union{
  int intval;
  char* strval;
  float floatval;
}

%token <intval> INT
%token <floatval> REAL
%token <strval> ID STRING
%token <strval> IF ELSE WHILE FOR FUNC RETURN BREAK CONTINUE AND OR LOCAL TRUE FALSE NIL UMINUS ASSIGN PLUS MINUS MUL DIV MOD EQ NOT_EQ D_PLUS D_MINUS LESS GREATER LESS_EQ GREATER_EQ LC_BRA RC_BRA L_BRA R_BRA L_PAR R_PAR SEMI COMMA COLON D_COLON DOT D_DOT

%left ASSIGN
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

%%
program: stmt program{;}
       |
       ;

smt: expr SEMI{;}
   | ifstmt{scopeval++;}
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
    | expr PLUS expr{;}
    | expr MINUS expr{;}
    | expr MUL expr{;}
    | expr DIV expr{;}
    | expr MOD expr{;}
    | expr GREATER expr{;}
    | expr GREATER_EQ expr{;}
    | expr LESS expr{;}
    | expr LESS_EQ expr{;}
    | expr EQ expr{;}
    | expr NOT_EQ expr{;}
    | expr AND expr{;}
    | expr OR expr{;}
    |term{;}
    ;

term: L_PAR expr R_PAR{;}
    | UMINUS expr{;}
    | NOT expr{;}
    | D_PLUS lvalue{;}
    | lvalue D_PLUS{;}
    | D_MINUS lvalue{;}
    | lvalue D_MINUS{;}
    |primary{;}
    ;

assignexpr: lvalue EQ expr{;}

primary: lvalue{;}
       | call{;}
       | objectdef{;}
       | L_PAR funcdef R_PAR{;}
       | cont{;}
       ;

lvalue: ID{;}
      | LOCAL ID{;}
      | D_COLON ID{;}
      | member{;}
      ;

member: lvalue DOT ID{;}
      | lvalue L_PAR expr R_PAR{;}
      | call DOT ID{;}
      | call L_PAR expr R_PAR{;}
      ;

call: call L_PAR elist R_PAR{;}
    | lvalue callsuffix{;}
    | L_PAR funcdef R_PAR L_PAR elist R_PAR{;}
    ;

callsuffix: normcall{;}
          | methodcall{;}
          ;

normcall: L_PAR elist R_PAR{;}

methodcall: D_DOT L_PAR elist R_PAR {;};

elist:  expr {;}
      | elist COMMA expr{;}
      | 
      ;

objectdef: L_BRA elist R_BRA{;}
         | L_BRA indexed R_BRA{;}
         ;

indexed: indexedelem{;}
       | indexed COMMA indexedelem{;}
       |{;}
       ;

indexedelem: LC_BRA {scopeval++; }
            expr COLON expr 
            RC_BRA{scopeval--;}

block:  LC_BRA{scopeval++;} RC_BRA{scopeval--;}
     | LC_BRA {scopeval++;} stmt RC_BRA{scopeval--;}
     ;

funcdef: function ID L_PAR {scopeval++;} idlist L_PAR {scopeval--;} block{;}
       | function L_PAR{scopeval++;} idlist L_PAR {scopeval--;} block{;}
       ;

const: INT{;}
     | REAL{;}
     |STRING{;}
     |NIL{;}
     |TRUE{;}
     |FALSE{;}
     ;

idlist: ID{;}
      | idlist COMMA ID{;}
      |
      ;

ifstmt: IF L_PAR expr R_PAR stmt ELSE stmt{;}
      | IF L_PAR expr R_PAR stmt{;}
      ;

whilestmt: WHILE L_PAR expr R_PAR stmt{;}
         ;

forstmt: FOR L_PAR elist SEMICOLON expr SEMICOLON elist R_PAR stmt{;}
       ;

returnstmt: RETURN SEMICOLON{;}
          | RETURN expr SEMICOLON{;}
          ;

%%

int yyerror(char yaccProovidedMessage){
  fprintf(stderr, "%s: at line %d, before token: %s\n",yaccProovidedMessage, yylineno, yytext);
  fprintf(stderr, "INPUT NOT VALID\n");
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