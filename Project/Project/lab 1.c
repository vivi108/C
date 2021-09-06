#include<stdio.h>

void main1() {

	char names[10][20], grades[10], GPA[10];
	int i=0, j=0;
	char ch='a';

	for (i = 0; i < 10; i++) {
		for (j = 0; j < 20; j++) {
			names[i][j] = '\n';
		}
	}
	
	for (i = 0; i < 10; i++) {
		printf("\nType the name of student: ");
		for (j = 0; j < 20; j++) {
			names[i][j] = getchar();
			if (names[i][j] == '\n') break;
		}printf("\nType the grade of student(one of A,B,C,D and F): ");
		grades[i] = getchar();
		getchar();
	}
	
	for (i = 0; i < 10; i++) {
		
		if (grades[i] == 'A')
			GPA[i] = '4';
		else if (grades[i] == 'B') 
			GPA[i] = '3';
		else if (grades[i] == 'C')
			GPA[i] = '2';
		else if (grades[i] == 'D')
			GPA[i] = '1';
		else if (grades[i] == 'F')
			GPA[i] = '0';
	}

	for (i = 0; i < 10; i++) {
		printf("\nstudent name = ");
		for (j = 0; j < 20; j++) {
			if (names[i][j] == '\n') break;
			printf("%c", names[i][j]);
		}
		printf("\ngrade = %c", grades[i]);
		printf("\nGPA = %c\n\n", GPA[i]);
	}
	




}