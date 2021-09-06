#include <stdio.h>

void main1() {
	//1. 봉급을 계산하는, 회사원들에 대 총 수입을 결정해주는 프로그램을 짤것.
	//2종류의 임금
	//	1. straight time기본급(처음 40시간은) 10000
	//	2. time - and-a - half추가수당(0.5배 더 지급) 15000
	//	- 1을찍으면 프로그램 종료되게 할것


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