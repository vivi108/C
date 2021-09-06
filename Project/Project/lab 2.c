#include <stdio.h>
#include <string.h>


void main2() {
	char str[100];
	int i, len;
	len = sizeof(str) / sizeof(str[0]);

	printf("\nInput String: ");
	gets_s (str, sizeof(str));

	printf("\nOutput: ");
	for (i = 0; i < len; i++) {
		if (str[i] == 'a' || str[i] == 'A')
			putchar('a');
		else if (str[i] == 'e' || str[i] == 'E')
			putchar('e');
		else if (str[i] == 'o' || str[i] == 'O')
			putchar('o');
		else if (str[i] == 'i' || str[i] == 'I')
			putchar('i');
		else if (str[i] == 'u' || str[i] == 'U')
			putchar('u');
		else if (str[i] == '\n') break;
	}
	printf("\n");










}