#include<stdio.h>
#include<stdlib.h>

// A Single linked list is a list made up of ndoes that consists of two parts
// 1. Data - contains the actual data
// 2. Link - contains the address of the next node of the list

struct node{
	int data;
	struct node *link;
};

void count_nodes(struct node *head) {
	int count = 0;
	if(head == NULL) {
		printf("\nLinked list is empty");
	}
	struct node *ptr = NULL;
	ptr = head;
	while(ptr != NULL) {
		count++;
		ptr = ptr->link;
	}
	printf("\nCount is %d",count);
}
void print_data(struct node *head) {
	if(head == NULL){
		printf("\nLLnked List is empty");
	}
	struct node *ptr = NULL;
	ptr = head;
	while(ptr != NULL) {
		printf("%d ",ptr->data);
		ptr = ptr->link;
	}
}

void insert_at_end_loop(struct node *head, int data){
	struct node *ptr, *temp;
	ptr = head;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->link = NULL;
	// the below loop loops through the link for each pointer till a data with NULL pointer is reached
	while(ptr->link != NULL) {
		ptr = ptr->link;
	}
	ptr->link=temp;
}
struct node* add_beg(struct node *head, int data) {
	struct node *ptr = malloc(sizeof(struct node));
	ptr->data=data;
	ptr->link=NULL;
	ptr->link=head;
	head = ptr;
	return head;
}
int main() {
	struct node *head = NULL;
	head = (struct node *)malloc(sizeof(struct node));
	
	head -> data = 45;
	head -> link = NULL;
	
	struct node *current = NULL;
	current = (struct node *)malloc(sizeof(struct node));
	current->data = 49;
	current->link = NULL;
	head->link = current;
	
	current = malloc(sizeof(struct node));
	current->data = 50;
	current->link = NULL;
	head->link->link = current;
	
	count_nodes(head);
	printf("\nData are: ");
	print_data(head);
	insert_at_end_loop(head, 91);
	printf("\nAfter insertion: ");
	print_data(head);
	printf("\n");
	
	struct note *ptr = malloc(sizeof(struct node));
	head = add_beg(head, 3);
	printf("\nAfter inserting 3 at the beginning: ");
	print_data(head);
	return 0;
}
