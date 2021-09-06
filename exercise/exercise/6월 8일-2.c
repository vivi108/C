#include<stdio.h>
int max();
void main2() {
	int num1, num2, num3;
	scanf_s("%d %d %d", &num1, &num2, &num3);
	printf("%d", max(num1, num2, num3));
}
int max(int x, int y, int z) {
	int m= x;
		if (m < y)
			m = y;
		
		if (m < z)
		m = z;
		
		return m;
}