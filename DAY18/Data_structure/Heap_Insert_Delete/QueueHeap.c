#include <stdio.h>
#include "QueueHeap.h"


int GetHiPriChildIDX(Heap* ph, int idx)
{
	if (GetLChildIDX(idx) > ph->numOfData)
		return 0;
	else if (GetLChildIDX(idx) == ph->numOfData)
		return GetLChildIDX(idx);
	else
	{
		if (ph->HeapArr[GetLChildIDX(idx)].pr > ph->HeapArr[GetRChildIDX(idx)].pr)
			return GetRChildIDX(idx);
		else
			return GetLChildIDX(idx);
	}
}
int GetParentIDX(int idx)
{
	return idx / 2;
}

int GetLChildIDX(int idx)
{
	return idx * 2;
}

int GetRChildIDX(int idx)
{
	return GetLChildIDX(idx) + 1;
}

void HeapInit(Heap* ph)
{
	ph->numOfData = 0;
}

int HIsEmpty(Heap* ph)
{
	if (ph->numOfData == 0)
		return TRUE;
	else
		return FALSE;
}

void HInsert(Heap* ph, HData data, Priority pr)
{
	HeapElem newElem = { pr,data };//새 노드 생성
	int idx = ph->numOfData + 1; // 새 노드 저장할 인덱스 값 저장

	while (idx != 1)
	{
		if (pr < (ph->HeapArr[GetParentIDX(idx)].pr))
		{
			ph->HeapArr[idx] = ph->HeapArr[GetParentIDX(idx)];
			idx = GetParentIDX(idx);
		}
		else
			break;

	}
	ph->HeapArr[idx] = newElem;
	ph->numOfData += 1;
}
HData HDelete(Heap* ph)
{
	HData retdata = ph->HeapArr[1].data;
	HeapElem Hlem = ph->HeapArr[ph->numOfData];

	int parentidx = 1;
	int childidx;

	while (childidx = GetHiPriChildIDX(ph,parentidx))
	{
		if (Hlem.pr <= ph->HeapArr[childidx].pr)
			break;
		else
		{
			ph->HeapArr[parentidx] = ph->HeapArr[childidx];
			parentidx = childidx;
		}
	}

	ph->HeapArr[parentidx] = Hlem;
	ph->numOfData -= 1;
	return retdata;
}