/*
OVERVIEW: Given a single sorted linked list find the median element of the single linked list.
Median is the middle element.
E.g.: 1->2->3->4->5, output is 3.

INPUTS: A sorted linked list.

OUTPUT: Return median of the linked list elements.

ERROR CASES: Return -1 for error cases.

NOTES: If length is even, return average of middle pair of numbers.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

int linkedListMedian(struct node *head) {
	int len = 0;
	int result = 0;
	if (head == NULL)
		return -1;
	struct node *tail = head;
	while (tail != NULL){
		len++;
		tail = tail->next;
	}
	if (len % 2 != 0){
		len = len / 2 + 1;
		while (len != 1){
			head = head->next;
			len--;
		}
		result = head->num;
	}
	else{
		len = len / 2;
		while (len != 1){
			head = head->next;
			len--;
		}
		result = head->num;
		head = head->next;
		result += head->num;
		result = result / 2;
	}
	return result;
}
