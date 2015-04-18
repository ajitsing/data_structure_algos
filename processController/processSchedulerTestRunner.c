#include <stdio.h>

int testCount=0;
int passCount=0;

void setup();
void tearDown();

void fixtureSetup();
void fixtureTearDown();

void testStarted(char* name){
	printf("\t%s\n",name);
}

void resetTestCount(){
	testCount=0;
	passCount=0;
	printf("********* Starting tests\n\n");
}

void summarizeTestCount(){
	printf("\n********* Ran %d tests passed %d failed %d\n",testCount,passCount,testCount-passCount);
}

void incrementTestCount(){
	testCount++;
}

void incrementPassCount(){
	passCount++;
}

void testFailed(){
	printf("\t\t*** failed\n");
}

int main(){
	fixtureSetup();
	resetTestCount();

	setup();
		test_create_a_process_controller_for_6_processes();
	tearDown();

	setup();
		test_add_a_process_Sublime_for_6sec();
	tearDown();

	setup();
		test_add_a_process_Vlc_for_5sec();
	tearDown();

	setup();
		test_add_a_process_Gcc_for_10sec();
	tearDown();

	setup();
		test_add_a_process_Calculator_for_4sec();
	tearDown();

	setup();
		test_add_a_process_Browser_for_8sec();
	tearDown();

	setup();
		test_add_a_process_MicrosoftWord_for_15sec();
	tearDown();

	setup();
		test_start_processing();
	tearDown();


	summarizeTestCount();
	fixtureTearDown();
	return 0;
}

void setup(){}

void tearDown(){}

void fixtureSetup(){}

void fixtureTearDown(){}
