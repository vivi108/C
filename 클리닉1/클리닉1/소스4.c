#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>


int main(){
int pick;
do {
	printf("*******�޴�*******\n1.��\n2.����\n3.����\n****************\n �޴��� �����ϼ��� :");

	scanf("%d", &pick);
	switch (pick) {
	case 1:
		printf("�󶼸� �����߽��ϴ�\n");
		break;
	case 2:
		printf("������ �����߽��ϴ�\n");
		break;
	}

} while (pick != 3);

return 0;
}