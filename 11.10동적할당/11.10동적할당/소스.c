#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
struct NODE {
	int key;
	struct NODE *next;
};
struct NODE *node0, *node1, *node2;
void main() {
	/*EXERCISE4
	node0 = (struct NODE *)malloc(sizeof(struct NODE));
	node1 = (struct NODE *)malloc(sizeof(struct NODE));
	node2 = (struct NODE *)malloc(sizeof(struct NODE));
	node0->next = &node1;
	node1->next = &node2;
	node2->next = NULL;
	
	EXERCISE3
	node = (struct NODE *)malloc( sizeof(struct NODE));
	if (node == (struct NODE*)NULL)printf("failed");
	scanf("%d", node->key);
	node->key = NULL;
	
	
	free(node);
	
	EXERCISE1
	int num;
	int* nums;
	nums = (int *)malloc(10*sizeof(num));
	if (nums == (int*)NULL)printf("failed");
	free(nums);

	int* nums;
	nums = (int *)malloc(10 * sizeof(int));
	if (nums == (int*)NULL)printf("failed");
	
	EXERCISE2
	int i;
	for (int i = 0; i < 10; i++) {
		scanf("%d", &nums[i]);
	}
	for (int i = 0; i < 10; i++) {
		printf("%d", nums[i]);
	}
	free(nums);*/
}
