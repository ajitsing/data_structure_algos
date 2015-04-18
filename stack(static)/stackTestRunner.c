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
		test_create_stack_for_20_elements();
	tearDown();

	setup();
		test_stack_is_not_full();
	tearDown();

	setup();
		test_stack_is_empty();
	tearDown();

	setup();
		test_push_5_in_stack();
	tearDown();

	setup();
		test_push_10_in_stack();
	tearDown();

	setup();
		test_push_15_in_stack();
	tearDown();

	setup();
		test_push_20_in_stack();
	tearDown();

	setup();
		test_push_25_in_stack();
	tearDown();

	setup();
		test_pop_25TheLastElement_from_stack();
	tearDown();

	setup();
		test_pop_20TheLastElement_from_stack();
	tearDown();


	summarizeTestCount();
	fixtureTearDown();
	return 0;
}

void setup(){}

void tearDown(){}

void fixtureSetup(){}

void fixtureTearDown(){}
