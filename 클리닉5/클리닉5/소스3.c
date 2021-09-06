#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main() {
	char str[10];
	
	while (1) {
		int cnt1 = 0, cnt2 = 0, cnt3 = 0;
		printf("암호를 생성하세요: ");
		scanf_s("%s", str, sizeof(str));
		if (5 <= strlen(str)) {
			for (int i = 0; i < strlen(str); i++) {
				if (isdigit(str[i]) != 0) cnt1++;
				if (isupper(str[i]) != 0) cnt2++;
				if (islower(str[i]) != 0) cnt3++;
				
			}
		}
		if (cnt1+cnt2+cnt3==strlen(str)&&cnt1>0 && cnt2 > 0 && cnt3 > 0) {
			printf("적정한 암호입니다\n");
			break;
		}
		else {
			printf("숫자, 소문자 대문자를 섞어서 암호를 다시 만드세요\n");

		}
		
	}
}