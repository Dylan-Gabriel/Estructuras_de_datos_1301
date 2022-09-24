#include <stdio.h>
#include <stdlib.h>
#include "dlist.h"

void print_list(DList *list);

int main(int argc, char *argv[]){
	int counts = 10;
	DList *list1;
	DListNode *nodes = (DListNode*) malloc(counts * sizeof(DListNode));
	dlist_init(list1, free);

	for(int i = 0; i < counts; i++){
		dlist_ins_next(list1, &nodes[i], (void*)counts);
	}
	print_list(list1);
	return 0;
}

void print_list(DList *list){
	if(list != NULL){
		DListNode *viewport = list->head;
		int size = list->size;
		printf("size: %d, head: %d, tail: %d\n",list->size, list->head, list->tail);
		printf("data: %d, prev: %d, next: %d\n",viewport->data, viewport->prev, viewport->next);
		while(size>0){
			printf("data: %d, prev: %d, next: %d\n",viewport->data, viewport->prev, viewport->next);
			*viewport = *viewport->next;
			size--;
		}
	}
}