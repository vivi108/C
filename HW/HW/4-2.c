#include<stdio.h>
void rec(char a);

void main2() {
	
	char filling;
	puts("enter a character to fill the rectangle: ");
	scanf_s("%c", &filling);
	rec(filling);
}
void rec(char a) {
	
	int i, j, len1, len2;
	puts("enter sides: ");
	scanf_s("%d %d", &len1, &len2);

	puts("\n");

	for (i = 1; i <= len1; i++) {
		for (j = 1; j <= len2; j++) {
			putchar(a);
		}puts("\n");
	}

}