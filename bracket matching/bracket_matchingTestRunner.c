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
		test_expression_1_is_correct();
	tearDown();

	setup();
		test_expression_2_is_incorrect();
	tearDown();

	setup();
		test_expression_3_is_correct();
	tearDown();

	setup();
		test_expression_4_is_correct();
	tearDown();

	setup();
		test_expression_5_is_incorrect();
	tearDown();

	setup();
		test_expression_6_is_incorrect();
	tearDown();

	setup();
		test_expression_7_is_incorrect();
	tearDown();

	setup();
		test_expression_8_is_incorrect();
	tearDown();

	setup();
		test_expression_9_is_correct();
	tearDown();


	summarizeTestCount();
	fixtureTearDown();
	return 0;
}

void setup(){}

void tearDown(){}

void fixtureSetup(){}

void fixtureTearDown(){}
