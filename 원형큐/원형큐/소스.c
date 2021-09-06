#include<stdio.h>
#include<stdlib.h>
struct GENERAL {
	int level;
	int key;
	int child_key;
};
struct GENERAL tree;
int main() {
	int i = 0;//노드가 몇개인지 세는 용도
	while (scanf_s("(%d %d %d)", &tree.level, &tree.key, &tree.child_key) == 3) {
		i++;
	}
	printf("\ni=%d\n", i);
	return 1;
}

/*
#include<stdio.h>
int q[10];//global queue
int front = 0, back = 0;

int enqueue(int);
int dequeue(int*);
int queue_full();
int queue_empty();

void main() {
	int val;
	// these series of enqueue and dequeue is just for the test
	enqueue(10);
	enqueue(35);
	if (dequeue(&val) != -1) printf("dequeue: %d\n", val);
	if (dequeue(&val) != -1) printf("dequeue: %d\n", val);
	enqueue(50);
	enqueue(20);
}
//check the queue is full or not.
int queue_full() {
	if ((back + 1) == front) return 1;
	else return 0;
}
//check the queue is empty or not.
int queue_empty() {
	if (front == back) return 1;
	else return 0;
}
//appends data to the queue, if queue is not full, then get a new item.
int enqueue(int newitem) {
		int ch = queue_full();
		if (ch) {
			return -1;
		}
		else {
			back = (back + 1) ;
			q[back] = newitem;

			return 0;
		}
}
//removes data from the queue, if queue is not empty, the output would be going to the 'frontest' one.
int dequeue(int *item) {
		int ch = queue_empty();
		if (ch) {
			return -1;
		}
		else {
			front = (front + 1);
			*item = q[front];

			return 0;
		}

}
/*# define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int enqueue(int);
int dequeue(int*);
int is_full();
int is_empty();

int q[5];
int front = 0, back = 0;

void main() {
	int val;
	enqueue(10);
	enqueue(40);
	enqueue(15);
	enqueue(35);
	if (dequeue(&val) != -1) printf("dequeue: %d\n", val);
	if (dequeue(&val) != -1) printf("dequeue: %d\n", val);
	enqueue(50);
	enqueue(20);
	enqueue(25);
	enqueue(50);
	if (dequeue(&val) != -1) printf("dequeue: %d\n", val);
	if (dequeue(&val) != -1) printf("dequeue: %d\n", val);
	if (dequeue(&val) != -1) printf("dequeue: %d\n", val);
	if (dequeue(&val) != -1) printf("dequeue: %d\n", val);
	if (dequeue(&val) != -1) printf("dequeue: %d\n", val);
	if (dequeue(&val) != -1) printf("dequeue: %d\n", val);

}
int enqueue(int newitem) {
	printf("enqueue=%d\n", newitem);
	int ch = is_full();
	if (ch) {
		printf("full\n");
		return -1;
	}
	else {
		back = (back + 1) % 5;
		q[back] = newitem;

		return 0;
	}
}
int dequeue(int *item) {
	int ch = is_empty();
	if (ch) {
		printf("empty\n");
		return -1;
	}
	else {
		front = (front + 1) % 5;
		*item = q[front];

		return 0;
	}

}
int is_full() {
	if ((back+1)%5==front) return 1;//가득 차있으면 1을 반환
	else return 0;
}
int is_empty() {
	if (front == back) return 1;//비어있을 때 1
	else return 0;
}*/
