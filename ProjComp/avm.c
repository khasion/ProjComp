#include "avm.h"

avm_memcell stack[AVM_STACKSIZE];
incomplete_jump*    ij_head   = (incomplete_jump*) 0;
unsigned            ij_total  = 0;

instruction* instructions = (instruction*) 0;
unsigned currIns = 0;


generator_func_t (generators[]) = {
	 generate_ASSIGN ,
	 generate_ADD ,
     generate_SUB ,
     generate_MUL ,
     generate_DIV ,
     generate_MOD ,
	 generate_UMINUS ,
	 generate_AND,
	 generate_OR ,
	 generate_NOT ,
	 generate_IF_EQ ,
	 generate_IF_NOTEQ ,	
	 generate_IF_LESSEQ ,
	 generate_IF_GREATEREQ ,
	 generate_IF_LESS ,
	 generate_IF_GREATER ,
	 generate_CALL ,
	 generate_PARAM ,
	 generate_RETURN ,
	 generate_GETRETVAL ,
	 generate_FUNCSTART ,
	 generate_FUNCEND ,
	 generate_JUMP ,
	 generate_TABLECREATE ,
     generate_TABLEGETELEM ,
     generate_TABLESETELEM ,
     generate_NOP
};

/*avmbinaryfile(){
    return magicnumber() and aarrays() and code();
}

magicnumber(){
    return match(unsigned) and currtoken.intval == magicnumber;
}

arrays(){
    return strings() and userfunctions() and libfunctions();
}

strings(){
    unsigned n;
    if (!match(unsigned)) return false;
    else{
        for (n=currtoken.intval; n; --n){
            string();
    }
    */



void avm_tableincrefcounter(avm_table* t){
     ++t->refCounter;
}

void avm_tabledecrefcounter (avm_table* t){
     assert(t->refCounter > 0);
     if(!--t->refCounter) avm_tabledestroy(t);
}

void avm_tablebucketsinit (avm_table_bucket** p){
     for(unsigned i=0; i<AVM_TABLE_HASHSIZE; ++i){
          p[i] = (avm_table_bucket*) 0;
     }
}

avm_table* avm_tablenew (void){
     avm_table* t = (avm_table*) malloc(sizeof(avm_table));
     AVM_WIPEOUT(*t);
     t->refCounter = t->total = 0;
     avm_tablebucketsinit(t->numIndexed);
     avm_tablebucketsinit(t->strIndexed);
     return t;
}

void avm_tablebucketsdestroy(avm_table_bucket** p){
     unsigned i;
     for(i = 0; i < AVM_TABLE_HASHSIZE; ++i ,++p){
          for(avm_table_bucket* b = *p; b;){
               avm_table_bucket* del = b;
               b = b->next;
               avm_memcellclear(&del->key);
               avm_memcellclear(&del->value);
          }
          p[i] = (avm_table_bucket*) 0;
     }
}


void avm_tabledestroy (avm_table* t){
     avm_tablebucketsdestroy(t->strIndexed);
     avm_tablebucketsdestroy(t->numIndexed);
     free(t);
}

void make_operand(Expr* e, vmarg* arg){
     switch(e->type){
          case var_e:
          case tableitem_e:
          case arithexpr_e:
          case boolexpr_e:
          case newtable_e: {
               assert(e->sym);
               arg->val = e->sym->offset;
               switch (e->sym->space) { 
                    case programvar: arg->type = global_a; break;
                    case functionlocal: arg->type = local_a; break;
                    case formalarg: arg->type = formal_a; break;
                    default: assert(0);
               }
               break;
          }
          case constbool_e: {
               arg->val = e->boolConst;
               arg->type = bool_a; break;
          }
          case conststring_e: {
               arg->val = consts_newstring(e->strConst);
               arg->type = string_a; break;
          }
          case constnum_e: {
               arg->val = consts_newnumber(e->numConst);
               arg->type = number_a; break;
          }
          case nil_e: arg->type = nil_a; break;
          case programfunc_e: {
               arg->type = userfunc_a;
               arg->val = e->sym->taddress;
               arg->val = userfuncs_newfunc(e->sym);
               break;
          }
          case libraryfunc_e: {
               arg->type = libfunc_a;
               arg->val = libfuncs_newused(e->sym->name);
               break;
          }
          default: assert(0);
     }
}

void make_numberoperand (vmarg* arg, double val){
     arg->val = consts_newnumber(val);
     arg->type = number_a; 
}

void make_booleanoperand (vmarg* arg , unsigned val){
     arg->val = val;
     arg->type = bool_a;
}

void make_retvaloperand (vmarg* arg){
     arg->type = retval_a;
}

// void patch_incomplete_jumps() {  
//      for (each incomplete jump x)  {   
//           if (x.iaddress = intermediate code size){
//                instructions[x.instrNo].result = target code size;
//           }   
//           else    instructions[x.instrNo].result = quad[x.iaddress].taddress;  
//      }
// }

void generate (vmopcode op, Quad quad) {  
     instruction t;  
     avm_initstack();
     t.opcode = op;  
     make_operand(quad.arg1, &t.arg1);  
     make_operand(quad.arg2, &t.arg2);  
     make_operand(quad.result, &t.result);  
     quad.taddress = currIns++;
     emit(t);
}  

void generate_ADD (Quad quad)  { generate(add_v, quad); } 
void generate_SUB (Quad quad)  { generate(sub_v, quad); } 
void generate_MUL (Quad quad)  { generate(mul_v, quad); } 
void generate_DIV (Quad quad)  { generate(div_v, quad); } 
void generate_MOD (Quad quad)  { generate(mod_v, quad); }

