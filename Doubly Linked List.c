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
	return head;
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

struct node* addAtPosBefore(struct node* head, int data, int pos) {
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

struct node* addAtPosAfter(struct node* head, int data, int pos) {
	struct node* temp = head;
	struct node* temp2 = NULL;
	struct node* newP = NULL;
	if(head==NULL) {
		printf("\nList is empty");
	}
	newP = addToEmpty(newP, data);
	while(pos>2){
		temp = temp->next;
		pos--;
	}
	if(pos==1) {
		head = addAtBeg(head, data);
	}
	else {
	temp2 = temp->next;
	temp->next = newP;
	temp2->prev = newP;
	newP->next = temp2;
	newP->prev = temp;
	return head;
	}
	
}

struct node* createList(struct node* head) {
	int n, data, i;
	printf("Enter the number of node: ");
	scanf("%d",&n);
	
	if(n==0){
		return head;
	}
	printf("Enter the elemnent for first node: ");
	scanf("%d", &data);
	head = addToEmpty(head, data);
	
	for(i=1; i<n; i++) {
		printf("Enter the elment for %d node: ",i+1);
		scanf("%d",&data);
		head = addAtEnd(head, data);
	}
	return head;
}

struct node* deleteFirst(struct node* head){
	head = head->next;
	free(head->prev);
	head->prev=NULL;
	return head;
}

struct node* deleteEnd(struct node* head) {
	struct node* temp = head;
	struct node* temp2 = NULL;
	while(temp->next!= NULL) {
		temp = temp->next;
	}
	temp2 = temp->prev;
	temp2->next = NULL;
	free(temp);
	temp = NULL;
	return head;
}

struct node* delPos(struct node* head, int pos) {
	struct node* temp = head;
	struct node* temp2 = NULL;
	if(pos==1){
		head = deleteFirst(head);
		return head;
	}
		while(pos>1) {
			temp = temp->next;
			pos--;
		}
	if(temp->next==NULL) {
		head = deleteEnd(head);
	}
	else{
		temp2 = temp->prev;
		temp2->next=temp->next;
		temp->next->prev = temp2;
		free(temp);
		temp = NULL;
	}
		return head;
}

struct node* reverse(struct node* head) {
	struct node* ptr1 = head;
	struct node* ptr2 = ptr1->next;
	
	ptr1->next = NULL;
	ptr2->prev = ptr2;
	 
	while(ptr2 != NULL) {
		ptr2->prev = ptr2->next;
		ptr2->next = ptr1;
		ptr1 = ptr2;
		ptr2 = ptr2->prev;
	}
	head=ptr1;
	return head;
}

int main() {
	struct node *head = NULL;
	head = createList(head);
	print_data(head);
	
	printf("\nAfter clearing list and entering new node: ");
	head = addToEmpty(head, 10);
	printf("%d", head->data);
	
	head = addAtBeg(head, 20);
	printf("\nAfter Inserting at beginning: ");
	print_data(head);
	
	head = addAtEnd(head, 30);
	printf("\nAfter Inserting at end: ");
	print_data(head);
	
	int pos = 2;
	head = addAtPosBefore(head, 22, pos);
	printf("\nAfter inserting at position(before): ");
	print_data(head);
	
	head = addAtPosAfter(head, 23, pos);
	printf("\nAfter insertion at position(after): ");
	print_data(head);
	
	head = deleteFirst(head);
	printf("\nAfter deleting first node: ");
	print_data(head);
	
	head = deleteEnd(head);
	printf("\nAFter deleting last node: ");
	print_data(head);
		
	head = delPos(head, pos);
	printf("\nAfter deleting position: ");
	print_data(head);	
	
	head = reverse(head);
	printf("\nAfter reversing: ");
	print_data(head);
		
	return 0;
}
