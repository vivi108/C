#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct VOTE {
	char name[100];
	int age;
	char who[50];
};
void main() {
	struct VOTE v[100];
	FILE *vote;
	vote = fopen("vote.txt", "r");
	if (vote == NULL) printf("no file");

	int n = 0;
	int trump = 0, biden = 0;
	while ((fscanf(vote, "%s %d %s", v[n].name, &(v[n]).age, v[n].who)) == 3) {
		n++;
	}
	for (int i = 0; i < n; i++) {		if (strcmp(v[i].who, "Biden") == 0) biden++;		if (strcmp(v[i].who, "Trump") == 0) trump++;	}
    printf("Biden:%.2f vs Trump:%.2f\n", (float)biden / (float)n*100.0, (float)trump / (float)n*100.0);
	/*
	   biden = 0;    trump = 0;    int cnt = 0;    for (int i = 2; i < n; i+=3) { 세번째 줄만 합산하는법        if (strcmp(p[i].cand, "Biden") == 0) biden++;        if (strcmp(p[i].cand, "Trump") == 0) trump++;        cnt++;    }    printf("Every 3rd Row: Biden:%.2f vs Trump:%.2f\n", (float)biden / (float)cnt*100.0, (float)trump / (float)cnt*100.0);*/

}