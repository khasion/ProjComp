#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
     int            val;
     struct stack*  next;
}Stack;

Stack* breakstack;
Stack* contstack;
Stack* loopcounterstack;
Stack* scopeoffsetstack;

void      push(Stack** s, int val);
int       pop(Stack** s);
int       pop_and_top(Stack** s);
void      print_stack(Stack** s);