#include<stdio.h>
void odd_even(int x) {
	if ((x % 2) == 1) printf("%d는 홀수 입니다\n", x);
	else printf("%d는 짝수 입니다\n", x);
}
void calculate() {
	printf("수식을 입력하세요 : ");
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
		printf("지원되지 않는 연산자입니다\n");
		break;
	}
}
int main() {
	int num, n;
	do {
		printf("*******메뉴*******\n1. 홀수 짝수 구분\n2. 사칙 연산\n3.종료\n****************\n메뉴를 선택하세요 : ");
		
		scanf_s("%d", &num);
		switch (num) {
		case 1:
			printf("홀짝을 구분할 정수를 입력해주세요: ");
			scanf_s("%d", &n);
			odd_even(n);
			break;
		case 2:
			calculate();
			break;
		}
	} while (num!=3);
}