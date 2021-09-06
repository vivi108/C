#include<stdio.h> // call from Header file
void word_count(char*); //prototype of word_count Function

void main() {      //start with main function
	char str[10] = "hello";  //initializing the str[10]
	word_count(str);   //function call

}
void word_count(char* add) {  //function definition, add is address of str[]
	int i, count = 0; //declarations
	for (i = 0; i < 10; i++) {  
		if ( *(add+i) == '\0') break; // Using valid pointer arithmetic. As soon as it finds '\0', it ends..
		else count += 1; //Before '\0' is found from array, count the letters one by one.
	}
	printf("\nLetters: %d\n", count); //print how many letters str[10] has.
}