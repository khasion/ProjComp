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
}Symbol;

typedef struct dataitem {
	Symbol* 	sym;
    	char* 	type;
    	int 	funcscope;
    	bool 	hide; /* true if hidden, else false */
    	struct dataitem* next;
    	struct dataitem* scopenext;
}DataItem;

typedef struct symtable {
    	struct dataitem** table;
    	unsigned int buckets;
    	unsigned int size;
}SymTable;

SymTable* symtable;
DataItem* scope_head;

DataItem* lvalue_id(char* yytext, unsigned yylineno);
DataItem* lvalue_localid(char* yytext, unsigned yylineno);
DataItem* lvalue_dcolonid(char* yytext, unsigned yylineno);
DataItem* funcname_noname(char* yytext, unsigned yylineno);
DataItem* funcname_id(char* yytext, unsigned yylineno);
DataItem* idlist_id(char* yytext, unsigned yylineno);
DataItem* idlist_commaid(char* yytext, unsigned yylineno);

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

void expand();

/* Get hash for scope. */
int hash_scope(int key);

/* Insert a new DataItem in the hash table.*/
DataItem* table_insert(Symbol_t type, const char* name, unsigned space, unsigned offset, unsigned scope, unsigned funcscope, unsigned line);

/* Print table contents.*/
void print_table();

/* Unhide all DataItems with smaller scope and hide all DataItems with larger scope. */
void hide(int scope);

/* Search for a DataItem in hash table. */
DataItem* table_lookup(const char* name, unsigned scope);
/* Search for collisions with library functions.*/
DataItem* table_libcollision(const char* name);

/* Print errors.*/
void Error(int i, char* name, int line);

/* Create new DataItem. */
DataItem* create_item(Symbol_t type, const char* name, unsigned space, unsigned offset, unsigned scope, unsigned funcscope, unsigned line);

void free_table(SymTable *freetable);

DataItem* table_get(char* name, unsigned int scope);

#endif