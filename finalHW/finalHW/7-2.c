#include<stdio.h>

void main2() {

	int a = 10, b = 20;
	int* p1=&a, p2=&b, p;

	printf("Before: p1=%p p2=%p\n", p1, p2);
	printf("Before: a=%d b=%d\n\n", a, b);

	p = p1;
	p1 = p2;
	p2 = p;

	printf("After: p1=%p p2=%p\n", p1, p2);
	printf("After: a=%d b=%d", a, b);
}