#include "disjoined_sets.h"

static 
void dset_link(struct DSet *x, struct DSet *y){
	if(x->rank > y->rank){
		y->parent = x;
	}else{
		x->parent = y;
		if(x->rank == y->rank){
			y->rank++;
		}
	}
}

void dset_make_set(struct DSet *x){
	x->parent = x;
	x->rank = 0;
}

void dset_union(struct DSet *x, struct DSet *y){
	dset_link(dset_find_set(x), dset_find_set(y));
}

struct DSet* dset_find_set(struct DSet *x){
	if(x != x->parent){
		x->parent = dset_find_set(x->parent);
	}
	return x->parent;
}

