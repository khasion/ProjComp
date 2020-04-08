#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

#define MAX_HASH 65521

char* libs[12];

typedef enum scopespace_t {
	programvar,
	functionlocal,
	formalarg
}Scopespace_t;

typedef enum symbol_t {
	var_s,
	programfunc_s,
	libraryfunc_s
}Symbol_t;

typedef struct symbol {
	Symbol_t 		type;
	char* 		name;
	Scopespace_t 	space;
	unsigned 		offset;
	unsigned 		scope;
	unsigned 		line;
}Symbol;

typedef struct dataitem {
	Symbol* sym;
    	char* type;
    	int value;
    	int funcscope;
    	bool hide; /* true if hidden, else false */
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

unsigned scopespacecounter = 1;
unsigned formalargoffset = 0;
unsigned functionlocaloffset = 0;
unsigned programvaroffset = 0;


void enterscopespace();
void exitscopespace();

Scopespace_t currscopespace();

void resetformalargsoffset();
void resetfunctionlocaloffset();
void restortcurrscopeoffset();

unsigned currscopespaceoffset();
void incurrscopeoffset();

SymTable* create_new_symtable();

int get_next_size(int n);

int hash_function(char* name);

void expand();

/* Get hash for scope. */
int hash_scope(int key);

/* Insert a new DataItem in the hash table.*/
DataItem* table_insert(char* name, const char* type, int value, int scope, int funcscope, int line);

/* Print table contents.*/
void print_table();

/* Unhide all DataItems with smaller scope and hide all DataItems with larger scope. */
void hide(int scope);

/* Search for a DataItem in hash table. */
DataItem* table_lookup(char* name, char* type, int value, int scope, int funcscope, int line);

/* Print errors.*/
void Error(int i, int line);

/* Create new DataItem. */
DataItem* create_item(char* name, const char* type, int value, int scope, int funcscope, int line);

void free_table(SymTable *freetable);

DataItem* table_get(char* name, unsigned int scope);
