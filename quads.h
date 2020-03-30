#include "table.h"

typedef enum iopcode {
	assign,		op_add,		op_sub,
	op_mul,		op_div,		op_mod,
	uminus,		con_and,		con_or,
	con_not,		if_eq,		if_noteq,
	if_lesseq,	if_greatereq,	if_less,
	if_greater,	call,		param,
	ret,			getretval,	funcstart,
	funcend,		tablecreate,	
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
	nevtable_e,

	costnum_e,
	constbool_e,
	conststring_e,

	nil_e,
}Expr_t;

typedef struct expr {
	Expr_t type;
	Symbol* item;	
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

Quad* quads = (Quad*) 0;
unsigned total = 0;
unsigned int currQuad = 0;

unsigned int tempcounter = 0;

unsigned scopespacecounter = 1;

unsigned formalargoffset = 0;
unsigned functionlocaloffset = 0;
unsigned programvaroffset = 0;

#define EXPAND_SIZE 1024
#define CURR_SIZE (total*sizeof(Quad))
#define NEW_SIZE (EXPAND_SIZE*sizeof(Quad)+CURR_SIZE)

void init_quad();
void expand_quad();

void emit();

char* newtempname();
void resettemp();
DataItem* newtemp();

int currscope();

Scopespace_t currscopespace();

void resetformalargsoffset(void);
void resetfunctionlocaloffset(void);
void restorecurrscopeoffset(unsigned n);

unsigned nextquadlabel(void);
void patchlabel(unsigned quadNo, unsigned label);

Expr* lvalue_expr(Symbol* sym);
