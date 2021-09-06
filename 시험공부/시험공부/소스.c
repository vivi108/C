# define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int q[10], subq[10];
int front = 0, back = 0;//for using in main Queue
int subfront = 0, subback = 0;//for using in sub Queue

int push(int);
int pop(int*);// this pop function is same as dequeue function in main Queue

int enqueue(int);
int queue_full();
int queue_empty();

//these functions for sub queue
int subenqueue(int);
int subdequeue(int*);
int subqueue_full();
int subqueue_empty();

void main() {
	int val;
	push(10);
	push(20);
	push(30);
	push(40);
	if (pop(&val) != -1) printf("pop: %d\n", val);
	if (pop(&val) != -1) printf("pop: %d\n", val);
	if (pop(&val) != -1) printf("pop: %d\n", val);
	if (pop(&val) != -1) printf("pop: %d\n", val);

}
//this push fuction is working with three steps.
//first, all of the components in the main queue are moved to the sub queue until main queue is empty.
//second, get a new item and save it to the main queue.
//thire, all of the components in the subqueue that saved temporarily should go back to the main queue, until subqueue is empty. 
int push(int newitem) {
	int carry;
	for (int i = 0; i < 10; i++) {
		if (queue_empty()) {
			break;
		}
		pop(&carry);
		subenqueue(carry);
	}

	enqueue(newitem);
	
	for (int i = 0; i < 10; i++) {
		if (subqueue_empty()) break;
		subdequeue(&carry);
		enqueue(carry);
	}
	return 1;
}

//For smooth exchachge between main Queue and sub Queue, all Queue should be the circular ones.

//-----for main Q--------------
//appends data to the main queue, if queue is not full, then get a new item.
int enqueue(int newitem) {
	int ch = queue_full();
	if (ch) {
		printf("full\n");
		return -1;
	}
	else {
		back = (back + 1) % 10;
		q[back] = newitem;

		return 0;
	}
}
//removes data from the queue, if queue is not empty, the output would be going to the 'frontest' one.
//In part, it plays the role of dequeue, but in general, it also plays the role of Pop, so it is called Pop.
int pop(int *item) {
	int ch = queue_empty();
	if (ch) {
		printf("empty\n");
		return -1;
	}
	else {
		front = (front + 1) % 10;
		*item = q[front];

		return 0;
	}

}
//check the main queue is full or not.
int queue_full() {
	if ((back + 1) % 10 == front) return 1;
	else return 0;
}
//check the main queue is empty or not
int queue_empty() {
	if (front == back) return 1;
	else return 0;
}


//-------------for sub Q----------------------------------------------------
//appends data to the sub queue, if queue is not full, then get a new item.
int subenqueue(int newitem) {
	int ch = subqueue_full();
	if (ch) {
		printf("sub queue full\n");
		return -1;
	}
	else {
		subback = (subback + 1) % 10;
		subq[subback] = newitem;

		return 0;
	}
}
//removes data from the sub queue, if queue is not empty, the output would be going to the 'frontest' one from the sub queue.
int subdequeue(int *item) {
	int ch = subqueue_empty();
	if (ch) {
		printf("sub queue empty\n");
		return -1;
	}
	else {
		subfront = (subfront + 1) % 10;
		*item = subq[subfront];

		return 0;
	}

}
//check the sub queue is full or not.
int subqueue_full() {
	if ((subback + 1) % 10 == subfront) return 1;
	else return 0;
}
//check the sub queue is empty or not
int subqueue_empty() {
	if (subfront == subback) return 1;
	else return 0;
}