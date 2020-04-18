#include "table.h"

int func_id = 0;

unsigned globalscope 		= 0;
unsigned funcscope 			= 0;
unsigned scopespacecounter 	= 1;
unsigned formalargoffset 	= 0;
unsigned functionlocaloffset 	= 0;
unsigned programvaroffset 	= 0;

unsigned currfuncscope() {
	return funcscope;
}

void enterfuncscope() {
	++funcscope;
}

void exitfuncscope() {
	--funcscope;
}

unsigned currscope() {
	return globalscope;
}

void exitscope() {
	--globalscope;
}

void nextscope() {
	++globalscope;
}

void enterscopespace() {
	++scopespacecounter;
}

void exitscopespace() {
	assert(scopespacecounter > 1);
	scopespacecounter--;
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

void resetformalargsoffset(void){
	formalargoffset = 0;
}

void resetfunctionlocaloffset(void){
	functionlocaloffset = 0;
}

void restorecurrscopeoffset(unsigned n){
	switch (currscopespace()){
		case programvar	: programvaroffset = n; break;
		case functionlocal	: functionlocaloffset = n; break;
		case formalarg		: formalargoffset = n; break;
		default: assert(0);
	}
}

unsigned currscopespaceoffset(void) {
	switch (currscopespace()) {
		case programvar	:	return programvaroffset;
		case functionlocal	:	return functionlocaloffset;
		case formalarg		:	return formalargoffset;
		default 			: 	assert(0);
	}
}

void incurrscopeoffset(void) {
	switch (currscopespace()) {
		case programvar 	:	++programvaroffset; break;
		case functionlocal 	:	++functionlocaloffset; break;
		case formalarg 	:	++formalargoffset; break;
		default: assert(0);
	}
}

/* ------------------------------------------------------------------------------------------------------------ */


void Error(int i , char* name, int line)
{
	switch(i) {
		case 0: 	printf("Error  :  Using ProgramFunc as an lvalue at line: %d\n", line); break;
		case 1: 	printf("Error  :  Using LibFunc as an lvalue at line: %d\n", line); break;
		case 2: 	printf("Error  :  Use of 'return' while not in a function at line: %d\n", line); break; 
		case 3:	printf("Error  :  Use of 'break' while not in a loop at line: %d\n", line); break;
		case 4:	printf("Error  :  Use of 'continue' while not in a loop at line: %d\n", line); break;
		case 5:	printf("Error  :  No global variable '::%s' exists at Line: %d\n", name, line); break;
		case 6:	printf("Error  :  Collision with '%s' library function at line: %d\n", name, line); break;
		case 7:	printf("Error  :  User function '%s',Collision with '%s' library function at line: %d\n", name , name , line); break;
		case 8:	printf("Error  :  Variable '%s' already defined at Line: %d \n", name, line ); break;
		case 9:	printf("Error  :  Collision with function named '%s' defined at line: %d \n", name , line ); break;
		case 10:	printf("Error  :  Variable '%s' already defined at Line: %d \n", name, line); break;
		case 11:	printf("Error  :  Cannot access '%s' inside function  at Line: '%d'  \n", name, line); break;
	}
}

DataItem* lvalue_id (char* yytext, unsigned yylineno) {
	DataItem* temp;
	int tempscope = currscope();
	int flag = 0;
	while (tempscope >= 0) {
		temp = table_lookup(yytext, tempscope--);
		if (temp && ( temp->sym->type == programfunc_s || ( temp->hide || ( !temp->hide && (currfuncscope() == temp->funcscope || temp->sym->scope == 0)) )) ) {
			flag = 1;
			break;
		}
		else if (temp) {
			Error(11, yytext, yylineno);
			flag = 1;
			break;
		}
	}
	if (temp && (temp->sym->type == libraryfunc_s || temp->sym->type == programfunc_s)) {
		flag = 1;
	}
	if (!flag) {
		temp = table_insert(var_s, yytext, currscopespace(), currscopespaceoffset(), currscope(), currfuncscope(), yylineno);
		incurrscopeoffset();
	}
	return temp;
}

DataItem* lvalue_localid(char* yytext, unsigned yylineno) {
	DataItem* temp;
	if ( (temp = table_libcollision(yytext))) {
		Error(6, yytext, yylineno);
		return temp;
	}
	temp = table_lookup(yytext, currscope());
	if ( !temp || temp->hide) {
		if (currscope() >= 0) {
			temp = table_insert(localvar_s, yytext, currscopespace(), currscopespaceoffset(), currscope(), currfuncscope(), yylineno);
			incurrscopeoffset();
		}
		else {
			temp = table_insert(globalvar_s, yytext, currscopespace(), currscopespaceoffset(), currscope(), currfuncscope(), yylineno);
			incurrscopeoffset();
		}
	}
	return temp;
}

DataItem* lvalue_dcolonid(char* yytext, unsigned yylineno) {
	DataItem* temp;
	temp = table_lookup(yytext, 0);
	if (!temp) {
		Error(5, yytext, yylineno);
		temp = create_item(globalvar_s, yytext, currscopespace(), currscope(), currscopespaceoffset(), currfuncscope(), yylineno);
	}
	return temp;
}

DataItem* funcname_noname(char* yytext, unsigned yylineno) {
	char* name;
	name = (char*) malloc(sizeof(char)* 3);
	sprintf(name, "_f%d", func_id++);
	DataItem* temp = table_insert(nonameprogramfunc_s, name, currscopespace(), currscopespaceoffset(), currscope(), currfuncscope(), yylineno);
	return temp;
}

DataItem* funcname_id(char* yytext, unsigned yylineno) {
	DataItem* temp;
	int flag = 0;
	if ( (temp = table_lookup(yytext, currscope()))) {
		if (temp->sym->type <= 2) Error(8, yytext, temp->sym->line);
		else Error(9, yytext, temp->sym->line);
		flag = 1;
	}
	if ( (temp = table_libcollision(yytext))) {
		Error(7, yytext, yylineno);
		flag = 1;
	}
	if (!flag) {
		temp = table_insert(programfunc_s, yytext, currscopespace(), currscopespaceoffset(), currscope(), currfuncscope(), yylineno);
	}
	return temp;
}

DataItem* idlist_id(char* yytext, unsigned yylineno) {
	DataItem* temp;
	int flag = 0; 
	temp = table_lookup(yytext, currscope()+1);
	if (temp && !temp->hide) {
		Error(8, yytext, yylineno);
		flag = 1;
	}
	if ( (temp = table_libcollision(yytext)) ) {
		Error(6, yytext, yylineno);
		flag = 1;
	}
	if (!flag) {
		temp = table_insert(var_s, yytext, currscopespace(), currscopespaceoffset(), currscope()+1, currfuncscope()+1, yylineno);
	}
	return temp;
}

DataItem* idlist_commaid(char* yytext, unsigned yylineno) {
	DataItem* temp;
	int flag = 0;
	if ( (temp = table_lookup(yytext, currscope()+1))) {
		Error(8, yytext, yylineno);
		flag = 1;
	}
	if ( (temp = table_libcollision(yytext))) {
		Error(6, yytext, yylineno);
		flag = 1;
	}
	if (!flag) {
		temp = table_insert(var_s, yytext, currscopespace(), currscopespaceoffset(), currscope()+1, currfuncscope()+1, yylineno);
	}
	return temp;
}

SymTable *create_new_symtable() {
    	int i;
    	SymTable *new_sym = (SymTable*) malloc(sizeof(SymTable*));
    	new_sym->table = (DataItem**) malloc(509*sizeof(DataItem));
    	new_sym->size = 0;
    	new_sym->buckets = 509;

	for (i=0; i<new_sym->buckets; i++) {
		new_sym->table[i] = (DataItem*) malloc(sizeof(DataItem));
		new_sym->table[i] = NULL;
	}
    	return new_sym;
}

int get_next_size(int n) {
    	switch(n) {
        	case 509: return 1021;
        	case 1021: return 2053;
        	case 2053: return 4093;
        	case 4093: return 8191;
        	case 8191: return 16381;
        	case 16381: return 32771;
        	case 32771: return HASH_MULTIPLIER;
    	}
    	return 0;
}

int hash_function(const char* name){
  	size_t ui;
  	unsigned int uiHash = 0;
  	for (ui = 0U; name[ui] != '\0'; ui++){
  		uiHash = uiHash * HASH_MULTIPLIER + name[ui];
  	}
  	return uiHash%509;
}

void expand() {
    	SymTable *new_sym = (SymTable*) malloc(sizeof(SymTable));
    	SymTable *old_sym = symtable;
    	unsigned int i, new_size = get_next_size(symtable->size);

    	new_sym->table = (DataItem**) malloc(new_size*sizeof(DataItem));
    	for (i=0; i<new_size; i++) {
        	new_sym->table[i] = (DataItem*) malloc(sizeof(DataItem));
    	}

    	new_sym->size = 0;
    	new_sym->buckets = new_size;
    	symtable = new_sym;

    	for (i=0; i<old_sym->size; i++) {
        	DataItem* temp = old_sym->table[i];
        	while (temp) {
            		temp = temp->next;
        	}
    	}
    	free_table(old_sym);
}

DataItem* table_lookup(const char* name, unsigned scope) {
	DataItem* temp;
	temp = symtable->table[hash_function(name)];
	while (temp) {
		
		if ( strcmp(temp->sym->name, name) == 0 && temp->sym->scope == scope) {
			return temp;
		}
		temp = temp->next;
	}
	return temp;
}

DataItem* table_libcollision(const char* name) {
	DataItem* temp;
	temp = symtable->table[hash_function(name)];
	while (temp) {
		if ( strcmp(temp->sym->name, name) == 0 && temp->sym->type == libraryfunc_s) {
			return temp;
		}
		temp = temp->next;
	}
	return NULL;
}

DataItem* table_insert(Symbol_t type, const char* name, unsigned space, unsigned offset, unsigned scope, unsigned funcscope, unsigned line){
    	DataItem *new_item = create_item(type, name, space, offset, scope, funcscope, line);
    	DataItem* tmp;
    	int hash;

    	if (symtable->size == symtable->buckets-1) {
        	expand();
    	}
    	hash = hash_function(name);
    	if (symtable->table[hash] == NULL) {
        	symtable->table[hash] = new_item;
        	symtable->table[hash]->next = NULL;
    	}
    	else {
        	new_item->next = symtable->table[hash];
        	symtable->table[hash]= new_item;
    	}

	if ( *name == '_') {
		printf("name: %s scope : %d\n", new_item->sym->name, new_item->sym->scope);
		return new_item;
	}

    	if(scope_head == NULL || (scope_head->sym->scope >= new_item->sym->scope)){
		//printf("NAME: %s\n", new_item->sym->name);
      	new_item->scopenext = scope_head;
      	scope_head = new_item;
    	} 
	else {
      	tmp = scope_head;
      	while(tmp->scopenext != NULL && (tmp->sym->scope < new_item->sym->scope) ){
        		tmp = tmp->scopenext;
      	}
      	new_item->scopenext = tmp->scopenext;
      	tmp->scopenext = new_item;
    	}
	    
    	return new_item;
}

void print_table() {
   	int i=-1 ;
    	DataItem* tmp = scope_head;
	printf("--------------------------Scope #%d -------------------------- \n" ,++i);
    	while(tmp != NULL){
      		if(tmp->sym->scope > i) printf("--------------------------Scope #%d -------------------------- \n" ,++i);
      		printf("\"%s\" %s (line %d) (scope %d) (hide %d)\n", tmp->sym->name, tmp->type,tmp->sym->line, tmp->sym->scope , tmp->hide);
      		tmp = tmp->scopenext;
    	}
}

void hide(int scope) {
  	DataItem *temp = scope_head;
	printf("MAKE\n");
  	while (temp) {
    		if (temp->sym->scope == scope ) temp->hide = true;
    		temp = temp->scopenext;
  	}
	printf("UNMAW\n");
}

DataItem* create_item(Symbol_t type, const char* name, unsigned space, unsigned offset, unsigned scope, unsigned funcscope, unsigned line) {
    	DataItem* new_data;
    	new_data = (DataItem*) malloc(sizeof(DataItem));
	new_data->sym = (Symbol*) malloc(sizeof(Symbol));
    	new_data->sym->name = strdup(name);
	new_data->sym->type = type;
	new_data->sym->space = space;
	new_data->sym->offset = offset;
	new_data->sym->scope = scope;
	new_data->sym->line = line;
	new_data->sym->iaddress = 0;
	new_data->sym->totalLocals = 0;

	switch (type) {
		case 0	:	new_data->type = strdup("[local variable]");		break;
		case 1	:	new_data->type = strdup("[global variable]"); 	break;
		case 2	:	new_data->type = strdup("[variable]");			break;
		case 3	:	new_data->type = strdup("[userfunc]");			break;
		case 4	:	new_data->type = strdup("[userfunc noname]"); 	break;
		case 5	:	new_data->type = strdup("[library function]");	break;
		default: assert(0);
	}

    	new_data->funcscope = funcscope;
    	new_data->hide = false;
    	new_data->next = NULL;
    	new_data->scopenext = NULL;
    	return new_data;
}

void free_table(SymTable *freetable) {
    	unsigned int i;
    	for (i=0; i<freetable->buckets; i++) {
        	DataItem *tmp_curr = freetable->table[i];
        	DataItem *tmp_next = tmp_curr;
        	while(tmp_next) {
            		tmp_next = tmp_next->next;
            		free(tmp_curr);
            		tmp_curr = tmp_next;
        	}
    	}
    	free(freetable);
}