/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * merge2LinkedLists(struct node *head1, struct node *head2) {
	struct node *result_head;
	struct node *result_end;
	if (head1 == NULL)
		return head2;
	if (head2 == NULL)
		return head1;
	if (head1->num < head2->num){
		result_head = result_end = head1;
		head1 = head1->next;
	}
	else{
		result_head = result_end = head2;
		head2 = head2->next;
	}
	while (head1 != NULL && head2 != NULL){
		if (head1->num < head2->num){
			result_end->next = head1;
			result_end = result_end->next;
			head1 = head1->next;
		}
		else{
			result_end->next = head2;
			result_end = result_end->next;
			head2 = head2->next;
		}
	}
	if (head1 != NULL)
		result_end->next = head1;
	if (head2 != NULL)
		result_end->next = head2;
	return result_head;
}
