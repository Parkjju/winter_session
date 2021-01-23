#include <stdlib.h>
#include <stdio.h>
#include "queueList.h"


void QueueInit(Queue* pq)
{
	pq->front = NULL;
	pq->rear = NULL;
}
int QIsEmpty(Queue* pq)
{
	if (pq->front==NULL)
		return TRUE;
	else
		return FALSE;
}

void Enqueue(Queue* pq, Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->next = NULL;
	newNode->data = data;

	if (QIsEmpty(pq))
	{
		pq->front = newNode;
		pq->rear = newNode;
	}

	pq->rear->next = newNode;
	pq->rear = newNode;

}
Data Dequeue(Queue* pq)
{
	Node* rpos = pq->front;
	Data rdata = pq->front->data;

	if (QIsEmpty(pq))
	{
		printf("Queue memory error!\n");
		exit(-1);
	}
	pq->front = pq->front->next;
	free(rpos);

	return rdata;
}
Data QPeek(Queue* pq)
{
	return pq->front->data;
}