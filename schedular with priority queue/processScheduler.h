#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define REAR processBlock->rear
#define FRONT processBlock->front
#define PROCESS processBlock->process
#define MAX processBlock->max_size

typedef struct{
	char name[20];
	int Time;
	int priority;
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
int addProcessToProcessBlock(ProcessBlock* processBlock, string process_name, int process_time, int priority);
int isEmpty(ProcessBlock* processBlock);
void sortProcess(ProcessBlock* processBlock);
void clearProcessBlock(ProcessBlock *processBlock);
void processingProcessBlock(ProcessBlock* processBlock);