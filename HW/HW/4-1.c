
#include<stdio.h>
void ari(int a, int b);

void main1() {
	int len1, len2;
	puts("enter the two integars: ");
	scanf_s("%d %d", &len1, &len2);

	puts("\n");
	ari(len1, len2);
}
void ari(int a, int b) {
	int i, j;
	for (i = 1; i <= a; i++) {
		for (j = 1; j <= b; j++) {
			putchar('*');
		}puts("\n");
	}
}