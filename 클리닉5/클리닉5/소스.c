#include<stdio.h>
#include<math.h>
int main1() {
	int x1, y1, x2, y2;
	printf("첫번째 점의 x,y좌표를 입력하세요: ");
	scanf_s("%d %d", &x1, &y1);
	printf("두번째 점의 x,y좌표를 입력하세요: ");
	scanf_s("%d %d", &x2, &y2);
	double d = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
	printf("\n두 점 사이의 거리 : %lf", d);
}