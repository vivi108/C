#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct NODE {
	int index;
	char bucket[10];
	struct NODE * chain;
};
struct NODE draft[40];
struct NODE *hash[33];

struct NODE* Search(char *);
int Insert(char *, struct NODE *);
int Delete(char *);
void print();
int hash_Function(char *);

//Read from file
//Give and initialize hash tables
//Create Table
//1. Insert into the created table
//2. search
//3. delete
//4. insert
//5. search
//6.print again
void main() {
	FILE * input = fopen("keyinput.txt", "r");
	if (input == (FILE *)NULL) printf("no file");
	int n = 0;
	while ((fscanf(input, "%s", draft[n].bucket)) == 1) n++;
	fclose(input);
	
	
	for (int i = 0; i < 33; i++) {
		hash[i] = (struct NODE *)malloc(sizeof(struct NODE));
		hash[i]->index = i;
		hash[i]->chain = NULL;
		for (int j = 0; j < 10; j++) {
			hash[i]->bucket[j] = NULL;
		}

	}
	
	for (int i = 0; i < n; i++) {
		struct NODE* node = (struct NODE *)malloc(sizeof(struct NODE));
		char * p = draft[i].bucket;
		node = &draft[i];
		node->chain = NULL;
		node->index = hash_Function(node->bucket);
		if (Insert(p,node) == 1 )printf("insert\n");
		else printf("existed\n");

		
	}
	printf("\n----print-----\n");
	print();
	
	printf("\n----searching-----\n");
	if (Search("Blue") != NULL)printf("found\n");
	else printf("not found\n");
	if (Search("black") != NULL)printf("found\n");
	else printf("not found\n");
	if (Search("Green") != NULL)printf("found\n");
	else printf("not found\n");

	printf("\n----Delete-----\n");
	Delete("Purple");
	Delete("Blue");
	Delete("Green");
	
	printf("\n----Insert-----\n");
	char * g = "Green";
	char *w = "White";
	char *go = "Golden";
	char *ne = "nedloG";
	struct NODE color[4];
	strcpy(color[0].bucket,g);
	strcpy(color[1].bucket, w);
	strcpy(color[2].bucket, go);
	strcpy(color[3].bucket, ne);

	for (int i = 0; i < 4; i++) {
		struct NODE* node2 = (struct NODE *)malloc(sizeof(struct NODE));
		char * p = color[i].bucket;
		node2 = &color[i];
		node2->index = hash_Function(node2->bucket);
		node2->chain = NULL;
		
		if (Insert(p, node2) == 1)printf("insert\n");
		else printf("existed\n");
	}
	
	printf("\n----searching-----\n");
	if (Search("Blue") != NULL)printf("found\n");
	else printf("not found\n");
	if (Search("nedloG") != NULL)printf("found\n");
	else printf("not found\n");
	if (Search("Yellow") != NULL)printf("found\n");
	else printf("not found\n");
	if (Search("Green") != NULL)printf("found\n");
	else printf("not found\n");
	
	printf("\n----print-----\n");
	print();
}

//Get the key value from the hash function.
// return 0 if it already exists using the search function.
// Or put the value and index value in the same place, if they are full, link to chain.
//(struct NODE * n is for new node that made above)
int Insert(char *item, struct NODE * n)
{
	int hash_key =  hash_Function(item);
	if (Search(item) !=NULL ) return 0;
	if ( hash[hash_key]->bucket == NULL){
		hash[hash_key] = n;
	}
	else{
		n->chain = hash[hash_key];
		hash[hash_key] = n;
	}
	return 1;
}
//Get the hash key value by inputting the word you want to find
//Return NULL if not present
//Return what you find, if any.
//Find something else linked to the link list and return what you found
struct NODE* Search(char * key)
{
	int hash_key = hash_Function(key);
	if (hash[hash_key] == NULL)
		return NULL;

	if (strcmp(hash[hash_key]->bucket, key)==0){
		return hash[hash_key];
	}
	else{
		struct NODE* node = hash[hash_key];
		while (node->chain){
			if (strcmp(node->chain->bucket, key) == 0){
				return node->chain;
			}
			node = node->chain;
		}
	}
	return  NULL;
}
//Get the hash key value by taking the word you want to erase as input
// Return 0 that could not be found if the index you want to erase is empty
// If you find it, save the current item somewhere else
// Drag and drop the node to which the following chain points:
// If not found, browse and delete the chain while it is not null.
int Delete(char * item){
	int hash_key = hash_Function(item);
	if (hash[hash_key] == NULL) {
		printf("not found\n");
		return 0;
	}
	if (strcmp(hash[hash_key]->bucket, item) == 0){
		hash[hash_key] = hash[hash_key]->chain;
		printf("deleted\n");
		return 1;
	}
	else{
		struct NODE* node = hash[hash_key];
		struct NODE* next = node->chain;
		while (next){
			if (strcmp(next->bucket, item) == 0){
				node->chain = next->chain;
				printf("deleted\n");
				return 1;
				break;
			}
			node = next;
			next = node->chain;
		}
	}
	
}
// If empty while running 33 indexes, output NULL, otherwise output up to linked list.
void print() {
	for (int i = 0; i < 33; i++){
		printf("index: %d\t",i);
		if (hash[i] != NULL){
			if (strcmp(hash[i]->bucket, "\0")==0) printf("NULL");
			struct NODE* node = hash[i];
			while (node->chain){
				printf("%s ",node->bucket);
				node = node->chain;
			}
		}
		printf("\n");
	}
}

int hash_Function(char *key) //h(x)
{
		int count = 0, sum = 0;
		while (key[count] != '\0') {
			sum += key[count];
			count++;
		}
		return sum % 33;
}
