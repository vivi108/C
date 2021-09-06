#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define NUM_PROC 1000
#define SWITCH_OVERHEAD 1
#define TIME_QUANTUM 2
void printLL(struct NODE * );

struct NODE {
	int pid, burst_t, arrival_t, priority;
	int wait_t, turnaround_t, remain_t;
	struct NODE *next;
};
struct NODE pc[10];



void main() {
	
	
	FILE * input = fopen("input.txt", "r");
	if (input == (FILE *)NULL) printf("no file");
	int n = 0;
	while ((fscanf(input, "%d %d %d %d", &pc[n].pid, &pc[n].priority, &pc[n].arrival_t, &pc[n].burst_t )) == 4) n++;
	fclose(input);

}
void findavgTime(int n, struct NODE *p, int quantum)
{
	int  total_wt = 0, total_tat = 0;
	int  total_rt = 0; // response time
	int ct; // completion time
	// Function to find waiting time of all processes
	ct = findWaitingTime(n, p->burst_t, p->wait_t, p->remain_t, quantum);
	// Function to find turn around time for all processes
	findTurnAroundTime(n, bt, wt, tat);
	printf("Switching Time = %d\n", SWITCH_OVERHEAD);
	printf("Time Quantum = %d\n", TIME_QUANTUM); printf("ProcessID Arrival Time Burst Time Waiting Time Turnaround Time Response Time\n");
	for (int i = 0; i < n; i++) {
		total_wt = total_wt + wt[i];
		total_tat = total_tat + tat[i];
		total_rt = total_rt + rt[i];
		int compl_time = tat[i] + 0;
		printf(" %5d %7d %7d %7d %7d %7d\n",
			i, 0, bt[i], wt[i], tat[i], rt[i]);
	}
	printf("Avg. Waiting Time = %9.2f\n", (float)total_wt / (float)n);
	printf("Avg. Turnaround Time = %9.2f\n", (float)total_tat / (float)n);
	printf("Avg. Response Time = %9.2f\n", (float)total_rt / (float)n);
	printf("Completion Time = %6d\n", ct);
	printf("Thoughput(#Jobs/Time)= %9.2f\n", (float)n / (float)ct);
}
// Function to calculate turn around time
void findTurnAroundTime(int n, struct NODE * p)
{
	for (int i = 0; i < n; i++)
		p[i].turnaround_t = p[i].burst_t + p[i].wait_t;
}
int findWaitingTime(int n, struct NODE *p, int quantum){
	
	int t = 0; // Current time
	
	while (1) {
		bool done = true;
		for (int i = 0; i < n; i++) {
			if (p[i].remain_t == p[i].burst_t) // first running quantum
				p[i].remain_t = t + SWITCH_OVERHEAD; // response time
				
			if (p[i].remain_t > 0) {
				done = false; 
				printf("%5d: SWITCHING %5d\n", t, SWITCH_OVERHEAD );
				t = t + SWITCH_OVERHEAD;
				if (p[i].remain_t > quantum) {
					printf("%5d: proc(%3d) %5d\n", t, i, quantum);
					t += quantum;
					p[i].remain_t -= quantum;
				} 
				else {
					printf("%5d: proc(%3d) %5d\n", t, i, p[i].remain_t);
					t = t + p[i].remain_t;
					p[i].wait_t = t - p[i].burst_t;
					p[i].remain_t = 0;
				}
			} 
		} 
		 
		if (done == true)
			break;
	}
	return t; // Completion time
}

int fcfs(struct NODE * p, int n) {
	int temp, wt = 0;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		temp = 0;
		for (int j = cnt; j < i; j++) {
			temp += p[j].burst_t;
		}
		wt = temp - p[i].arrival_t + p[cnt].arrival_t;
		if (wt <= 0) {
			cnt = i;
			p[i].wait_t = 0;
			p[i].turnaround_t = p[i].burst_t + p[i].wait_t;
		}
		else {
			p[i].wait_t = wt;
			p[i].turnaround_t = p[i].burst_t + p[i].wait_t;
		}
	}
}
//퀀텀만큼 동작하고 다음으로 넘어가는 알고리즘
// temp에다 값저장 temp2에다는 process들의 특정 값 저장

//int i , count 그리고 totaltime

//초기화 절차

// process들의 남은 시간을 temp2 배열에 넣어준다.

//무한 루프

// 현재 임시 값은 quantom

// 만약 process i의 남은 시간이 없다면, 

// count를 증가 시키고, 

//i를 증가 시켜 다른 process로 간다. 

// 만약 남은 시간이 퀀텀보다 크다면, 그 값을 빼준다음 다시 저장

// 남은시간이 0이거나 퀀텀보다 크다면,

// temp에다가 남은 시간 저장해주고,

// 실행했으니까, pro[i].remain_t는 0으로

// 전체 시간은 수행한 시간, 왜냐하면 위에서

//퀀텀보다 작을 때, 그 값을 total time에 넣어 주었다.

//process[i]의 전체 시간은 tt

// 다 돌았을 때,

//while문 여기 까지

// 이제 그동안 temp에 모았던거 reamin_t로 넣어준다.

