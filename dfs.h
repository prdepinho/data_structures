
#ifndef  DFS_INC
#define  DFS_INC

#include "graph.h"

enum DFSColor{
	DFS_GRAY,
	DFS_BLACK,
	DFS_WHITE
};

struct DFSNode{
	int d_time;
	int f_time;
	int color;
	struct GraphNode *parent;
};

void dfs(struct Graph *g);

#endif   /* ----- #ifndef DFS_INC  ----- */
