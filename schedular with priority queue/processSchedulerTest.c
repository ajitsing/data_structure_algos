#include "sampletestUtils.h"
#include "processScheduler.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

ProcessBlock * processBlock = NULL;

void setup(){
	processBlock = createProcessBlock(5);
}

void tearDown(){
	clearProcessBlock(processBlock);
}

void test_add_process_Sublime_Git_Cmd_Vlc(){
	addProcessToProcessBlock(processBlock, "Sublime",10, 3);
	addProcessToProcessBlock(processBlock, "Browser",12, 5);
	addProcessToProcessBlock(processBlock, "Git",8, 4);
	addProcessToProcessBlock(processBlock, "Cmd",6, 2);
	addProcessToProcessBlock(processBlock, "Vlc",4, 1);

	ASSERT(PROCESS[REAR].Time == 4 && PROCESS[3].Time == 6);
}

void test_sort_process_by_priority(){
	addProcessToProcessBlock(processBlock, "Sublime",10, 3);
	addProcessToProcessBlock(processBlock, "Browser",2, 5);
	addProcessToProcessBlock(processBlock, "Git",8, 4);
	addProcessToProcessBlock(processBlock, "Cmd",4, 2);
	addProcessToProcessBlock(processBlock, "Vlc",12, 1);

	sortProcess(processBlock);

	ASSERT(PROCESS[0].priority == 1 && PROCESS[4].priority == 5);
}

void test_execute_the_process(){
	int i;
	addProcessToProcessBlock(processBlock, "Cmd",10, 2);
	addProcessToProcessBlock(processBlock, "Git",10, 4);
	addProcessToProcessBlock(processBlock, "Vlc",10, 1);
	addProcessToProcessBlock(processBlock, "Browser",10, 5);
	addProcessToProcessBlock(processBlock, "Sublime",10, 3);

	sortProcess(processBlock);	

	processingProcessBlock(processBlock);

	ASSERT(1);

}