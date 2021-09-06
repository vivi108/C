#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct salary {
	char name[100];
	int age;
	float pay;
};

void main() {
	struct salary s[100];
	FILE *v1, *v2, *v3;
	v1 = fopen("salary_v1.txt", "r");
	if (v1 == NULL) printf("no file");
	v2= fopen("salary_v2.txt", "w");
	v3 = fopen("salary_v2.txt", "w");

	int n = 0;
	while ((fscanf(v1, "%s %d %s", s[n].name, &(s[n]).age, &(s[n]).pay)) == 3) n++;




	fclose(v1);
	fclose(v2);
	fclose(v3);
}