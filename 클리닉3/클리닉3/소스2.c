#include<stdio.h>
void odd_even(int x) {
	if ((x % 2) == 1) printf("%d�� Ȧ�� �Դϴ�\n", x);
	else printf("%d�� ¦�� �Դϴ�\n", x);
}
void calculate() {
	printf("������ �Է��ϼ��� : ");
	int x, y;
	char op;
	scanf_s("%d%c%d", &x, &op,1, &y);
	
	switch (op) {
	case '+':
		printf("%d %c %d = %d\n", x, op, y, x + y);
		break;
	case '-':
		printf("%d %c %d = %d\n", x, op, y, x - y);
		break;
	case '*':
		printf("%d %c %d = %d\n", x, op, y, x * y);
		break;
	case '/':
		printf("%d %c %d = %d\n", x, op, y, x / y);
		break;
	default:
		printf("�������� �ʴ� �������Դϴ�\n");
		break;
	}
}
int main() {
	int num, n;
	do {
		printf("*******�޴�*******\n1. Ȧ�� ¦�� ����\n2. ��Ģ ����\n3.����\n****************\n�޴��� �����ϼ��� : ");
		
		scanf_s("%d", &num);
		switch (num) {
		case 1:
			printf("Ȧ¦�� ������ ������ �Է����ּ���: ");
			scanf_s("%d", &n);
			odd_even(n);
			break;
		case 2:
			calculate();
			break;
		}
	} while (num!=3);
}