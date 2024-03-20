#include<stdio.h>
#include<stdlib.b>

// The difference between a singly linked list and doubly linked list is that in doubly linked list
// each node has an extra pointer that pointsto the previous node, together with the next pointer
// and data similar to singly linked list.

struct node{
	int data;
	struct node* prev;
	stuct node* next;
};

int main() {
	struct node *head = malloc(sizeof(struct node));
	
	head->prev = NULL;
	head->data = 10;
	head->next = NULL;
	
	return 0;
	
}
