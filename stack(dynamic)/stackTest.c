#include "sampletestUtils.h"
#include "stack.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

Stack *stack = NULL;

void test_create_stack_for_20_elements(){
	stack = createStack(20);
	ASSERT(stack->max_size == 20);
}

void test_stack_is_not_full(){
	ASSERT(!isStackFull(stack)); 
}

void test_stack_is_empty(){
	ASSERT(isStackEmpty(stack)); 
}

void test_push_5_in_stack(){
	stack = pushStack(stack, 5);
	ASSERT(stack->array[0] == 5);	
}

void test_push_10_in_stack(){
	stack = pushStack(stack, 10);
	ASSERT(stack->array[1] == 10);	
}

void test_push_15_in_stack(){
	stack = pushStack(stack, 15);
	ASSERT(stack->array[2] == 15);	
}

void test_push_20_in_stack(){
	stack = pushStack(stack, 20);
	ASSERT(stack->array[3] == 20);	
}

void test_push_25_in_stack(){
	stack = pushStack(stack, 25);
	ASSERT(stack->array[4] == 25);	
}

void test_pop_25TheLastElement_from_stack(){
	int element = popStack(stack);
	ASSERT(element == 25);
}

void test_pop_20TheLastElement_from_stack(){
	int element = popStack(stack);
	ASSERT(element == 20);
}

void test_display_stack(){
	displayElementsOfStack(stack);
}