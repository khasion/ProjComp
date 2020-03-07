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
%type <strval>indexed indexedelem comma_expr rec_stmt block const idlist ifstmt whilestmt forstmt returnstmt




%%
program: stmt program{;}
       |
       ;

stmt: expr SEMI{printf("expr;\n");}
   | ifstmt{printf("ifstmt;\n");}
   | whilestmt{printf("whilestmt\n");}
   | forstmt{printf("forstmt\n");}
   | returnstmt{printf("returnstmt\n");}
   | BREAK SEMI{printf("break;\n");}
   | CONTINUE SEMI{printf("continue;\n");}
   | block{printf("block\n");}
   | funcdef{printf("funcdef\n");}
   | SEMI{printf(";\n");}
   ;

expr: assignexpr{printf("assignexpr\n");}
    | expr PLUS expr{printf("expr%d + expr%d\n",$1,$3); $$ = $1 + $3;}
    | expr MINUS expr{printf("expr - expr\n"); $$ = $1 - $3;}
    | expr MUL expr{printf("expr * expr\n"); $$ = $1 * $3;}
    | expr DIV expr{printf("expr \\ expr\n"); $$ = $1 / $3;}
    | expr MOD expr{printf("expr mod expr\n"); $$ = $1 % $3;}
    | expr GREATER expr{printf("expr > expr\n"); if($1 > $3){$$ = 1;}else{$$ = 0;};}
    | expr GREATER_EQ expr{printf("expr >= expr\n"); if($1 >= $3){$$ = 1;}else{$$ = 0;};}
    | expr LESS expr{printf("expr < expr\n"); if($1 < $3){$$ = 1;}else{$$ = 0;};}
    | expr LESS_EQ expr{printf("expr <= expr\n"); if($1 <= $3){$$ = 1;}else{$$ = 0;};}
    | expr EQ expr{printf("expr == expr\n"); if($1 == $3){$$ = 1;}else{$$ = 0;};}
    | expr NOT_EQ expr{printf("expr != expr\n"); if($1 != $3){$$ = 1;}else{$$ = 0;};}
    | expr AND expr{printf("expr and expr\n"); if($1 && $3){$$ = 1;}else{$$ = 0;};}
    | expr OR expr{printf("expr or expr\n"); if($1 || $3){$$ = 1;}else{$$ = 0;};}
    | term{printf("term\n");}
    ;

term: L_PAR expr R_PAR{printf("L_PAR expr R_PAR\n");}
    | UMINUS expr %prec UMINUS{printf("UMINUS expr prec UMINUS\n");}
    | NOT expr{printf("not expr\n");}
    | D_PLUS lvalue{printf("D_PLUS lvalue\n");}
    | lvalue D_PLUS{printf("lvalue D_PLUS\n");}
    | D_MINUS lvalue{printf("D_MINUS lvalue\n");}
    | lvalue D_MINUS{printf("lvalue D_MINUS\n");}
    |primary{printf("primary\n");}
    ;

assignexpr: lvalue ASSIGN expr{printf("lvalue assign expr\n");};

primary: lvalue{printf("lvalue\n");}
       | call{printf("call\n");}
       | objectdef{printf("objectdef\n");}
       | L_PAR funcdef R_PAR{printf("L_PAR funcdef R_PAR\n");}
       | const{printf("const\n");}
       ;

lvalue: ID{
          printf("id\n");
          table_lookup(yytext, "", 0, globalscope, open_func, yylineno);
        }
      | LOCAL ID{
        printf("local id\n");
        table_lookup(yytext, "", 1, globalscope, open_func, yylineno);
      }
      | D_COLON ID{
        printf("D_COLON id\n");
        table_lookup(yytext, "", 2, globalscope, open_func, yylineno);
      }
      | member{printf("member\n");}
      ;

member: lvalue DOT ID{printf("lvalue dot id\n");}
      | lvalue L_BRA expr R_BRA{printf("lvalue L_BRA expr R_BRA\n");}
      | call DOT ID{printf("call dot id\n");}
      | call L_BRA expr R_BRA{printf("call L_BRA expr R_BRA\n");}
      ;

