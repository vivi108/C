#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int saveIntoLL(struct NODE * , int , int);
void printLL(struct NODE * );

struct NODE {
	int pid, priority, arrival_t, burst_t;
	struct NODE *next;
};
struct NODE pc[10];
struct NODE *head;


void main() {
	head= (struct NODE *)malloc(sizeof(struct NODE));
	
	FILE * input = fopen("input.txt", "r");
	if (input == (FILE *)NULL) printf("no file");
	int n = 0;
	while ((fscanf(input, "%d %d %d %d", &pc[n].pid, &pc[n].priority, &pc[n].arrival_t, &pc[n].burst_t )) == 4) n++;
	fclose(input);
	saveIntoLL(head,0, n);
	printLL(head);
}

int saveIntoLL(struct NODE * node, int i, int n) {
	if (i == n) return 0;
		head->pid = pc[i].pid;
		head->pid = pc[i].priority;
		head->arrival_t = pc[i].arrival_t;
		head->burst_t = pc[i].burst_t;
		saveIntoLL(head->next,i + 1, n);
}
void printLL(struct NODE * node) {
	if (node == NULL)printf("end");
	printf("%d %d %d %d", head->pid, head->pid, head->arrival_t, head->burst_t);
	printLL(head->next);
}