#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() {
	printf("���̸� �Է��Ͻÿ�");
	int age;
	scanf("%d", &age);
	if (0 <= age && age <= 18) printf("û�ҳ� ����Դϴ�\n");
	else {
		if (age < 65) printf("���� ����Դϴ�\n");
		else printf("��ο�� ����Դϴ�\n");
	}

	return 0;
}