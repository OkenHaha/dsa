// realloc() function is used to change the size of the memory block without losign the old data
// void *realloc(pointer to the previously allocated memory, new size)
// int *ptr = (int *)malloc(sizeof(int));
// ptr = (int *)realloc(ptr, 2*sizeof(int));
// this will allocate memory space of 2*sizeof(int)
// This function moves the contents of the old block to a new block and the data of the old block is not lost
// we may lose the dat awhen the new size is smaller than the old size
// newly allocated bytes are uninitialized
#include<stdio.h>
#include<stdlib.h>
int main() {
	int i;
	int *ptr = (int *)malloc(2*sizeof(int));
	
	if(ptr==NULL) {
		printf("memory not available.");
		exit(1);
	}
	for(i=0;i<2;i++) {
		printf("Enter two integer: ");
		scanf("%d",ptr+i);
	}
	ptr = (int *)realloc(ptr, 4*sizeof(int));
	if(ptr==NULL) {
		printf("memory not available.");
		exit(1);
	}
	printf("Enter 2 more integers: \n");
	for(i=2;i<4;i++) {
		scanf("%d ", ptr+i);
	}
	for(i=0;i<4;i++) {
		printf("%d ", *(ptr+i));
	}
	return 0;
}
