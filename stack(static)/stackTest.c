#include "sampletestUtils.h"
#include "stack.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

void test_create_stack_for_20_elements(){
	Stack stack;
	stack = createStack(stack, 20);
	ASSERT(stack.max_size == 20);
}

void test_stack_is_not_full(){
	Stack stack;
	ASSERT(!isStackFull(stack)); 
}

void test_stack_is_empty(){
	Stack stack;
	ASSERT(isStackEmpty(stack)); 
}

void test_push_5_in_stack(){
	Stack stack;
	stack = pushStack(stack, 5);
	ASSERT(stack.array[0] == 5);	
}

void test_push_10_in_stack(){
	Stack stack;
	stack = pushStack(stack, 10);
	ASSERT(stack.array[1] == 10);	
}

void test_push_15_in_stack(){
	Stack stack;
	stack = pushStack(stack, 15);
	ASSERT(stack.array[2] == 15);	
}

void test_push_20_in_stack(){
	Stack stack;
	stack = pushStack(stack, 20);
	ASSERT(stack.array[3] == 20);	
}

void test_push_25_in_stack(){
	Stack stack;
	stack = pushStack(stack, 25);
	ASSERT(stack.array[4] == 25);	
}

void test_pop_25TheLastElement_from_stack(){
	Stack stack;
	stack = popStack(stack);
	ASSERT(stack.top == 3);
}

void test_pop_20TheLastElement_from_stack(){
	Stack stack;
	stack = popStack(stack);
	ASSERT(stack.top == 2);
}