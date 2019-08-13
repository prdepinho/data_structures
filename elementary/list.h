
#ifndef  list_INC
#define  list_INC

struct ListObj{
	struct ListObj *prev;
	struct ListObj *next;
	int key;
	void *data;
};

struct List{
	struct ListObj *head;
};

struct ListObj* list_search(struct List *list, int key);

int list_insert(struct List *list, struct ListObj *x);

void list_delete(struct List *list, struct ListObj *x);


#endif   /* ----- #ifndef list_INC  ----- */

