# define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void convertToBin(int x, char b[])
{
	char t[1024];
	int i = 0;
	while (x > 0) {
		t[i] = x % 2 + '0';
		x = x / 2;
		i++;
	}
	for (int j = 0; j < i; j++) {
		b[j] = t[i - j - 1];
	}
	b[i] = 0;
}
int main()
{
	char bin[1024];
	for (int i = 0; i <= 1000; i++) {
		convertToBin(i, bin);
		printf("DEC:%d BIN:%s HEX:%0x\n", i, bin, i);
	}
	return 1;
}
