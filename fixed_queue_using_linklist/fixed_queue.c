#include "fixed_queue.h"

Queue* createQueue(int size){
	Queue* queue = (Queue*) malloc(sizeof(Queue));
	queue->linklist = createLinkList(queue->linklist);
	queue->front = 0;
	queue->rear = 0;
	queue->max_size = size;
	return queue;
}

int isEmpty(Queue *queue){
	if((queue->front == queue->rear) && (queue->rear == 0))return 1;
	else return 0;
}

int isFull(Queue *queue){
	if (queue->front == (queue->rear+1) % queue->max_size)return 1;
	else return 0;
}

void insertItem(Queue* queue, int value){
	if(isFull(queue))return;
	queue->rear = countNumberOfNodes(queue->linklist);
	if(queue->front == 0)queue->front = 1;
	insertDataInLinkedList(queue->linklist, queue->rear, value);
}

void removeItem(Queue* queue){
	if(isEmpty(queue))return;
	deleteDataFromLinkList(queue->linklist, queue->front);
	queue->rear = countNumberOfNodes(queue->linklist);
}