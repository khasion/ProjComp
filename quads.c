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

char* newtempname() {
	char* name = (char*) malloc(sizeof(char)*3);
	name[0] = '$';
	name[1] = 48 + tempcounter++;
	name[2] = '\0';
	return name;
}

void resettemp() {
	tempcounter = 0;
}

DataItem* newtemp() {
	char* name = newtempname();
	DataItem* temp = table_get(name, currscope());
	if (temp) {
		return temp;
	}
	table_insert(name, "[Temporary var]", 1, globalscope, funcscope, yylineno);
	return table_get(name, currscope());
}

int currscope() {
	return globalscope;
}

Scopespace_t currscopespace(void) {
	if (scopespacecounter == 1) {
		return programvar;
	}
	else if (scopespacecounter % 2 == 0) {
		return formalarg;
	}
	return functionlocal;
}

unsigned currscopespaceoffset(void) {
	switch (currscopespace()) {
		case programvar		:	return programvaroffset;
		case functionlocal	:	return functionlocaloffset;
		case formalarg		:	return formalargoffset;
		default 		: 	assert(0);
	}
}

void incurrscopeoffset(void) {
	switch (currscopespace()) {
		case programvar 	:	++programvaroffset; break;
		case functionlocal 	:	++functionlocaloffset; break;
		case formalarg 		:	++formalargoffset; break;
		default 		: 	assert(0);
	}
}

void enterscopespace() {
	scopespacecounter++;
}

void exitscopespace() {
	assert(scopespacecounter > 1);
	scopespacecounter--;
}

void resetformalargsoffset(void){
	formalargoffset = 0;
}

void resetfunctionlocaloffset(void){
	functionlocaloffset = 0;
}

void restorecurrscopeoffset(unsigned n){
	switch (currscopespace()){
		case programvar: programvaroffset = n; break;
		case functionlocal: functionlocaloffset = n; break;
		case formalarg: formalargoffset = n; break;
		default: assert(0);
	}
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
	e->index = sym;
	switch(sym->type){
		case var_s : e->type = var_e; break;
		case programfunc_s : e->type = programfunc_e; break;
		case libraryfunc_s : e->type = libraryfunc_e; break;
		default: assert(0);
	}
	return e;
}
