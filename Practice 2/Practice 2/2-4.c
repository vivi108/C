#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
	int i, j, k, size;
	size = argc - 1;
	char *key;
	char* a[ - 1];

	for (i = 2; i < argc; i++) {
		key = argv[i];

		j = i - 1;
		while (j >= 1 && strcmp(argv[j], key) > 0) {
			argv[j + 1] = argv[j];
			j--;
		}

		argv[j + 1] = key;
	}

	//Problem                                                                                                                                                   
	//for(i = 2; i < size; i++){                                                                                                                                
	//    if(argv[i-1] != argv[i])                                                                                                                              
	//      a[i] = argv[i-1];                                                                                                                                   
	//}                                                                                                                                                         

	//for(i=0; i< size; i++)                                                                                                                                    
	//  puts(a[i]);                                                                                                                                             

	for (i = 1; i < argc; i++)
		puts(argv[i]);

	return 0;
}