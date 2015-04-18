#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INCREMENT_FRONT processBlock->front = (processBlock->front+1) % processBlock->max_size;
#define INCREMENT_REAR 	processBlock->rear = (processBlock->rear+1) % processBlock->max_size;

typedef struct{
	char name[20];
	int Time;
}Process;

typedef struct{
	int max_size;
	int rear;
	int front;
	int cpuTimeSlice;
	Process *process;
}ProcessBlock;

typedef char* string;

ProcessBlock* createProcessBlock(int size);
ProcessBlock* addProcessToProcessBlock(ProcessBlock* processBlock, string process_name, int process_time);
ProcessBlock* processingProcessBlock(ProcessBlock* processBlock);
ProcessBlock* removeProcess(ProcessBlock* processBlock,int front);
int isEmpty(ProcessBlock* processBlock);