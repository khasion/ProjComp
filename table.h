#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define SIZE 100

/*  func_name: To onoma tou function sto opoio anhkei.
    an den anhkei se function tote: func_name = "global"
*/
typedef struct dataitem{
    char* name;
    char* type;
    char* func_name;
    void* value;
    int scope;
    int line;
    bool hide;
    struct dataitem* next;
}DataItem;

DataItem* hashArray[SIZE][SIZE];

/* Get hash for name and scope. */
int hash_name(char* key);
int hash_scope(int key);

/* Insert a new DataItem in the hash table.*/
void table_insert(char* name, char* type, char* func_name, int scope, int line, bool hide);

/* Print table contents.*/
void print_table();

/* Hide and unhide a single DataItem. */
void hide(char* name, char* func_name);
void unhide(char* name, char* func_name);

/* Hide and unhide all DataItems belonging to a function. */
void hide_func(char* func_name);
void unhide_func(char* func_name);

/* Hide and unhide all DataItems that are not global. */
void hide_all_no_globals();
void unhide_all_no_globals();

/* Hide and unhide all DataItems not in give function. */
void hide_all_no_func(char* func_name);
void unhide_all_no_func(char* func_name);

/* Search for a DataItem in hash table. */
DataItem* table_lookup(char* name, char* func_name);

/* Create new DataItem. */
DataItem* create_item(char* name, char* type, char* func_name, int scope, int line, bool hide);