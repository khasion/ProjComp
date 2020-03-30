#include "table.h"

int func_id = 0;

DataItem* table_lookup(char* name, char* type, int value, int scope, int funcscope, int line){
  	int insert_flag = 0;
  	int cmp;
  	int cmp2;
  	DataItem* ret = NULL;
  	DataItem* tmp = symtable->table[hash_function(name)];
  	DataItem* tmp2;
  	if(tmp->value == -1){
    		if(value == 0 && scope == 0) {
      			ret=table_insert(name, strdup("[global variable]"), 0, scope, funcscope, line);
    		}
		else if (value == 1 && scope == 0) {
      			ret=table_insert(name, strdup("[global variable]"), 0, scope, funcscope, line);
    		} 
		else if(value == 0  && scope > 0) {
       			ret=table_insert(name, strdup("[variable]"), 0 , scope, funcscope, line);
    		} 
		else if(value == 1) {
       			ret=table_insert(name, strdup("[local variable]"), 1 , scope, funcscope, line);
		} 
		else if (value == 2 ) {
      			printf("ERROR : No global variable '::%s' exists at Line:%d \n" ,name , line);
      			insert_flag = 1;
      			ret = tmp;
    		} else if(value == 3) {
      			char* func_name= (char*)malloc(30);
      			sprintf(func_name, "_f_%d", func_id);
      			ret=table_insert(func_name, strdup("[userfunc noname]"), 3, scope, funcscope, line);
      			func_id= func_id + 1;
    		}
		else if (value == 4) {
       			ret=table_insert(name, strdup("[userfunc]"), 4, scope, funcscope, line);
    		}
		else if (value == 5) {
       			ret=table_insert(name, strdup("[formal argument]"), 5, scope, funcscope, line);
    		}
		else if (value == 6) {
       			ret=table_insert(name, strdup("[formal argument]"), 6, scope, funcscope, line);
    		}
  	} else{
    		cmp = strcmp(tmp->name, name);
    		insert_flag=0;
    		if(cmp== 0 && (value == 5 || value == 6 || value == 1) && tmp->value== 7 ) {
      			printf("Collision with '%s' library function at line: %d\n", name , line);
      			insert_flag = 1;
      			ret = tmp;
    		}
		else if(cmp ==  0 && value == 4 && tmp->value == 7) {
      			printf("User function '%s',Collision with '%s' library function at line: %d\n", tmp->name , name , line);
      			insert_flag = 1;
      			ret = tmp;
    		}
		else if (cmp == 0 && value == 1 && tmp->value !=7) {
      			ret = table_insert(name, strdup("[local variable]"), 1, scope, funcscope, line);
    		}
    		while(tmp->value != -1) {
      			if(cmp==0 && tmp->scope == 0 && scope == 0) {
        			insert_flag = 1;
        			ret = tmp;
      			}
			else if(value ==  1 && cmp==0 && tmp->scope == scope) {
        			insert_flag = 1;
        			ret = tmp;
      			}
			else if(value == 2 && cmp==0 && tmp->scope == 0) {
        			insert_flag = 1;
        			ret = tmp;
      			}
			else if(scope > 0 && value == 0 ) {
        			tmp2 = symtable->table[hash_function(name)];
        			cmp2 = strcmp(tmp2->name, name);
        			int tmp_scope = scope;
        			while(tmp_scope != -1) {
          				while(tmp2->value != -1) {
             					if(cmp2==0 && tmp_scope == tmp2->scope) {
              						insert_flag = 1;
              						ret = tmp2;
              						break;
            					}
            					tmp2=tmp2->next;
          				}
          				tmp2 = symtable->table[hash_function(name)];
          				tmp_scope--;
        			}
      			}
      			if (value == 4 && cmp==0 && tmp->scope == scope && tmp->value != 4 && tmp->value !=7) {
        			printf("Error: Variable '%s' already defined at Line: %d \n" ,name , tmp->line );
        			insert_flag = 1;
        			ret = tmp;
        			break;
      			}
      			if (value == 4 && cmp==0 && tmp->scope == scope && tmp->value == 4 ) {
        			printf("Error: Collision with function named '%s' defined at line %d \n" , name , tmp->line );
        			insert_flag = 1;
        			ret = tmp;
        			break;
      			}
      			if (value == 6 && cmp==0 && tmp->scope == scope) {
         			insert_flag = 1;
         			printf("ERROR: Variable '%s' already defined at Line: %d \n" , name , tmp->line);
         			insert_flag = 1;
         			ret = tmp;
         			break;
      			}
      			if((value==0 || value==2 || value == 1)  && cmp==0  && (tmp->value != 4 || tmp->value != 5 || tmp->value != 6) &&  tmp->funcscope < funcscope && tmp->scope != 0) {
        			printf("ERROR:Cannot access '%s' inside function  at Line: '%d'  \n",name  , line);
        			insert_flag = 1;
        			ret = tmp;
        			break;
      			}
      			tmp = tmp->next;
    		}
  		if(insert_flag == 0) {
    			if(value == 0 && scope == 0){
      				ret=table_insert(name, strdup("[global variable]"), 0, scope, funcscope, line);
    			}
			else if(value == 0 && scope > 0) {
      				ret= table_insert(name, strdup("[variable]"), 0, scope, funcscope, line);
    			} 
			else if (value == 4) {
      				ret= table_insert(name, strdup("[userfunc]"), 4, scope, funcscope, line);
    			}else if (value == 5) {
      				ret= table_insert(name, strdup("[formal argument]"), 5, scope, funcscope, line);
    			}else if (value == 6) {
      				ret= table_insert(name, strdup("[formal argument]"), 6, scope, funcscope, line);
    			}
  		}
	}
  	return ret;
}

