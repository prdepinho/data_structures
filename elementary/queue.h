
#ifndef  queue_INC
#define  queue_INC

struct Queue{
	void **array;
	int head;
	int tail;
	int alloc_size;
};

int queue_new(struct Queue *queue, int alloc_size);

void queue_free(struct Queue *queue);

int queue_enqueue(struct Queue *queue, void *x);

void* queue_dequeue(struct Queue *queue);

int queue_empty(struct Queue *queue);

#endif   /* ----- #ifndef queue_INC  ----- */
