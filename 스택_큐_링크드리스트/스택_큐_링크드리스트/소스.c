# define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int enqueue(int);
int dequeue(int*);
int queue_full();
int queue_empty();

int q[5];
int front = 0, back = 0;

//test program using the sequence of inserts and deletes shown in pages 22-23
void main() {
	int val;

	enqueue(10);
	enqueue(50);
	enqueue(20);
	enqueue(70);
	if (dequeue(&val) != -1) printf("dequeue: %d\n", val);
	
	enqueue(100);
	enqueue(40);
	enqueue(140);
	if (dequeue(&val) != -1) printf("dequeue: %d\n", val);
	if (dequeue(&val) != -1) printf("dequeue: %d\n", val);
	if (dequeue(&val) != -1) printf("dequeue: %d\n", val);

}

//for circular queue, to use the spaces that already used, use the reminder operator
//appends data to the queue, if queue is not full, then get a new item.
int enqueue(int newitem) {
	int ch = queue_full();
	if (ch) {
		printf("as front= back+1, so queue overflow\n");
		return -1;
	}
	else {
		back = (back + 1) % 5;
		q[back] = newitem;

		return 0;
	}
}
//removes data from the queue, if queue is not empty, the output would be going to the 'frontest' one.
//before delete item in the front, it has to move the position of front.  
int dequeue(int *item) {
	int ch = queue_empty();
	if (ch) {
		printf("queue is empty\n");
		return -1;
	}
	else {
		front = (front + 1) % 5;
		*item = q[front];

		return 0;
	}

}
//check the queue is full or not.
//as front= back+1, so queue overflow
int queue_full() {
	if ((back + 1) % 5 == front) return 1;
	else return 0;
}
//check the queue is empty or not.
//if front item is same as back item, then queue is empty
int queue_empty() {
	if (front == back) return 1;//비어있을 때 1
	else return 0;
}