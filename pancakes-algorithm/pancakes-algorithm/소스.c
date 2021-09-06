#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main() {
	int arr[30], stack[30], stackcpy[30];
	int color[30] = { 0, };//a>b이면 a의 color=1 반대이면 0
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
		for (int i = 0; i < cnt; i++) {//flag의 개수와 전체 개수가 같으면 완료;
			if (color[i] == 1) flag++;
		}
		if (flag == cnt) {
			printf("flip(0)\n");
			break;
		}
		for (int i = 0; i < cnt; i++) {//color이 0인것은 뒤집는다.
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
	printf("\n 결과:");
	printarr(cnt, stackcpy);
}
//arr[i]>=arr[i+1] 이면 color[i]=1
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
int flip(int num, int* color, int * stack, int cnt) {//앞에서부터 몇번째에 뒤집을 건지 num은 1부터 시작
	int forsaving[30];
	printf("flip(%d), 옮겨지는 것: ", num);
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