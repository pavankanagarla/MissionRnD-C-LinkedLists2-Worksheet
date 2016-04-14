/*
OVERVIEW: Given a single linked list, reverse the linked list.
E.g.: 1->2->3->4->5, output is 5->4->3->2->1.

INPUTS: A linked list.

OUTPUT: Reverse the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * reverseLinkedList(struct node *head) {
	struct node *main_head = head;
	struct node *temp;
	if (head == NULL)
		return NULL;
	head = head->next;
	main_head->next = NULL;
	while (head != NULL){
		temp = head; 
		head = head->next;
		temp->next = main_head;
		main_head = temp;
	}
	return main_head;
}
