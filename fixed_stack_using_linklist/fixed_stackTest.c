#include "sampletestUtils.h"
#include "fixed_stack.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

Stack * stack = NULL;

void test_create_stack(){
	stack = createStack(5);
	ASSERT(stack->max_size == 5);
}

void test_insert_10_in_the_stack(){
	insertItem(stack,10);
	ASSERT(stack->linklist->start->link->data == 10);
}

void test_insert_20_in_the_stack(){
	insertItem(stack,20);
	ASSERT(stack->linklist->start->link->data == 20);
}

void test_insert_30_in_the_stack(){
	insertItem(stack,30);
	ASSERT(stack->linklist->start->link->data == 30);
}

void test_2nd_item_is_20_in_the_stack(){
	ASSERT(stack->linklist->start->link->link->data == 20);
}

void test_delete_item_from_stack(){
	removeItem(stack);
	ASSERT(stack->linklist->start->link->data == 20);
}

void test_delete_2nd_item_from_stack(){
	removeItem(stack);
	ASSERT(stack->linklist->start->link->data == 10);
}

void test_add_50_in_stack(){
	insertItem(stack,50);
	ASSERT(stack->linklist->start->link->data == 50);
}

void test_display_stack(){
	displayLinkList(stack->linklist);
	ASSERT(1);
}