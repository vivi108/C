#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct NODE {
	int key;
	struct NODE *next;
};
struct NODE* node, *ptr, *optr = NULL, *first, *newnode;
void insert(int);
void delete(int);
void main() {
	node = (struct NODE*)malloc(4 * sizeof(struct NODE));
	if (node == (struct NODE*)NULL) printf("ERROR");
	node[0].key = 100;
	node[1].key = 250;
	node[2].key = 467;

	node[0].next = &node[1];
	node[1].next = &node[2];
	node[2].next = NULL;
	ptr = &node[0];
	
	int newkey;
	scanf("%d", &newkey);

}
void insert(int delkey) {
	
	first = &node[0];
	ptr =first
	while (ptr)	{		if (ptr->key == delkey) {			if (first == ptr) {				first = ptr->next;				ptr->next = NULL;				break;			}					}		else {			optr->next = ptr->next;			ptr->next = NULL;			break;		}			}	printf("Inserted List\n");	
}
void delete(int k) {

}