#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() {
	printf("나이를 입력하시오");
	int age;
	scanf("%d", &age);
	if (0 <= age && age <= 18) printf("청소년 요금입니다\n");
	else {
		if (age < 65) printf("성인 요금입니다\n");
		else printf("경로우대 요금입니다\n");
	}

	return 0;
}