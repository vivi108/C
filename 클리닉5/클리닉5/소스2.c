#include<stdio.h>
#include<string.h>
int main2() {
	char str[10];
	printf("�̸��� �Է��ϼ���: ");
	gets_s(str, sizeof(str));
	printf("%s", str);
}