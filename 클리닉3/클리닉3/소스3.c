#include <stdio.h>
void Swap(int x, int y);
int a = 10;
int b = 20;
int main() {
	
	printf("Swap ���� a = %d, b = %d\n", a, b);
	Swap(a, b);
	printf("Swap ���� a = %d, b = %d\n", a, b);
	return 0;
}
void Swap() {
	int temp;
	temp = a;
	a = b;
	b = temp;
}
