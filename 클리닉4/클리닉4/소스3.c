#include<stdio.h>

void DivideRemain(int x, int y, int* d, int * r) {
	*d = x / y;
	*r = x % y;
}
void main2() {

	int a, b;
	int res1, res2;
	while (1) {
		printf("�������� ���� ���ڸ� �Է��ϼ��� : ");
		scanf_s("%d", &a);
		printf("�������� ���� �и� �Է��ϼ��� : ");
		scanf_s("%d", &b);
		if (a == 0 && b == 0) break; //��������
		if (b == 0) {
			printf("0���� ���� �� �����ϴ�\n");
			continue;
		}
		DivideRemain(a, b, &res1, &res2);
		
		printf("%d / %d: ���� %d�̰� �������� %d�Դϴ�\n", a, b, res1, res2);
		
	}
}