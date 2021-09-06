#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>


int main(){
int pick;
do {
	printf("*******메뉴*******\n1.라떼\n2.우유\n3.종료\n****************\n 메뉴를 선택하세요 :");

	scanf("%d", &pick);
	switch (pick) {
	case 1:
		printf("라떼를 선택했습니다\n");
		break;
	case 2:
		printf("우유를 선택했습니다\n");
		break;
	}

} while (pick != 3);

return 0;
}