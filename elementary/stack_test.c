#include "stack.h"
#include <stdio.h>

int main(void){
	struct Stack stack;
	int a = 10;
	int *b = NULL;

	if(stack_new(&stack, 10)){
		printf("stack_new error\n");
		return 0;
	}
	stack_push(&stack, &a);

	if(stack_empty(&stack)){
		printf("empty\n");
	}

	b = stack_pop(&stack);
	if(b == NULL){
		printf("stack_push returned NULL\n");
	}else{
		printf("pushed element %d\n", *b);
	}

	if(stack_empty(&stack)){
		printf("empty\n");
	}
	printf("free\n");
	stack_free(&stack);

	return 0;
}
