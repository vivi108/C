#include <stdio.h>

void main4() {
//4. 1-100������ ��� �Ҽ��� ���
	int i, j, count = 0;
	for (i = 2; i <= 100; i++) {
		for (j = 2; j < i; j++) {
			if (i%j == 0) break;
		}
		if (j == i) {
			printf("%d\n", i);
			count++;
			if (count % 5 == 0) printf("\n");
		}
	}

}