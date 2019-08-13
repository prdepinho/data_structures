#include "list.h"
#include <stdio.h>

int main(void){
	struct List list;
	list.head = NULL;

	struct ListObj objects[10];
	char data[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};

	int i;
	for(i = 0; i < 10; i++){
		objects[i].next = NULL;
		objects[i].prev = NULL;
		objects[i].key = i;
		objects[i].data = &data[i];
		list_insert(&list, &objects[i]);
	}

	struct ListObj *it = list.head;
	if(it == NULL){
		printf("List is empty\n");
	}else{
		do{
			printf("list element: %d: %c\n", it->key, *(char*)(it->data));
		}while((it = it->next) != NULL);
	}

	it = list_search(&list, 3);
	printf("list searched: %d: %c\n", it->key, *(char*)(it->data));

	it = list.head;
	if(it == NULL){
		printf("List is empty\n");
	}else{
		do{
			list_delete(&list, it);
		}while((it = it->next) != NULL);
	}

	if(list.head == NULL){
		printf("List is empty\n");
	}
	
	return 0;
}

