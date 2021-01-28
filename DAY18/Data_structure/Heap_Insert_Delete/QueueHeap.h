#ifndef _HEAP_QUEUE_H_
#define _HEAP_QUEUE_H_

#define TRUE 1
#define FALSE 0
#define HEAP_LEN 100

typedef char HData;
typedef int Priority;

typedef struct _HeapElem
{
	Priority pr;
	HData data;
}HeapElem;

typedef struct _heap
{
	int numOfData;
	HeapElem HeapArr[HEAP_LEN];
}Heap;

void HeapInit(Heap* ph);
int HIsEmpty(Heap* ph);

void HInsert(Heap* ph, HData data, Priority pr);
HData HDelete(Heap* ph);
#endif