SymTable *create_new_symtable() {
    	unsigned int i;
    	SymTable *new_sym = (SymTable*) malloc(sizeof(SymTable*));
    	new_sym->table = (DataItem**) malloc(509*sizeof(DataItem));
    	new_sym->size = 0;
    	new_sym->buckets = 509;
    	for (i=0; i<new_sym->buckets; i++) {
        	new_sym->table[i] = (DataItem*) malloc(sizeof(DataItem));
        	new_sym->table[i]->value = -1;
        	new_sym->table[i]->next = NULL;
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
    	unsigned int i, new_size = get_next_size(symtable->size);

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
            		temp = temp->next;
        	}
    	}
    	free_table(old_sym);
}

DataItem* table_insert(char* name, const char* type, int value, int scope, int funcscope, int line){
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
    	if(scope_head == NULL || (scope_head->scope >= new_item->scope && new_item->value == 7)){
      		new_item->scopenext = scope_head;
      		scope_head = new_item;
    	} else{
      		tmp = scope_head;
      		while(tmp->scopenext != NULL && (tmp->scope < new_item->scope  || tmp->value == 7)){
        		tmp = tmp->scopenext;
      		}
      		new_item->scopenext = tmp->scopenext;
      		tmp->scopenext = new_item;
    	}
    	return new_item;
}

void print_table() {
   	int i=-1 ;
    	DataItem* tmp = scope_head;
    	while(tmp != NULL){
      		if(tmp->scope > i) printf("--------------------------Scope #%d -------------------------- \n" ,++i);
      		printf("\"%s\" %s (line %d) (scope %d) (hide %d)\n", tmp->name, tmp->type,tmp->line, tmp->scope , tmp->hide);
      		tmp = tmp->scopenext;
    	}
}

void hide(int scope) {
  	DataItem *temp1 = scope_head;
  	while (temp1) {
    		if (temp1->scope == scope ) temp1->hide = true;
    		temp1 = temp1->scopenext;
  	}
}

DataItem* create_item(char* name, const char* type, int value, int scope, int funcscope, int line){
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
    	unsigned int i;
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

DataItem* table_get(char* name, unsigned int scope) {
  	assert(name);
  	assert(scope >= 0);
  	DataItem* temp = symtable->table[hash_function(name)];
  	while(temp) {
    		if (strcmp(temp->name, name) == 0 && temp->scope == scope) {
      			return temp;
    		}
    		temp = temp->next;
  	}
  	return NULL;
}
