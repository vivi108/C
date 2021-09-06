#include <stdio.h>
#include <string.h>

 void main3(){
	int i, j, len;
	char line[81]=" ";
	printf("Input: ");
	
	for (j = 0; j < 81; j++) {
		line[j] = getchar();
		if (line[j] == '\n') break;
	}

	len = strlen(line);

	printf("\nreversed string: ");
	for (i = len - 1; 0 <= i; --i){
    printf("%c", line[i]);
	 }
	printf("\n");


}

