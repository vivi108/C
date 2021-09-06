#include <stdio.h>

void main() {

	int table [20][10];
	int i, j;

	table[0][0] = 0;

	for (i = 0; i < 20; i++) {
		for (j = 0; j < 9; j++) {
			table[i][j+1] = table[i][j] + 2;
		 
		}if (i == 19) break;
		table[i + 1][0] = table[i][j] + 2;

	}

	for (i = 0; i < 20; i++) {
		for (j = 0; j < 10; j++) {
			printf("table[%d][%d] = %d\n", i, j, table[i][j]);
		}printf("\n");
	}

}