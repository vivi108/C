#include<stdio.h>
#include<string.h>

void main() {

	
	char* s, *string="abc ";
	char buf[81] = "This is a test";
	s = strchr(buf, 't');
	if (s= strchr(buf, 't')) {
		printf("%p\n", s);
		printf("%p", buf+10);
	}
	
}

/**char* strchr1(char buf[], char c) {
	int k = 0;
	while (buf[k] != NULL) {
		if (buf[k] == c) (char *)%buf
	}

}**/