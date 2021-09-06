#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define NUM_PROC 10
#define SWITCH_OVERHEAD 1
struct NODE {
	int pid, burst_t, arrival_t, priority;
	int wait_t, turnaround_t, remain_t, response_t;
	struct NODE *next;
};
struct NODE pc[10];

int FCFS(int, struct NODE *);
int findTurnAroundTime(int, struct NODE *);
int findWaitingTime(int, struct NODE *);
int at_sort(struct NODE *, int);

void main() {

	FILE * input = fopen("input.txt", "r");
	if (input == (FILE *)NULL) printf("no file");
	int n = 0;
	while ((fscanf(input, "%d %d %d %d", &pc[n].pid, &pc[n].priority, &pc[n].arrival_t, &pc[n].burst_t)) == 4) n++;
	fclose(input);

	for (int i = 0; i < n; i++) {
		pc[i].wait_t = 0;
		//printf("%d %d %d %d\n",pc[i].pid, pc[i].priority, pc[i].arrival_t, pc[i].burst_t);
	}
	at_sort(pc, n);
	FCFS( n,  pc);
	
}
int FCFS(int n, struct NODE * p) {

	int  total_wt = 0, total_tat = 0;
	int  total_rt = 0; // response time
	int ct; // completion time
	// Function to find waiting time of all processes
	ct = findWaitingTime(n, p);
	// Function to find turn around time for all processes
	findTurnAroundTime(n, p);
	printf("Switching Time = %d\n", SWITCH_OVERHEAD);
	printf("ProcessID Arrival_T Burst_T Wait_T Turna_T Respo_T Priorty\n");
	for (int i = 0; i < n; i++) {
		total_wt = total_wt + p[i].wait_t;
		total_tat = total_tat + p[i].turnaround_t;
		total_rt = total_rt + p[i].response_t;
		int compl_time = p[i].turnaround_t + 0;
		printf("%5d\t%7d\t%7d\t%7d\t%7d\t%7d\t%7d\n",
			p[i].pid, p[i].arrival_t, p[i].burst_t, p[i].wait_t, p[i].turnaround_t, p[i].response_t, p[i].priority);
	}
	printf("Avg. Waiting_T = %9.2f\n", (float)total_wt / (float)n);
	printf("Avg. Turnaround_T = %9.2f\n", (float)total_tat / (float)n);
	printf("Avg. Response_T = %9.2f\n", (float)total_rt / (float)n);
	printf("Completion_T = %6d\n", ct);
	printf("Thoughput(#Jobs/Time)= %9.2f\n", (float)n / (float)ct);

	return 0;
}
// Function to calculate turn around time
int findTurnAroundTime(int n, struct NODE * p) {
	for (int i = 0; i < n; i++) p[i].turnaround_t = p[i].burst_t + p[i].wait_t;
	return 0;
}
int findWaitingTime(int n, struct NODE *p) {
	for (int i = 0; i < n; i++) {
		p[i].remain_t = p[i].burst_t;
	}

	int t = 0; // Current time

	while (1) {
		bool done = true;
		for (int i = 0; i < n; i++) {
			if (p[i].remain_t == p[i].burst_t) // first running quantum
				p[i].response_t = t + SWITCH_OVERHEAD; // response time

			if (p[i].remain_t > 0) {
				done = false;
				printf("%5d: SWITCHING %5d\n", t, SWITCH_OVERHEAD);
				t = t + SWITCH_OVERHEAD;
					printf("%5d: PID(%3d) %5d\n", t, p[i].pid, p[i].remain_t);
					t = t + p[i].remain_t;
					p[i].wait_t = t - p[i].burst_t;
					p[i].remain_t = 0;
				}
			}
		

		if (done == true) break;
	}
	return t; // Completion time

}
// Compare the process from 0 to n starting with n-1, then when i becomes n-2, put it in front and then compare it from n to last.
//If simultaneous, sort by process number. A small number comes out first.
int at_sort(struct NODE *pro, int n) {
	struct NODE temp;

	int i, j;
	for (i = n - 1; i > 0; i--) {
		for (j = 0; j < i; j++) {
			if (pro[j].arrival_t > pro[j + 1].arrival_t) {
				temp = pro[j + 1];
				pro[j + 1] = pro[j];
				pro[j] = temp;
			}
			else if (pro[j].arrival_t == pro[j + 1].arrival_t&&pro[j].pid > pro[j + 1].pid) {
				temp = pro[j + 1];
				pro[j + 1] = pro[j];
				pro[j] = temp;
			}
		}
	}
	return 0;
}