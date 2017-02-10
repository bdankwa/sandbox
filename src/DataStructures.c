/*
 ============================================================================
 Name        : DataStructures.c
 Author      : Boakye Dankwa
 Version     :
 Copyright   : Your copyright notice
 Description :
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lists.h"

#define LIST_NODES (5)

int main(void) {

	list_t userCredentials;
	char user1[] = "bdankwa";
	char user2[] = "kofi";
	char user3[] = "kankam";
	char user4[] = "yaw";

	puts("Testing linked list");

	struct node users[LIST_NODES];
	for(int i=0; i< LIST_NODES; i++){
		users[i].key = malloc(128);
		users[i].data = malloc(256);
	}

	init_list(&userCredentials);

	strcpy(users[0].key, user1);
	strcpy(users[0].data, "complex password");
	strcpy(users[1].key, user2);
	strcpy(users[1].data, "weird password");
	strcpy(users[2].key, user3);
	strcpy(users[2].data, "simple password");
	strcpy(users[3].key, user4);
	strcpy(users[3].data, "no password");

	for(int i=0; i< 4; i++){
		users[i].next = NULL;
		users[i].prev = NULL;
		if(insert_s(&userCredentials, &users[i]) < 0){
			printf("error inserting to single llist at %i \n", i);
		}
	}

	struct node* someone;
	if((someone = search_s(&userCredentials, user2)) != NULL){
		printf("found user: %s, whose password is: %s \n",
				(char*)someone->key, (char*)someone->data);
	}
	else{
		printf("unable to find user %s\n", user2);
	}

	if(!insert_s(&userCredentials, &users[1])){
		printf("successfully added: %s \n",
				(char*)someone->key);
	}
	else{
		printf("unable to add user %s\n", user2);
	}

	if(!delete_s(&userCredentials, &users[1])){
		printf("successfully deleted: %s \n",
				(char*)someone->key);
	}
	else{
		printf("unable to delete user %s\n", user2);
	}

	if(search_s(&userCredentials, user2) == NULL){
		printf("user %s no longer in the list\n", user2);
	}
	else{
		printf("user %s still in the list\n", user2);
	}


	return EXIT_SUCCESS;
}
