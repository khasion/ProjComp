#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_HASH 65521

typedef struct dataitem{
    char* name;
    char* type;
    void* value;
    int scope;
    int line;
    bool hide;
    struct dataitem* next;
}DataItem;

typedef struct symtable {
    struct dataitem** table;
    unsigned int buckets;
    unsigned int size;
}SymTable;

SymTable* symtable;

SymTable* create_new_symtable();

int get_next_size(int n);

int hash_function(int scope);

void expand();

/* Get hash for scope. */
int hash_scope(int key);

/* Insert a new DataItem in the hash table.*/
void table_insert(char* name, char* type, void* value, int scope, int line);

void set_value();

/* Print table contents.*/
void print_table();

/* Unhide all DataItems with smaller scope and hide all DataItems with larger scope. */
void hide(int scope);
void unhide(int scope);

/* Search for a DataItem in hash table. */
DataItem* table_lookup(char* name);

/* Create new DataItem. */
DataItem* create_item(char* name, char* type, void* value, int scope, int line);

void free_table(SymTable *freetable);