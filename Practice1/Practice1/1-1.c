#include <stdio.h>

void main1() {
	printf("\nEnter three different integers: ");
	 
	int i, j, k;
	scanf_s("%d %d %d", &i, &j, &k);

	float average, sum, product, smallest, largest;

	sum = i+j+k;
	average = sum / 3;
	product = i * j*k;

	if (i <= j) {
		smallest = i;
		largest = j;
	}
	if (i > j) {
		smallest = j;
		largest = i;
	}
	if (k > largest) {
		largest = k;
	}
	if (k < smallest) {
		smallest = k;
	}
	printf("\nSum is %f\n",sum);
	printf("\nAverage is %f\n", average);
	printf("\nProduct is %f\n", product);
	printf("\nSmallest is %f\n", smallest);
	printf("\nLargest is %f\n", largest);
	

}