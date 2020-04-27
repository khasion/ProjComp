#include "quads.h"

Quad* quads = NULL;
unsigned total = 0;
unsigned int currQuad = 1;

unsigned int tempcounter = 0;

void make_stmt(Stmt_t* s) {
     s->breaklist = s->contlist = 0;
}

int newlist(int i) {
     quads[i].label = 0;
     return i;
}

Expr* member_item (Expr* lv, char* name) {
     Expr* ti = newexpr(tableitem_e); // Make a new expression
     lv = emit_iftableitem(lv); // Emit code if r-value use of table item
     ti->sym = lv->sym;
     ti->index = newexpr_conststring(name);// Const string index
     return ti;
}

int mergelist(int l1, int l2) {
     if (!l1) {
          return l2;
     }
     else	if (!l2) {
          return l1;
     }
     else {
          int i = l1;
          while (quads[i].label) {
               i = quads[i].label;
          }
          quads[i].label = l2;
          return l1;
     }
}

void patchlist (int list, int label) {
     while (list) {
          int next = quads[list].label;
          quads[list].label = label;
          list = next;
     }
}

void init_quad() {
     quads = (Quad*) malloc(NEW_SIZE);
     currQuad = 1;
}

void expand_quad() {
     assert(total <= currQuad);
     Quad* p = (Quad*) malloc(NEW_SIZE);
     if (quads) {
          memcpy(p, quads, CURR_SIZE);
          free(quads);
     }
     quads = p;
     total += EXPAND_SIZE;
}

void emit(Opcode op, Expr* arg1, Expr* arg2, Expr* res, unsigned label, unsigned line) {
     if (currQuad >= total) expand_quad();
     Quad* p = quads + currQuad++;
     p->op = op;
     p->arg1 = arg1;
     p->arg2 = arg2;
     p->result = res;
     p->label = label;
     p->line = line;
}

Expr* make_call(Expr* lv, Expr* reversed_elist) {
     Expr* func = emit_iftableitem(lv);
     while (reversed_elist) {
          emit(param, reversed_elist, NULL, NULL, nextquad() + 1, reversed_elist->sym->line);
          reversed_elist = reversed_elist->next;
     }
     emit (call, func, NULL, NULL, nextquad() + 1, func->sym->line);
     Expr* result = newexpr(var_e);
     result->sym = newtemp();
     emit(getretval, NULL, NULL, result, nextquad() + 1, result->sym->line);
     return result;
}

Expr* emit_iftableitem(Expr* e) {
     assert(e);
     if (e->type != tableitem_e) {
          return e;
     }
     Expr* result   = newexpr(var_e);
     result->sym    = newtemp();
     emit(tablegetelem, e, e->index, result, nextquad() + 1, e->sym->line);
     return result;
}

char* newtempname(void) {
     char* name = (char*) malloc(sizeof(char)*3);
     sprintf(name, "^%d", tempcounter++);
     return name;
}

void resettemp(void) {
     tempcounter = 0;
}

Symbol* newtemp(void) {
     char* name = newtempname();
     Symbol* temp;
     temp = table_lookup(name, currscope());
     if (!temp) {
          return table_insert(var_s, name, currscopespace(), currscopespaceoffset(), currscope(), currfuncscope(), 0);
     }
     return temp;
}

unsigned int istempname(char* s) {
     return *s == '^';
}

unsigned int istempexpr(Expr* e) {
     return e->sym && istempname(e->sym->name);
}

Expr* newexpr(Expr_t t) {
     Expr* e = (Expr*) malloc(sizeof(Expr));
     memset(e, 0, sizeof(Expr));
     e->type = t;
     return e;
}

Expr* newexpr_constbool(char* boolean){
     Expr* tmp = newexpr(constbool_e);
     tmp->boolConst = boolean;

     tmp->sym = (Symbol*) malloc(sizeof(Symbol));
     if (boolean) tmp->sym->name = strdup("'true'");
     else tmp->sym->name = strdup("'false'");

     return tmp;
}

