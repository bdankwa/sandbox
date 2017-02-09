/*
 * lists.h
 *
 *  Created on: Feb 8, 2017
 *      Author: bdankwa
 */

#ifndef LISTS_H_
#define LISTS_H_

struct node{
	struct node* next;
	struct node* prev;
	char* key;
	void* data;
};

typedef struct{
	struct node* head;
	unsigned int size;
} list_t;

void init_list(list_t* list);
struct node* search_s(list_t* list, char* key);
int insert_s(list_t* list, struct node* element);
int delete_s(list_t* list, void* key);
struct node* search_d(list_t* list, char* key);
int insert_d(list_t* list, struct node* element);
int delete_d(list_t* list, void* key);


#endif /* LISTS_H_ */
