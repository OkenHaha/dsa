#include<stdio.h>
#include<stdlib.h>

// The difference between a singly linked list and doubly linked list is that in doubly linked list
// each node has an extra pointer that pointsto the previous node, together with the next pointer
// and data similar to singly linked list.

struct node{
	int data;
	struct node* prev;
	struct node* next;
};

struct node* addToEmpty(struct node* head, int data){
	struct node* temp = malloc(sizeof(struct node));
	temp->prev = NULL;
	temp->data = data;
	temp->next = NULL;
	head = temp;
	return head;
}

int main() {
	struct node *head = NULL;
	head = addToEmpty(head, 10);
	printf("%d", head->data);
	
	return 0;
	
}
