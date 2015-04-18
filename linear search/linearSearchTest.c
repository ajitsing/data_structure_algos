#include "sampletestUtils.h"
#include "linearSearch.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

LinkList* list = NULL;

void setup(){
	list = createLinkList();
}

void tearDown(){
	clearTheLinkList(list);
}

void test_search_5_in_list(){
	int i;
	for (i = 1; i < 6; i++){
		insertDataInLinkedList(list, i, i);
	}

	ASSERT(linearSearch(list, 5) == 5);
}

void test_search_30_in_list(){
	int i;
	for (i = 1; i < 6; i++){
		insertDataInLinkedList(list, i, i*10);
	}

	ASSERT(linearSearch(list, 30) == 3);
}