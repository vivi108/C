#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() {
	printf("원하는 두 주사위의 합을 입력하시오\n");
	int num;
	scanf("%d", &num);
	printf("두 주사위 합이 7이(가) 되는 경우의 수를 찾아봅시다\n----------\n A\tB \n----------\n");
	for (int i = 1; i <= 6; i++) {
		for (int j = 1; j <= 6; j++) {
			if (i + j == num) printf(" %d\t%d \n", i, j);
		}
	}
	return 0;
}