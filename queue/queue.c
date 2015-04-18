#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

Queue* createQueue(Queue *queue,int size){
	queue = (Queue*)malloc(sizeof(queue));
	queue->array = (int*)malloc(sizeof(int)*size);
	queue->rear = -1;
	queue->front = -1;
	queue->max_size = size-1;
	return queue;
}

int isEmpty(Queue *queue){
	if((queue->front == queue->rear) && (queue->rear == -1))return 1;
	else return 0;
}

int isFull(Queue *queue){
	if (queue->front == (queue->rear+1) % queue->max_size)return 1;
	else return 0;
}

Queue* insertElement(Queue *queue, int element){
	if(isFull(queue))printf("overflow\n");
	else{
		queue->rear += 1;
		queue->array[queue->rear] = element;
		if(queue->front == -1)queue->front=0;
	}
	return queue;
}

int deleteElement(Queue *queue){
	if(isEmpty(queue))printf("overflow\n");
	else{
		if(queue->front == queue->rear)queue->front = queue->rear = -1;
		else queue->front= (queue->front+1) % queue->max_size;
	}
	return queue->array[queue->front-1];
}

void displayQueue(Queue *queue){
	for (;queue->front <= queue->rear; queue->front++) printf("%d\t",queue->array[queue->front]);
}