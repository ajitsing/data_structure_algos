#include <stdlib.h>
#include "stack.h"

Stack createStack(){
	Stack stack;
	stack.max_size = 20;
	stack.top= -1;
	return stack;
}

int isStackFull(Stack stack){
	if(stack.top == stack.max_size)RETURN_SUCCESS
	else RETURN_FAILURE
}

int isStackEmpty(Stack stack){
	if(stack.top == -1)RETURN_SUCCESS
	else RETURN_FAILURE	
}

Stack pushStack(Stack stack, int element){
	if(isStackFull(stack))OVERFLOW
	else{
	 	stack.top = stack.top+1;	
		stack.array[stack.top] = element;
	}
	return stack;
}

Stack popStack(Stack stack){
	if(isStackEmpty(stack))UNDERFLOW
	else{
		stack.top= stack.top - 1;
	}
	return stack;
}

void displayElementsOfStack(Stack stack){
	for (; stack.top != -1 ; stack.top--){
		printf("%d\n",stack.array[stack.top]);
	}
}