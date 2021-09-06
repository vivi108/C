//
// Software Pattern Lab#2
// ID:202035400
// Name:현선명
//

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>


struct Index
{
	char word[100];
	int num;
	int position[100];
};

// global variable
// idx_length indicate the length of the index array
int idx_length = 0;//리스트의 크기가 무엇이냐

//*******************************************************************************************************
// You can only modify inside the function.
// in: text - sample text
// out: index - created index table from sample text
void create_index(char* text, struct Index* index)
{
	//index에 속한 position과 word에 NULL값 넣기, 초기화
	for (int k = 0; k < 100; k++) {
		for (int n = 0; n < 100; n++) {
			index[k].word[n] = NULL;
			index[k].position[n] = NULL;
		}
	}
	int  i = 0, j = 0, num = 0;
	
	//Divide words by space
	for (int k = 0; k < strlen(text); k++) {//k is related to the number of characters
		
		if (text[k] != ' ') {
			index[i].word[j] = text[k]; //i is related to chunk
			index[i].position[0] = i;// Store the location of each word
			j++;
		}
		if (text[k] == ' ') { //Move on to the next chunk when there's a space.
			i++;
			j = 0;//word[]To start an array with word[0]
		}
	}
	num = i;// num is the total number of chunks
	
	
	//Compare words to increase the number of nums for the same word.
	for (int k = 0; k < num; k++) {//Turn the loops as many times as the number of chunks.
		for (j = k+1; j < num; j++) {
			if (strcmp(index[k].word, index[j].word) == 0) {
				index[k].num++;
				strcat(index[k].position, &j);//Adding the location of a chunk when the same word appears in the postion.
				strcpy(index[j].word, index[j+1].word);
			}

		}printf("\n-----------------------\n");
		printf("\n%s\n", index[k].word);
	}

}

// in: index - index table created by create_index function
// in: str - string to find
void print_result(struct Index* index, char* str)
{
	printf("\"%s\"", str);
	
}
//*******************************************************************************************************

// Do not modify this function
void print_index(struct Index* index)
{
	printf("word index\n");
	printf("----------------\n");
	for (int i = 0; i < idx_length; i++) {
		printf("%12s, %8d, (", index[i].word, index[i].num);
		for (int j = 0; j < index[i].num; j++) {
			if (j == 0) printf("%d", index[i].position[j]);
			else printf(", %d", index[i].position[j]);
		}
		printf(")\n");
	}
	printf("\n");
}

int main()
{
	char sample_text[1024] = "it was the best of times it was the worst of times it was the age of wisdom it was the age of foolishness it was the epoch of belief";
	struct Index index_table[100];	for (int i = 0; i < 100; i++) index_table[i].num = 0;
	// create init
	create_index(sample_text, index_table);

	// print_index
	print_index(index_table);

	// get string and find the number of times it occurs and following words
	char str[1024];
	printf("input string: ");
	scanf("%s", str);

	// print result
	// 1. Print the number of occurence
	// 2. Print next two words
	print_result(index_table, str);

	return 1;
}