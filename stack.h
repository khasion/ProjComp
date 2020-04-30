#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
     int            val;
     struct stack*  next;
}Stack;

Stack*    push(Stack** s, int val);
int       pop(Stack** s);
int       pop_and_top(Stack** s);
void      print_stack(Stack** s);