#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct NODE {
	int key;
	struct NODE * next;
};
struct NODE *head= NULL;
struct NODE *top= NULL;

/*
Use the principle of pushing the remainder divided by 2 to the stack and then dividing the share again.
And pop all the value at once.
*/
void main() {
	int stack_empty();
	int pop();
	void push(int);

	int num, remainder;
	printf("Enter the decimal number: ");
	scanf_s("%d", &num);
	
	while (num != 0) {
		
		remainder = num % 2;
		push(remainder);
		num = num / 2;
	}

	while (1) {
		if (stack_empty() == -1) {
			printf("\n\n Now Stack Is Empty\n");
			break;
		}
		printf("%d", pop());
	}
}
int stack_empty()
{
	if ((head == NULL) && (top == NULL))
		return -1;
	else
		return 0;
}
//You do not need to use the linked list to verify that the function is full.
//Therefore, you can continue to enter values
void push(int remainder) {
	struct NODE *newnode = (struct NODE*)malloc(sizeof(struct NODE));
	if (newnode == (struct NODE *)NULL) {
		printf("malloc failed");
	}
	newnode->key = remainder;
	newnode->next = NULL;
	
	if ((head == NULL) && (top == NULL))
	{
		head = newnode;
		top = head;
	}
	else
	{
		top->next = newnode;
		top = newnode;
	}
	
}
//The properties of the stack cause the rest of the values to appear in the opposite order
int pop() {
	int value=0;
	struct NODE* prev = NULL;
	struct NODE* crr = head;
	
	if (head == top) {
		value = top->key;
		free(crr);
		top = NULL;
		head = NULL;
	}
	else {
		while (crr != NULL)
		{
			if (crr == top) break;
			prev = crr;
			crr = crr->next;
		}
		value = top->key;
		top = prev;
		top->next = NULL;
		free(crr);
	}
	return value;
}