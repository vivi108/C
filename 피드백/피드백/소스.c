# define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include<string.h>

float average;
int min;
int max;

int cnt = 0;
int * list;
//숫자 받고, 세개 thread만들기 하나는 평균, 하나는 min, 하나는 max
void main() {
	char input[10];
	list = (int *)malloc(sizeof(int));

	while (1) {
		printf("input the ineger, if you want to stop entering, then input 'quit': ");
		scanf("%s", &input);
		if (strcmp(input, "quit")==0)  break;
		else {
			list[cnt] = atoi(input);
			cnt++;
		}
	}
	
	int sum = 0;
	for (int i = 0; i < cnt; i++) {
		sum += list[i];
	}
	float average = (float)sum / cnt;
	printf(" The average value is %f", average);
}
