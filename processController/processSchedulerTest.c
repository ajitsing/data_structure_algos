#include "sampletestUtils.h"
#include "processScheduler.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

ProcessBlock * processBlock;

void test_create_a_process_controller_for_6_processes(){
	processBlock = createProcessBlock(6);
	ASSERT(processBlock->max_size == 6);
}

void test_add_a_process_Sublime_for_6sec(){
	processBlock = addProcessToProcessBlock(processBlock,"Sublime",6);
	ASSERT(processBlock->process[processBlock->rear].Time == 6 && strcmp(processBlock->process[processBlock->rear].name, "Sublime")==0);
}

void test_add_a_process_Vlc_for_5sec(){
	processBlock = addProcessToProcessBlock(processBlock,"Vlc",5);
	ASSERT(processBlock->process[processBlock->rear].Time == 5 && strcmp(processBlock->process[processBlock->rear].name, "Vlc")==0);
}

void test_add_a_process_Gcc_for_10sec(){
	processBlock = addProcessToProcessBlock(processBlock,"Gcc",10);
	ASSERT(processBlock->process[processBlock->rear].Time == 10 && strcmp(processBlock->process[processBlock->rear].name, "Gcc")==0);
}

void test_add_a_process_Calculator_for_4sec(){
	processBlock = addProcessToProcessBlock(processBlock,"Calculator",4);
	ASSERT(processBlock->process[processBlock->rear].Time == 4 && strcmp(processBlock->process[processBlock->rear].name, "Calculator")==0);
}

void test_add_a_process_Browser_for_8sec(){
processBlock = addProcessToProcessBlock(processBlock,"Browser",8);
	ASSERT(processBlock->process[processBlock->rear].Time == 8 && strcmp(processBlock->process[processBlock->rear].name, "Browser")==0);
}

void test_add_a_process_MicrosoftWord_for_15sec(){
processBlock = addProcessToProcessBlock(processBlock,"MicrosoftWord",15);
	ASSERT(processBlock->process[processBlock->rear].Time == 15 && strcmp(processBlock->process[processBlock->rear].name, "MicrosoftWord")==0);
}

void test_start_processing(){
	processBlock = processingProcessBlock(processBlock);
	ASSERT(1);
}