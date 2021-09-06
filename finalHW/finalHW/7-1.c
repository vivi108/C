#include<stdio.h>


void main1() {

	char a= 'a';
	int b= 10;
	double c= 3.14;

	char* p1 =&a;
	int* p2 = &b;
	double* p3= &c;

	*p1 += 1;
	*p2 += 1;
	*p3 += 1;

	printf("a=%c\t\t*p1=%p\n", a, p1);
	printf("b=%d\t\t*p2=%p\n", b, p2);
	printf("c=%lf\t*p3=%p\n",c, p3);
}
