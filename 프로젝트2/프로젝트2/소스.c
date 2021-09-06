#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
	srand(time(NULL));
	int random = (int)(rand()%100)+1, cnt=1, input, minBorder=1, maxBorder=100;
	printf("컴퓨터가 숨긴 수를 맞히는 게임입니다\n=================================\n");
	while (1){
		printf("%d ~ %d 중의 값입니다. 얼마일까요? ", minBorder, maxBorder);
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
	printf("\n================================= \n 컴퓨터가 숨긴 %d를 %d번 만에 맞혔습니다",random, cnt);
	return 0;
}