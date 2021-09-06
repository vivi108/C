#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//Algorithm outline: sorted and comparision_ It's a way of finding, sending it to the very end, and putting it in place.
//Input: Entered in the order entered
int main() {
	int arr[30], stack[30], sorted[30];
	FILE *file = fopen("input.txt", "r");
	if (file == 0) {
		printf("could not open file\n");
	}
	int cnt = 0;
	while (fscanf(file, "%d", &arr[cnt]) == 1) {
		cnt++;
	}
	for (int i = 0; i < cnt; i++) {
		stack[i] = arr[cnt - i - 1];
		sorted[i] = arr[i];
	}
	printf("\nstack: ");
	printarr(cnt, arr);
	//sorted array for comparision
	InsertionSort(sorted, cnt);
	printf("-------------------------\n\n");
	//flip
	for (int i = 0; i < cnt; i++) {
		
		for (int k = 0; k < cnt; k++) {
			if (sorted[i] == arr[k]) {
				if (sorted[k] == arr[k]) {
					//If it's in place, it won't move.
				}
				else if (arr[cnt - 1] == sorted[i]) {
					//If the value is at the end of the array, flip only as much as you need
					flip(i, arr, cnt);
				}
				else {//If value is not in the right place, send it to the end and come back to right position.
					flip(k, arr, cnt);
					flip(i, arr, cnt);
				}
			}
		}
	}
	printf("flip(0)\n-------------------------\n");
	printf("results: ");
	printarr(cnt, arr);
}
int flip(int num, int * stack, int cnt) {//num indicates the number of times to flip from the front, num value starts from 1
	int forsaving[30];
	printf("flip(%d),", num+1);
	for (int i = 0; i < cnt - num ; i++) {//Call pop function as many times as (cnt-num+1)
		forsaving[i] = pop(cnt - i, stack);
	}
	for (int i = num ; i < cnt; i++) {
		stack[i] = forsaving[i - num ];
	}
	printarr(cnt, stack);
}

int pop(int end, int ** stack) {
	return stack[end - 1];
}
int printarr(int cnt, int * intarr) {
	for (int i = 0; i < cnt; i++) {
		printf("%d(%d) ", intarr[i], i);//printed format for "value(index)" 
	}
	printf("\n");
}
int InsertionSort(int* arr, int cnt) {
	for (int i = 0; i < cnt; i++) {
		int key = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
	int forsaving[30];
	
	for (int i = 0; i < cnt; i++) {
		forsaving[i] = pop(cnt - i, arr);
	}
	for (int i = 0; i < cnt; i++) {
		arr[i] = forsaving[i];
	}
}