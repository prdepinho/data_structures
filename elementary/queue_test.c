#include "queue.h"
#include <stdio.h>

void print_queue(struct Queue *q){
	int i;
	printf("queue: ");
	for(i = 0; i < q->alloc_size; i++){
		if(i == q->head){
			printf("H");
		}else if(i == q->tail){
			printf("T");
		}else{
			printf(" ");
		}
		if((struct GraphNode*)q->array[i] != NULL){
			printf("%d ", *(char*)q->array[i]);
		}else{
			printf(". ");
		}
	}
	printf("\n");
}

int main(void){
	struct Queue queue;
	char letters[] = {'a', 'b', 'c', 'd', 'e', 'f'};
	char *p = NULL;

	if(queue_new(&queue, 5)){
		printf("queue_new failed\n");
		return -1;
	}

	int a = 0;
	for(a = 0; a < 6; a++){
		if(queue_enqueue(&queue, &letters[a])){
			printf("queue_enqueue full at index %d\n", a);
		}else{
			printf("enqueue: %c\n", letters[a]);
		}
	}
	for(a = 0; a < 3; a++){
		p = queue_dequeue(&queue);
		if(p == NULL){
			printf("queue_dequeue empty\n");
		}else{
			printf("dequeued: %c\n", *p);
		}
	}

	for(a = 0; a < 6; a++){
		if(queue_enqueue(&queue, &letters[a])){
			printf("queue_enqueue full at index %d\n", a);
		}else{
			printf("enqueue: %c\n", letters[a]);
		}
	}
	for(a = 0; a < 6; a++){
		p = queue_dequeue(&queue);
		if(p == NULL){
			printf("queue_dequeue empty\n");
		}else{
			printf("dequeued: %c\n", *p);
		}
	}

	queue_free(&queue);
	return 0;

}

