#include<stdio.h>

int hamsu(int*, int*);
void main() {
	int a, b;
	printf("Input two intgers :");
	scanf_s("%d %d", &a, &b);
	puts("");
	int* p1= &a, p2= &b;
	hamsu(p1,p2);
	printf("sum= %d, product= %d", a, b);
}
int hamsu(int* num1, int* num2 ) {
	int sum, product;
	sum = *num1 + *num2;
	product = *num1 * *num2;
	return *num1 = sum, *num2=product;
}