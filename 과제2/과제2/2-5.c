#include <stdio.h>

void main5() {
	//5. �ƽ�Ű �ڵ� ���� 0-127���� ĳ���� �� ��Ÿ���� ���ٿ� ������.(ĳ����->�ƽ�Ű)
	int i, j;
	for (i = 0; i <= 127; i++) {
		printf("%c", i);
		if (i % 10 == 9) {
			printf("\n");
		}
	}
	return 0;
}