// wait 시간은 전체 시간 - cpu시간
int rr(struct NODE * p, int n, int q) {
	int temp, temp2[100];
	int cnt = 0;
	int total_t=0;
	if (temp2[0] != p[0].burst_t) {
		for (int i = 0; i < n; i++) {
			temp2[i] = p[i].remain_t;
		}
	}
	while (1) {
		for (int i = 0; i < n; i++) {
			temp = q;
			if (p[i].remain_t == 0) {
				cnt++;
				continue;
			}
			if (p[i].remain_t > q) p[i].remain_t -= q;
			else if (p[i].remain_t >= 0) {
				temp = p[i].remain_t;
				p[i].remain_t = 0;
			}
			total_t += temp;
			p[i].turnaround_t = total_t;
		}
		if (n == cnt) break;
	}
	for (int i = 0; i < n; i++) {
		p[i].remain_t = temp2[i];
		p[i].wait_t =  p[i].turnaround_t- p[i].burst_t;
	}
}

int pri_sch(struct NODE *pro, int n) {

	int flag = 0;
	int i, time, remain, num, min, temp[150];
	for (i = 0; i < n; i++) {
		pro[i].remain_t = pro[i].burst_t;

	}

	time = pro[0].arrival_t;

	remain = n;
	if (temp[0] != pro[0].burst_t) {
		for (i = 0; i < n; i++) {
			temp[i] = pro[i].remain_t;
		}
	}
	while (remain > 0) {
		min = 9999;
		for (i = 0; pro[i].arrival_t <= time && i < n; i++) {

			if (pro[i].remain_t != 0 && pro[i].priority < min && pro[i].burst_t>0) {
				num = i;
				min = pro[i].priority;
				flag = 1;

			}

		}

		if (flag == 1) {
			pro[num].remain_t = 0;
			pro[num].wait_t = time - pro[num].arrival_t;
			remain--;
			time += pro[num].burst_t;

		}
		else time++;

		flag = 0;
	}
	for (i = 0; i < n; i++) {
		pro[i].turnaround_t = pro[i].wait_t + pro[i].burst_t;

	}
	for (i = 0; i < n; i++) {
		pro[i].remain_t = temp[i];

	}

}

void printLL(struct NODE * node) {
	if (node == NULL)printf("end");
	printf("%d %d %d %d\n", head->pid, head->pid, head->arrival_t, head->burst_t);
	printLL(head->next);
}
// arival time 순으로 프로세스를 정렬 시켜 준다. 
void at_sort(struct NODE *pro, int n) {
	struct NODE temp;

	int i, j;
	for (i = n - 1; i > 0; i--) {
		for (j = 0; j < i; j++) {
			// i 가 n-1부터 시작해서 0 부터 n 까지 process를 비교하고, 그다음  i가 n-2 가 되면 맨 앞에껄 두고 그 다음 부터 마지막까지 비교 한다. 
			if (pro[j].arrival_t > pro[j + 1].arrival_t) {
				temp = pro[j + 1];
				pro[j + 1] = pro[j];
				pro[j] = temp;
			}
			else if (pro[j].arrival_t == pro[j + 1].arrival_t&&pro[j].pid > pro[j + 1].pid) {
				//동시에 왔으면 프로세스 번호 순으로 정렬한다. 작은 번호가 먼저 나온다. 
				temp = pro[j + 1];
				pro[j + 1] = pro[j];
				pro[j] = temp;
			}
		}
	}
}
void resort(struct NODE *pro, int n) {

	//프로세스 구조체

	// i 가 n-1부터 시작해서 0 부터 n 까지 process를 비교하고, 그다음  i가 n-2 가 되면 맨 앞에껄 두고 그 다음 부터 마지막까지 비교 한다. 

	//도착한 순서대로 정렬된 프로세스 구조체를 가져와서 burst_t과 대기시간 WT를 더해 준다.
	struct NODE temp;
	int i, j;
	for (i = n - 1; i > 0; i--) {
		for (j = 0; j < i; j++) {
			if (pro[j].pid > pro[j + 1].pid) {
				temp = pro[j + 1];
				pro[j + 1] = pro[j];
				pro[j] = temp;

			}

		}

	}

}
int process_generate(struct NODE *pro, int n) {

	// 랜덤 프로세스 생성, 

	FILE *fp2;
	int j, found;
	fp2 = fopen("proc.txt", "a+");
	int i = n;

	//프로세스 개수, 현재 마지막 프로세스가 몇개인지 파악하는 데 사용된다.
	int bt = (rand() % 25) + 1;
	pro[i].pid = i + 1;
	pro[i].burst_t = bt;
	while (1) {
		pro[i].priority = rand() % 50;
		found = 0;
		for (j = 0; j < i; ++j) {
			if (pro[j].priority == pro[i].priority) {
				found = 1;
				break;
			}
		}
		if (!found) break;
	}

	while (1) {
		pro[i].arrival_t = rand() % 50;
		found = 0;
		for (j = 0; j < i; ++j) {
			if (pro[j].arrival_t == pro[i].arrival_t) {
				found = 1;
				break;
			}
		}
		if (!found) break;
	}
	fprintf(fp2, "\r\n%d %d %d %d", pro[i].pid, pro[i].burst_t, pro[i].arrival_t, pro[i].pri);
	fclose(fp2);

}