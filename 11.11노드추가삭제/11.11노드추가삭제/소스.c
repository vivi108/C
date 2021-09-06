#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

struct NODE {
	int key;
	struct NODE *next;
};
struct NODE* node, *ptr, *optr=NULL ;
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
	
	node[3].key = 300;
	int newkey = node[3].key;

	while (ptr) {
		if (ptr->key == newkey) {
			printf("already exist");
		}
		if (ptr->key > newkey) {
			optr = ptr;
			ptr= 
		}
		ptr = ptr->next;
	}
	
/*
EXERCISE5
 struct NODE* ptr, * node0, * node1, * node2;	int found = 0;	node0 = (struct NODE*)malloc(sizeof(struct NODE));	node1 = (struct NODE*)malloc(sizeof(struct NODE));	node2 = (struct NODE*)malloc(sizeof(struct NODE));	node0->key = 100;	node1->key = 250;	node2->key = 467;	node0->next = node1;	node1->next = node2;	node2->next = NULL;


	링크드리스트 출력하는법
	void printList(struct NODE* ptr){    struct NODE* ptr;    while (ptr)    {        printf("key:%d\n", ptr->key);        ptr = ptr->next;    }}
추가
#include <stdio.h>#include <stdlib.h>struct NODE {	int key;	struct NODE* next;};void printList(struct NODE* ptr){	while (ptr)    {		printf("key:%d\n", ptr->key);		ptr = ptr->next;	}}
int main(){
	struct NODE* ptr, *old_ptr, *node0, *node1, *node2;	int found = 0;	node0 = (struct NODE*)malloc(sizeof(struct NODE));	node1 = (struct NODE*)malloc(sizeof(struct NODE));	node2 = (struct NODE*)malloc(sizeof(struct NODE));	node0->key = 100;	node1->key = 250;	node2->key = 467;	node0->next = node1;	node1->next = node2;	node2->next = NULL;	printf("Original List\n");	printList(node0);	struct NODE* new_node = (struct NODE*)malloc(sizeof(struct NODE));	new_node->key = 300;	new_node->next = NULL;	ptr = node0;	while (ptr)	{		if ((*ptr).key == new_node->key)		{			printf("key already exists\n");			break;		}		if ((*ptr).key < new_node->key)		{			old_ptr = ptr;			ptr = (*ptr).next;		}		else		{			(*old_ptr).next = new_node;			new_node->next = ptr;			printf("key inserted");			break;		}	}	printf("Inserted List\n");	printList(node0);	// free pointers by yourself	return 1;}

삭제
#include <stdlib.h>struct NODE {	int key;	struct NODE* next;};int main(){	struct NODE* node;	struct NODE* ptr, *old_ptr;	node = (struct NODE*)malloc(3 * sizeof(struct NODE));	node[0].key = 100;	node[1].key = 250;	node[2].key = 467;	node[0].next = &node[1];	node[1].next = &node[2];	node[2].next = NULL;	ptr = &node[0];	while (ptr) {		printf("%d ", ptr->key);		ptr = ptr->next;	}	int delkey;	printf("\nType del key : ");	scanf("%d", &delkey);	ptr = &node[0];	while (ptr){		if (ptr->key == delkey) {			old_ptr->next = ptr->next;			ptr->next = NULL;			break;		}		else {			old_ptr = ptr;			ptr = ptr->next;		}	}	ptr = &node[0];	while (ptr) {		printf("%d ", ptr->key);		ptr = ptr->next;	}}
	*/