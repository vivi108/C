#include<stdio.h>
#include<string.h>
int main2() {
	char str[10];
	printf("이름을 입력하세요: ");
	gets_s(str, sizeof(str));
	printf("%s", str);
}