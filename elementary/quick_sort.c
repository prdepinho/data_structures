#include <stdlib.h>
#include <stdio.h>
#include "quick_sort.h"

static
int quick_sort_partition(void **list, int p, int r, int (*comp)(void *a, void *b)){
	void *ptr = NULL;
	int i = p-1;
	int j;
	for(j = p; j < r; j++){
		if(comp(list[j], list[r])<=0){
			i++;
			ptr = list[i];
			list[i] = list[j];
			list[j] = ptr;
		}
	}
	ptr = list[i+1];
	list[i+1] = list[r];
	list[r] = ptr;
	return i+1;
}

void quick_sort(void **list, int p, int r, int (*comp)(void *a, void *b)){
	int q;
	if(p < r){
		q = quick_sort_partition(list, p, r, comp);
		quick_sort(list, p, q-1, comp);
		quick_sort(list, q+1, r, comp);
	}
}

