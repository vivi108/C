#include <stdio.h>

void main1() {
	//1. ������ ����ϴ�, ȸ����鿡 �� �� ������ �������ִ� ���α׷��� ©��.
	//2������ �ӱ�
	//	1. straight time�⺻��(ó�� 40�ð���) 10000
	//	2. time - and-a - half�߰�����(0.5�� �� ����) 15000
	//	- 1�������� ���α׷� ����ǰ� �Ұ�


	double totaltime = 0, payrate = 0, totalpay;

	while (1) {
		printf("\n Please enter the total working hours(-1 to end): \n");
		scanf_s("%lf", &totaltime);
		if (totaltime == -1) {
			break;
		}
		printf("\n Enter hourly rate of the worker($00.00): \n");
		scanf_s("%lf", &payrate);


		if (40 < totaltime) {
			totalpay = (40 * payrate) + (payrate*(totaltime - 40) * 3 / 2);
			printf("\n Salary is %lf\n ", totalpay);
		}
		else if 
		(0 <= totaltime <= 40) {
			totalpay = totaltime * payrate;
			printf("Salary is %lf", totalpay);
		}
		else
		{
			printf("\n invalid value \n");
		}











	}
}