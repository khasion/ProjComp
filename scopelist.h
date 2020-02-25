#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define SIZE 100

typedef struct dataitem{
    char* name;
    char* type;
    int scope;
    int line;
    int hide;
    int marked;
    struct dataitem* next;
    struct dataitem* next_scope;
}DataItem;

DataItem* hashArray[SIZE];

int hashCode(char* key);
DataItem* table_lookup(DataItem* n);
int table_insert(DataItem* key);
void table_hide(DataItem* key);

DataItem* create_node(char* name, char* type, int scope, int line, int hide);


DataItem* new_scope_node(char* name, int scope);

void insert_scope(char* name, int scope);

DataItem *search(char* name, int scope);

/* 
    scope = -1: Search entire table
    else : only items->scope = scope 
*/
void mark(char* name, int scope); 
void unmark(char *name, int scope);