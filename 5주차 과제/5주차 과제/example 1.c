#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>// header file to use strstr, and strlen

main() {
	//s is for strings, s_s is for search-for-string
	char s[500], s_s[50];
	
	//get inputs of s and s_s
	printf("\n Enter any strings for search: ");
	gets(s_s);
	
	printf("\n Enter any strings: ");
	gets(s);

	int found=0;// Declare if found or not, one if found, zero if not found..
	int count = 0;// to count if there is search-for-string in stings.
	int slen= strlen(s), s_slen= strlen(s_s);//The length of string and search-for-string
	char* cursor = strstr(s, s_s); //address at the moment of finding a word

	for (int i = 0; i < slen; i++) { //for loop through string length
		
		if (s_s[0] == s[i] ) {// if first character of search-string found
			
			for (int j = 0; j < s_slen; j++) { //for loop through length of search-string
				
				if (cursor!= NULL) { //if substring matches the search-string,
					found=1;//turn on the 'found' to 1
				}
				if (found) {//if found has integer,
					count++;//if search-for-string is found, add 1.
					cursor= strstr(cursor+s_slen, s_s);//Move cursor behind found string
					found = 0;// turn off the 'found' to use again in the loop
				}
			}
		}
	}
	
	printf("\n======================\ncount= %d", count);// print number of sub-strings that match the search string
}