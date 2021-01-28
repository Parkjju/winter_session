#ifndef _HEAP_QUEUE_H_
#define _HEAP_QUEUE_H_

#define TRUE 1
#define FALSE 0
#define HEAP_LEN 100

typedef char HData;
typedef int Priority;

typedef int PriorityComp(HData d1, HData d2);

typedef struct _heap
{
	PriorityComp* comp;
	int numOfData;
	HData heapArr[HEAP_LEN];
}Heap;

void HeapInit(Heap* ph,PriorityComp pr);
int HIsEmpty(Heap* ph);

void HInsert(Heap* ph, HData data);
HData HDelete(Heap* ph);
#endif
