#include <stdio.h>

void main2() {
	//2. �Էµ� (5���� �����Ǵ� �׺��� ����) �߿��� 9�� ��� �������� 

	int a, b, c, d, e, f, count = 0;
	
	printf("Type the integer(5digits or fewer): \n");
	scanf_s("%d", &a);
	b = a / 10000;
	c = (a / 1000)%10;
	d = (a / 100)%10;
	e = (a /10)%10;
	f = a % 10;
	
	if (b == 9) 
		count += 1;
	if (c == 9) 
		count += 1;
	if (d == 9) 
		count += 1;
	if (e == 9) 
		count += 1;
	if (f == 9) 
		count += 1;
				
	printf("%d", count);
	

}












