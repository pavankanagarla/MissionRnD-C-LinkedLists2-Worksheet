/*
OVERVIEW: Given a single linked list insert a new node at every Kth node with value K.
E.g.: 1->2->3->4->5, k = 2, 1->2->2->3->4->2->5

INPUTS: A linked list and Value of K.

OUTPUT: Insert a new node at every Kth node with value K.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

struct node * insertAtEveryKthNode(struct node *head, int K) {
	int count = 0;
	struct node *starting_node = head;
	struct node *temp;
	struct node *temp1 = head;
	if (head == NULL)
		return NULL;
	while (head != NULL){
		if (count == K){
			temp = (struct node*)malloc(sizeof(struct node));
			temp->num = K;
			temp1->next = temp;
			temp->next = head;
			count = 0;
		}
		temp1 = head;
		head = head->next;
		count++;
	}
	if (K == 1){
		temp = (struct node*)malloc(sizeof(struct node));
		temp->num = K;
		temp->next = NULL;
		temp1->next = temp;
	}
	return starting_node;
}
