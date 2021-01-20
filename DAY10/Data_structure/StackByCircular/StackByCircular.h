#include "CLinked.h"
#ifndef STACK_BY_CIRCULAR_H
#define STACK_BY_CIRCULAR_H

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct _Stack
{
	List* plist;
}ListStack;

typedef ListStack Stack;

void StackInit(Stack* pstack);
int SIsEmpty(Stack* pstack);

void SPush(Stack* pstack, Data data);
Data SPop(Stack* pstack);
Data SPeek(Stack* pstack);
#endif