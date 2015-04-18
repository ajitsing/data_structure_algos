#include <stdio.h>
#include "stack.h"

int main(){
	Stack stack;
	char answer;
	int size=0,choice,element;
	printf("Enter the size of stack\n");
	scanf("%d",&size);
	stack = createStack(stack,size);
	while(!0){
		printf("Chose your opration-->\n1.Enter data in stack\n2.Delete data from satck\n3.List all the elements\n4.Exit\n\n\n===>");
		scanf("%d",&choice);
		switch(choice){
			case 1:
			printf("\n\nEnter the element to be inserted\n");
			scanf("%d",&element); 
			stack = pushStack(stack, element);
			break;

			case 2: stack = popStack(stack);
			break;

			case 3: displayElementsOfStack(stack);
					break;

			case 4: return 0;

			printf("\n\n");
		}
	}
	return 0;
}