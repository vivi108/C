#include <stdio.h>

void main5() {
	int table[5][5];
	int i, j;

	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++){
			table[i][j] = (i + 1)*(i + 1)*(j + 1);
		}
	}

	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			printf("%d\t", table[j][i]);
		}printf("\n");
	}















}
