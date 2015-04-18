#include "sampletestUtils.h"
#include "reverse_list.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

LinkList* list = NULL;
Stack* stack = NULL;

void test_insert_data_in_list(){
	list = createLinkList();
	stack = createStack(5);
	insertDataInLinkedList(list, 1, 10);
	insertDataInLinkedList(list, 2, 20);
	insertDataInLinkedList(list, 3, 30);
	insertDataInLinkedList(list, 4, 40);
	insertDataInLinkedList(list, 5, 50);
	ASSERT(searchDataInLinkList(list, 5) == 50 && searchDataInLinkList(list, 2) == 20);
}

void test_add_elements_into_stack_from_linklist(){
	transferValuesToStack(list, stack);
	ASSERT(stack->linklist->start->link->data == 50);
}

void test_pop_out_the_elements_from_the_stack_and_add_to_linklist(){
	popOutFromStackAndInsertIntoList(list, stack);
	displayLinkList(list);
	ASSERT(searchDataInLinkList(list, 2) == 40);
}