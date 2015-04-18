#include "processScheduler.h"

ProcessBlock* createProcessBlock(int size){
	ProcessBlock *processBlock = (ProcessBlock*)malloc(sizeof(ProcessBlock));
	processBlock->process = (Process*)malloc(sizeof(Process)*size);
	processBlock->front = -1;
	processBlock->rear = -1;
	processBlock->max_size = size;
	processBlock->cpuTimeSlice = 2;
	return processBlock;
}

int isEmpty(ProcessBlock* processBlock){
	if(processBlock->front == processBlock->rear && processBlock->front == -1)return 1;
	else return 0;
}

int isFull(ProcessBlock* processBlock){
	if(processBlock->front == (processBlock->rear+1) % processBlock->max_size)printf("overFlow\n");
	else return 0;
}


ProcessBlock* addProcessToProcessBlock(ProcessBlock* processBlock, string process_name, int process_time){
	if(isFull(processBlock))return processBlock;
	else{
		INCREMENT_REAR
		processBlock->process[processBlock->rear].Time = process_time;
		strcpy(processBlock->process[processBlock->rear].name, process_name);
		if(processBlock->front == -1)processBlock->front = 0;
	}
	return processBlock;
}

int totalProcesses(ProcessBlock* processBlock){
	int max = 0;
	for (processBlock->front = 0; processBlock->front <= processBlock->rear; processBlock->front++)max++;
	return max;
}

ProcessBlock* removeProcess(ProcessBlock* processBlock,int front){
	char ans;
	printf("process-->  %s is ended\n",processBlock->process[front].name );getchar();
	printf("Do you want to enter another process press y/n\n");
	scanf("%c",&ans);
	if(ans == 'y' || ans == 'Y'){
		printf("Enter the name of process\n");
		scanf("%s",processBlock->process[processBlock->front].name);
		printf("Enter the time\n");
		scanf("%d",&processBlock->process[processBlock->front].Time);
	}
	else{
		strcpy(processBlock->process[processBlock->front].name,"finished");
		INCREMENT_FRONT
	}
	return processBlock; 
}

ProcessBlock* processingProcessBlock(ProcessBlock* processBlock){
	int count = 0,numberOfProcesses;
	numberOfProcesses = totalProcesses(processBlock);
	while(count != numberOfProcesses){
		if(strcmp(processBlock->process[processBlock->front].name,"finished") == 0)INCREMENT_FRONT
		else{
			processBlock->process[processBlock->front].Time -= processBlock->cpuTimeSlice;
			if(processBlock->process[processBlock->front].Time == 0 ||  processBlock->process[processBlock->front].Time == -1){
				processBlock = removeProcess(processBlock,processBlock->front);			
				count++;
			}
			else{
				INCREMENT_FRONT
				INCREMENT_REAR
			}
		}
	}
	return processBlock;
}