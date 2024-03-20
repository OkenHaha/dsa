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

void print_data(struct node* head) {
	if(head==NULL) {
		printf("\nList is empty");
	}
	struct node *ptr = NULL;
	ptr = head;
	while(ptr != NULL) {
		printf("%d ",ptr->data);
		ptr = ptr->next;
	}
}

struct node* addToEmpty(struct node* head, int data){
	struct node* temp = malloc(sizeof(struct node));
	temp->prev = NULL;
	temp->data = data;
	temp->next = NULL;
	head = temp;
	return head;
}

struct node* addAtBeg(struct node* head, int data) {
	struct node* temp = malloc(sizeof(struct node));
	temp->prev=NULL;
	temp->data=data;
	temp->next=NULL;
	temp->next=head;
	head->prev=temp;
	head=temp;
	return head;
}

struct node* addAtEnd(struct node* head, int data) {
	struct node* temp, *tp = malloc(sizeof(struct node));
	temp->prev=NULL;
	temp->data=data;
	temp->next=NULL;
	tp = head;
	while(tp->next != NULL) {
		tp=tp->next;
	}
	tp->next=temp;
	temp->prev=tp;
	return head;
}

int main() {
	struct node *head = NULL;
	head = addToEmpty(head, 10);
	printf("%d", head->data);
	
	head = addAtBeg(head, 20);
	printf("\nAfter Inserting at beginning: ");
	print_data(head);
	
	head = addAtEnd(head, 30);
	printf("\nAfter Inserting at end: ");
	print_data(head);
		
	return 0;
	
}
