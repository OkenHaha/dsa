#include<stdio.h>

//structure members as arguments
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
//instead of passing the copies of the structure members, we can pass
//their addresses (or regerences)
struct charset {
	char s;
	int i;
};
void keyValue(char* s, int* i) {
	scanf("%c %d", s, i);
}
int main() {
	struct student s1 = {"Nick", 16, 50, 72.5};
	print(s1.name, s1.age, s1.roll, s1.marks);
	printf("\n Call by Reference:\n");
	struct charset cs;
	keyValue(&cs.s, &cs.i); //in precedence, dot (.) is evaluated first then &
	printf("%c %d",cs.s, cs.i);
	return 0;
}
