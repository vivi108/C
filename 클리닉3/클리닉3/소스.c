#include<stdio.h>
int get_pay(int hour, int day_rate, int hour_rate) {
	if (hour < 8) {
		return hour * hour_rate;
	}
	int remain_hour = hour % 8;
	return remain_hour * hour_rate + (hour / 8)*day_rate;
}
int main() {
	int h=0;
	while (1){
		
		printf("�ٷνð���? (����� -1)");
		scanf_s("%d", &h);
		if (h == -1) {
			printf("���α׷��� �����մϴ�");
			break;
		}
		printf("������ �ӱ��� %d��\n\n", get_pay(h, 100000, 10000));
	}
}