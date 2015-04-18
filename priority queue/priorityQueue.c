#include "priorityQueue.h"

PriorityQueue* createQueue(int size){
	PriorityQueue* queue = (PriorityQueue*) malloc(sizeof(PriorityQueue));
	PROCESS = (Process*)malloc(sizeof(Process)*size);
	FRONT = -1;
	REAR = -1;
	MAX = size;
	return queue;
}

int isEmpty(PriorityQueue* queue){
	if(FRONT == REAR && FRONT == -1)return 1;
	else return 0;
}

int isFull(PriorityQueue* queue){
	if(FRONT == (REAR+1) % MAX)return 0;
	else return 0;
}

int enQueue(PriorityQueue* queue, Process newProcess){
	if(isFull(queue))return 0;
	else{
		REAR = (REAR+1) % MAX;
		PROCESS[REAR].Time = newProcess.Time;
		PROCESS[REAR].priority = newProcess.priority;
		strcpy(PROCESS[REAR].name, newProcess.name);
		if(FRONT == -1)FRONT = 0;
	}
	return 1;
}

void sortProcess(PriorityQueue* queue){
	int i,j,flag = 0;
	Process temp;
	for (i = 0; i < MAX; i++){

		flag = 0;

		for (j=0; j < MAX-i-1; j++){

			if(PROCESS[j].priority > PROCESS[j+1].priority){
				temp.priority = PROCESS[j].priority;
				temp.Time = PROCESS[j].Time;
				strcpy(temp.name, PROCESS[j].name);

				PROCESS[j].priority = PROCESS[j+1].priority;
				PROCESS[j].Time = PROCESS[j+1].Time;
				strcpy(PROCESS[j].name,PROCESS[j+1].name);


				PROCESS[j+1].priority = temp.priority;
				PROCESS[j+1].Time = temp.Time;
				strcpy(PROCESS[j+1].name,temp.name);

				flag = 1;
			}
		}
		
		if(flag == 0)break;
	}
}

Process deQueue(PriorityQueue* queue){
	Process deletedProcess;
	sortProcess(queue);

	deletedProcess = PROCESS[FRONT];
	FRONT = (FRONT+1) % MAX;
	return deletedProcess;
}

void clearQueue(PriorityQueue* queue){
	free(PROCESS);
	free(queue);
}