Expr* newexpr_constnum(double i) {
     Expr* e = newexpr(constnum_e);
     char* n;
     e->numConst = i;

     n = (char*) malloc(sizeof(char)*4);
     sprintf(n, "'%d'", (int)i);

     e->sym = (Symbol*) malloc(sizeof(Symbol));
     e->sym->name = strdup(n);
     return e;
}

Expr* newexpr_conststring(char* s) {
     Expr* tmp = newexpr(conststring_e);
     tmp->strConst = strdup(s);
     return tmp;
}

unsigned nextquad() {
     return currQuad;
}

void patchlabel(unsigned quadNo, unsigned label){
     assert(quadNo < currQuad);
     quads[quadNo].label = label;
}

void backpatch (int list, unsigned label){
     assert(list < currQuad );
     while (list) {
          int next = quads[list].label;
          quads[list].label = label;
          list = next;
     }
}

Expr* lvalue_expr(Symbol* sym){
     assert(sym);
     Expr* e = (Expr*) malloc(sizeof(Expr));
     memset(e, 0, sizeof(Expr));
     e->next = NULL;
     e->index = NULL;
     e->sym = (Symbol*) malloc(sizeof(Symbol));
     e->sym->name = strdup(sym->name);
     e->sym->type = sym->type;
     e->sym->space = sym->space;
     e->sym->offset = sym->offset;
     e->sym->scope = sym->scope;
     e->sym->line = sym->line;
     e->sym->iaddress = sym->iaddress;
     e->sym->totalLocals = sym->totalLocals;

     switch(sym->type){
          case localvar_s		: e->type = var_e; break;
          case globalvar_s		: e->type = var_e; break;
          case var_s          	: e->type = var_e; break;
          case programfunc_s  	: e->type = programfunc_e; break;
          case nonameprogramfunc_s	: e->type = programfunc_e; break;
          case libraryfunc_s  	: e->type = libraryfunc_e; break;
          default: assert(0);
     }
     return e;
}

void check_arith(Expr* e, const char* context) {
     if ( e->type == constbool_e ||
          e->type == conststring_e ||
          e->type == nil_e ||
          e->type == newtable_e ||
          e->type == programfunc_e ||
          e->type == libraryfunc_e ||
          e->type == boolexpr_e) {
               printf("Illegal expr used in %s!\n", context);
          }
}

// void print_content(Expr* e){
//      if(e->type >=0 || e->type <= 7){
//           printf("%s ",e->sym->name);
//      }else if(e->type == 8){
//           printf("%.2f ",e->numConst);
//      }else if(e->type == 9 && e->boolConst == '0'){
//           printf("FALSE");
//      }else if(e->type == 9 && e->boolConst == '1'){
//           printf("TRUE");
//      }else if(e->type == 10){
//           printf("%s ",e->strConst);
//      }
// }

void print_intermediate(){
     int i;
     char* iopcode_array[26] = {
          "assign",           "op_add",           "op_sub",
          "op_mul",           "op_div",           "op_mod",
          "uminus",           "op_and",           "op_or",
          "op_not",           "if_eq",            "if_noteq",
          "if_lesseq",        "if_greatereq",     "if_less",
          "if_greater",	     "call",             "param",
          "ret",              "getretval",        "funcstart",
          "funcend",          "tablecreate",      "jump",
          "tablegetelem",     "tablesetelem"};

     printf("\033[1;32m");
     printf("N\t|%-15s|%-15s|%-15s|%-15s|%-15s\n", "op", "arg1", "arg2", "result", "label");
     printf("\033[0m");
     for(i = 1; i < currQuad; i++){
          printf("%d:", i);
          printf("\t|%-15s", iopcode_array[quads[i].op]);
          
          if ( (quads + i) != NULL) {
               if( quads[i].arg1 && quads[i].arg1->sym)     printf("|%-15s", quads[i].arg1->sym->name);
               else printf("|%-15s", "");
               if(quads[i].arg2 && quads[i].arg2->sym)      printf("|%-15s", quads[i].arg2->sym->name);
               else printf("|%-15s", "");
               if(quads[i].result && quads[i].result->sym)  printf("|%-15s", quads[i].result->sym->name);
               else printf("|%-15s", "");
               printf("|%-15d\n", quads[i].label);
          }
     }
}
