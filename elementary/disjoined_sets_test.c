#include "disjoined_sets.h"
#include <stdlib.h>
#include <stdio.h>

int main(void){
	struct DSet sets[10];
	char data[] = {'a','b','c','d','e','f','g','h','i','j'};

	int i;
	for(i = 0; i < 10; i++){
		dset_make_set(&sets[i]);
		sets[i].data = &data[i];
	}

	dset_union(&sets[0], &sets[1]);
	dset_union(&sets[2], &sets[3]);
	dset_union(&sets[4], &sets[5]);
	dset_union(&sets[1], &sets[5]);
	dset_union(&sets[3], &sets[6]);
	dset_union(&sets[7], &sets[8]);
	dset_union(&sets[8], &sets[9]);

	struct DSet *it = NULL;
	for(i = 0; i < 10; i++){
		it = dset_find_set(&sets[i]);
		printf("the representative of %c is %c\n", 
				*(char*)sets[i].data, *(char*)it->data);
	}

	dset_union(&sets[0], &sets[2]);
	dset_union(&sets[0], &sets[7]);
	dset_union(&sets[0], &sets[8]);

	printf("second time: \n");
	for(i = 0; i < 10; i++){
		it = dset_find_set(&sets[i]);
		printf("the representative of %c is %c\n", 
				*(char*)sets[i].data, *(char*)it->data);
	}

	return 0;
}

