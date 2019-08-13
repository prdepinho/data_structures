#include <stdlib.h>
#include <stdio.h>
#include "dfs.h"
#include "elementary/list.h"

static int time;

static 
void dfs_print_graph(struct Graph *g){
	char buff[0xff];
	char color;
	int i;
	struct ListObj *it = NULL;
	printf("time: %d\n", time);
	for(i = 0; i < g->nodes_size; i++){
		switch(((struct DFSNode*)g->nodes[i].data)->color){
			case DFS_BLACK:
				color = 'B';
				break;
			case DFS_WHITE:
				color = 'W';
				break;
			case DFS_GRAY:
				color = 'G';
				break;
		}
		printf("%c [%d] %.2d,%.2d ", color, g->nodes[i].key,
				((struct DFSNode*)g->nodes[i].data)->d_time,
				((struct DFSNode*)g->nodes[i].data)->f_time);
		it = g->adjacencies[i].head;
		while(it != NULL){
			printf("->[%d]", it->key);
			it = it->next;
		}
		printf("\n");
	}
	gets(buff);
}

static
void dfs_visit(struct Graph *g, struct GraphNode *u){
	struct ListObj *it = NULL;
	struct GraphNode *v = NULL;
	time++;
	((struct DFSNode*)u->data)->d_time = time;
	((struct DFSNode*)u->data)->color = DFS_GRAY;
	it = g->adjacencies[u->key].head;
	dfs_print_graph(g);
	while(it != NULL){
		v = ((struct GraphEdge*)it->data)->node;
		if(((struct DFSNode*)v->data)->color == DFS_WHITE){
			((struct DFSNode*)v->data)->parent = u;
			dfs_visit(g, v);
		}
		it = it->next;
	}
	((struct DFSNode*)u->data)->color = DFS_BLACK;
	time++;
	((struct DFSNode*)u->data)->f_time = time;
	dfs_print_graph(g);
}

void dfs(struct Graph *g){
	struct DFSNode dfs_nodes[g->nodes_size];
	int i;
	for(i = 0; i < g->nodes_size; i++){
		dfs_nodes[i].color = DFS_WHITE;
		dfs_nodes[i].parent = NULL;
		dfs_nodes[i].d_time = 0;
		dfs_nodes[i].f_time = 0;
		g->nodes[i].data = &(dfs_nodes[i]);
	}
	time = 0;
	for(i = 0; i < g->nodes_size; i++){
		if(dfs_nodes[i].color == DFS_WHITE){
			dfs_visit(g, &(g->nodes[i]));
		}
	}
}

