#include<stdio.h>
int i;
int square(int y) {
	
	return i*i;
}
void main1() {
	
	for (i = 1; i <= 10; i++) {
		
		printf("%d\n", square(i));
	}
}
