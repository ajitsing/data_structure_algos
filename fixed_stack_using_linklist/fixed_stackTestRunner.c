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
		test_create_stack();
	tearDown();

	setup();
		test_insert_10_in_the_stack();
	tearDown();

	setup();
		test_insert_20_in_the_stack();
	tearDown();

	setup();
		test_insert_30_in_the_stack();
	tearDown();

	setup();
		test_2nd_item_is_20_in_the_stack();
	tearDown();

	setup();
		test_delete_item_from_stack();
	tearDown();

	setup();
		test_delete_2nd_item_from_stack();
	tearDown();

	setup();
		test_add_50_in_stack();
	tearDown();

	setup();
		test_display_stack();
	tearDown();


	summarizeTestCount();
	fixtureTearDown();
	return 0;
}

void setup(){}

void tearDown(){}

void fixtureSetup(){}

void fixtureTearDown(){}
