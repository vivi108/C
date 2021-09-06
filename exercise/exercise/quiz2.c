#include <stdio.h>
#include <string.h>

int Fibo(int);
void main3() {
	
	int N;
	printf("type an integer: ");
	scanf_s("%d", &N);
	printf("%d\n", Fibo(N));
}

int Fibo(int num) {
	int n, first = 0, second = 1, next, k;
	for (k = 0; k < num; k++) {
		if (k <= 1) {
			next = k;
			return next;
		}
		else {
			next = first + second;
			first = second;
			second = next;
			return next;
		} 
	}
}

void exchange(int *, int*);

void main5() {
	//int n1=10, n2=2;
	//float f1, f2;
	//void newVal(int, int , float*, float*);
	//newVal(n1, n2, &f1, &f2);
	
	//printf("n1, n2: ");
	//scanf_s("%d%d", &n1, &n2);
//	printf("Before= n1: %d, n2: %d\n", n1, n2);
	//exchange(&n1, &n2);
	//printf("After= n1: %d, n2: %d\n", n1, n2);
	
	//printf("After= n1: %d, n2: %d\n", n1, n2);
	//printf("After= sum: %f, ramain: %f\n", f1, f2);
	char str1[20], str2[20]="Hello, ";
	
}



void newVal(int val1, int val2, float* sum, float* remain) {
	*sum = val1 + val2;
	*remain = val1 % val2;
}
void exchange(int *p, int *q) {
	int temp;
	temp = *q;
	*q = *p;
	*p = temp;
}
void main6() {
	char* arr[13] = {"", "January", "febuary", "March","April", "May", "June","July", "August", "September", "October", "November", "December"};
	int year, month, day;
	scanf_s("%d %d %d", &year, &month, &day);
	printf("The date is: %d %s %d", year, arr[month], day);
}
