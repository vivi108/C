#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

//argv[1]: input_filename
//argv[2]: output_filename
//argv[3]: the_number of resource
//argv[4]: the number of process
struct NODE {
	int pid;
	int allocation[3];
	int max[3];
	int need[3];
	
};
int requestnum;
int request[3];//[0]=pid
int available[3];
struct NODE table[10];

int main() {
	
		FILE *file = fopen("process.txt", "r");
		if (file == 0) {
			printf("could not open file\n");
		}
		else {
			fscanf(file, "%d %d %d", &available[0], &available[1], &available[2]);
			printf("%d %d %d\n", available[0], available[1], available[2]);
			for (int n = 0; n < 4; n++) {
				fscanf(file, "%d	%d %d %d	%d %d %d", &table[n].pid, &table[n].allocation[0], &table[n].allocation[1], &table[n].allocation[2], &table[n].max[0], &table[n].max[1], &table[n].max[2]);
				printf("%d	%d %d %d	%d %d %d\n", table[n].pid, table[n].allocation[0], table[n].allocation[1], table[n].allocation[2], table[n].max[0], table[n].max[1], table[n].max[2]);
				for (int j = 0; j < 3; j++) {
					table[n].need[j] = table[n].max[j] - table[n].allocation[j];
				}
			}
			fseek(file, -10, SEEK_END);
			fscanf(file, "%d	%d %d %d", &requestnum, &request[0], &request[1], &request[2]);
			printf("%d	%d %d %d\n", requestnum, request[0], request[1], request[2] );
			requestnum--;
			fclose(file);
			print_state(4, 3);
			
		
			request_resources(4,3);
			
			print_state(4, 3);


		}
	
}
/* Releases resource(s). Returns customer number */
/*
int release_resources(int NUMBER_OF_PROCESSES, int NUMBER_OF_RESOURCES, int release[]){
	int i;
	printf("\n");

	// Adds the released resources back to the available array and need matrix. Also removed that from the allocation matrix.
	ADD(available, release, NUMBER_OF_RESOURCES);
	SUB(table[requestnum].allocation, release, NUMBER_OF_RESOURCES);
	ADD(table[requestnum].need, release, NUMBER_OF_RESOURCES);

	return requestnum;
}*/
/* Requests reqource(s). Returns customer number */
int request_resources(int NUMBER_OF_PROCESSES, int NUMBER_OF_RESOURCES){

	for (int i = 0; i < NUMBER_OF_RESOURCES; i++){
		// Test if resource can be allocated based on the total number of resources and maximum available.
		printf("%d : %d : %d %d\n", i, request[i], table[requestnum].need[i], available[i]);
		if (request[i] > table[requestnum].need[i] || request[i] > available[i]){
			
			printf("%d : UNAVAILABLE\n", requestnum);
			return requestnum;
		}
	}

	// Pretends to allocate the resource to check if this will place the system in an unsafe state.
	SUB(available, request, NUMBER_OF_RESOURCES);
	ADD(table[requestnum].allocation, request, NUMBER_OF_RESOURCES);
	SUB(table[requestnum].need, request, NUMBER_OF_RESOURCES);

	// If the system state is unsafe, restore the old state and indicate the process must wait.
	if (is_safe(NUMBER_OF_PROCESSES, NUMBER_OF_RESOURCES)==-1){
		ADD(available, request, NUMBER_OF_RESOURCES);
		SUB(table[requestnum].allocation, request, NUMBER_OF_RESOURCES);
		ADD(table[requestnum].need, request, NUMBER_OF_RESOURCES);
		printf("UNSAFE\n");
		return requestnum;
	}

	// If the system is in a safe state, then we will keep the matrices and arrays intact and indicate the request was successful.
	printf("ACCEPTED\n");
	return requestnum;
}


/* Determines if the system is in a safe state. Returns true if the system is safe, false if it is unsafe. */
int is_safe(int NUMBER_OF_PROCESSES, int NUMBER_OF_RESOURCES){
	bool finish[4]; //bool finish[NUMBER_OF_PROCESSES]; Array of booleans to determine if a customer is finished.
	bool flag, flag2; // Using these insteads of breaks because they're "bad".
	int work[3], i, j, k; //int work[NUMBER_OF_RESOURCES]: Work is a temp version of available. i, j, k are all used for iteration.

	// Initialize the finish and work arrays.
	memset(finish, false, NUMBER_OF_PROCESSES * sizeof(bool));
	memcpy(work, available, NUMBER_OF_RESOURCES * sizeof(int));

	// Need to keep going until we reach every process.
	for (k = 0; k < NUMBER_OF_PROCESSES; k++){
		flag = true;

		for (i = 0; i < NUMBER_OF_PROCESSES && flag; i++){
			// Check if this customer has already been completed.
			if (!finish[i]){
				flag2 = true;

				// Check to see if a process is asking for more than the system has available.
				for (j = 0; j < NUMBER_OF_RESOURCES && flag2; j++)
					if (table[i].need[j] > work[j]) flag2 = false;

				// If j made it to it's upper bound, we need to allocate the resources and finish the customer.
				if (flag2){
					finish[i] = true;
					printf("p%d\t", i+1);
					flag = false;
					ADD(work, table[i].allocation, NUMBER_OF_RESOURCES);
				}
			}
		}
	}
	
	// If all the customers were finished, the system is in a safe state.
	for (i = 0; i < NUMBER_OF_PROCESSES; i++) if (!finish[i]) return -1;
	return 1;
}

/* Adds arr1's elements by arr2's elements and store the results in arr1 */
//n=NUMBER_OF_RESOURCES
ADD(int arr1[], int arr2[], int n){
	for (int i = 0; i < n; i++) arr1[i] += arr2[i];
}

/* Subtracts arr1's elements by arr2's elements and store the results in arr1 */
SUB(int arr1[], int arr2[], int n){
	for (int i = 0; i < n; i++) arr1[i] -= arr2[i];
}


/* Output the current state */
/* Only use this for debugging purposes. */
/* Do not call this function in your submitted solution. */
print_state(int NUMBER_OF_PROCESSES, int NUMBER_OF_RESOURCES){
	int r;
	printf("\n");
	printf("PID\tAllocation\tNeed\t\tMaximum\t\tAvailable\n");
	for (int c = 0; c < NUMBER_OF_PROCESSES; ++c){
		printf("%d\t", table[c].pid);
		for (r = 0; r < NUMBER_OF_RESOURCES; ++r) printf("%d ", table[c].allocation[r]);
		printf("\t\t");
		for (r = 0; r < NUMBER_OF_RESOURCES; ++r) printf("%d ", table[c].need[r]);
		printf("\t\t");
		for (r = 0; r < NUMBER_OF_RESOURCES; ++r) printf("%d ", table[c].max[r]);
		printf("\t\t");
		if (c == 0)
			for (r = 0; r < NUMBER_OF_RESOURCES; ++r) printf("%d ", available[r]);
		printf("\n");
	}
	if (is_safe(NUMBER_OF_PROCESSES, NUMBER_OF_RESOURCES))
		printf("SAFE!\n");
	else
		printf("UNSAFE!\n");
	printf("\n");
}