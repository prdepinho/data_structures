
#ifndef  DISJOINED_SETS_INC
#define  DISJOINED_SETS_INC

struct DSet{
	struct DSet *parent;
	int rank;
	void *data;
};

void dset_make_set(struct DSet *x);

void dset_union(struct DSet *x, struct DSet *y);

struct DSet* dset_find_set(struct DSet *x);

#endif   /* ----- #ifndef DISJOINED_SETS_INC  ----- */
