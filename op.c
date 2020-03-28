#include "quads.h"

void init_quad() {
	quads = (Quad*) malloc(NEW_SIZE);
	currQuad = 0;
}

void expand_quad() {

}

void assign_dual(Expr* res, Expr* expr1, Expr* expr2, Opcode op, unsigned label, unsigned line) {
	assert(expr1 && expr2);

	if ( currQuad >= EXPAND_SIZE) expand_quad();

	(quads + CURR_SIZE)->arg1 = expr1;
	(quads + CURR_SIZE)->arg2 = expr2;
	(quads + CURR_SIZE)->label = label;
	(quads + CURR_SIZE)->line = line;
	(quads + CURR_SIZE)->op = op;
	(quads + CURR_SIZE)->result = res;
	currQuad++;
	total++;
}

void assign_unit(Expr* res, Expr* expr, Opcode op, unsigned label, unsigned line) {
	assert(res && expr);	
	
	if ( currQuad >= EXPAND_SIZE) {
		expand_quad();
	}

	(quads + CURR_SIZE)->arg1 = expr1;
	(quads + CURR_SIZE)->arg2 = NULL;
	(quads + CURR_SIZE)->label = label;
	(quads + CURR_SIZE)->line = line;
	(quads + CURR_SIZE)->op = op;
	(quads + CURR_SIZE)->result = res;
	currQuad++;
	total++;
}

void assign_copy(Expr* res, Expr* expr, Opcode op, unsigned label, unsigned line) {
	assert(res && expr);

	if ( currQuad >= EXPAND_SIZE) {
		expand_quad();
	}

	(quads + CURR_SIZE)->arg1 = expr;
	(quads + CURR_SIZE)->arg2 = NULL;
	(quads + CURR_SIZE)->label = label;
	(quads + CURR_SIZE)->line = line;
	(quads + CURR_SIZE)->op = op;
	(quads + CURR_SIZE)->result = res;
	currQuad++;
	total++;
}
