#include <stdio.h>
#include <stdlib.h>
#include "StackByCircular.h"
#include "CLinked.h"

void StackInit(Stack* pstack)
{
	pstack->plist = (List*)malloc(sizeof(List));
	ListInit(pstack->plist);
}

int SIsEmpty(Stack* pstack)
{
	if (LCount(pstack->plist)==0)
		return TRUE;
	else
		return FALSE;
}

void SPush(Stack* pstack, Data data)
{
	LInsertFront(pstack->plist, data);
}
Data SPop(Stack* pstack)
{	
	Data rdata;
	LFirst(pstack->plist, &rdata);
	LRemove(pstack->plist);
	return rdata;
}
Data SPeek(Stack* pstack)
{

	Data data;
	LFirst(pstack->plist, &data);
	return data;
}