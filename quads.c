#include "quads.h"

Quad* quads = (Quad*) 0;
unsigned total = 0;
unsigned int currQuad = 0;

unsigned int tempcounter = 0;

void make_stmt(Stmt_t* s) {
	s->breaklist = s->contlist = 0;
}

int newlist(int i) {
	quads[i].label = 0;
	return i;
}

Expr* member_item (Expr* lv, char* name) { 
	lv = emit_iftableitem(lv); // Emit code if r-value use of table item 
	Expr* ti = newexpr(tableitem_e); // Make a new expression 
	ti->sym = lv->sym; 
	ti->index = newexpr_conststring(name);// Const string index 
	return ti; 
}

int mergelist (int l1, int l2) {
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

Expr* make_call(Expr* lv, Expr* reversed_elist) {
	Expr* func = emit_iftableitem(lv);
	while (reversed_elist) {
		emit(param, reversed_elist, NULL, NULL, 0, reversed_elist->sym->line);
		reversed_elist = reversed_elist->next;
	}
	emit (call, func, NULL, NULL, 0, 0);
	Expr* result = newexpr(var_e);
	result->sym = newtemp();
	emit(getretval, NULL, NULL, result, 0, 0);
	return result;
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

char* newtempname(void) {
	char* name = (char*) malloc(sizeof(char)*30);
    	sprintf(name, "_t%d", ++tempcounter);
	return name;
}

void resettemp(void) {
	tempcounter = 0;
}

Symbol* newtemp(void) {
	char* name = newtempname();
	DataItem* temp;
	Symbol* sym = NULL;
	if ( (temp = table_lookup(name, currscope()))) {
		sym = temp->sym;
	}
	if (sym) {
		return sym;
	}
	table_insert(var_s, name, currscopespace(), currscopespaceoffset(), currscope(), currfuncscope(), 0);
	printf("HELOO\n");
	return table_lookup(name, currscope())->sym;
}

unsigned int istempname(char* s) {
	return *s == '_';
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

Expr* newexpr_constbool(unsigned char boolean){
	Expr* tmp = malloc(sizeof(Expr));
	tmp->boolConst = boolean;
	return tmp;
}

Expr* newexpr_constnum(double i) {
	Expr* e = newexpr(constnum_e);
	e->numConst = i;
	return e;
}

Expr* newexpr_conststring(char* s) {
     Expr* e = newexpr(conststring_e);
     e->strConst = strdup(s);
     return e;
}

unsigned nextquad() {
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

void check_arith(Expr* e, const char* context) {
	if ( e->type == constbool_e ||
		e->type == conststring_e ||
		e->type == nil_e ||
		e->type == newtable_e ||
		e->type == programfunc_e ||
		e->type == libraryfunc_e ||
		e->type == boolexpr_e) {
			printf("Illegal expr used in %s!", context);
		}
}