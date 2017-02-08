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
	char user3[] = "kofi";
	char user4[] = "yaw";

	puts("Testing linked list");

	struct node users[LIST_NODES];
	for(int i=0; i< LIST_NODES; i++){
		users[i].key = malloc(128);
		users[i].data = malloc(256);
	}
	strcpy(users[0].key, user1);
	strcpy(users[0].data, "complex password");

	init_list(&userCredentials, &users[0]);

	strcpy(users[1].key, user2);
	strcpy(users[1].data, "weird password");
	strcpy(users[2].key, user3);
	strcpy(users[2].data, "simple password");
	strcpy(users[3].key, user4);
	strcpy(users[3].data, "no password");

	for(int i=1; i< 4; i++){
		if(insert_s(&userCredentials, &users[i]) < 0){
			printf("error inserting to single llist at %i \n", i);
		}
	}

	struct node* someone;
	if((someone = search_s(&userCredentials, user3)) != NULL){
		printf("found user: %s, whose password is: %s \n",
				(char*)someone->key, (char*)someone->data);
	}
	else{
		printf("unable to find user %s\n", user3);
	}


	return EXIT_SUCCESS;
}
