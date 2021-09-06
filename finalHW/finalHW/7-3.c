#include<stdio.h>

void call_by_value(int);
void call_by_reference(int*);

void main() {

	int a;
	printf("The difference between \"call by value \" and \"call by value \"");
	printf("\nInput an integer: ");
	scanf_s("%d", &a);
	
	int* p = &a;
	
	puts("");
	
	printf("Before the call_by_value function: ");
	printf(" value: %d\tAddress: %p\n", a, p);
	call_by_value(a);
	printf("After the call_by_value function ");
	printf(" value: %d\tAddress: %p", a, p);
	
	puts("");
	puts("");

	printf("Before the call_by_reference function: ");
	printf(" value: %d\tAddress: %p\n", a, p);
	call_by_reference(p);
	printf("After the call_by_reference function ");
	printf(" value: %d\tAddress: %p\n", a, p);
	

}

void call_by_value(int num) {
	num += 10;
	printf("In the call_by_value function: ");
	printf(" value: %d\tAddress: %p\n", num, &num);
	
}

void call_by_reference(int* num) {
	*num = *num + 10;
	printf("In the call_by_reference function: ");
	printf(" value: %d\tAddress: %p\n", *num, num);
}