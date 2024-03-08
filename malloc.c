#include<stdio.h>
#include<stdlib.h>

//malloc is a buiult-in function declared in the header file <stdlib.h>

/*
malloc is the short name for "memory allocation"
and is used to dynamically allocate a single large 
block of contiguous memory according to the size specified.
*/

// malloc function simply allocates a memory block according to
// the size specified in the heap and on success it return a pointer
// pointing to the first byte of the alocated memory else returns NULL

// void pointer is a pointer which points to any type of data
// malloc doesn't have an idea of what is is pointing to
// it merely allocates memory requested by the user without
// knowing the type of data to be stored inside the memory
int main() {
	// int *ptr = (int*)malloc(4));
	//malloc allocates 4 bytres of memory in the heap and the
	//address of the first byte is stored in the pointer ptr
	int i, n;
	printf("Enter the number of integers: ");
	scanf("%d",&n);
	int *ptr = (int *)malloc(n*sizeof(int));
	
	if(ptr==NULL) {
		printf("memory not available.");
		exit(1);
	}
	for(i=0;i<n;i++) {
		printf("Enter an integer: ");
		scanf("%d",ptr+i);
	}
	for(i=0;i<n;i++) {
		printf("%d ", *(ptr+i));
	}
	return 0;
}
