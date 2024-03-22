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
	if(head==NULL) {
		printf("\nList is empty");
	}
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
	if(head==NULL) {
		printf("\nList is empty");
	}
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

struct node* addAtPos(struct node* head, int data, int pos) {
	struct node* temp = head;
	struct node* temp2 = NULL;
	struct node* newP = NULL;
	if(head==NULL) {
		printf("\nList is empty");
	}
	newP = addToEmpty(newP, data);
	while(pos!=1){
		temp = temp->next;
		pos--;
	}
	if(temp->next == NULL) {
		temp->next = newP;
		newP->prev = temp;
	}else {
	temp2 = temp->next;
	temp->next = newP;
	temp2->prev = newP;
	newP->next = temp2;
	newP->prev = temp;
	return head;
	}
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
	
	int pos = 2;
	head = addAtPos(head, 22, pos);
	printf("\nAfter inserting at position: ");
	print_data(head);
		
	return 0;
	
}
