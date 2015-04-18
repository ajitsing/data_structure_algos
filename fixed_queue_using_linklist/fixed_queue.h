#include <stdio.h>
#include "linkedlist.h"

typedef struct{
	LinkList *linklist;
	int front;
	int rear;
	int max_size;
} Queue;

Queue* createQueue(int size);
void insertItem(Queue* queue, int value);
void removeItem(Queue* queue);
int isEmpty(Queue *queue);
int isFull(Queue *queue);