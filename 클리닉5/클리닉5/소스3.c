#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main() {
	char str[10];
	
	while (1) {
		int cnt1 = 0, cnt2 = 0, cnt3 = 0;
		printf("��ȣ�� �����ϼ���: ");
		scanf_s("%s", str, sizeof(str));
		if (5 <= strlen(str)) {
			for (int i = 0; i < strlen(str); i++) {
				if (isdigit(str[i]) != 0) cnt1++;
				if (isupper(str[i]) != 0) cnt2++;
				if (islower(str[i]) != 0) cnt3++;
				
			}
		}
		if (cnt1+cnt2+cnt3==strlen(str)&&cnt1>0 && cnt2 > 0 && cnt3 > 0) {
			printf("������ ��ȣ�Դϴ�\n");
			break;
		}
		else {
			printf("����, �ҹ��� �빮�ڸ� ��� ��ȣ�� �ٽ� ���弼��\n");

		}
		
	}
}