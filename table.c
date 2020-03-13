#include "table.h"
int func_name =0;
DataItem* table_lookup(char* name, char* type, int value, int scope, int funcscope, int line){

  int insert_flag = 0;

  int x;
  int y;
  DataItem* tmp = symtable->table[hash_function(name)];
  DataItem* tmp2;
  if(tmp->name == NULL ){
    if(value == 0 && scope == 0){
      table_insert(name, "[global variable]", 0, scope, funcscope, line);
    } else if(value == 0 && scope > 0){
      table_insert(name, "[variable]", 0, scope, funcscope, line);
    } else if(value == 1){
      table_insert(name, "[local variable]", 0, scope, funcscope, line);
    } else if (value == 2  ){
      printf("ERROR: Can't find global variable %s\n",name);
    } else if(value == 3){
      char* natalia=malloc(30);
      sprintf(natalia, "_f_%d", func_name);
      table_insert(natalia, "[userfunc noname]", 0, scope, funcscope, line);
      func_name= func_name + 1;
    }  else if (value == 4){
      table_insert(name, "[userfunc]", 0, scope, funcscope, line);
    }else if (value == 5){
      table_insert(name, "[formal argument]", 0, scope, funcscope, line);
    }else if (value == 6){
      table_insert(name, "[formal argument]", 0, scope, funcscope, line);
    }
  }
   else if (tmp->name != NULL) {

    x = strcmp(tmp->name, name);
    while(tmp!=NULL){

      if(x==0 && tmp->scope == 0 && scope == 0){
        insert_flag = 1;
      } else if(value ==  1 && x==0 && tmp->scope == scope){
        insert_flag = 1;
      } else if(value == 2 && x==0 && tmp->scope == 0){
        insert_flag = 1;
      } else if(scope > 0 && value == 0) {
        tmp2 = symtable->table[hash_function(name)];
        y = strcmp(tmp2->name, name);
        int tmp_scope = scope;
        while(tmp_scope != -1){
          while(tmp2!=NULL){
            if(y==0 && tmp_scope == tmp2->scope  && funcscope == tmp2->funcscope){
              insert_flag = 1;
            }
            tmp2=tmp2->next;
          }
          tmp2 = symtable->table[hash_function(name)];
          tmp_scope--;
      }
    }
    if (value == 4 && x==0 && tmp->scope == scope){
      insert_flag = 1;
      printf("ERROR:Same name variable and function  %s\n",name);
    }
    if (value == 6 && x==0 && tmp->funcscope == funcscope){
      insert_flag = 1;
      printf("ERROR: Same name with variable at same scope %s\n",name);
      break;
    }
    tmp = tmp->next;
  }
  if(insert_flag == 0){
    if(value == 0 && scope == 0){
      table_insert(name, "[global variable]", 0, scope, funcscope, line);
    } else if(value == 0 && scope > 0){
      table_insert(name, "[variable]", 0, scope, funcscope, line);
    } else if(value == 1){
      table_insert(name, "[local variable]", 0, scope, funcscope, line);
    } else if (value == 4){
      table_insert(name, "[userfunc]", 0, scope, funcscope, line);
    }else if (value == 5){
      table_insert(name, "[formal argument]", 0, scope, funcscope, line);
    }else if (value == 6){
      table_insert(name, "[formal argument]", 0, scope, funcscope, line);
    }
  }
  }

  return NULL;
}

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

int hash_function(char* name){
  //printf("%d\n",scope % symtable->buckets );
  size_t ui;
  unsigned int uiHash = 0U;
  for (ui = 0U; name[ui] != '\0'; ui++){
  	uiHash = uiHash * MAX_HASH + name[ui];
  }

  return uiHash%symtable->buckets;
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
            // table_insert(temp->name, temp->type, temp->value, temp->scope,
            // temp->line);
            temp = temp->next;
        }
    }
    free_table(old_sym);
}

void table_insert(char* name, char* type, void* value, int scope, int funcscope, int line){
    DataItem *new_item = create_item(name, type, value, scope, funcscope, line);
    DataItem* tmp;
    int hash;
    if (symtable->size == symtable->buckets-1) {
        expand();
    }

    hash = hash_function(name);

    if (symtable->table[hash] == NULL) {
        symtable->table[hash] = new_item;
        symtable->table[hash]->next = NULL;
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
      while(tmp->next != NULL && tmp->next->scope <= new_item->scope){
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
  //  int i ;
    DataItem* tmp = scope_head;
    // for (i = 0 ; i < symtable->buckets; i++) {
    //     DataItem* temp = symtable->table[i];
    //     while (temp) {
    //         if(temp->name != NULL){
    //           printf("\"%s\" %s (line %d) (scope %d)\n", temp->name, temp->type,temp->line, temp->scope);
    //
    //         }
    //         temp = temp->next;
    //     }
    // }
    while(tmp != NULL){
      //printf("%d %s se scopelist\n",tmp->scope,tmp->name);
      printf("\"%s\" %s (line %d) (scope %d)\n", tmp->name, tmp->type,tmp->line, tmp->scope);
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
    int i;
    for (i=0; i<scope; i++) {
        DataItem *temp = symtable->table[i];
        while(temp) {
            temp->hide = true;
            temp = temp->next;
        }
    }
}


DataItem* create_item(char* name, char* type, void* value, int scope, int funcscope, int line){
    DataItem* new_data;
    new_data = (DataItem*)malloc(sizeof(DataItem));
    new_data->name = strdup(name);
    new_data->type = strdup(type);
    new_data->value = value;
    new_data->scope = scope;
    new_data->funcscope = funcscope;
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
