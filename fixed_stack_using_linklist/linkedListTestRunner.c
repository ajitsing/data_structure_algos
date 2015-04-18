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
		test_create_LinkList();
	tearDown();

	setup();
		test_add_10_to_LinkList_at_1st_location();
	tearDown();

	setup();
		test_delete_10_from_linklist();
	tearDown();

	setup();
		test_add_10_again_to_LinkList_at_1st_location();
	tearDown();

	setup();
		test_add_20_to_linklist_at_2nd_location();
	tearDown();

	setup();
		test_add_30_to_linklist_at_2nd_location();
	tearDown();

	setup();
		test_add_40_to_linklistat_2nd_location();
	tearDown();

	setup();
		test_add_50_to_linklist_at_4th_location();
	tearDown();

	setup();
		test_add_60_to_linklist_at_the_end();
	tearDown();

	setup();
		test_add_70_to_linklist_at_1st_location();
	tearDown();

	setup();
		test_delete_60_from_linklist();
	tearDown();

	setup();
		test_70_is_at_1st_position();
	tearDown();

	setup();
		test_20_is_at_6th_position();
	tearDown();

	setup();
		test_10_is_at_2nd_position();
	tearDown();

	setup();
		test_delete_40_from_the_linklist();
	tearDown();

	setup();
		test_delete_10_from_the_linklist();
	tearDown();

	setup();
		test_delete_first_node_from_the_linklist();
	tearDown();

	setup();
		test_50_is_at_2nd_position();
	tearDown();

	setup();
		test_will_not_delete_100_which_is_not_in_the_linklist();
	tearDown();

	setup();
		test_will_not_delete_60_which_is_not_in_the_linklist();
	tearDown();

	setup();
		test_display_list();
	tearDown();

	setup();
		test_clear_the_linklist();
	tearDown();


	summarizeTestCount();
	fixtureTearDown();
	return 0;
}

void setup(){}

void tearDown(){}

void fixtureSetup(){}

void fixtureTearDown(){}
