#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define NUM_PROC 10
#define SWITCH_OVERHEAD 1

struct NODE {
	int pid, burst_t, arrival_t, priority, tempburst_t;
	int wait_t, turnaround_t, remain_t, response_t, intime, outtime;
	struct NODE *next;
};
struct NODE pc[10];
int at_sort(struct NODE *, int);
void scheduling(struct NODE * , struct NODE * , int , int* , int* );
void insert(struct NODE *, struct NODE * , int* , int* );

bool compare(struct NODE  p1, struct NODE  p2);
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
	
	priority(pc, n);
}
// It is used to include all the valid and eligible
// processes in the heap for execution. heapsize defines
// the number of processes in execution depending on
// the current time currentTime keeps a record of
// the current CPU time.
void insert(struct NODE * Heap, struct NODE * value, int* heapsize,int* currentTime){
	int start = *heapsize, i;
	Heap[*heapsize] = *value;
	if (Heap[*heapsize].intime == -1)
		Heap[*heapsize].intime = *currentTime;
	++(*heapsize);
	// Ordering the Heap
	while (start != 0 && Heap[(start - 1) / 2].priority >
		Heap[start].priority) {
		struct NODE temp = Heap[(start - 1) / 2];
		Heap[(start - 1) / 2] = Heap[start];
		Heap[start] = temp;
		start = (start - 1) / 2;
	}
}
// It is used to reorder the heap according to
// priority if the processes after insertion
// of new process.
void order(struct NODE * Heap, int* heapsize, int start)
{
	int biggest = start;
	int left = 2 * start + 1;
	int right = 2 * start + 2;
	if (left < *heapsize && Heap[left].priority > Heap[biggest].priority) biggest = left;
	if (right < *heapsize && Heap[right].priority > Heap[biggest].priority) biggest = right;
	// Ordering the Heap
	if (biggest != start) {
		struct NODE temp = Heap[biggest];
		Heap[biggest] = Heap[start];
		Heap[start] = temp;
		order(Heap, heapsize, biggest);
	}
}

// Compares two intervals according to staring times.
bool compare(struct NODE  p1, struct NODE  p2){
	return (p1.arrival_t > p2.arrival_t);
}
// This function is used to find the process with
// highest priority from the heap. It also reorders
// the heap after extracting the highest priority process.
// This function is responsible for executing
// the highest priority extracted from Heap[].
void scheduling(struct NODE * Heap, struct NODE * array, int n, int* heapsize, int* currentTime){
	if (heapsize == 0) return;
	
	struct NODE * max = &Heap[0];
	if (max->response_t == -1)
		max->response_t = *currentTime - max->arrival_t;
	--(*heapsize);
	if (*heapsize >= 1) {
		Heap[0] = Heap[*heapsize];
		order(Heap, heapsize, 0);
	}
	
	max->outtime = *currentTime + 1;
	--max->burst_t;
	printf("%5d: PID(%3d) \n",*currentTime, max->pid); 
		// insert it back into the Heap*/
	if (max->burst_t > 0) {
		insert(Heap, max, heapsize, currentTime);
		return;
	}
	for (int i = 0; i < n; i++)
		if (array[i].pid == max->pid) {
			array[i] = *max;
			break;
		}
}
//for Aging
double f_t(double n, double alpha) {
	return n + n * alpha;
}

int priority(struct NODE * array, int n)
{
	double alpha = 0.6;
	int totalwaitingtime = 0, totalburst_t = 0,
		totalturnaroundtime = 0, i, insertedprocess = 0,
		heapsize = 0, currentTime = array[0].arrival_t,
		totalresponse_t = 0;
	struct NODE Heap[40];
	
	for (int i = 0; i < n; i++) {
		totalburst_t += array[i].burst_t;
		array[i].tempburst_t = array[i].burst_t;
	}
	
	do {
		if (insertedprocess != n) {
			for (i = 0; i < n; i++) {
				//if (array[i].tempburst_t != 0) array[i].priority = f_t(array[i].priority, alpha);
				if (array[i].arrival_t == currentTime) {
					printf("NEW PROCESS INSERTED\n");
					++insertedprocess;
					array[i].intime = -1;
					array[i].response_t = -1;
					insert(Heap, &array[i], &heapsize, &currentTime);
				}
			}
		} scheduling(Heap, array, n, &heapsize, &currentTime);
		++currentTime;
		if (heapsize == 0 && insertedprocess == n)
			break;
	} while (1);
	for (int i = 0; i < n; i++) {
		totalresponse_t += array[i].response_t;
		totalwaitingtime += (array[i].outtime - array[i].intime - array[i].tempburst_t);
		totalburst_t += array[i].burst_t;
		
	}
	printf("\nalpha= (%3lf)\n", alpha);
	printf("Total waiting time = %f\n", (float)totalwaitingtime);
	printf("Average waiting time = %f\n",
		((float)totalwaitingtime / (float)n));
	printf("Average response time = %f\n",
		((float)totalresponse_t / (float)n));
	printf("Average turnaround time = %f\n",
		((float)(totalwaitingtime + totalburst_t) / (float)n));

	return 0;
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