void add_incomplete_jump(unsigned n, unsigned label) {
    incomplete_jump* newjump;
    newjump = (incomplete_jump*) malloc(sizeof(incomplete_jump));

    newjump->instrNo = n;
    newjump->iaddress = label;
    

    newjump->next = ij_head;
    ij_head = newjump;
}

void generate_relational (vmopcode  op, Quad quad) {  
     instruction t;  t.opcode = op;  
     make_operand(quad.arg1, &t.arg1);  
     make_operand(quad.arg2, &t.arg2);    
     t.result.type = label_a;  
     if (quad.label < currprocessedquad()) {   
          t.result.val = quads[quad.label].taddress;  
     }
     else {
          add_incomplete_jump(currIns++, quad.label); 
     } 
     quad.taddress = currIns++;  
     emit(t); 
}

void generate_NEWTABLE (Quad quad)  { generate(newtable_v, quad); } 
void generate_TABLEGETELM (Quad quad)  { generate(tablegetelem_v, quad); } 
void generate_TABLESETELEM (Quad quad)  { generate(tablesetelem_v, quad); } 
void generate_ASSIGN (Quad quad)   { generate(assign_v, quad); } 
void generate_NOP ()   { instruction t; t.opcode=nop_v; emit(t); } 



void generate_JUMP (Quad quad)  { generate_relational(jump_v, quad); } 
void generate_IF_EQ (Quad quad)   { generate_relational(jeq_v, quad); } 
void generate_IF_NOTEQ(Quad quad)  { generate_relational(jne_v, quad); } 
void generate_IF_GREATER (Quad quad)  { generate_relational(jqt_v, quad); } 
void generate_IF_GREATEREQ(Quad quad)  { generate_relational(jge_v, quad); }
void generate_IF_LESS (Quad quad)   { generate_relational(jlt_v, quad); } 
void generate_IF_LESSEQ (Quad quad)  { generate_relational(jle_v, quad); }

void generate_NOT (Quad quad) {    
     quad.taddress = currIns++;  
     instruction t;    
     t.opcode = jeq_v;  
     make_operand(quad.arg1, &t.arg1);  
     make_booloperand(&t.arg2, false);  
     t.result.type = label_a;  
     t.result.val  = currIns++ + 3;  
     emit(t);    
     t.opcode = assign_v;  
     make_booloperand(&t.arg1, false);  
     reset_operand(&t.arg2);  
     make_operand(quad.result, &t.result);  
     emit(t);
     t.opcode = jump_v;  
     reset_operand (&t.arg1);  
     reset_operand(&t.arg2);  
     t.result.type = label_a;  
     t.result.val  =currIns++ +2;  
     emit(t);    
     t.opcode = assign_v;  
     make_booloperand(&t.arg1, true);  
     reset_operand(&t.arg2);  
     make_operand(quad.result, &t.result);  
     emit(t); 
} 

void generate_OR (Quad quad) {    
     quad.taddress = currIns++;  
     instruction t;    
     t.opcode = jeq_v;  
     make_operand(quad.arg1, &t.arg1);  
     make_booloperand(&t.arg2, true);  
     t.result.type = label_a;  
     t.result.val  = currIns++ +4;  
     emit(t);
     make_operand(quad.arg2, &t.arg1);  
     t.result.val  = currIns++ +3;  
     emit(t);
     t.opcode = assign_v;  
     make_booloperand(&t.arg1, false);  
     reset_operand(&t.arg2);  
     make_operand(quad.result, &t.result);  
     emit(t);    
     t.opcode = jump_v;  
     reset_operand (&t.arg1);  
     reset_operand(&t.arg2);  
     t.result.type = label_a;  
     t.result.val  = currIns++ +2;  
     emit(t);    
     t.opcode = assign_v;  
     make_booloperand(&t.arg1, true);  
     reset_operand(&t.arg2);  
     make_operand(quad.result, &t.result);  
     emit(t); 
}

void generate_PARAM(Quad quad) {  
     quad.taddress = currIns++;
     instruction t;  
     t.opcode = pusharg_v;  
     make_operand(quad.arg1, &t.arg1);  
     emit(t); 
}   

void generate_CALL(Quad quad) {  
     quad.taddress = currIns++;  
     instruction t;  
     t.opcode = call_v;  
     make_operand(quad.arg1, &t.arg1);  
     emit(t); 
}   
void generate_GETRETVAL(Quad quad) {  
     quad.taddress = currIns++;  
     instruction t;  
     t.opcode = assign_v;  
     make_operand(quad.result, &t.result);  
     make_retvaloperand(&t.arg1);  
     emit(t); 
}

void generate_FUNCSTART(Quad quad){
    Symbol* f;
     f = quad.result->sym;
     f->taddress = currIns++;
     quad.taddress = currIns++;
     //userfunctions.add(f->name , f->taddress , f->totalLocals);
     //push(funcstack , f);
     instruction t;
     t.opcode = funcenter_v;
     make_operand(quad.result , &t.result);
     emit(t);
}
void generate_RETURN(Quad quad){
     quad.taddress = currIns++;
     instruction t;
     t.opcode = assign_v;
     make_retvaloperand(&t.result);
     make_operand(quad.arg1, &t.arg1);
     emit(t);
     //f = top(funcstack);
     //append(f.returnList , currIns++);
     t.opcode = jump_v;
     reset_operand (&t.arg1);
     reset_operand (&t.arg2);
     t.result.type = label_a;
     emit(t);
}

void generate_FUNCEND(Quad quad){
     //f=pop(funcstack);
     //backpatch(f.returnList , currIns++);
     quad.taddress = currIns++;
     instruction t;
     t.opcode = funcexit_v;
     make_operand(quad.result , &t.result);
     emit(t);
}

void generate1(void) {
     unsigned i;
     for(i = 0; i < 27; i++){
         (*generators[quads[i].op])( *(quads+i));
     }
}