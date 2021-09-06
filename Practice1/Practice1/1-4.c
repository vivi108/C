#include <stdio.h>

void main4() {

	int num = 0, i , sum=0, square=0, cube=0;

	printf("\nEnter the interger: \n");
	scanf_s("%d", &num);

	for (i=0; i<=num; i++) {
		sum =sum+i;
	}
	printf("sum = %d\n", sum); //입력받은 수까지의 합
	
	for (i = 0; i <= num; i++) {
		square = square + i*i;
	}
	printf("squares = %d\n", square);

	for (i = 0; i <= num; i++) {
		cube = cube + i * i * i;
	}
	printf("cubes = %d\n", cube);



}