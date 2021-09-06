#include <stdio.h>

void main5() {
	//5. 아스키 코드 값이 0-127까지 캐릭터 값 나타내기 한줄에 열개씩.(캐릭터->아스키)
	int i, j;
	for (i = 0; i <= 127; i++) {
		printf("%c", i);
		if (i % 10 == 9) {
			printf("\n");
		}
	}
	return 0;
}