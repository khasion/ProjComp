#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "quads.h"

#ifndef AVM_H
#define AVM_H

#define AVM_TABLE_HASHSIZE    211

typedef void (*generator_func_t)(Quad);
extern generator_func_t generators[];

typedef enum vmopcode {
     assign_v,           add_v,              sub_v,
     mul_v,              div_v,              mod_v,
     uminus_v,           and_v,              or_v,
     not_v,              jeq_v,              jne_v,
     jle_v,              jge_v,              jlt_v,
     jqt_v,              call_v,             pusharg_v,
     funcenter_v,        funcexit_v,         newtable_v,
     tablegetelem_v,     tablesetelem_v,     jump_v,
     nop_v
}vmopcode;

typedef enum vmarg_t {
     label_a        = 0,
     global_a       = 1,
     formal_a       = 2,
     local_a        = 3,
     number_a       = 4,
     string_a       = 5,
     bool_a         = 6,
     nil_a          = 7,
     userfunc_a     = 8,
     libfunc_a      = 9,
     retval_a       = 10
}vmarg_t;

typedef struct vmarg {
     vmarg_t   type;
     unsigned  val;
}vmarg;

typedef struct instruction {
     vmopcode  opcode;
     vmarg     result;
     vmarg     arg1;
     vmarg     arg2;
     unsigned  srcLine;
}instruction;

extern instruction* instructions;

typedef struct userfunc {
     unsigned  address;
     unsigned  localSize;
     char*     id;
}userfunc;

extern double*   numConsts;
extern unsigned  totalNumConsts;

extern char**    stringConsts;
extern unsigned  totalStringConsts;

extern char**    namedLibfuncs;
extern unsigned  totalNamedLibFuncs;



userfunc* userFuncs;
unsigned  totaluserFuncs;

typedef enum avm_memcell_t {
     number_m       = 0,
     string_m       = 1,
     bool_m         = 2,
     table_m        = 3,
     userfunc_m     = 4,
     libfunc_m      = 5,
     nil_m          = 6,
     undef_m        = 7
}avm_memcell_t;

struct avm_table;
typedef struct avm_memcell {
     avm_memcell_t type;
     union {
          double              numVal;
          char*               strVal;
          unsigned char       boolVal;
          struct avm_table*   table_val;
          unsigned            funcVal;
          char*               libfuncVal;
     } data;
} avm_memcell;

#define AVM_STACKSIZE    4096
#define AVM_WIPEOUT(m)   memset( &(m), 0, sizeof(m))

avm_memcell stack[AVM_STACKSIZE];

static void avm_initstack (void) {
     for (unsigned i=0; i<AVM_STACKSIZE; ++i) {
          AVM_WIPEOUT(stack[i]);
          stack[i].type = undef_m;
     }
}

typedef struct avm_table_bucket {
     avm_memcell         key;
     avm_memcell         value;
     struct avm_table_bucket*   next;
}avm_table_bucket;

typedef struct avm_table {
     unsigned            refCounter;
     avm_table_bucket*   strIndexed[AVM_TABLE_HASHSIZE];
     avm_table_bucket*   numIndexed[AVM_TABLE_HASHSIZE];
     unsigned            total;
}avm_table;





avm_table*     avm_tablenew(void);
void           avm_tabledestroy (avm_table* t);
avm_memcell*   avm_tablegetelem (avm_memcell* key);
void           avm_tablesetelem (avm_memcell* key, avm_memcell* value);


typedef struct incomplete_jump {
     unsigned       instrNo;
     unsigned       iaddress;
     struct incomplete_jump*    next;
}incomplete_jump;

extern incomplete_jump*    ij_head;
extern unsigned            ij_total;
 

void avm_memcellclear(avm_memcell* m);

void emit(instruction i);


void make_numberoperand (vmarg* arg, double val);
void make_booloperand (vmarg* arg , bool val);
void make_retvaloperand (vmarg* arg);
void reset_operand (vmarg* arg);

unsigned currprocessedquad();
unsigned consts_newstring(char* s);
unsigned consts_newnumber(double d);
unsigned userfuncs_newfunc(Symbol* s);
unsigned libfuncs_newused(char* s);


extern void generate_ADD (Quad);
extern void generate_SUB (Quad);
extern void generate_MUL (Quad);
extern void generate_DIV (Quad);
extern void generate_MOD (Quad);
extern void generate_TABLECREATE (Quad);
extern void generate_TABLEGETELEM (Quad);
extern void generate_TABLESETELEM (Quad);
extern void generate_ASSIGN (Quad);
extern void generate_NOP ();
extern void generate_JUMP (Quad);
extern void generate_IF_EQ (Quad);
extern void generate_IF_NOTEQ (Quad);
extern void generate_IF_GREATER (Quad);
extern void generate_IF_GREATEREQ (Quad);
extern void generate_IF_LESS (Quad);
extern void generate_IF_LESSEQ (Quad);
extern void generate_UMINUS (Quad);
extern void generate_NOT (Quad);
extern void generate_AND (Quad);
extern void generate_OR (Quad);
extern void generate_PARAM (Quad);
extern void generate_CALL (Quad);
extern void generate_GETRETVAL (Quad);

extern void generate_FUNCSTART (Quad);
extern void generate_RETURN (Quad);
extern void generate_FUNCEND (Quad);

#endif