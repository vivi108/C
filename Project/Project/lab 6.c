#include <stdio.h>

void main6() {

	int age[10];
	//age[i]는 학생들의 나이
	int i, max=0, count=0;
	
	for (i = 0; i < 10; i++) {
		printf("\nEnter the age: ");
		scanf_s("%d", &age[i]);
	}

	for (i = 0; i < 10; i++) {
		if (age[i] > max)
			max = age[i];
		else continue;
	}

	for (i = 0; i < 10; i++) {
		if (age[i] == max)
			count += 1;
	}

	printf("\n the number of oldest students: %d\n", count);

}