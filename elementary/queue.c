#include "queue.h"
#include <stdlib.h>

int queue_new(struct Queue *queue, int alloc_size){
	queue->array = malloc(sizeof(void*)*alloc_size);
	if(queue->array == NULL){
		return -1;
	}
	queue->alloc_size = alloc_size;
	queue->head = 0;
	queue->tail = 0;
	return 0;
}

void queue_free(struct Queue *queue){
	free(queue->array);
}

int queue_enqueue(struct Queue *queue, void *x){
	if(queue->head == (queue->tail +1) % (queue->alloc_size)){
		return -1;
	}
	queue->array[queue->tail] = x;
	if(queue->tail == queue->alloc_size -1){
		queue->tail = 0;
	}else{
		queue->tail++;
	}
	return 0;
}

void* queue_dequeue(struct Queue *queue){
	if(queue->head == queue->tail){
		return NULL;
	}
	void *x = queue->array[queue->head];
	if(queue->head == queue->alloc_size -1){
		queue->head = 0;
	}else{
		queue->head++;
	}
	return x;
}

int queue_empty(struct Queue *queue){
	return queue->head == queue->tail;
}

