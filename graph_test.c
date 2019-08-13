#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

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
	if(graph_set_edge_ws(&g, &(g.nodes[0]), &(g.nodes[1]), 10)){
		printf("graph_set_edge_s failed \n");
	}
	if(graph_set_edge_ws(&g, &(g.nodes[0]), &(g.nodes[3]), 28)){
		printf("graph_set_edge_d failed \n");
	}
	if(graph_set_edge_ws(&g, &(g.nodes[1]), &(g.nodes[4]), 32)){
		printf("graph_set_edge_s failed \n");
	}
	if(graph_set_edge_ws(&g, &(g.nodes[2]), &(g.nodes[5]), 42)){
		printf("graph_set_edge_s failed \n");
	}
	if(graph_set_edge_ws(&g, &(g.nodes[2]), &(g.nodes[4]), 54)){
		printf("graph_set_edge_d failed \n");
	}
	if(graph_set_edge_ws(&g, &(g.nodes[3]), &(g.nodes[1]), 18)){
		printf("graph_set_edge_d failed \n");
	}
	if(graph_set_edge_ws(&g, &(g.nodes[4]), &(g.nodes[3]), 32)){
		printf("graph_set_edge_d failed \n");
	}
	if(graph_set_edge_ws(&g, &(g.nodes[5]), &(g.nodes[5]), 15)){
		printf("graph_set_edge_d failed \n");
	}
	if(graph_set_edge_d(&g, &(g.nodes[2]), &(g.nodes[1]))){
		printf("graph_set_edge_d failed \n");
	}
	print_graph(&g);
	graph_free(&g);
	return 0;
}

