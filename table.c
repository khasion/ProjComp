#include "table.h"

int hashName(char* key){
    return atoi(key) % SIZE;
}

int hashScope(int scope){
    return scope % SIZE;
}

void table_insert(char* name, char* type, char* desc, int scope, int line, int hide){
    DataItem *new_item = create_item(name, type, desc, scope, line, hide);
    int hash1 = hashName(name);
    int hash2 = hashScope(scope);

    if (hashArray[hash1][hash2] == NULL) {
        hashArray[hash1][hash2] = new_item;
    }
    else {
        new_item->next = hashArray[hash1][hash2];
        hashArray[hash1][hash2] = new_item;
    }
}

DataItem* table_lookup(DataItem* n){

}


void table_hide(DataItem* key){
    key->hide = 0;
}

DataItem* create_item(char* name, char* type, char* desc, int scope, int line, int hide){
    DataItem* new_node;
    new_node = (DataItem*)malloc(sizeof(DataItem));
    new_node->name = strdup(name);
    new_node->type = strdup(type);
    new_node->desc = strdup(desc);
    new_node->scope = scope;
    new_node->line = line;
    new_node->hide = hide;
    new_node->next = NULL;
    return new_node;    
}