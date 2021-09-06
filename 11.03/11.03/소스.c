#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//Example5-6
/**void main() {
	
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
}**/
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