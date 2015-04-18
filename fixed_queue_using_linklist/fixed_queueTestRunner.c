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

void testFailed(const char* fileName, int lineNumber){
	printf("\t\t*** failed at %s:%d\n",fileName,lineNumber);
}

int main(){
	fixtureSetup();
	resetTestCount();

	setup();
		test_create_queue_for_5_elements();
	tearDown();

	setup();
		test_insert_10_at_the_rear_end();
	tearDown();

	setup();
		test_insert_20_at_the_rear_end();
	tearDown();

	setup();
		test_insert_30_at_the_rear_end();
	tearDown();

	setup();
		test_insert_40_at_the_rear_end();
	tearDown();

	setup();
		test_insert_50_at_the_rear_end();
	tearDown();

	setup();
		test_insert_60_at_the_rear_end();
	tearDown();

	setup();
		test_delete_10_from_the_list();
	tearDown();

	setup();
		test_delete_40_from_the_list();
	tearDown();

	setup();
		test_insert_10_again_at_the_rear_end();
	tearDown();

	setup();
		test_insert_40_again_at_the_rear_end();
	tearDown();


	summarizeTestCount();
	fixtureTearDown();
	return 0;
}

void setup(){}

void tearDown(){}

void fixtureSetup(){}

void fixtureTearDown(){}
