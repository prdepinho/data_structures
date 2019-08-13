#include "dfs.h"
#include <stdlib.h>
#include <stdio.h>

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
	if(graph_new(&g, 6)){
		printf("graph_new failed\n");
		return -1;
	}
	graph_set_edge_ks(&g, 0, 1);
	graph_set_edge_ks(&g, 0, 3);
	graph_set_edge_ks(&g, 1, 4);
	graph_set_edge_ks(&g, 2, 4);
	graph_set_edge_ks(&g, 2, 5);
	graph_set_edge_ks(&g, 3, 1);
	graph_set_edge_ks(&g, 4, 3);
	graph_set_edge_ks(&g, 5, 5);

	print_graph(&g);

	dfs(&g);

	graph_free(&g);
	return 0;
}

