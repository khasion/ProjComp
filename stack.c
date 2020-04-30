#include "stack.h"

Stack* push(Stack* s, int val) {
     Stack* new_stack;
     new_stack = (Stack*) malloc(sizeof(Stack));
     new_stack->val = val;
     new_stack->next = NULL;
     if (s == NULL) {
          s = new_stack;
     }
     else {
          new_stack->next = s;
          s = new_stack;
     }
     return s;
}

int pop(Stack *s) {
     int value = 0;
     if (s) {
          value = s->val;
          s = s->next;
     }
     return value;
}

int pop_and_top(Stack* s) {
     if (s) {
          s = s->next;
          if (s) return s->val;
     }
     return 0;
}