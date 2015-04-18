#include <stdio.h>
#define OVERFLOW  printf("\n\nstack overflow\n\n");
#define UNDERFLOW printf("\n\nstack underflow\n\n"); 
#define SUCCESS 1;
#define FAILURE 0;

typedef struct{
	int top;
	int max_size;
	int* array;
}Stack;

Stack* createStack(int size);
int isStackFull(Stack* stack);
int isStackEmpty(Stack* stack);
Stack* pushStack(Stack* stack, int element);
int popStack(Stack* stack);
void displayElementsOfStack(Stack* stack);