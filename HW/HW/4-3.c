#include<stdio.h>
#include<math.h>
double gongsik(float a, float b, float c);

void main3() {
	float x, y, z;
	printf("\nThe coefficients of a Quadratic Equation ax^2=bx+c=0 are a, b and c\nEnter values of a,b and c: ");
	scanf_s("%f %f %f", &x, &y, &z);
	gongsik(x, y, z);
}
double gongsik(float a, float b, float c) {
	double root, x1, x2;
	
	root = b * b - 4 * a*c;
	puts("");

	if (root >= 0) {
		
		root = sqrt(root);
		x1 = (-b + root) / 2 * a;
		x2 = (-b - root) / 2 * a;
		
		
		return printf("Two real and equal roots\nRoots are %lf and %lf.", x1, x2);
	}
	else return puts(" \ndiscriminant is negative \n");
}