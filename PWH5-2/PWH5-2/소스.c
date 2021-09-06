#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>


int Partition(int arr[][3], int , int , int );
int QuickSort(int arr[][3], int , int , int );
int duplexSelection(int arr[][3], int, int );
int MergeJoin(int arr[][3], int arr2[][3], int t1c, int , int );

int swap(int arr[][3], int a, int b );
void printTable(int arr[][3], int, int);
int printTable_M(int table[][5], int , int);

void main() {
	//PART 1
	int table1[15][3], duplexedTable1[15][3];
	int table2[10][3], duplexedTable2[10][3];
	srand(time(NULL));

	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 3; j++) {
			table1[i][j] = 1 + rand() % 100;
			duplexedTable1[i][j] = table1[i][j];
		}
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 3; j++) {
			table2[i][j] = 1 + rand() % 100;
			duplexedTable2[i][j] = table2[i][j];
		}
	}
	printf("\n###Draft Tables before updated:\n");
	printTable(table1,15,3);
	printTable(table2,10,3);

	table1 [10-1][3-1] = 55;
	duplexedTable1[10 - 1][3 - 1] = 55;
	table1[14-1][3-1] = 55;
	duplexedTable1[14 - 1][3 - 1] = 55;
	
	table2[5-1][1-1] = 55;
	duplexedTable2[5-1][1-1] = 55;

	//part 2
	printf("\n\tPART 2\n");
	duplexSelection(duplexedTable1, 15, 3);
	duplexSelection(duplexedTable2, 10, 1);
	printf("###duplexed Table 1&2: \n");
	printTable(duplexedTable1, 15, 3);
	printTable(duplexedTable2, 10, 3);

	//part 2-1
	QuickSort(table1, 0, 15-1, 3 - 1);
	QuickSort(table2, 0, 10 - 1, 1 - 1);
	printf("###QuickSorted Table 1&2: \n");
	printTable(table1, 15, 3);
	printTable(table2, 10, 3);

	//part3
	printf("\n\tPART 3\n");
	MergeJoin(table1, table2, 3, 1, 55);
}
//----------(QUICK SORT) ----------------------------

// Used to determine partition for quicksort -  parameter bool along_left chooses whether
// sorting is of left (set to true) or right column (set to false).
// 'left' and 'right' denote the range of row indices that we are going to sort.
int Partition(int arr[][3], int left, int right, int colnum){
	int pivot = arr[left][colnum]; 
	int low = left + 1;
	int high = right;

	while (low <= high) {
		while (low <= right && pivot >= arr[low][colnum]) low++;
		while (high >= (left + 1) && pivot <= arr[high][colnum])  high--;
		if (low <= high)swap(arr, low, high, colnum);
	}
	swap(arr, left, high); 
	return high;  

}

int QuickSort(int arr[][3], int left, int right, int colnum) {
	if (left <= right) {
		int pivot = Partition(arr, left, right, colnum); 
		QuickSort(arr, left, pivot - 1, colnum); 
		QuickSort(arr, pivot + 1, right, colnum); 
	}
	return 0;
}
//-------------------------------DUPLEX SELECTION ---------------------------
/*
Find the largest key value during n-1 and the next largest key value and 
replace it with the rightmost key and secondly the rightmost key.
While searching for keys to find MAX, 
the idea of finding MIN would reduce the pass came up with the Duplex Selection Sort, 
where the value raised by (n-1)/2 is the total number of passes.
*/
int duplexSelection(int table[][3], int row, int colnum) {
	row--;
	colnum--;
	int min_index = 0, start = 0;
	int max_index = 0, end = row;
	while (start < end) {
		min_index = start;
		max_index = end;
		for (int i = start ; i < end+1; i++) {
			if(table[min_index][colnum] > table[i][colnum]) 
				min_index = i;
			if (table[max_index][colnum] < table[i][colnum]) 
				max_index = i;
		}
		swap(table, start, min_index);
		if (start == max_index) max_index = min_index;
		swap(table, end, max_index);
		start++;
		end--;
	}
	
	return 0;
	
}//-------------------------------MERGE JOIN ---------------------------
//Merge as a condition for the connection 
//while scanning the sorted results by accessing the processing range of both tables separately.
int MergeJoin(int t1[][3], int t2[][3],int t1c, int t2c, int val) {
	t1c--;
	t2c--;
	int	out_len=15, in_len=10, out_indx=0, in_indx=0;
	int result[15][5] = { 0, };
	int arr_in[10][3] = { 0, }, arr_out[15][3] = { 0, };
	int in = 0, out = 0;
	
	for (; out_indx < out_len && in_indx < in_len; ){
		int		temp = t1[out_indx][t1c];
		bool	found = false;
		
		while (in_indx < in_len && temp == t2[in_indx][t2c]){
			found = true;
			arr_in[in][0] = temp;
			arr_in[in][1] = t2[in_indx][t2c + 1];
			arr_in[in][2] = t2[in_indx][t2c + 2];
			in_indx++;
			in++;
		}

		if (found){
			while (out_indx < out_len && temp == t1[out_indx][t1c]){
				
				arr_out[out][0] = t1[out_indx][t1c - 2];
				arr_out[out][1] = t1[out_indx][t1c - 1];
				arr_out[out][2] = temp;
				out_indx++;
				out++;
			}
		}
		else if (t1[out_indx][t1c] < t2[in_indx][t2c]) out_indx++;
		else in_indx++;
	}

	printf("\n");
	//for join arr_out and arr_in based on val
	int cnt = 0;
	for (int i = 0; i < 15; i++) {
		if (arr_out[i][0] == 0) break;
		for (int j = 0; j < 10; j++) {
			if (arr_in[j][0] == 0) break;
			if (arr_out[i][2] ==val&&val== arr_in[j][0]) {
				for (int k = 0; k < 3; k++) {
					result[cnt][k] = arr_out[i][k];
				}
				result[cnt][3] = arr_in[j][1];
				result[cnt][4] = arr_in[j][2];
				cnt++;
			}
		}
	}
	printf("###=>table based on value: \n");
	printTable_M(result, 15, 5);

	return 0;
}


// swapping row a, row b
int swap(int arr[][3], int a, int b) 
{
	for (int i = 0; i < 3; i++) {
		int temp = arr[a][i];
		arr[a][i] = arr[b][i];
		arr[b][i] = temp;
	}
	return 0;
}
void printTable(int table[][3], int row, int col) {

	printf("-----------------\n");
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			printf("%d ",table[i][j]);
		}
		printf("\n");
	}
	printf("-----------------\n");
}

//same as printTable, but just for the table which has 5 columns.
int printTable_M(int table[][5], int row, int col) {

	printf("-----------------\n");
	for (int i = 0; i < row; i++) {
		if (table[i][0] == 0) break;
		for (int j = 0; j < col; j++) {
			printf("%d ", table[i][j]);
		}
		printf("\n");
	}
	printf("-----------------\n");
	return 0;
}