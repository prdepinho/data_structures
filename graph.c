#include "graph.h"
#include <stdlib.h>


int graph_new(struct Graph *g, int nodes_size){
	g->nodes = malloc(sizeof(struct GraphNode)*nodes_size);
	if(g->nodes == NULL){
		return -1;
	}
	g->adjacencies = malloc(sizeof(struct List)*nodes_size);
	if(g->adjacencies == NULL){
		free(g->nodes);
		return -1;
	}
	int i;
	for(i = 0; i < nodes_size; i++){
		g->nodes[i].key = i;
		g->adjacencies[i].head = NULL;
	}
	g->nodes_size = nodes_size;
	return 0;
}

void graph_free(struct Graph *g){
	if(g->nodes != NULL){
		free(g->nodes);
	}
	int i;
	struct ListObj *it = NULL;
	struct ListObj *next = NULL;
	for(i = 0; i < g->nodes_size; i++){
		it = g->adjacencies[i].head;
		while(it != NULL){
			free(it->data);
			next = it->next;
			free(it);
			it = next;
		}
	}
	if(g->adjacencies != NULL){
		free(g->adjacencies);
	}
}

int graph_set_edge_s(struct Graph *g, struct GraphNode *x, struct GraphNode *y){
	struct ListObj *obj_y = malloc(sizeof(struct ListObj));
	if(obj_y == NULL){
		return -1;
	}
	struct GraphEdge *edge = malloc(sizeof(struct GraphEdge));
	if(edge == NULL){
		free(obj_y);
		return -1;
	}
	edge->node = y;
	edge->weight = 0;
	obj_y->next = NULL;
	obj_y->prev = NULL;
	obj_y->data = edge;
	obj_y->key = y->key;
	list_insert(&(g->adjacencies[x->key]), obj_y);
	return 0;
}

int graph_set_edge_ws(struct Graph *g, struct GraphNode *x, struct GraphNode *y, int weight){
	struct ListObj *obj_y = malloc(sizeof(struct ListObj));
	if(obj_y == NULL){
		return -1;
	}
	struct GraphEdge *edge = malloc(sizeof(struct GraphEdge));
	if(edge == NULL){
		free(obj_y);
		return -1;
	}
	edge->node = y;
	edge->weight = weight;
	obj_y->next = NULL;
	obj_y->prev = NULL;
	obj_y->data = edge;
	obj_y->key = y->key;
	list_insert(&(g->adjacencies[x->key]), obj_y);
	return 0;
}

int graph_set_edge_wd(struct Graph *g, struct GraphNode *x, struct GraphNode *y, int weight){
	struct ListObj *obj_y = malloc(sizeof(struct ListObj));
	if(obj_y == NULL){
		return -1;
	}
	struct GraphEdge *edge_y = malloc(sizeof(struct GraphEdge));
	if(edge_y == NULL){
		free(obj_y);
		return -1;
	}
	edge_y->node = y;
	edge_y->weight = weight;
	obj_y->next = NULL;
	obj_y->prev = NULL;
	obj_y->data = edge_y;
	obj_y->key = y->key;
	list_insert(&(g->adjacencies[x->key]), obj_y);

	struct ListObj *obj_x = malloc(sizeof(struct ListObj));
	if(obj_x == NULL){
		list_delete(&(g->adjacencies[x->key]), obj_y);
		free(obj_y);
		free(edge_y);
		return -1;
	}
	struct GraphEdge *edge_x = malloc(sizeof(struct GraphEdge));
	if(edge_x == NULL){
		list_delete(&(g->adjacencies[x->key]), obj_y);
		free(obj_y);
		free(edge_y);
		free(obj_x);
		return -1;
	}
	edge_x->node = x;
	edge_x->weight = weight;
	obj_x->next = NULL;
	obj_x->prev = NULL;
	obj_x->data = edge_x;
	obj_x->key = x->key;
	list_insert(&(g->adjacencies[y->key]), obj_x);
	return 0;
}

int graph_set_edge_d(struct Graph *g, struct GraphNode *x, struct GraphNode *y){
	struct ListObj *obj_y = malloc(sizeof(struct ListObj));
	if(obj_y == NULL){
		return -1;
	}
	struct GraphEdge *edge_y = malloc(sizeof(struct GraphEdge));
	if(edge_y == NULL){
		free(obj_y);
		return -1;
	}
	edge_y->node = y;
	edge_y->weight = 0;
	obj_y->next = NULL;
	obj_y->prev = NULL;
	obj_y->data = edge_y;
	obj_y->key = y->key;
	list_insert(&(g->adjacencies[x->key]), obj_y);

	struct ListObj *obj_x = malloc(sizeof(struct ListObj));
	if(obj_x == NULL){
		list_delete(&(g->adjacencies[x->key]), obj_y);
		free(obj_y);
		free(edge_y);
		return -1;
	}
	struct GraphEdge *edge_x = malloc(sizeof(struct GraphEdge));
	if(edge_x == NULL){
		list_delete(&(g->adjacencies[x->key]), obj_y);
		free(obj_y);
		free(edge_y);
		free(obj_x);
		return -1;
	}
	edge_x->node = x;
	edge_x->weight = 0;
	obj_x->next = NULL;
	obj_x->prev = NULL;
	obj_x->data = edge_x;
	obj_x->key = x->key;
	list_insert(&(g->adjacencies[y->key]), obj_x);
	return 0;
}


int graph_set_edge_ks(struct Graph *g, int x, int y){
	return graph_set_edge_s(g, &(g->nodes[x]), &(g->nodes[y]));
}

int graph_set_edge_kd(struct Graph *g, int x, int y){
	return graph_set_edge_d(g, &(g->nodes[x]), &(g->nodes[y]));
}

int graph_set_edge_kws(struct Graph *g, int x, int y, int weight){
	return graph_set_edge_ws(g, &(g->nodes[x]), &(g->nodes[y]), weight);
}

int graph_set_edge_kwd(struct Graph *g, int x, int y, int weight){
	return graph_set_edge_wd(g, &(g->nodes[x]), &(g->nodes[y]), weight);
}

