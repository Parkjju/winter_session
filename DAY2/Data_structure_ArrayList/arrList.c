#include <stdio.h>
#include "arrList.h"

void ListInit(List* plist)
{
	plist->curPosition = -1;
	plist->numOfData = 0;
}

void LInsert(List* plist, LData data)
{
	plist->numOfData++;
	plist->curPosition++;
	plist->arr[plist->curPosition] = data;
}

int LFirst(List* plist, LData* pdata)
{
	if (plist->numOfData == 0)
		return 0;
	else
	{
		plist->curPosition = 0;
		(*pdata) = plist->arr[plist->curPosition];
		return 1;
	}
}

int LNext(List* plist, LData* pdata)
{
	if (plist->curPosition == (plist->numOfData) - 1)
		return 0;
	else
	{
		plist->curPosition++;
		(*pdata) = plist->arr[plist->curPosition];
		return 1;
	}
}

LData LRemove(List* plist)
{
	int num = plist->numOfData;
	int i = plist->curPosition;
	int j = 0;
	LData rdata = plist->arr[i];

	for (j = i; j<num-1; j++)
	{
		plist->arr[j] = plist->arr[j+1];
	}
	(plist->curPosition)--;
	(plist->numOfData)--;
	return rdata;
}

int LCount(List* plist)
{
	return plist->numOfData;
}