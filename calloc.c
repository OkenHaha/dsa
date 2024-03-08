// calloc() function is used to dynamically allocate multiple blocks of memory
// it is different from malloc in two ways
// 1. calloc() needs two arguments instead of just one
// void *calloc(number_of_blocks, size_of_each_block)
// 2. Memory allocated by calloc is initialized to zero
// it is not the case with malloc. Memory allocated by malloc is initialized with some garbage value
// calloc stand for clear allocation
// malloc stand for memory allocation
#include<stdio.h>
#include<stdlib.h>

int main() {
	int i, n;
	printf("Enter the number of integers: ");
	scanf("%d",&n);
	int *ptr = (int *)calloc(n, sizeof(int));
	
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
