#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
	srand(time(NULL));
	int random = (int)(rand()%100)+1, cnt=1, input, minBorder=1, maxBorder=100;
	printf("��ǻ�Ͱ� ���� ���� ������ �����Դϴ�\n=================================\n");
	while (1){
		printf("%d ~ %d ���� ���Դϴ�. ���ϱ��? ", minBorder, maxBorder);
		scanf_s("%d", &input);
		if (input == random) break;
		if (random > input) {
			minBorder = input + 1;
		}
		else{
			maxBorder = input - 1;
		}
		cnt++;
	}
	printf("\n================================= \n ��ǻ�Ͱ� ���� %d�� %d�� ���� �������ϴ�",random, cnt);
	return 0;
}