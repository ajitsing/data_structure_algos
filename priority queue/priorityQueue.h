#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define REAR queue->rear
#define FRONT queue->front
#define PROCESS queue->process
#define MAX queue->max_size

typedef struct{
	char name[20];
	int Time;
	int priority;
}Process;

typedef struct{
	int max_size;
	int rear;
	int front;
	Process *process;
}PriorityQueue;

PriorityQueue* createQueue(int size);
int enQueue(PriorityQueue* queue, Process newProcess);
Process deQueue(PriorityQueue* queue);
void clearQueue(PriorityQueue* queue);