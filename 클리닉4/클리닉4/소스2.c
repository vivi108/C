#include<stdio.h>
void GetSumProduct(int x, int y, int* sum, int * product);
int main1() {
	
	int a = 5, b = 8;
	int res1, res2;
	while (1) {
		scanf_s("%d %d", &a, &b);
		GetSumProduct(a, b, &res1, &res2);
		if (a == 0 && b == 0) break;
		printf("%d + %d =%d\n", a, b, res1);
		printf("%d * %d =%d\n", a, b, res2);
	}
}
void GetSumProduct(int x, int y, int* sum, int * product) {
	*sum = x + y;
	*product = x * y;
}