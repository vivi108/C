#include<stdio.h>

void DivideRemain(int x, int y, int* d, int * r) {
	*d = x / y;
	*r = x % y;
}
void main2() {

	int a, b;
	int res1, res2;
	while (1) {
		printf("나눗셈을 위한 분자를 입력하세요 : ");
		scanf_s("%d", &a);
		printf("나눗셈을 위한 분모를 입력하세요 : ");
		scanf_s("%d", &b);
		if (a == 0 && b == 0) break; //종료조건
		if (b == 0) {
			printf("0으로 나눌 수 없습니다\n");
			continue;
		}
		DivideRemain(a, b, &res1, &res2);
		
		printf("%d / %d: 몫은 %d이고 나머지는 %d입니다\n", a, b, res1, res2);
		
	}
}