#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#include "graph.h"
#include "bfs.h"

void print_graph(struct Graph *g){
	int i;
	struct ListObj *it = NULL;
	for(i = 0; i < g->nodes_size; i++){
		printf("[%d]", g->nodes[i].key);
		it = g->adjacencies[i].head;
		while(it != NULL){
			printf("-%d->[%d]", ((struct GraphEdge*)it->data)->weight, 
					it->key);
			it = it->next;
		}
		printf("\n");
	}
}

int main(void){
	struct Graph g;
	if(graph_new(&g, 8)){
		printf("graph_new failed\n");
		return -1;
	}
	graph_set_edge_kd(&g, 0, 1);
	graph_set_edge_kd(&g, 0, 4);
	graph_set_edge_kd(&g, 1, 5);
	graph_set_edge_kd(&g, 5, 2);
	graph_set_edge_kd(&g, 5, 6);
	graph_set_edge_kd(&g, 2, 6);
	graph_set_edge_kd(&g, 2, 3);
	graph_set_edge_kd(&g, 6, 3);
	graph_set_edge_kd(&g, 6, 7);
	graph_set_edge_kd(&g, 3, 7);

	printf("graph: \n");
	print_graph(&g);

	bfs(&g, &(g.nodes[1]));

	graph_free(&g);

	return 0;
}
