#include "processScheduler.h"

ProcessBlock* createProcessBlock(int size){
	ProcessBlock *processBlock = (ProcessBlock*)malloc(sizeof(ProcessBlock));
	PROCESS = (Process*)malloc(sizeof(Process)*size);
	FRONT = -1;
	REAR = -1;
	MAX = size;
	processBlock->cpuTimeSlice = 2;
	return processBlock;
}

void clearProcessBlock(ProcessBlock *processBlock){
	free(PROCESS);
	free(processBlock);
}

int isEmpty(ProcessBlock* processBlock){
	if(FRONT == REAR && FRONT == -1)return 1;
	else return 0;
}

int isFull(ProcessBlock* processBlock){
	if(FRONT == (REAR+1) % MAX)return 0;
	else return 0;
}


int addProcessToProcessBlock(ProcessBlock* processBlock, string process_name, int process_time, int priority){
	if(isFull(processBlock))return 0;
	else{
		REAR = (REAR+1) % MAX;
		PROCESS[REAR].Time = process_time;
		PROCESS[REAR].priority = priority;
		strcpy(PROCESS[REAR].name, process_name);
		if(FRONT == -1)FRONT = 0;
	}
	return 1;
}

void sortProcess(ProcessBlock* processBlock){
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

ProcessBlock* removeProcess(ProcessBlock* processBlock,int front){
	char ans;
	printf("process-->  %s is ended\n",PROCESS[front].name );getchar();
	printf("Do you want to enter another process press y/n\n");
	scanf("%c",&ans);
	if(ans == 'y' || ans == 'Y'){
		REAR = FRONT;
		printf("Enter the name of process\n");
		scanf("%s",PROCESS[REAR].name);
		printf("Enter the time\n");
		scanf("%d",&PROCESS[REAR].Time);
		printf("Enter the priority\n");
		scanf("%d",&PROCESS[REAR].priority);
	}
	else FRONT = (FRONT+1) % MAX;
	return processBlock; 
}

void processingProcessBlock(ProcessBlock* processBlock){
	int count = 0;
	while(count != MAX){
		while(PROCESS[FRONT].Time == 0 ||  PROCESS[FRONT].Time == -1){
			PROCESS[FRONT].Time -= processBlock->cpuTimeSlice;
		}
		processBlock = removeProcess(processBlock,FRONT);			
		count++;
	}
}