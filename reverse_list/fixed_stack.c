#include "fixed_stack.h"

Stack* createStack(int size){
	Stack * stack = (Stack*) malloc(sizeof(Stack));
	stack->linklist = createLinkList();
	stack->max_size = size;
	return stack;
}

void insertItem(Stack* stack, int value){
	if(countNumberOfNodes(stack->linklist) > stack->max_size)return;
	insertDataInLinkedList(stack->linklist, 1, value);
}

int removeItem(Stack* stack){
	int element;
	element = searchDataInLinkList(stack->linklist, 1);
	if(countNumberOfNodes(stack->linklist) < 1)return 0;
	deleteDataFromLinkList(stack->linklist, 1);
	return element;
}