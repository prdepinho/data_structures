
#ifndef  stack_INC
#define  stack_INC

struct Stack{
	void **array;
	int top;
	int alloc_size;
};

int stack_new(struct Stack *stack, int alloc_size);

void stack_free(struct Stack *stack);

int stack_empty(struct Stack *stack);

int stack_push(struct Stack *stack, void *x);

void* stack_pop(struct Stack *stack);

#endif   /* ----- #ifndef stack_INC  ----- */
