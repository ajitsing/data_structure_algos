#include <stdio.h>
#define OVERFLOW  printf("\n\nstack overflow\n\n");
#define UNDERFLOW printf("\n\nstack underflow\n\n"); 
#define RETURN_SUCCESS return 1;
#define RETURN_FAILURE return 0;

typedef struct{
	int top;
	int max_size;
	int array[20];
}Stack;

Stack createStack();
int isStackFull(Stack stack);
int isStackEmpty(Stack stack);
Stack pushStack(Stack stack, int element);
Stack popStack(Stack stack);
void displayElementsOfStack(Stack stack);