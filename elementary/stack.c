#include "stack.h"
#include <stdlib.h>


int stack_new(struct Stack *stack, int alloc_size){
	stack->array = malloc(sizeof(void*)*alloc_size);
	if(stack->array == NULL){
		return -1;
	}
	stack->alloc_size = alloc_size;
	stack->top = -1;
	return 0;
}

void stack_free(struct Stack *stack){
	free(stack->array);
}

int stack_empty(struct Stack *stack){
	return stack->top == -1;
}

int stack_push(struct Stack *stack, void *x){
	stack->top++;
	stack->array[stack->top] = x;
}

void* stack_pop(struct Stack *stack){
	if(stack_empty(stack)){
		return NULL;
	}
	stack->top--;
	return stack->array[stack->top +1];
}

