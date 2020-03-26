#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_HASH 65521

char* libs[12];

typedef struct dataitem {
    char* name;
    char* type;
    int value;
    int scope;
    int funcscope;
    int line;
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

SymTable* create_new_symtable();

int get_next_size(int n);

int hash_function(char* name);

void expand();

/* Get hash for scope. */
int hash_scope(int key);

/* Insert a new DataItem in the hash table.*/
DataItem* table_insert(char* name, char* type, int value, int scope, int funcscope, int line);

/* Print table contents.*/
void print_table();

/* Unhide all DataItems with smaller scope and hide all DataItems with larger scope. */
void hide(int scope);

/* Search for a DataItem in hash table. */
DataItem* table_lookup(char* name, char* type, int value, int scope, int funcscope, int line);

/* Create new DataItem. */
DataItem* create_item(char* name, char* type, int value, int scope, int funcscope, int line);

void free_table(SymTable *freetable);
