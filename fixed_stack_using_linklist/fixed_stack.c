#include "fixed_stack.h"

Stack* createStack(int size){
	Stack * stack = (Stack*) malloc(sizeof(Stack));
	stack->linklist = createLinkList(size);
	stack->max_size = size;
	return stack;
}

void insertItem(Stack* stack, int value){
	if(countNumberOfNodes(stack->linklist) > stack->max_size)return;
	insertDataInLinkedList(stack->linklist, 1, value);
}

void removeItem(Stack* stack){
	if(countNumberOfNodes(stack->linklist) < 1)return;
	deleteDataFromLinkList(stack->linklist, 1);
}