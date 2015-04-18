#include <stdio.h>

typedef struct{
	int max_size;
	int rear;
	int front;
	int * array;
}Queue;

Queue* createQueue(Queue* queue,int size);
int isEmpty(Queue* queue);
int isFull(Queue* queue);
Queue* insertElement(Queue* queue, int element);
int deleteElement(Queue* queue);
void displayQueue(Queue* queue);
