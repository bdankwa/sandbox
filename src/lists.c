/*
 * lists.c
 *
 *  Created on: Feb 8, 2017
 *      Author: bdankwa
 */
#include "lists.h"
#include <string.h>

void init_list(list_t* list, struct node* head){
	list->head = head;
	list->size = 0;
}
/**********************************************
 * Single linked list implementation
 **********************************************/
struct node* search_s(list_t* list, char* key){
	struct node* obj = NULL;
	if(list != NULL){
		if(list->head != NULL){
			while((obj = list->head->next) != NULL &&
					strcmp(obj->key, key) != 0){
				;
			}
		}
	}
	return obj;
}
int insert_s(list_t* list, struct node* element){
	int status = -1;

	if(list != NULL){
		if((list->head != NULL) && (element != NULL)){
			//if element with same key exits in list, delete first
			if(search_s(list, element->key) != NULL){
				status = delete_s(list, element->key);
			}
			element->next = list->head->next;
			list->head = element;
			list->size++;
			status = 0;
		}
	}
	return status;
}
int delete_s(list_t* list, void* key){
	struct node* obj = NULL;
	struct node* prev = NULL;
	int status = -1;

	if(list != NULL){
		if(list->head != NULL){
			while((obj = list->head->next) != NULL &&
					strcmp(obj->key, key) != 0){
				prev = obj;
			}
			if(obj != NULL && prev != NULL && obj->next != NULL){
				prev->next = obj->next;
				list->size--;
				status = 0;
				free(obj);
			}
			//boundary condition
			else if(prev == NULL && obj != NULL){ // deleting head
				list->head = list->head->next;
				list->size--;
				status = 0;
				free(obj);
			}
			//boundary condition
			else if(obj->next == NULL){ // deleting tail
				prev->next = NULL;
				list->size--;
				status = 0;
				free(obj);
			}
			else{
				;
			}
		}
	}
	return status;
}

/**********************************************
 * Doubly linked list implementation
 **********************************************/
struct node* search_d(list_t* list, char* key){
	return search_s(list, key);
}
int insert_d(list_t* list, struct node* element){
	int status = -1;

	if(list != NULL){
		if(list->head != NULL && element != NULL){
			//if element with same key exits in list, delete first
			if(search_s(list, element->key) != NULL){
				status = delete_d(list, element->key);
			}
			list->head->prev = element;
			element->prev = NULL;
			element->next = list->head;
			list->head = element;
			status = 0;
			list->size++;
		}
	}
	return status;
}
int delete_d(list_t* list, void* key){
	int status = -1;
	struct node* obj = NULL;

	if(list != NULL){
		obj = search_s(list, key);
		if(obj != NULL){
			if(obj->prev == NULL){ //deleting head
				list->head->next->prev = obj;
				obj->next = list->head->next;
				list->head = obj;
				status = 0;
				list->size--;
				free(obj);
			}
			else if (obj->next == NULL){ //deleting tail
				obj->prev->next = NULL;
				status = 0;
				list->size--;
				free(obj);
			}
			else{ //deleting object between head and tail
				obj->prev->next = obj->next;
				obj->next->prev = obj->prev;
				status = 0;
				list->size--;
				free(obj);
			}
		}
	}

	return status;
}

