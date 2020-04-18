#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

#ifndef TABLE_H
#define TABLE_H

#define HASH_MULTIPLIER 65599

char* libs[12];

typedef enum scopespace_t {
	programvar,
	functionlocal,
	formalarg
}Scopespace_t;

typedef enum symbol_t {
	localvar_s,
	globalvar_s,
	var_s,
	programfunc_s,
	nonameprogramfunc_s,
	libraryfunc_s
}Symbol_t;

typedef struct symbol {
	Symbol_t 		type;
	char* 		name;
	Scopespace_t 	space;
	unsigned 		offset;
	unsigned 		scope;
	unsigned 		line;
	unsigned 		iaddress;
	unsigned		totalLocals;
    	char* 		desc;
    	int 			funcscope;
    	bool 		hide; /* true if hidden, else false */
    	struct symbol* next;
    	struct symbol* scopenext;
}Symbol;

typedef struct symtable {
    	struct symbol** table;
    	unsigned int buckets;
    	unsigned int size;
}SymTable;

Symbol* scope_head;
SymTable* symtable;

Symbol* lvalue_id(char* yytext, unsigned yylineno);
Symbol* lvalue_localid(char* yytext, unsigned yylineno);
Symbol* lvalue_dcolonid(char* yytext, unsigned yylineno);
Symbol* funcname_noname(char* yytext, unsigned yylineno);
Symbol* funcname_id(char* yytext, unsigned yylineno);
Symbol* idlist_id(char* yytext, unsigned yylineno);
Symbol* idlist_commaid(char* yytext, unsigned yylineno);

unsigned currfuncscope();
void enterfuncscope();
void exitfuncscope();

void exitscope();
void nextscope();
unsigned currscope();

void enterscopespace();
void exitscopespace();

Scopespace_t currscopespace();

void resetformalargsoffset();
void resetfunctionlocaloffset();
void restorecurrscopeoffset();

unsigned currscopespaceoffset();
void incurrscopeoffset();

SymTable* create_new_symtable();

int get_next_size(int n);

int hash_function(const char* name);

/* Get hash for scope. */
int hash_scope(int key);

/* Insert a new Symbol in the hash table.*/
Symbol* table_insert(Symbol_t type, const char* name, unsigned space, unsigned offset, unsigned scope, unsigned funcscope, unsigned line);

/* Print table contents.*/
void print_table();

/* Unhide all Symbols with smaller scope and hide all Symbols with larger scope. */
void hide(int scope);

/* Search for a Symbol in hash table. */
Symbol* table_lookup(const char* name, unsigned scope);
/* Search for collisions with library functions.*/
Symbol* table_libcollision(const char* name);

/* Print errors.*/
void Error(int i, char* name, int line);

/* Create new Symbol. */
Symbol* create_item(Symbol_t type, const char* name, unsigned space, unsigned offset, unsigned scope, unsigned funcscope, unsigned line);

void free_table(SymTable *freetable);

Symbol* table_get(char* name, unsigned int scope);

#endif