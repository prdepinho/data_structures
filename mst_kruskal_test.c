#include <stdlib.h>
#include <stdio.h>
#include "mst_kruskal.h"

void print_graph(struct Graph *g){
	int i;
	struct ListObj *it = NULL;
	for(i = 0; i < g->nodes_size; i++){
		printf("[%d]", g->nodes[i].key);
		it = g->adjacencies[i].head;
		while(it != NULL){
			printf("-%.2d->[%d]", ((struct GraphEdge*)it->data)->weight, 
					it->key);
			it = it->next;
		}
		printf("\n");
	}
}

int main(void){
	struct Graph g;
	if(graph_new(&g, 9)){
		printf("graph_new failed\n");
		return -1;
	}
	graph_set_edge_kwd(&g, 0, 1, 4);
	graph_set_edge_kwd(&g, 0, 2, 8);
	graph_set_edge_kwd(&g, 1, 2, 11);
	graph_set_edge_kwd(&g, 1, 4, 8);
	graph_set_edge_kwd(&g, 2, 3, 7);
	graph_set_edge_kwd(&g, 2, 5, 1);
	graph_set_edge_kwd(&g, 3, 5, 6);
	graph_set_edge_kwd(&g, 3, 4, 2);
	graph_set_edge_kwd(&g, 4, 6, 7);
	graph_set_edge_kwd(&g, 4, 7, 4);
	graph_set_edge_kwd(&g, 5, 7, 2);
	graph_set_edge_kwd(&g, 6, 8, 9);
	graph_set_edge_kwd(&g, 6, 7, 14);
	graph_set_edge_kwd(&g, 7, 8, 10);

	print_graph(&g);

	graph_free(&g);
	return 0;
}

