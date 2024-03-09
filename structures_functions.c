#include<stdio.h>
#include<stdlib.h>
//  A structure is a user defined data type that can be used to group elemnets of different types into a single type.
// structure members as arguments
struct student {
	char name[50];
	int age;
	int roll;
	float marks;
};
void print(char name[], int age, int roll, float marks) {
	printf("%s %d %d %.2f", name, age, roll, marks);
}

// call by reference
// instead of passing the copies of the structure members, we can pass
// their addresses (or regerences)
struct charset {
	char s;
	int i;
};
void keyValue(char* s, int* i) {
	scanf("%c %d", s, i);
}

// structure variable as argument
// unlike arrays, name of the structure variable are not pointers
struct point {
	int x;
	int y;
};
void print2(struct point p) {
	printf("\n%d %d",p.x, p.y);
}
// pointer to structure as argument
// it is better to pass the address of the structure when the structure gets very large in size.
// use the arrow pointer (->) to access the the structure members inside the called function
void print3(struct point *ptr){
	printf("\n%d %d", ptr->x, ptr->y);
}

// returning structre variable from a function
// returning a structure variabvle froma a function is similar to returning a variable from a function
struct point edit(struct point p){
	(p.x)++;
	p.y = p.y + 5;
	return p;
}

// returning a pointer to a structure from the fucntion
struct point* func(int a, int b) {
	struct point *ptr = (struct point *)malloc(sizeof(struct point));
	ptr->x=a;
	ptr->y=b+5;
	return ptr;
}

// passing array of structures as arguments
void print4(struct point arr[]) {
	int i;
	for(i=0;i<2;i++) {
		printf("\n%d %d",arr[i].x, arr[i].y);
	}
}

// self referential structures
// the type of stuctures in which one or more pointers point to the structure of the same type
struct code {
	int i;
	char c;
	struct code *ptr;
};
int main() {
	struct student s1 = {"Nick", 16, 50, 72.5};
	print(s1.name, s1.age, s1.roll, s1.marks);
	// call by reference
	printf("\n Call by Reference:");
	struct charset cs;
	keyValue(&cs.s, &cs.i); //in precedence, dot (.) is evaluated first then &
	printf("%c %d\n",cs.s, cs.i);
	
	// structure as variable argument
	struct point p1 = {
		23, 45
	};
	
	// pointers in structure
	struct point p2 = {
		59, 60
	};
	print2(p1);
	print3(&p2);
	
	// here you can see the value of p1 gets updated
	p1 = edit(p1);
	print2(p1);
	
	struct point *ptr1;
	ptr1 = func(2, 3);
	print3(ptr1);
	free(ptr1);
	
	// array arguments
	struct point arr[2] = {{1, 2}, {3, 4}};
	print4(arr);
	
	// referential structure
	struct code var1;
	struct code var2;
	var1.i = 65;
	var1.c = 'A';
	var1.ptr = NULL;
	
	var2.c = 'B';
	var2.i = 66;
	var2.ptr = NULL;
	var1.ptr = &var2;
	printf("\n%d %c",var1.i, var1.c);
	printf("\n%d %c",var1.ptr->i, var1.ptr->c);
	return 0;
}
