#include "table.h"

typedef enum iopcode {
	assign,		op_add,		op_sub,
	op_mul,		op_div,		op_mod,
	uminus,		con_and,	con_or,
	con_not,	if_eq,		if_noteq,
	if_lesseq,	if_greatereq,	if_less,
	if_greater,	call,		param,
	ret,		getretval,	funcstart,
	funcend,	tablecreate,	
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
	expr_t type;
	DataItem* item;	
	struct expr* index;
	double numConst;
	char* strConst;
	unsigned char boolConst;
	expr* next;
}Expr;

typedef struct quad {
	iopcode op;
	expr* result;
	expr* arg1;
	expr* arg2;
	unsigned label;
	unsigned line;
}Quad;

quad* quads = (quad*) 0;
unsigned total = 0;
unsigned int currQuad = 0;

#define EXPAND_SIZE 1024;
#define CURR_SIZE (total*sizeof(quad))
#define NEW_SIZE (EXPAND_SIZE*sizeof(quad)+CURR_SIZE)
