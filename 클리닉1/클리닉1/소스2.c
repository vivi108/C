#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() {
	printf("수식을 입력하시오\n");
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
		printf("지원되지 않는 연산자입니다");
		break;
	}
	return 0;
}