#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

main() {
	//s is for strings, s_s is for search-for-string
	char s[500], s_s[50];
	int count = 0; //for counting of matched strings.

	//get inputs of s and s_s
	//Assumption: Wildcard is used only in the muddle of string, and only once.
	printf("\n Enter any strings for search: ");
	gets(s_s);//read search-string

	printf("\n Enter any strings: ");
	gets(s);//read string


	//dividing the search string start
	//divide the search string into two parts, front is first part and end is second part
	char front[50] = "", end[50] = { NULL };
	
	int k;//for loop which one is for dividing before * and after*
	
	for (k = 0; s_s[k] != '*'; k++) {//Save strings up to * in front of the 'front'
		front[k]= s_s[k];
	}
	
	int endstart = k + 1;// Declaring to set an end's starting point
	
	for (k=endstart; s_s[k] != '\0'; k++) {//Save string from * behind to \0 on end
		end[k-endstart]= s_s[k];
	}
	printf("\n========================\nfront:%s", front);//check the first part
	printf("\nend:%s\n=========================\n", end);//check the second part
	//dividing the search string end.
	
	
	int frontlen = strlen(front), endlen=strlen(end); //The length of characters entered divided before and after *
	int number = 0;//Declares number separately because declaring i=0 in the loop will continue to return to the beginning.
	int j = 0;

	char* cursor= strstr(s, front); //'cursor' might have address when it can find first part and second part, this is initialized value
	char* remainder= strstr(s, front);// to save the 'cursor' in seperate way, this is initialized value
	
	//searching for match starts
	for (int i = number; s[i]!='\0'&& cursor!=NULL && remainder!=NULL; i++) { //loop until the string ends or no longer matches the 'front' and 'end'
		//find substring that matches the first part of the search string
		//find the first part then cursor will have its address
		
		cursor = strstr(remainder, front);
		/*Find the first part from the address after you find the second part. If it just started, it's to find the first part.
		The reminder stores the starting address of the second part of the most recent loop, so you can find the first part after you find the second part.*/

		if (cursor!=NULL) { //if found, start from the end of the first part and find substring that matches the second part of the search string
			
			for (j = i+1; j>i && s[j]!='\0'&&remainder != NULL; j++) {//After the address of the first part found in the most recent loop and until the string is terminated
				
				cursor = strstr(cursor+frontlen, end);//Find the second part after the first part
				remainder = cursor;
				
				if (cursor != NULL) {// if second part of the search string is found, increment count by 1 and go to the next part of the string
					count++;//If you found the second part that matches the first part
					number = j;// Enter j into number so that the second part of the most recent loop can be found from the rear array
					
					remainder = strstr(cursor + endlen, front);//Find the first part from the address after finding the second part so that cursor = strstr(remainder, front); can get another first part's address
					break;//If you have found the second part that matches the first part, close the loop
					
				}
				else break;//If you haven't found the second part that matches the first part, exit.
			}
		}
		else break;//If there is no more first part to look for, loop exit
	}//search for finding matches end
	

	//print count
	printf("\n==================\nthe number of matched strings=%d", count);



}