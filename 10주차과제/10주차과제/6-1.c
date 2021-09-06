#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct EMPLOYEE {
	char name[10];
	char spell[5];
	int num;
	float fnum;
	char year[15];
};
struct EMPLOYEE e[50];
void fcopy() {
	FILE *in, *out;
	in = fopen("employee.dat.txt", "r");
	if (in == NULL)printf("\nno file");
	
	out = fopen("employee.bak.txt", "w");

	int n = 0;
	while ((fscanf(in, "%s %s %d %f %s", e[n].name, e[n].spell, &(e[n]).num, &(e[n]).fnum, e[n].year)) == 5) n++;

	for (int i = 0; i < n; i++) {

		fprintf(out, "%s %s %d %f %s\n", e[i].name, e[i].spell, e[i].num, e[i].fnum, e[i].year);
	}
	fclose(in);
	fclose(out);

}
void main() {
	fcopy();
	
}