#include "table.h"

#ifndef QUADS_H
#define QUADS_H

typedef struct prefix {
	int enter;
	int test;
}Prefix;

typedef struct stmt_t {
	int breaklist;
	int contlist;
}Stmt_t;

typedef struct x_lists{
	int label;
	struct x_lists* next;
}X_list;

typedef enum iopcode {
	assign,		op_add,		op_sub,
	op_mul,		op_div,		op_mod,
	uminus,		op_and, 		op_or,
	op_not,		if_eq,		if_noteq,
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

	nil_e
}Expr_t;



typedef struct expr {
	Expr_t type;
	Symbol* sym;
	struct expr* index;
	double numConst;
	char* strConst;
	unsigned char boolConst;
	X_list* truelist;
	X_list* falselist;
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


typedef struct call {
	Expr*			elist;
	unsigned char method;
	char* 			name;
}Call;

#define EXPAND_SIZE 1024
#define CURR_SIZE (total*sizeof(Quad))
#define NEW_SIZE (EXPAND_SIZE*sizeof(Quad)+CURR_SIZE)

Expr* member_item (Expr* lv, char* name);

Expr* make_call(Expr* lv, Expr* reversed_elist);

Expr* emit_iftableitem(Expr* e);

void make_stmt(Stmt_t* s);
int newlist(int i);

X_list* mergelist(X_list* l1, X_list* l2);
X_list* makelist(unsigned label);

void patchlist(int list, int label);

void init_quad();
void expand_quad();

void emit();

char* newtempname();
void resettemp();
Symbol* newtemp();
unsigned int istempname(char* s);
unsigned int istempexpr(Expr* e);

Expr* newexpr(Expr_t type);
Expr* newexpr_constbool(unsigned char boolean);
Expr* newexpr_conststring(char* s);
Expr* newexpr_constnum(double i);

void patchlabel(unsigned quadNo, unsigned label);

Expr* lvalue_expr(Symbol* sym);
unsigned nextquad();

void check_arith(Expr* e, const char* context);
void print_intermadiate();
void backpatch(X_list* list, unsigned label);


#endif
