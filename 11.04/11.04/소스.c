#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct PERSON {
	char name[10];
	int age;
	char hobby[50];
};
void main() {
	struct PERSON p[6];
	struct PERSON temp;
	FILE *personal, *age, *hobby;
	personal = fopen("personal.txt", "r");
	if (personal == NULL) printf("no file");
	age = fopen("age.txt", "a+");
	hobby = fopen("hobby.txt", "w");
	int n=0;
	while ((fscanf(personal, "%s %d %s", p[n].name, &(p[n]).age, p[n].hobby)) == 3) n++;
	
	int i, j;
	for (i = 0; i < n; i++) {		for (j = 0; j < n - i-1; j++) {			if (p[j].age > p[j + 1].age)			{				temp = p[j];				p[j] = p[j + 1];				p[j + 1] = temp;			}		}		fputs(p[i].name, age);		fputc(p[i].age, age);		fputc(p[i].hobby, age);	}
	
	fclose(personal);
	fclose(age);
	fclose(hobby);
}
/*
#include <stdio.h>#include <stdlib.h>#include <string.h>void main() {	FILE* myfile = fopen("personal.txt", "r");	struct person	{		char name[100];		int age;		char hobby[100];	};	struct person p[100];	int n = 0;	while (fscanf(myfile, "%s %d %s", p[n].name, &p[n].age, p[n].hobby) == 3)	{		n++;	}	// sort by Age	struct person temp;	for (int i = 0; i < n; i++)	{		for (int j = 0; j < (n - i) - 1; j++)		{			if (p[j].age > p[j + 1].age)			{				temp = p[j];				p[j] = p[j + 1];				p[j + 1] = temp;			}		}	}	// print all	for (int i = 0; i < n; i++) {		printf("%s %d %s\n", p[i].name, p[i].age, p[i].hobby);	}}
*/