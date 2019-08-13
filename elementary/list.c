#include "list.h"
#include <stdlib.h>

struct ListObj* list_search(struct List *list, int key){
	struct ListObj *x = list->head;
	while(x != NULL && x->key != key){
		x = x->next;
	}
	return x;
}

int list_insert(struct List *list, struct ListObj *x){
	x->next = list->head;
	if(list->head != NULL){
		list->head->prev = x;
	}
	list->head = x;
	x->prev = NULL;
}

void list_delete(struct List *list, struct ListObj *x){
	if(x->prev != NULL){
		x->prev->next = x->next;
	}else{
		list->head = x->next;
	}
	if(x->next != NULL){
		x->next->prev = x->prev;
	}
}

