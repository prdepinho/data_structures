#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "bfs.h"
#include "elementary/queue.h"

static 
void bfs_print_graph(struct Graph *g, struct Queue *q){
	char buff[0xff];
	char color;
	int i;
	struct ListObj *it = NULL;
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
			printf("%d ", ((struct GraphNode*)q->array[i])->key);
		}else{
			printf(". ");
		}
	}
	printf("\n");
	for(i = 0; i < g->nodes_size; i++){
		switch(((struct BFSNode*)g->nodes[i].data)->color){
			case BFS_BLACK:
				color = 'B';
				break;
			case BFS_WHITE:
				color = 'W';
				break;
			case BFS_GRAY:
				color = 'G';
				break;
		}
		printf("%c [%d]", color, g->nodes[i].key);
		it = g->adjacencies[i].head;
		while(it != NULL){
			printf("->[%d]", it->key);
			it = it->next;
		}
		printf("\n");
	}
	gets(buff);
}

int bfs(struct Graph *g, struct GraphNode *s){
	struct BFSNode bfs_nodes[8];
	int i;
	for(i = 0; i < g->nodes_size; i++){
		bfs_nodes[i].color = BFS_WHITE;
		bfs_nodes[i].depth = INT_MAX;
		bfs_nodes[i].parent = NULL;
		g->nodes[i].data = &(bfs_nodes[i]);
	}
	((struct BFSNode*)s->data)->color = BFS_GRAY;
	((struct BFSNode*)s->data)->depth = 0;
	struct Queue q;
	if(queue_new(&q, g->nodes_size)){
		return -1;
	}
	queue_enqueue(&q, s);

	struct GraphNode *u = NULL;
	struct BFSNode *v = NULL;
	struct ListObj *it = NULL;
	bfs_print_graph(g, &q);
	while(!queue_empty(&q)){
		u = (struct GraphNode*)queue_dequeue(&q);
		it = g->adjacencies[u->key].head;
		while(it != NULL){
			v = (struct BFSNode*)((struct GraphEdge*)it->data)->node->data;
			if(v->color == BFS_WHITE){
				v->color = BFS_GRAY;
				v->depth = ((struct BFSNode*)u->data)->depth+1;
				v->parent = u;
				queue_enqueue(&q, ((struct GraphEdge*)it->data)->node);
			}
			it = it->next;
		}
		((struct BFSNode*)u->data)->color = BFS_BLACK;
		bfs_print_graph(g, &q);
	}
	queue_free(&q);
	return 0;
}

