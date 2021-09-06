#include <stdio.h>
#define SIZE 7
void calculate(int *, double *);

int main() {
	
	double average;
	int arr[7] = { 1,2,3,4,5,6,7 };
	calculate(arr, &average);
	printf("배열 원소의 평균 :%lf\n배열 원소의 제곱 :", average);
	for (int i = 0; i < SIZE; i++) {
		printf("%d ", arr[i]);
	}
	return 0;
}
void calculate(int *arr, double *a) {
	int sum = 0;
	for (int i = 0; i < SIZE; i++) {
		sum += arr[i];
		arr[i] = arr[i] * arr[i];
	}
	*a = (double)sum / SIZE;
}