#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef long long int lint;

typedef struct stack {
    lint* stkarr;
    lint top;
    lint size;
} stack;

stack* CreateStack(lint size) {
    stack* new_stack = (stack*)malloc(sizeof(stack));
    new_stack->size = size;
    new_stack->top = -1;
    new_stack->stkarr = (lint*)malloc(sizeof(lint)*size);
    return new_stack;
}

void push(stack* S, lint val) {
    S->stkarr[++(S->top)] = val;
}

lint pop(stack* S) {
    if(S->top == -1) {
        printf("--Stack is empty--\n");
        return INT_MIN;
    } else {
        lint popped_val = S->stkarr[S->top--];
        return popped_val;
    }
}

//utility function:
void PrintStack(stack* S) {
    for(lint i = 0; i <= S->top; i++) printf("%lld ", S->stkarr[i]);
    printf("\n");
}

int main() {
    stack* S = CreateStack(100);
    push(S, 10);
    push(S, 11);
    push(S, 12);
    push(S, 13);
    push(S, 14);
    PrintStack(S);
    pop(S);
    PrintStack(S);
    pop(S);
    PrintStack(S);
    pop(S);
    PrintStack(S);
    return 0;       
}