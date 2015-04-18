#include <stdio.h>
#include "linkedList.h"

typedef struct{
	LinkList* linklist;
	int max_size;
}Stack;

Stack * createStack(int size);
void insertItem(Stack* stack, int value);
void removeItem(Stack* stack);