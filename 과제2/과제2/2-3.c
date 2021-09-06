#include <stdio.h>

void main3() {
	//3. 온도를 변경해주는 프로그램 섭씨 30 - 50도 사이를 화씨로 변경하게 해주기.테이블 형식으로

	double feh;
	int i;
	
	printf("Celsius\t\tFahrenheit\n");
		for (i = 30; i <= 50; i++) {
			feh = (1.8* i + 32);
			printf("%d\t\t%lf\n",i ,feh);
	}



























}