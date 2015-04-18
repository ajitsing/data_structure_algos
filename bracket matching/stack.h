#include <stdio.h>
#define OVERFLOW  printf("\n\nstack overflow\n\n");
#define UNDERFLOW printf("\n\nstack underflow\n\n"); 
#define SUCCESS 1;
#define FAILURE 0;

typedef struct{
	int top;
	int max_size;
	char* array;
}Stack;

Stack* createStack(int size);
int isStackFull(Stack* stack);
int isStackEmpty(Stack* stack);
void pushStack(Stack* stack, char element);
char popStack(Stack* stack);
void displayElementsOfStack(Stack* stack);