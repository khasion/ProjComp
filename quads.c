#include "quads.h"

void init_quad() {
	quads = (Quad*) malloc(NEW_SIZE);
	currQuad = 0;
}

void expand_quad() {
	assert(total == currQuad);
	Quad* p = (Quad*) malloc(NEW_SIZE);
	if (quads) {
		memcpy(p, quads, CURR_SIZE);
		free(quads);
	}
	quads = p;
	total += EXPAND_SIZE;
}

void emit(Opcode op, Expr* arg1, Expr* arg2, Expr* res, unsigned label, unsigned line) {
	if (currQuad == total) expand();
	Quad* p = quads + currQuad++;
	p->op = op;
	p->arg1 = arg1;
	p->arg2 = arg2;
	p->result = res;
	p->label = label;
	p->line = line;
}

Expr* emit_iftableitem(Expr* e) {
     if (e->type != tableitem_e) {
          return e;
     }
     Expr* result   = newexpr(var_e);
     result->sym    = newtemp();
     emit(tablegetelem, e, e->index, result, 0, 0);
     return result;
}

char* newtempname() {
	char* name = (char*) malloc(sizeof(char)*3);
     sprintf(name, "$%d", tempcounter++);
	return name;
}

void resettemp() {
	tempcounter = 0;
}

Symbol* newtemp() {
	char* name = newtempname();
	Symbol* temp = table_get(name, currscope())->sym;
	if (temp) {
		return temp;
	}
	table_insert(name, "[Temporary var]", -1, currscope(), 0, 0);
	return table_get(name, currscope())->sym;
}

Expr* newexpr(Expr_t t) {
     Expr* e = (Expr*) malloc(sizeof(Expr));
     memset(e, 0, sizeof(Expr));
     e->type = t;
     return e;
}

Expr* newexpr_constbool(unsigned char boolean){
	Expr* tmp = malloc(sizeof(Expr));
	tmp->boolConst = boolean;
	return tmp;
}

Expr* newexpr_conststring(char* s) {
     Expr* e = newexpr(conststring_e);
     e->strConst = strdup(s);
     return e;
}

unsigned nextquadlabel(void){
	return currQuad;
}

void patchlabel(unsigned quadNo, unsigned label){
	assert(quadNo && label);
	quads[quadNo].label = label;
}

Expr* lvalue_expr(Symbol* sym){
	assert(sym);
	Expr* e = (Expr*) malloc(sizeof(Expr));
	memset(e, 0, sizeof(Expr));
	e->next = (Expr*) 0;
	e->sym = sym;
	switch(sym->type){
		case var_s          : e->type = var_e; break;
		case programfunc_s  : e->type = programfunc_e; break;
		case libraryfunc_s  : e->type = libraryfunc_e; break;
		default: assert(0);
	}
	return e;
}