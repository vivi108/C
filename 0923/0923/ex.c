#include<stdio.h>

void main() {
	struct MonthDays {
		int ID;
		char lastName[10];
		float pay_rate;
		float hours_worked;
	}c[6] = { {3462,"Jones", 4.62, 40.0},{6793,"Robbins", 5.83, 38.5},{6985, "Smith", 5.22, 45.5}, {7834, "Swain", 6.89, 40.0},{8867, "Timmins", 6.43, 35.5}, {9002,"Williams", 4.75, 42.2}};

	float totalpay[6], totalgross=0;
	printf("ID num\tName : Gross pay\n=======================================\n");
	for (int i = 0; i < 6; i++) {
		totalpay[i] = c[i].pay_rate*c[i].hours_worked;
		printf("%d\t%s : %f\n", c[i].ID, c[i].lastName, totalpay[i]);
		totalgross += totalpay[i];
	}
	printf("\n===========================================\n  total gross: %f", totalgross);
}