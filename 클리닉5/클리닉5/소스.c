#include<stdio.h>
#include<math.h>
int main1() {
	int x1, y1, x2, y2;
	printf("ù��° ���� x,y��ǥ�� �Է��ϼ���: ");
	scanf_s("%d %d", &x1, &y1);
	printf("�ι�° ���� x,y��ǥ�� �Է��ϼ���: ");
	scanf_s("%d %d", &x2, &y2);
	double d = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
	printf("\n�� �� ������ �Ÿ� : %lf", d);
}