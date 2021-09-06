#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>


struct NODE {
	int key;
	struct NODE *next;
};
struct NODE* node, *head;

int insertkey(int newkey, struct NODE *head, struct NODE *address) {
	
	struct NODE* newnode = (struct NODE*)malloc(sizeof(struct NODE));
	struct NODE* ptr = head->next, *prev= head;
	head->next = ptr;
	address = head->next;

	while (ptr) {
		if (ptr->key > newkey) break;
		else if (ptr->key == newkey) {
			return -1;
			break;
		}
		else{
			
			prev = ptr;
			ptr = ptr->next;
			
		}
	}
	
	newnode->key = newkey;
	prev->next = newnode;
	newnode->next = ptr;

	return 0;
			
}
void printList(struct NODE* ptr)
{
	while (ptr)
	{
		printf("key:%d\n", ptr->key);
		ptr = ptr->next;
	}printf("\n");
}
void main() {
	node = (struct NODE*)malloc(3 * sizeof(struct NODE));
	if (node == (struct NODE*)NULL) printf("ERROR");
	head = (struct NODE*)malloc(sizeof(struct NODE));

	node[0].key = 100;
	node[1].key = 250;
	node[2].key = 467;

	node[0].next = &node[1];
	node[1].next = &node[2];
	node[2].next = NULL;
	
	
	head->next =&node[0] ;
	printf("\n---------------------------\nOriginal List\n");
	printList(head->next);
	//
	int result =insertkey(250, head, head->next);
	if (result) printf("\n---------------------------\nfailed\n");
	else printf("\n---------------------------\nsuccessed\n");
	//
	result = insertkey(300, head, head->next);
	if (result) printf("failed\n");
	else printf("successed\n");
	//
	result = insertkey(50, head, head->next);
	if (result) printf("failed\n");
	else printf("successed\n");
	//
	result = insertkey(500, head, head->next);
	if (result) printf("failed\n");
	else printf("successed\n");

	printf("\n---------------------------\nInserted List\n");
	printList(head->next);
}