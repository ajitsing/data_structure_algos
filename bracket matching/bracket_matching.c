#include "bracket_matching.h"
#include <string.h>

int test_the_expression(char* expression){
	int i,length = strlen(expression);
	char bracket[length];
	Stack *stack = createStack(length);

	for (i = 0; i < length; i++){
		if(expression[i] == '('){
			pushStack(stack, expression[i]);
		}
		else if(expression[i] == ')'){
			if(isStackEmpty(stack))return 0;
			else popStack(stack);
		}
	}
	if(!isStackEmpty(stack))return 0;
	
	return 1;
}