#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main() {
	int arr[30], stack[30], stackcpy[30];
	int color[30] = { 0, };//a>b�̸� a�� color=1 �ݴ��̸� 0
	FILE *file = fopen("input.txt", "r");
	if (file == 0) {
		printf("could not open file\n");
	}
	int cnt = 0;
	while (fscanf(file, "%d", &arr[cnt]) == 1) {
		cnt++;
	}
	for (int i = 0; i < cnt; i++) {
		stack[i] = arr[cnt - i - 1];
	}
	printf("original: ");
	printarr(cnt, arr);
	int flag = 0;
	while (1) {

		Tagging(stack, color, cnt);
		flag = 0;
		for (int i = 0; i < cnt; i++) {//flag�� ������ ��ü ������ ������ �Ϸ�;
			if (color[i] == 1) flag++;
		}
		if (flag == cnt) {
			printf("flip(0)\n");
			break;
		}
		for (int i = 0; i < cnt; i++) {//color�� 0�ΰ��� �����´�.
			if (color[i] == 0) {
				flip(i+1, color, stack, cnt);
				break;
			}
		}
		
		printf("\n");

	}

	for (int i = 0; i < cnt; i++) {
		stackcpy[i] = stack[cnt - i - 1];
	}
	printf("\n ���:");
	printarr(cnt, stackcpy);
}
//arr[i]>=arr[i+1] �̸� color[i]=1
int Tagging(int * intarr, int *intcolor,int cnt){
	intializ_Color(intcolor);
	for (int i = 0; i < cnt-1 ; i++) {
		if (intarr[i] >= intarr[i + 1]) intcolor[i] = 1;
		else intcolor[i] = 0;

	}
}
int intializ_Color(int * color) {
	for (int i = 0; i < 30; i++) {
		color[i] = 1;
	}
}
int flip(int num, int* color, int * stack, int cnt) {//�տ������� ���°�� ������ ���� num�� 1���� ����
	int forsaving[30];
	printf("flip(%d), �Ű����� ��: ", num);
	for (int i = 0; i < cnt-num+1; i++) {
		forsaving[i]=pop(cnt-i, stack);
		printf("%d ", forsaving[i]);
	}
	for (int i = num-1; i <cnt; i++) {
		stack[i]=forsaving[i-num+1];
	}
	
}
	
int pop(int end, int ** stack) {
	return stack[end - 1];
}
int printarr(int cnt, int * intarr) {
	for (int i = 0; i < cnt; i++) {
		printf("%d ", intarr[i]);
	}
	printf("\n");
}
int printcolor(int cnt, int * intarr) {
	for (int i = 0; i < cnt; i++) {
		printf("%d ", intarr[i]);
	}
	printf("\n");
}