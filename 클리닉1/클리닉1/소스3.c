#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() {
	printf("���ϴ� �� �ֻ����� ���� �Է��Ͻÿ�\n");
	int num;
	scanf("%d", &num);
	printf("�� �ֻ��� ���� 7��(��) �Ǵ� ����� ���� ã�ƺ��ô�\n----------\n A\tB \n----------\n");
	for (int i = 1; i <= 6; i++) {
		for (int j = 1; j <= 6; j++) {
			if (i + j == num) printf(" %d\t%d \n", i, j);
		}
	}
	return 0;
}