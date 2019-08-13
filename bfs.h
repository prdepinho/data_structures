
#ifndef  BFS_INC
#define  BFS_INC

#include "graph.h"

enum BFSColor{
	BFS_BLACK,
	BFS_GRAY,
	BFS_WHITE
};

struct BFSNode{
	int color;
	int depth;
	struct GraphNode *parent;
};

int bfs(struct Graph *g, struct GraphNode *s);


#endif   /* ----- #ifndef BFS_INC  ----- */