call: call L_PAR elist R_PAR{printf("call L_PAR elist R_PAR\n");}
    | lvalue callsuffix{printf("lvalue callsuffix\n");}
    | L_PAR funcdef R_PAR L_PAR elist R_PAR{printf("L_PAR funcdef R_PAR L_PAR elist R_PAR\n");}
    ;

callsuffix: normcall{printf("callsuffix\n");}
          | methodcall{printf("methodcall\n");}
          ;

normcall: L_PAR elist R_PAR{printf("L_PAR elist R_PAR\n");};

methodcall: D_DOT ID L_PAR elist R_PAR {printf("D_DOT id L_PAR elist R_PAR\n");};

elist : expr comma_expr{printf("expr comma_expr\n");}
      | {;}
      ;

comma_expr : COMMA expr comma_expr{printf("comma expr comma_expr\n");}
            |{;}
            ;

objectdef: L_BRA elist R_BRA{printf("l_bra elist R_BRA\n");}
         | L_BRA indexed R_BRA{printf("L_BRA indexed R_BRA\n");}
         ;

indexed: indexedelem{printf("indexedelem\n");}
       | indexed COMMA indexedelem{printf("indexed comma indexedelem\n");}
       ;

indexedelem: LC_BRA {globalscope++; } expr COLON expr RC_BRA{printf("indexedelem\n"); globalscope--;}


rec_stmt : rec_stmt stmt{;}
          | {;}
          ;

block:  LC_BRA{globalscope++;} RC_BRA{printf("block1\n"); globalscope--;}
     | LC_BRA {globalscope++;} rec_stmt  RC_BRA{printf("block2\n"); globalscope--;}
     ;

funcdef: FUNC L_PAR {printf("funcdef1\n"); funcscope++;} idlist R_PAR {funcscope--; ; open_func++;} block{open_func--;}
       | FUNC ID L_PAR{printf("funcdef2\n"); funcscope++;} idlist R_PAR {funcscope--; ; open_func++;} block{open_func--;}
       ;

const: INT{printf("int\n") ;}
     | REAL{printf("real\n");}
     | STRING{printf("string\n");}
     | NIL{printf("nil\n");}
     | TRUE{printf("true\n");}
     | FALSE{printf("false\n");}
     ;

idlist: ID{printf("id\n");}
      | idlist COMMA ID{printf("idlist comma id\n");}
      |{;}
      ;

ifstmt: IF L_PAR expr R_PAR stmt {printf("ifstmt\n");}
        | IF L_PAR expr R_PAR  stmt ELSE stmt{printf("ifstmt 2\n");}
        ;

whilestmt: WHILE L_PAR {funcscope++;} expr R_PAR {funcscope--;} stmt{printf("whilestmt\n"); globalscope++;}
         ;

forstmt: FOR L_PAR {funcscope++;} elist SEMI expr SEMI elist R_PAR {funcscope--;} stmt{printf("forstmt\n"); globalscope++;}
       ;

returnstmt: RETURN SEMI{printf("return\n");}
          | RETURN expr SEMI{printf("return2\n");}
          ;

%%

int yyerror(char* yaccProovidedMessage){
  fprintf(stderr, "%s: at line %d, before token: %s\n",yaccProovidedMessage, yylineno, yytext);
  fprintf(stderr, "INPUT NOT VALID\n");
  return -1;
}

int main(int argc, char** argv){
  symtable = create_new_symtable();
  /* table_insert("print", "[[library function]]", 0, 0, 0);
  table_insert("input", "[library function]", 0, 0, 0);
  table_insert("objectmemberkyes", "[library function]", 0, 0, 0);
  table_insert("objectotslmembers", "[library function]", 0, 0, 0);
  table_insert("objectcopy", "[library function]", 0, 0, 0);
  table_insert("totalarguments", "[library function]", 0, 0, 0);
  table_insert("argument", "[library function]", 0, 0, 0);
  table_insert("typeof", "[library function]", 0, 0, 0);
  table_insert("strtonum", "[library function]", 0, 0, 0);
  table_insert("sqrt", "[library function]", 0, 0, 0);
  table_insert("cos", "[library function]", 0, 0, 0);
  table_insert("sin", "[library function]", 0, 0, 0); */
  //print_table();
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
