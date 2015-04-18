int maxTime(ProcessBlock* processBlock){
	int max = 0;
	for (processBlock->front = 0; processBlock->front <= processBlock->rear; processBlock->front++){
		if(processBlock->process[processBlock->front].Time > max){
			max = processBlock->process[processBlock->front].Time;
		}
	}
	return max;
}

ProcessBlock* deQueue(ProcessBlock* processBlock,int front, int max){
	printf("process-->  %s is ended\n",processBlock->process[front].name );getchar();
	processBlock->process[processBlock->front].Time = 20;
	processBlock->front = (processBlock->front+1) % processBlock->max_size;
	return processBlock; 
}

ProcessBlock* processingProcessBlock(ProcessBlock* processBlock){
	int count = 0,max;
	while(processBlock->front <= (processBlock->rear+1) % processBlock->max_size){
		if(isEmpty(processBlock)){printf("under Flow\n"); return processBlock;}
		else{
			processBlock->process[processBlock->front].Time -= processBlock->cpuTimeSlice;
			if(processBlock->process[processBlock->front].Time <= 0){
				if(count == 4)return processBlock;
				if(count == 0)max = maxTime(processBlock)+5;
				processBlock = deQueue(processBlock,processBlock->front,max);			
				processBlock->rear = (processBlock->rear+1) % processBlock->max_size;
				count++;
			}
			else{
				processBlock->rear = (processBlock->rear+1) % processBlock->max_size;
				processBlock->front = (processBlock->front+1) % processBlock->max_size;
			}
		}
	}
	return processBlock;
}


void displayProcessBlock(ProcessBlock* processBlock){
	printf("\n\n\n");
	for (processBlock->front = 0; processBlock->front <= processBlock->rear; processBlock->front++){
		printf("Process->%-10s   Time->%-d\n",processBlock->process[processBlock->front].name, processBlock->process[processBlock->front].Time);
	}
	printf("\n\n\n");
}

$ t.sh
********* Starting tests

        test_create_a_process_controller_for_6_processes
        test_add_a_process_Sublime_for_6sec
        test_add_a_process_Vlc_for_5sec
        test_add_a_process_Gcc_for_10sec
        test_add_a_process_Calculator_for_4sec
        test_add_a_process_Browser_for_8sec
        test_add_a_process_MicrosoftWord_for_15sec
coool--->    0

coool--->Vlc    5

coool--->Gcc    10

coool--->Calculator    4

coool--->Browser    8

coool--->MicrosoftWord    15

coool--->Sublime    6

coool--->Vlc    3

coool--->Gcc    8

coool--->Calculator    2

process-->  Calculator is ended

coool--->Browser    6

coool--->MicrosoftWord    13

coool--->Sublime    4

coool--->Vlc    1

process-->  Vlc is ended

coool--->Gcc    6

coool--->finished    0

coool--->Browser    4

coool--->MicrosoftWord    11

coool--->Sublime    2

process-->  Sublime is ended

coool--->finished    -1

coool--->Gcc    4

coool--->finished    0

coool--->Browser    2

process-->  Browser is ended

coool--->MicrosoftWord    9

coool--->finished    0

coool--->finished    -1

coool--->Gcc    2

process-->  Gcc is ended

coool--->finished    0

coool--->finished    0

coool--->MicrosoftWord    7

coool--->finished    0

coool--->finished    -1

coool--->finished    0

coool--->finished    0

coool--->finished    0

coool--->MicrosoftWord    5

coool--->finished    0

coool--->finished    -1

coool--->finished    0

coool--->finished    0

coool--->finished    0

coool--->MicrosoftWord    3

coool--->finished    0

coool--->finished    -1

coool--->finished    0

coool--->finished    0

coool--->finished    0

coool--->MicrosoftWord    1

process-->  MicrosoftWord is ended

        test_start_processing

********* Ran 8 tests passed 8 failed 0

ajitsing@AJITHS ~/Dropbox/programming/programming/DSC/processController
$

ajitsing@AJITHS ~/Dropbox/programming/programming/DSC/processController
$