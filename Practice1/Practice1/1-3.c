#include <stdio.h>

void main() {

	int a, b, c, d, e,f,g;
	printf("\nEnter an integer(5 digits or fewer) containting only 0s and 1s: \n");
	scanf_s("%d", &a);
	
	b = (a / 10000) * 16;
	c = ((a % 10000) / 1000) * 8;
	d = ((a % 1000) / 100) * 4;
	e = ((a % 100)/10) * 2;
	f = (a % 10) * 1;
	
	g = b + c + d + e+ f ;
	printf("\nBinary %d is decimal %d.\n", a, g);
}