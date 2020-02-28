#include "table.h"

int hash_name(char* key){
    return atoi(key) % SIZE;
}

int hash_func(char* func_name){
    return atoi(func_name) % SIZE;
}

void table_insert(char* name, char* type, char* func_name,
int scope, int line, bool hide){
    DataItem *new_item = create_item(name, type, func_name, scope,
    line, hide);
    int hash1 = hash_name(name);
    int hash2 = hash_func(func_name);

    if (hashArray[hash1][hash2] == NULL) {
        hashArray[hash1][hash2] = new_item;
    }
    else {
        new_item->next = hashArray[hash1][hash2];
        hashArray[hash1][hash2] = new_item;
    }
}

void set_value(char* name, char* func_name, void* value) {
    DataItem* temp = table_lookup(name, func_name);
    if (temp) temp->value = value;
}

void print_table() {
    int i, j;
    for (i=0; i<SIZE; i++) {
        for (j=0; j<SIZE; j++) {
            DataItem* temp = hashArray[i][j];
            while (temp) {
                printf("Name: %s\nType: %s\nRange: %s\nScope: %d\n \
                Line: %d\nHidden: %d\n", temp->name, temp->type,
                temp->func_name, temp->scope, temp->line, temp->hide);
                temp = temp->next;
            }
        }
    }
}

void hide(char* name, char* func_name) {
    DataItem* temp = table_lookup(name, func_name);
    if (temp) temp->hide = true;
}

void unhide(char* name, char* func_name) {
    DataItem* temp = table_lookup(name, func_name);
    if (temp) temp->hide = false;
}

void hide_func(char* func_name) {
    int i, j;
    for (i=0; i<SIZE; i++) {
        for (j=0; j<SIZE; j++) {
            DataItem* temp = hashArray[i][j];
            while (temp) {
                if ( strcmp(temp->func_name, func_name) == 0) {
                    temp->hide = true;
                }
                temp = temp->next;
            }
        }
    }
}

void unhide_func(char* func_name) {
    int i;
    for (i=0; i<SIZE; i++) {
        DataItem* temp = hashArray[i][hash_func(func_name)];
        while (temp) {
            if ( strcmp(temp->func_name, func_name) == 0) {
                temp->hide = false;
            }
            temp = temp->next;
        }
    }
}

void hide_all_no_func(char* func_name) {
    int i, j;
    for (i=0; i<SIZE; i++) {
        for (j=0; j<SIZE; j++) {
            DataItem* temp = hashArray[i][j];
            while (temp) {
                if ( strcmp(temp->func_name, func_name) != 0) {
                    temp->hide = true;
                }
                temp = temp->next;
            }
        }
    }
}

void unhide_all_no_func(char* func_name) {
    int i, j;
    for (i=0; i<SIZE; i++) {
        for (j=0; j<SIZE; j++) {
            DataItem* temp = hashArray[i][j];
            while (temp) {
                if ( strcmp(temp->func_name, func_name) != 0) {
                    temp->hide = false;
                }
                temp = temp->next;
            }
        }
    }
}

void hide_all_no_globals(){
    int i, j;
    for (i=0; i<SIZE; i++) {
        for (j=0; j<SIZE; j++) {
            DataItem* temp = hashArray[i][j];
            while(temp) {
                if ( strcmp(temp->func_name, "global") != 0) {
                    temp->hide = true;
                }
                temp = temp->next;
            }
        }
    }
}

void unhide_all_no_globals(){
    int i, j;
    for (i=0; i<SIZE; i++) {
        for (j=0; j<SIZE; j++) {
            DataItem* temp = hashArray[i][j];
            while(temp) {
                if ( strcmp(temp->func_name, "global") != 0) {
                    temp->hide = false;
                }
                temp = temp->next;
            }
        }
    }
}

DataItem* table_lookup(char* name, char* func_name){
    int j;
    for (j=0; j<SIZE; j++) {
        DataItem* temp = hashArray[hash_name(name)][j];
            while (temp) {
                if ( strcmp(temp->name, name) == 0 &&
                strcmp(temp->func_name, func_name) == 0) {
                    return temp;
                }
                temp = temp->next;
            }
        }
    return NULL;
}

DataItem* create_item(char* name, char* type, char* func_name,
int scope, int line, bool hide){
    DataItem* new_node;
    new_node = (DataItem*)malloc(sizeof(DataItem));
    new_node->name = strdup(name);
    new_node->type = strdup(type);
    new_node->func_name = strdup(func_name);
    new_node->value = NULL;
    new_node->scope = scope;
    new_node->line = line;
    new_node->hide = hide;
    new_node->next = NULL;
    return new_node;    
}