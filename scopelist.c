#include "scopelist.h"

DataItem *scope_table[100];

DataItem *new_scope_node(char* name, int scope) {
    DataItem *new_node;
    char* new_name;
    new_node = (DataItem*) malloc(sizeof(DataItem));
    new_name = strdup(name);
    new_node->name = new_name;
    new_node->scope = scope;
    new_node->marked = false;
    new_node->next_scope = NULL;
    return new_node;
}

void insert_scope(char* name, int scope) {
    DataItem *scope_node = new_scope_node(name, scope);
    scope_node->next = scope_table[scope];
    scope_table[scope]->next_scope = scope_node;
}

DataItem *search(char* name, int scope) {
    DataItem *temp = scope_table[scope];
        while (temp) {
            if (strcmp(temp->name, name) == 0) {
                return temp;
            }
            temp = temp->next_scope;
        }
    return NULL;
}

void mark(char* name, int scope) {
    DataItem *temp;
    int i;
    if (scope != -1) {
        for (i=0; i<100; i++) {
            if ( (temp = search(name, scope)) ) temp->marked = true;
        }
    }
    else {
        search(name, scope)->marked = true;
    }
}

void unmark(char *name, int scope) {
    DataItem *temp;
    int i;
    if (scope != -1) {
        for (i=0; i<100; i++) {
            if ( (temp = search(name, scope)) ) temp->marked = false;
        }
    }
    else {
        search(name, scope)->marked = false;
    }
}