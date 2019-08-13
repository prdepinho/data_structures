#include <stdlib.h>
#include <stdio.h>
#include "quick_sort.h"

int comp_int(void *a, void *b){
	int int_a = *(int*)a;
	int int_b = *(int*)b;
	return int_a-int_b;
}

int main(void){
	int array[] = {2, 8, 7, 1, 3, 5, 6, 4};
	int* array_ptr[8];
	int i;
	for(i = 0; i < 8; i++){
		array_ptr[i] = &(array[i]);
	}
	for(i = 0; i < 8; i++){
		printf("%d ", *(int*)array_ptr[i]);
	}
	printf("\n");
	quick_sort((void**)array_ptr, 0, 7, comp_int);
	for(i = 0; i < 8; i++){
		printf("%d ", *(int*)array_ptr[i]);
	}
	printf("\n");

	return 0;
}

