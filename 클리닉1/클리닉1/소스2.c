#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() {
	printf("������ �Է��Ͻÿ�\n");
	int x, y;
	char op;
	scanf("%d %c %d", &x, &op, &y);
	switch (op) {
	case '+':
		printf("%d %c %d = %d", x, op, y, x + y);
		break;
	case '-':
		printf("%d %c %d = %d", x, op, y, x - y);
		break;
	case '*':
		printf("%d %c %d = %d", x, op, y, x * y);
		break;
	case '/':
		printf("%d %c %d = %d", x, op, y, x / y);
		break;
	default:
		printf("�������� �ʴ� �������Դϴ�");
		break;
	}
	return 0;
}