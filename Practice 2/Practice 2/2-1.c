#include <stdio.h>

void main1() {

	printf("\n Type the ten intgers: \n");
	int num1[10], num2[10], i, j, k = 0, bin1[10], bin2[10];
	for (i = 0; i < 10; i++) {
		scanf_s("%d", &num1[i]);
	}

	printf("\n Type the ten intgers: \n");
	for (i = 0; i < 10; i++) {
		scanf_s("%d", &num2[i]);
	}
	for (i = 0; i < 10; i++) {

		for (j = 0; j < i; j++) {
			if (num1[j] != num2[i]) {
				bin1[j] = num1[j];
				bin2[j] = num2[j];
			}
		}


	}

	for (i = 0; i < 10; i++) {
		printf("%d %d", bin1[i], bin2[i]);
	}







}





