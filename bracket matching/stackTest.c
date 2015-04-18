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
	pushStack(stack, '(');
	ASSERT(stack->array[0] == '(');	
}

void test_push_10_in_stack(){
	pushStack(stack, '(');
	ASSERT(stack->array[1] == '(');	
}

void test_push_15_in_stack(){
	pushStack(stack, '(');
	ASSERT(stack->array[2] == '(');	
}

void test_push_20_in_stack(){
	pushStack(stack, ')');
	ASSERT(stack->array[3] == ')');	
}

void test_push_25_in_stack(){
	pushStack(stack, ')');
	ASSERT(stack->array[4] == ')');	
}

void test_pop_25TheLastElement_from_stack(){
	char ch = popStack(stack);
	ASSERT(ch == ')');
}

void test_display_stack(){
	displayElementsOfStack(stack);
}