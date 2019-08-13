
#ifndef  GRAPH_INC
#define  GRAPH_INC

#include "elementary/list.h"

struct GraphNode{
	int key;
	void *data;
};

struct GraphEdge{
	struct GraphNode *node;
	int weight;
};

struct Graph{
	struct GraphNode *nodes;
	struct List *adjacencies;
	int nodes_size;
};

int graph_new(struct Graph *g, int nodes_size);

void graph_free(struct Graph *g);

int graph_set_edge_s(struct Graph *g, struct GraphNode *x, struct GraphNode *y);

int graph_set_edge_d(struct Graph *g, struct GraphNode *x, struct GraphNode *y);

int graph_set_edge_ws(struct Graph *g, struct GraphNode *x, struct GraphNode *y, int weight);

int graph_set_edge_wd(struct Graph *g, struct GraphNode *x, struct GraphNode *y, int weight);

int graph_set_edge_ks(struct Graph *g, int x, int y);

int graph_set_edge_kd(struct Graph *g, int x, int y);

int graph_set_edge_kws(struct Graph *g, int x, int y, int weight);

int graph_set_edge_kwd(struct Graph *g, int x, int y, int weight);

#endif   /* ----- #ifndef GRAPH_INC  ----- */
