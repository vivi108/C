//12/27 LAB
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 3

typedef struct PERSON{
	char RRN[13];
	char name[20];
	float salary;
	float bonus;
}
PERSON employee[MAX];

void main() {
	for (int i = 0; i < MAX; i++) {
		scanf("%s", employee[i].RNN);
		if (i > 0) {
			for (int j = 0; j < i; j++) {
				if (strcmp(employee[i].RNN, employee[j].RNN) == 0) printf("RNN is not unique");
			}
		}
		scanf("%s", employee[i].name);
		scanf("%f", &employee[i].salary);
		scanf("%f", &employee[i].bonus);
		if (employee[i].bonus >= = employee[i].salary) printf("bonus is more than salary");
	}
}

/*void main() {
	for (int i = 0; i < 4; i++) {
		scanf("%s", &employee[i].RRN);
		scanf("%s", &employee[i].name);
		scanf("%f", &employee[i].salary);
		scanf("%f", &employee[i].bonus);
		for (int j = 0; j < i; j++) {
			if (strcmp(employee[i].RRN, employee[j].RRN)==0) printf("ERROR: RRN is not unique");
		}
		if (employee[i].bonus >= employee[i].salary) printf("ERROR: bonus is greater than salary");
	}
}*/

//10/28
/*void main() {
	FILE *inFile, *outFile;
	int a, sum = 0;

	inFile = fopen("myinFile.txt", "r");
	if (inFile == NULL) {
		printf("Input File could not be opened");
		exit(1);
	}
	outFile = fopen("myoutFile.txt", "w");
	if (inFile == NULL) {
		printf("Output File could not be opened");
		exit(1);
	}
	while (fscanf(inFile, "%d", &a) == 1) { sum = sum + a; }
	fprintf(outFile, "The sume is %d \n", sum);

	fclose(inFile);
	fclose(outFile);
}

int  main() {
	FILE *infile;
	char line[100];
	int lcount = 0;
	if ((infile = fopen("charstream.txt", "r")) == NULL) {
		printf("Input File could not be opened");
		exit(1);
	}
	while (*fgets(line, sizeof(line), infile) != EOF) {
		lcount++;
		printf("Line %d:%s", lcount, line);
	}
	fclose(infile);
	return 1;

	//Example5-6
/*void main() {

	FILE *myFile;
	myFile = fopen("myinFile.txt", "r");
	char ch;

	if (myFile == NULL) printf("\nFile Could Not Be Opened");
	else {
		//ch = fgetc(myFile);
		//while (ch != EOF) {
		//	putchar(ch);
		//	ch = fgetc(myFile);
		//}
		while ((ch = fgetc(myFile)) != EOF) putchar(ch);
		printf("\nFinished printing thr file \n");
		fclose(myFile);
	}


}*

Example6
void main() {
	char ch;

	FILE *myinFile, *myoutFile;
	myinFile = fopen("myinFile.txt", "r");
	if (myinFile == NULL) printf("could not ne open\n");
	myoutFile = fopen("myoutFile.txt", "w");
	while((ch = fgetc(myinFile)) != EOF) fputc(ch, myoutFile);

	fclose(myinFile);
	fclose(myoutFile);
}
struct CAR {
	char name[20];
	int year;
} car[2] = { {"Avante", 2007} ,{"Sonata", 2008} };

void main() {
	char ch, ch2;
	int i = 0;
	FILE *myinFile, *outFile;
	outFile = fopen("cars.txt", "w");

	fputs(car, outFile);

	myinFile = fopen("cars.txt", "r");
	if (myinFile == NULL) printf("could not ne open\n");

	while ((ch = fgetc(myinFile)) != EOF) putchar(ch);

	fclose(myinFile);
	fclose(outFile);
}
//hint  fprintf(ex01file, "%s\t%d\n", car[i].name, car[i].year);
}*/



