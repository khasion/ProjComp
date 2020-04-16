#include "table.h"

#ifndef QUADS_H
#define QUADS_H

typedef struct stmt_t {
	int breaklist;
	int contlist;
}Stmt_t;

typedef enum iopcode {
	assign,		op_add,		op_sub,
	op_mul,		op_div,		op_mod,
	uminus,		con_and, 		con_or,
	con_not,		if_eq,		if_noteq,
	if_lesseq,	if_greatereq,	if_less,
	if_greater,	call,		param,
	ret,			getretval,	funcstart,
	funcend,		tablecreate,	jump,
	tablegetelem,	tablesetelem
}Opcode;

typedef enum expr_t {
	var_e,
	tableitem_e,

	programfunc_e,
	libraryfunc_e,

	arithexpr_e,
	boolexpr_e,
	assignexpr_e,
	newtable_e,

	constnum_e,
	constbool_e,
	conststring_e,

	nil_e,
}Expr_t;

typedef struct expr {
	Expr_t type;
	Symbol* sym;
	struct expr* index;
	double numConst;
	char* strConst;
	unsigned char boolConst;
	struct expr* next;
}Expr;

typedef struct quad {
	Opcode op;
	Expr* result;
	Expr* arg1;
	Expr* arg2;
	unsigned label;
	unsigned line;
}Quad;


#define EXPAND_SIZE 1024
#define CURR_SIZE (total*sizeof(Quad))
#define NEW_SIZE (EXPAND_SIZE*sizeof(Quad)+CURR_SIZE)

Expr* member_item (Expr* lv, char* name);
Expr* emit_iftableitem(Expr* e);

void make_stmt(Stmt_t* s);
int newlist(int i);

int mergelist(int l1, int l2);
void patchlist(int list, int label);

void init_quad();
void expand_quad();

void emit();

char* newtempname();
void resettemp();
Symbol* newtemp();
Expr* newexpr(Expr_t type);
Expr* newexpr_constbool(unsigned char boolean);
Expr* newexpr_conststring(char* s);
Expr* newexpr_constnum(int i);

unsigned nextquadlabel(void);
void patchlabel(unsigned quadNo, unsigned label);

Expr* lvalue_expr(Symbol* sym);
Quad* nextquad();
void check_arith(Expr* e);
#endif
