#include "table.h"

SymTable *create_new_symtable() {
    int i;
    SymTable *new_sym = (SymTable*) malloc(sizeof(SymTable*));
    new_sym->table = (DataItem**) malloc(509*sizeof(DataItem));
    new_sym->size = 0;
    new_sym->buckets = 509;
    for (i=0; i<new_sym->buckets; i++) {
        new_sym->table[i] = (DataItem*) malloc(sizeof(DataItem));
    }
    return new_sym;
}

int get_next_size(int n) {
    switch(n) {
        case 509: return 1021;
        case 1021: return 2053;
        case 2053: return 4093;
        case 4093: return 8191;
        case 8191: return 16381;
        case 16381: return 32771;
        case 32771: return MAX_HASH;
    }
    return 0;
}

int hash_function(int scope){
  printf("%d\n",scope % symtable->buckets );
    return scope % symtable->buckets;
}

void expand() {
    SymTable *new_sym = (SymTable*) malloc(sizeof(SymTable));
    SymTable *old_sym = symtable;
    int i, new_size = get_next_size(symtable->size);

    new_sym->table = (DataItem**) malloc(new_size*sizeof(DataItem));
    for (i=0; i<new_size; i++) {
        new_sym->table[i] = (DataItem*) malloc(sizeof(DataItem));
    }

    new_sym->size = 0;
    new_sym->buckets = new_size;
    symtable = new_sym;

    for (i=0; i<old_sym->size; i++) {
        DataItem* temp = old_sym->table[i];
        while (temp) {
            table_insert(temp->name, temp->type, temp->value, temp->scope,
            temp->line);
            temp = temp->next;
        }
    }
    free_table(old_sym);
}

void table_insert(char* name, char* type, void* value, int scope, int line){
    DataItem *new_item = create_item(name, type, value, scope,
    line);
    DataItem* tmp;
    int hash;
    if (symtable->size == symtable->buckets-1) {
        expand();
    }

    hash = hash_function(scope);

    if (symtable->table[hash] == NULL) {
        symtable->table[hash]= new_item;
    }
    else {
        new_item->next = symtable->table[hash];
        symtable->table[hash]= new_item;
    }

    if(scope_head == NULL || scope_head->scope >= new_item->scope){
      new_item->next = scope_head;
      scope_head = new_item;
    } else{
      tmp = scope_head;
      while(tmp->next != NULL && tmp->next->scope < new_item->scope){
        tmp = tmp->next;
      }
      new_item->next = tmp->next;
      tmp->next = new_item;
    }

}

void set_value(char* name, char* func_name, void* value) {
    // DataItem* temp = table_lookup(name);
    // if (temp) temp->value = value;
}

void print_table() {
    int i;
    DataItem* tmp = scope_head;
    for (i=0; i<symtable->buckets; i++) {
        DataItem* temp = symtable->table[i];
        while (temp) {
            if(temp->name != NULL)
            printf("\"%s\" %s (line %d) (scope %d)\n", temp->name, temp->type,
            temp->line, temp->scope);
            temp = temp->next;
        }
    }
    while(tmp != NULL){
      printf("%d se scopelist\n",tmp->scope);
      tmp = tmp->next;
    }
}

void hide(int scope) {
    int i;
    for (i=scope+1; i<symtable->buckets; i++) {
        DataItem *temp = symtable->table[i];
        while(temp) {
            temp->hide = false;
            temp = temp->next;
        }
    }
}

void unhide(int scope) {
    int i, j;
    for (i=0; i<scope; i++) {
        DataItem *temp = symtable->table[i];
        while(temp) {
            temp->hide = true;
            temp = temp->next;
        }
    }
}

DataItem* table_lookup(char* name, char* type, void* value, int scope, int line){
  int i;
  for (i=0; i<symtable->buckets; i++) {
          DataItem* temp = symtable->table[i];
          while (temp->next != NULL) {
            printf("\t%s ela %s\n",temp->name,name);
              if (strcmp(temp->name, name) == 0) {
                printf("\t tobrikaaaaa\n");
                  return temp;
              }
              temp = temp->next;
          }
      }
  //if(scope == 0){
    table_insert(name, "[global variable]", 0, scope, line);
  //}
  return NULL;
}

DataItem* create_item(char* name, char* type, void* value, int scope, int line){
    DataItem* new_data;
    new_data = (DataItem*)malloc(sizeof(DataItem));
    new_data->name = strdup(name);
    new_data->type = strdup(type);
    new_data->value = value;
    new_data->scope = scope;
    new_data->line = line;
    new_data->hide = false;
    new_data->next = NULL;
    new_data->scopenext = NULL;
    return new_data;
}

void free_table(SymTable *freetable) {
    int i;
    for (i=0; i<freetable->buckets; i++) {
        DataItem *tmp_curr = freetable->table[i];
        DataItem *tmp_next = tmp_curr;
        while(tmp_next) {
            tmp_next = tmp_next->next;
            free(tmp_curr);
            tmp_curr = tmp_next;
        }
    }
    free(freetable);
}
