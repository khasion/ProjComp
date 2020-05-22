#include "table.h"

extern unsigned *mem;

enum vmopcode {
    assign_v, 	add_v,		sub_v,
	mul_v,		div_v,		mod_v,
	uminus_v,	and_v,		or_v,
	not_v,		jeq_v,		jne_v ,
	jle_v,		jge_v,		jlt_v,
	jgt_v,		call_v,		pusharg_v,
	ret_v,		getretval_v,funcenter_v,
	funcexit_v,	jump_v,		tablecreate_v,	
	tablegetelem_v,	tablesetelem_v, nop_v 
};

enum vmarg_t{
    label_a = 0,
   	global_a = 1,
   	formal_a = 2,
   	local_a = 3,
   	integer_a = 4,
   	double_a = 5,
   	string_a = 6,
   	bool_a = 7,
   	nil_a = 8,
   	userfunc_a = 9,
   	libfunc_a = 10,
   	retval_a = 11
};

struct vmarg{
    vmarg_t type;
    unsigned val;
};

struct instruction{
    vmopcode opcode;
    vmarg* result;
    vmarg* arg1;
    vmarg* arg2;
    unsigned srcLine;
};

struct userfunc{
    unsigned address;
    unsigned localSize;
    char* id;
};

double* numConsts;
unsigned totalNumConsts;
char** stringConsts;


void init_mem();

void environment_progravar(Symbol* s);
void environment_formalarg(Symbol* s);
void environment_functionlocal(Symbol* s);