#include <stdlib.h>
#include "stack.h"

Stack* createStack(int size){
	Stack* stack = (Stack*)malloc(sizeof(stack));
	stack->max_size = size;
	stack->top= -1;
	stack->array = (int*)malloc(sizeof(Stack)*size);
	return stack;
}

int isStackFull(Stack* stack){
	if(stack->top == stack->max_size-1)return SUCCESS
	else return FAILURE
}

int isStackEmpty(Stack* stack){
	if(stack->top == -1)return SUCCESS
	else return FAILURE	
}

Stack* pushStack(Stack* stack, int element){
	if(isStackFull(stack))OVERFLOW
	else{
	 	stack->top = stack->top+1;	
		stack->array[stack->top] = element;
	}
	return stack;
}

int popStack(Stack* stack){
	if(isStackEmpty(stack))UNDERFLOW
	else{
		stack->top= stack->top - 1;
	}
	return  stack->array[stack->top + 1];
}

void displayElementsOfStack(Stack* stack){
	for (; stack->top != -1 ; stack->top--){
		printf("%d\n",stack->array[stack->top]);
	}
}