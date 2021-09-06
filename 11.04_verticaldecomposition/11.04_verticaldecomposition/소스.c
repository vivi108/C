#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct PERSON {
	char name[100];
	int age;
	char hobby[50];
};
void main() {
	struct PERSON p[100];
	FILE *personal, *age, *hobby;
	personal = fopen("personal.txt", "r");
	if (personal == NULL) printf("no file");
	age = fopen("age.txt", "w");
	hobby = fopen("hobby.txt", "w");
	int n = 0;
	while ((fscanf(personal, "%s %d %s", p[n].name, &(p[n]).age, p[n].hobby)) == 3) n++;

	fput(p.name, );

	fclose(personal);
	fclose(age);
	fclose(hobby);
}