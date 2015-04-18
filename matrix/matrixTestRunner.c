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
		test_create_matrix_of_5_X_5_size();
	tearDown();

	setup();
		test_insert_10_in_the_row_0_column_1();
	tearDown();

	setup();
		test_insert_20_in_the_row_3_column_4();
	tearDown();

	setup();
		test_insert_30_in_the_row_4_column_4();
	tearDown();

	setup();
		test_can_not_insert_40_in_the_row_5_column_1();
	tearDown();

	setup();
		test_replace_30_in_the_row_4_column_4_by_35();
	tearDown();

	setup();
		test_replace_55_in_the_row_1_column_0_by_55();
	tearDown();

	setup();
		test_set_1_2_3_4_5_values_in_matrix();
	tearDown();

	setup();
		test_set_6_7_8_9_10_values_in_matrix();
	tearDown();

	setup();
		test_set_11_12_13_14_15_values_in_matrix();
	tearDown();

	setup();
		test_set_16_17_18_19_20_values_in_matrix();
	tearDown();

	setup();
		test_set_21_22_23_24_25_values_in_matrix();
	tearDown();

	setup();
		test_convert_matrix_in_text();
	tearDown();

	setup();
		test_set_1_2_3_4_5_values_in_column_matrix();
	tearDown();

	setup();
		test_set_6_7_8_9_10_values_in_column_matrix();
	tearDown();

	setup();
		test_convert_matrix_in_text_and_print();
	tearDown();

	setup();
		test_set111_222_333_444_555_666_777_888_999_100_values_in_column_matrix();
	tearDown();

	setup();
		test_11convert_matrix_in_text_and_print();
	tearDown();


	summarizeTestCount();
	fixtureTearDown();
	return 0;
}

void setup(){}

void tearDown(){}

void fixtureSetup(){}

void fixtureTearDown(){}
