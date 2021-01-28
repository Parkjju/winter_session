#include <stdio.h>
#include "HeapImprove.h"


int GetHiPriChildIDX(Heap* ph, int idx)
{
	if (GetLChildIDX(idx) > ph->numOfData)
		return 0;
	else if (GetLChildIDX(idx) == ph->numOfData)
		return GetLChildIDX(idx);
	else
	{
		if (ph->comp(ph->heapArr[GetLChildIDX(idx)],ph->heapArr[GetRChildIDX(idx)])<0)//오른쪽 자식노드의 우선순위가 높을때
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

void HeapInit(Heap* ph,PriorityComp pr)
{
	ph->numOfData = 0;
	ph->comp = pr;
}

int HIsEmpty(Heap* ph)
{
	if (ph->numOfData == 0)
		return TRUE;
	else
		return FALSE;
}

void HInsert(Heap* ph, HData data)
{
	int idx = ph->numOfData + 1; // 새 노드 저장할 인덱스 값 저장

	while (idx != 1)
	{
		if (ph->comp(data,ph->heapArr[GetParentIDX(idx)])>0)
		{
			ph->heapArr[idx] = ph->heapArr[GetParentIDX(idx)];
			idx = GetParentIDX(idx);
		}
		else
			break;

	}
	ph->heapArr[idx] = data;
	ph->numOfData += 1;
}
HData HDelete(Heap* ph)
{
	HData retdata = ph->heapArr[1];
	HData last = ph->heapArr[ph->numOfData];
	int parentidx = 1;
	int childidx;

	while (childidx = GetHiPriChildIDX(ph, parentidx))
	{
		if (ph->comp(last,ph->heapArr[childidx])>0)
			break;
		else
		{
			ph->heapArr[parentidx] = ph->heapArr[childidx];
			parentidx = childidx;
		}
	}

	ph->heapArr[parentidx] = last;
	ph->numOfData -= 1;
	return retdata;
}