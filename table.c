#include "scopelist.h"



int hashCode(char* key){
    return *key % SIZE;
}

DataItem* table_lookup(DataItem* n){

}

int table_insert(DataItem* key){
    int hashIndex = hashCode(key->name);
    while(hashArray[hashIndex] != NULL){
        ++hashIndex;
        hashIndex %= SIZE;
    }
    hashArray[hashIndex] = key;
}

void table_hide(DataItem* key){
    key->hide = 0;
}

DataItem* create_node(char* name, char* type, int scope, int line, int hide){
    DataItem* new_node;
    new_node = (DataItem*)malloc(sizeof(DataItem));
    new_node->name = strdup(name);
    new_node->type = strdup(type);
    new_node->scope = scope;
    new_node->line = line;
    new_node->hide = hide;
    new_node->next = NULL;
    return new_node;    
}