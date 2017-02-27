#ifndef SOFTSYS_ASOCIAL_AARDVARK_STACK_H
#define SOFTSYS_ASOCIAL_AARDVARK_STACK_H

#define STACK_MAX 10000

struct Stack {
    int     data[STACK_MAX];
    int     size;
};
typedef struct Stack Stack;

void Stack_Init(Stack *S);
int Stack_Top(Stack *S);
void Stack_Push(Stack *S, int d);
void Stack_Pop(Stack *S);

#endif