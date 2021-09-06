#include <stdio.h>
# define MAX 10

int top;
int stack[MAX];

int stack_empty();
int stack_full();
int push(int);
int pop(int*);

void main() {
	top = -1;
	int val;
	
	push(10);
	if (pop(&val) != -1) printf("pop: %d\n", val);
	push(20);
	push(30);
	push(400);
	if (pop(&val) != -1) printf("pop: %d\n", val);

}
//check the stack is empty or not.
int stack_empty() {
	if (top == -1) return 1; 
	else return 0;
}
//check the stack is full or not.
int stack_full() {
	if (top == MAX - 1) return 1; 
	else return 0;
}
//appends data to the stack, if stack is not full, then get a new item.
int push(int newitem) {

	if (stack_full()) {
		return 0;
	}
	else {
		top += 1;
		stack[top] = newitem;
		return 1;
	}
}
//removes data from the stack, if stack is not empty, 
//the output would be going to the 'latest' one.
int pop(int *item) {
	if (stack_empty()) {
		return 0;
	}
	else {
		*item = stack[top];
		top =top - 1;
		return 1;
	}
}