#include<stdio.h>
#define STUDENT 7
#define N 10
int calculate(int a[], int p[][N]);
int main(){

	int answer[N] = { 1,3,2,3,4,2,3,1,4,2 };
	int paper[STUDENT][N] = { {1,3,2,3,4,2,3,1,3,2},
							  {2,3,2,4,3,2,3,1,4,2},
							  { 4, 2, 2, 3, 4, 2, 3, 1, 4, 2 },
							  { 1, 3, 2, 3, 3, 2, 3, 4, 4, 2 },
							  { 1, 3, 2, 3, 4, 2, 3, 3, 4, 2 },
							  { 1, 1, 1, 4, 4, 3, 3, 2, 4, 3 },
							  { 1, 3, 2, 3, 4, 2, 3, 1, 4, 2 }, };
	calculate(answer, paper);
}
int calculate(int a[], int p[][N]) {
	printf("======================================\n문항  1  2  3  4  5  6  7  8  9  10  점수\n");
	printf("======================================\n");
	int cnt[STUDENT] = { 0 , };
	for (int i = 0; i < STUDENT; i++) {
		printf("%d번 ", i+1);
		for (int j = 0; j < N; j++) {
			if (a[j]==p[i][j]) {
				printf(" O ");
				cnt[i]++;
			}
			else {
				printf(" X ");
			}
		}
		printf(" %d점\n", cnt[i]);
	}
	
	printf("\n====================\n번호 점수 석차\n====================\n");
	for (int i = 0; i < STUDENT; i++) {
		int num = 1;
		printf("%d번 %d점", i+1, cnt[i]);
		for (int j = 0; j < STUDENT; j++) {
			if (cnt[i] < cnt[j]) num++;
		}
		printf("  %d등\n",  num);
	}
	printf("\n====================\n");
	return 0;
}