#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

//202035400 현선명

int exactMatch(char, char);
int partialMatch(char, char);
int partialMatch2(char, char);

main() {
	//s is for strings, s_s is for search-for-string
	char s[100]="tiger tiker hier their toner tigger tiggggger tier", s_s[50];

	//get inputs of s_s
	printf("\n Texts: %s", s);
	//Assumption: Wildcard is used only in the muddle of string, and only once.
	printf("\n Enter any strings for search: ");
	gets(s_s);//read search-string

	int exactcount = 0;
	for (int i = 0; s[i] != '*' && s[i] != '#'; i++) {// exactMatch실행조건, *과 #이 없을것.
			exactcount = exactMatch(s, s_s);
	}
	
	if (exactcount!=0)// exactMatch가 실행되어 값이 있다면 값을 print.
	printf("\n======================\nNumber of times: %d\n", exactcount);// print number of sub-strings that match the search string, from exactmatch
	
	
	char shap[] = "#", astrisk[]="*";
	
	int partialcount = 0;
	if (strstr(s_s, shap) == NULL) {// when it comes to *
		partialcount = partialMatch(s, s_s);
		printf("\n======================\nNumber of times: %d\n", partialcount);// print number of sub-strings that match the search string, from partialmatch
	}
	int partialcount2 = 0;
	if (strstr(s_s, astrisk) == NULL){// when it comes to #
		partialcount2 = partialMatch2(s, s_s);
		printf("\n======================\nNumber of times: %d\n", partialcount2);// print number of sub-strings that match the search string, from partialmatch
	}
}

int exactMatch(char s[100], char s_s[50]) {
	
	int count = 0;// to count if there is search-for-string in stings.
	int slen = strlen(s), s_slen = strlen(s_s);//The length of string and search-for-string
	char* cursor = strstr(s, s_s); //address at the moment of finding a word

	for (int i = 0; i < slen; i++) { //for loop through string length

		if (s_s[0] == s[i]) {// if first character of search-string found

			for (int j = 0; j < s_slen; j++) { //for loop through length of search-string

				if (cursor != NULL) { //if substring matches the search-string,
					count++;//if search-for-string is found, add 1.
					cursor = strstr(cursor + s_slen, s_s);//Move cursor behind found string
					
				}
			}
		}
	}
	return count;
	
}

int partialMatch(char s[100], char s_s[50]) {
	//dividing the search string start
	//divide the search string into two parts, front is first part and end is second part
	char front[50] = "", end[50] = { NULL };

	int k;//for loop which one is for dividing before * and after*
	int count = 0; //for counting of matched strings.
	for (k = 0; s_s[k] != '*'; k++) {//Save strings up to * in front of the 'front'
		front[k] = s_s[k];
	}

	int endstart = k + 1;// Declaring to set an end's starting point

	for (k = endstart; s_s[k] != '\0'; k++) {//Save string from * behind to \0 on end
		end[k - endstart] = s_s[k];
	}//dividing the search string end.


	int frontlen = strlen(front), endlen = strlen(end); //The length of characters entered divided before and after *
	int number = 0;//Declares number separately because declaring i=0 in the loop will continue to return to the beginning.
	int j = 0;

	char* cursor = strstr(s, front); //'cursor' might have address when it can find first part and second part, this is initialized value
	char* remainder = strstr(s, front);// to save the 'cursor' in seperate way, this is initialized value

	//searching for match starts
	
		for (int i = number; s[i] != '\0'&& cursor != NULL && remainder != NULL; i++) { //loop until the string ends or no longer matches the 'front' and 'end'
			//find substring that matches the first part of the search string
			//find the first part then cursor will have its address
			if (s[i] != ' ') {
				
				cursor = strstr(remainder, front);
				/*Find the first part from the address after you find the second part. If it just started, it's to find the first part.
				The reminder stores the starting address of the second part of the most recent loop, so you can find the first part after you find the second part.*/

				if (cursor != NULL) { //if found, start from the end of the first part and find substring that matches the second part of the search string

					for (j = i + 1; j > i && s[j] != '\0'&&remainder != NULL; j++) {//After the address of the first part found in the most recent loop and until the string is terminated

						cursor = strstr(cursor + frontlen, end);//Find the second part after the first part
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
			}
			else { number = i; continue; }
		}//search for finding matches end
		
		
		//take a way the count from count decided. when it goes no charter between front and end, then get a minus 1
		char tier[30] = strcat(front,end);
	
		cursor = strstr(s, tier); //address at the moment of finding a word
		for (int i = 0; i < strlen(s); i++) { //for loop through string length

			if (s_s[0] == s[i]) {// if first character of search-string found

				for (int j = 0; j < strlen(s_s); j++) { //for loop through length of search-string

					if (cursor != NULL) { //if substring matches the search-string,
						count--;//if search-for-string is found, add 1.
						cursor = strstr(cursor + strlen(tier), tier);//Move cursor behind found string

					}
				}
			}
		}

	return count;
}

int partialMatch2(char s[100], char s_s[50]) {
	
	char front[50] = "", end[50] = { NULL };

	int k;//for loop which one is for dividing before # and after#
	int count = 0; //for counting of matched strings.
	for (k = 0; s_s[k] != '#'; k++) {//Save strings up to # in front of the 'front'
		front[k] = s_s[k];
	}
	
	int endstart = k ;// Declaring to set an end's starting point

	char blank[] = "";
	for (k = endstart; s_s[k] == '#'; k++) {//Save string from # behind to \0 on end
		blank[k - endstart+1]; //calculate how many '#' in s_s
	}
	int many = k - endstart + 1;

	for (k = endstart; s_s[k] != '\0' ; k++) {//Save string from # behind to \0 on end
		if (s_s[k] != '#') { endstart = k;  continue; }
		end[k - endstart] = s_s[k];
	}
	//dividing the search string end.


	int frontlen = strlen(front), endlen = strlen(end); //The length of characters entered divided before and after #
	int number = 0;//Declares number separately because declaring i=0 in the loop will continue to return to the beginning.
	int j = 0;

	char* cursor = strstr(s, front); //'cursor' might have address when it can find first part and second part, this is initialized value
	char* remainder = strstr(s, front);// to save the 'cursor' in seperate way, this is initialized value

	//searching for match starts

	for (int i = number; s[i] != '\0'&& cursor != NULL && remainder != NULL; i++) { //loop until the string ends or no longer matches the 'front' and 'end'
		//find substring that matches the first part of the search string
		//find the first part then cursor will have its address
		if (s[i] != ' ') {

			cursor = strstr(remainder, front);

			/*Find the first part from the address after you find the second part. If it just started, it's to find the first part.
			The reminder stores the starting address of the second part of the most recent loop, so you can find the first part after you find the second part.*/

			if (cursor != NULL) { //if found, start from the end of the first part and find substring that matches the second part of the search string

				for (j = i + 1; j > i && s[j] != '\0'&&remainder != NULL; j++) {//After the address of the first part found in the most recent loop and until the string is terminated

					cursor = strstr(cursor + frontlen, end);//Find the second part after the first part
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
		}
		else { number = i; continue; }
	}//search for finding matches end

	
	return count;
	
}