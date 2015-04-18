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
		test_create_a_queue_of_size_20();
	tearDown();

	setup();
		test_queue_is_empty();
	tearDown();

	setup();
		test_queue_is_not_full();
	tearDown();

	setup();
		test_insert_10_in_queue();
	tearDown();

	setup();
		test_insert_20_in_queue();
	tearDown();

	setup();
		test_insert_30_in_queue();
	tearDown();

	setup();
		test_insert_40_in_queue();
	tearDown();

	setup();
		test_insert_50_in_queue();
	tearDown();

	setup();
		test_delete_10_from_queue();
	tearDown();

	setup();
		test_delete_20_from_queue();
	tearDown();

	setup();
		test_delete_30_from_queue();
	tearDown();

	setup();
		test_insert_10_again_in_queue();
	tearDown();

	setup();
		test_print_queue();
	tearDown();


	summarizeTestCount();
	fixtureTearDown();
	return 0;
}

void setup(){}

void tearDown(){}

void fixtureSetup(){}

void fixtureTearDown(){}
