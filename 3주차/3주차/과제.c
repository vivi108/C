#include<stdio.h>
void liquid(int, int*, float*, float*, float*); //prototpye of liquid()

void main() {
	int cups, num; // declaration of cups, pints, quarts, gallons
	float gallons, quarts, pints;

	printf("\nEnter an integer: ");
	scanf_s("%d", &num);// get an integer which means total cups

	liquid(num, &cups, &gallons, &quarts, &pints); //call the liquid() fuction

	printf("\ngallons: %f \n", gallons); //print them to check the values in a variables
	printf("\nquarts: %f \n", quarts);
	printf("\npints: %f \n", pints);
	printf("\ncups: %d \n", cups);
}

void liquid(int num, int* c, float* g, float* q, float* p) { // called fuction with five parameters
	
	*c = num;// an integer is total number of cups
	*p = *c / 2.0; // 2 cups equal to a pint 
	*q = *c / 4.0; // 4 cups equal to a quart
	*g = *c / 16.0; // 16 cups equal to a gallon 
}