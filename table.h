#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define SIZE 100

typedef struct dataitem{
    char* name;
    char* type;
    char* desc;
    int scope;
    int line;
    bool hide;
    struct dataitem* next;
}DataItem;

DataItem* hashArray[SIZE][SIZE];

int hashName(char* key);
int hashScope(int key);

void table_insert(char* name, char* type, char* desc, int scope, int line, int hide);

DataItem* table_lookup(DataItem* n);

void table_hide(DataItem* key);

DataItem* create_item(char* name, char* type, char* desc, int scope, int line, int hide);