#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct DATA {//Structure for storing presented files
	int tag;
	char date[15];
	char fee_paid[5];
	char name[25];
	int age;
	char organization[30];
	char job[15];
	struct DATA* next;//structure pointer for linked list
};

struct DATA data[30];//for struct array 

struct DATA* node;//for linked list 
struct DATA* node2;//for linked list (1-1,1-2)
struct DATA* node3;
struct DATA* node4;

//함수 프로토타입
void printList(struct DATA*);
char* searchString(const char* str1, const char* str2);//길은지
void SearchNameArray();//1-1 길은지
void SearchNameLinkedList();//1-2 길은지
void SearchUniversityArray();//2-1 길은지
void SearchUniversityLinkedList();//2-2 길은지
void p3_1(struct DATA*, int);//3-1 김병준
void p4_1(struct DATA*, struct DATA*, int);//4-1 김병준
void p5_1(struct DATA*, int);//5-1 김병준
void P6_1(struct DATA*, int*);//6-1 정조은
void P6_2(struct DATA*, int*);//6-2 정조은
void P7_1(struct DATA*, struct DATA*, int*); //7-1 정조은
void P7_2(struct DATA*, struct DATA*, int*); //7-2 정조은
void copy_array(int);//8-1 현선명
void check(int);//8-1 현선명

 //setup 제작-현선명
void main() {
	FILE* mainfile;
	mainfile = fopen("registraion_data.txt", "r");
	if (mainfile == NULL) printf("can't find file");//defensive coding for mainfile

	int n = 0;
	//Read the information from the mainfile and save it in structure
	while ((fscanf(mainfile, "%d/%[^/]/%[^/]/%[^/]/%d/%[^/]/%s", &(data[n]).tag, data[n].date, data[n].fee_paid, data[n].name, &(data[n]).age, data[n].organization, data[n].job)) == 7) {
		data[n].next = NULL;
		n++;
	}
	fclose(mainfile);

	//linked list
	node = (struct DATA*)malloc(30 * sizeof(struct DATA));
	if (node == (struct DATA*)NULL) printf("ERROR");//defensive code for node

	for (int i = 0; i < n; i++) {//save the data into the node
		node[i].tag = data[i].tag;
		node[i].age = data[i].age;
		strcpy(node[i].date, data[i].date);
		strcpy(node[i].fee_paid, data[i].fee_paid);
		strcpy(node[i].name, data[i].name);
		strcpy(node[i].organization, data[i].organization);
		strcpy(node[i].job, data[i].job);
		if (i == n - 1) node[i].next = NULL;//The next of the last node is NULL value.
		else node[i].next = &node[i + 1];// Link the following address to next

	}


	node2 = (struct DATA*)malloc(30 * sizeof(struct DATA));//make extra node for each function
	if (node2 == (struct DATA*)NULL) printf("ERROR");

	for (int i = 0; i < n; i++) {
		node2[i].tag = data[i].tag;
		node2[i].age = data[i].age;
		strcpy(node2[i].date, data[i].date);
		strcpy(node2[i].fee_paid, data[i].fee_paid);
		strcpy(node2[i].name, data[i].name);
		strcpy(node2[i].organization, data[i].organization);
		strcpy(node2[i].job, data[i].job);
		if (i == n - 1) node2[i].next = NULL;//The next of the last node is NULL value.
		else node2[i].next = &node2[i + 1];//Link the following address to next
	}
	node3 = (struct DATA*)malloc(30 * sizeof(struct DATA));//make extra node for each function
	if (node3 == (struct DATA*)NULL) printf("ERROR");

	for (int i = 0; i < n; i++) {
		node3[i].tag = data[i].tag;
		node3[i].age = data[i].age;
		strcpy(node3[i].date, data[i].date);
		strcpy(node3[i].fee_paid, data[i].fee_paid);
		strcpy(node3[i].name, data[i].name);
		strcpy(node3[i].organization, data[i].organization);
		strcpy(node3[i].job, data[i].job);
		if (i == n - 1) node3[i].next = NULL;//The next of the last node is NULL value.
		else node3[i].next = &node3[i + 1];// Link the following address to next
	}

	node4 = (struct DATA*)malloc(30 * sizeof(struct DATA));//make extra node for each function
	if (node4 == (struct DATA*)NULL) printf("ERROR");

	for (int i = 0; i < n; i++) {
		node4[i].tag = data[i].tag;
		node4[i].age = data[i].age;
		strcpy(node4[i].date, data[i].date);
		strcpy(node4[i].fee_paid, data[i].fee_paid);
		strcpy(node4[i].name, data[i].name);
		strcpy(node4[i].organization, data[i].organization);
		strcpy(node4[i].job, data[i].job);
		if (i == n - 1) node4[i].next = NULL;//The next of the last node is NULL value.
		else node4[i].next = &node4[i + 1];// Link the following address to next
	}

	printf("\n---------------------------------1-------------------------------\n");
	SearchNameArray();
	SearchNameLinkedList();
	printf("\n---------------------------------2-------------------------------\n");
	SearchUniversityArray();
	SearchUniversityLinkedList();
	printf("\n-------------------------------3---------------------------------\n");
	p3_1(data, n);//3-1
	for (int i = 0; i < n; i++)
	{
		printf("%d\t%s\t%s\t%s\t%d\t%s\t%s\n", data[i].tag, data[i].date, data[i].fee_paid, data[i].name, data[i].age,
			data[i].organization, data[i].job);
	}
	printf("\n--------------------------------4--------------------------------\n");
	p4_1(node, data, n);//4-1
	printf("<Linked List>\n");
	printList(node);
	printf("<Array>\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d\t%s\t%s\t%s\t%d\t%s\t%s\n", data[i].tag, data[i].date, data[i].fee_paid, data[i].name, data[i].age,
			data[i].organization, data[i].job);
	}
	printf("\n---------------------------------5-------------------------------\n");
	p5_1(data, n);
	printf("\n---------------------------------6-------------------------------\n");
	P6_1(data, &n);
	P6_2(node4, &n);
	printf("\n---------------------------------7-------------------------------\n");
	P7_1(data, node, &n);
	P7_2(node, data, &n);

	printf("\n---------------------------------8-------------------------------\n");
	copy_array(n);//8-1
}
//print the values for linked list
void printList(struct DATA* ptr) {
	while (ptr) {
		printf("%d\t%s\t%s\t%s\t%d\t%s\t%s\n", ptr->tag, ptr->date, ptr->fee_paid, ptr->name, ptr->age, ptr->organization,
			ptr->job);
		ptr = ptr->next;
	}
}
//Make sure that str2(entered string) is included in str1
char* searchString(const char* str1, const char* str2) {
	char* cp = (char*)str1;
	char* s1, *s2;
	if (!*str2) return (char*)str1;
	while (*cp) {
		s1 = cp;
		s2 = (char*)str2;
		while (*s1 && *s2 && !(*s1 - *s2)) s1++, s2++;
		if (!*s2) return cp;
		cp++;
	}
	return NULL;
}

void SearchNameArray() {//1-1
	char searchName[105];
	int n = 30;

	//search in array
	printf("Step 1 Array\n");
	printf("Input name to search (Choi): ");
	scanf("%[^\n]", &searchName);

	char* name;

	for (int i = 0; i < n; i++) {//If searchName is included in data[i].name, print the information
		name = searchString(data[i].name, searchName);

		if (name == NULL) { //if didn't find 'Choi'
			continue;
		}
		else {//if find 'Choi', print the information
			printf("%d/%s/%s/%s/%d/%s/%s\n", data[i].tag, data[i].date, data[i].fee_paid, data[i].name, data[i].age, data[i].organization, data[i].job);
		}

	}
}

void SearchNameLinkedList() {//1-2
	char searchName[105];

	//seach in Linkedlist
	printf("\nStep 2 Linked List\n");
	printf("Input name to search (Choi): ");
	getchar();
	scanf("%[^\n]", &searchName);


	while (node3) { //when node3, loop
		char* name;
		name = searchString(node3->name, searchName); //if the searchName is included in the node3, print the information


		if (name == NULL) { //if didn't find 'Choi'
			node3 = node3->next;
			continue;
		}
		else { //if find 'Choi', print the information
			printf("%d/%s/%s/%s/%d/%s/%s\n", node3->tag, node3->date, node3->fee_paid, node3->name, node3->age, node3->organization, node3->job);
			node3 = node3->next;
		}
	}
}

void SearchUniversityArray() {//2-1
	char searchUniveristy[105];
	int n = 30;

	//search in array
	printf("Step 1 Array\n");
	printf("Input University name to search (Gachon University): ");
	fflush(stdin);
	getchar();
	scanf("%[^\n]", &searchUniveristy);

	char* University;

	for (int i = 0; i < n; i++) { //If searchUniversity is included in data[i].organization, print the information
		University = searchString(data[i].organization, searchUniveristy);

		if (University == NULL) { //if didn't find 'Gachon University'
			continue;
		}
		else {//if find 'Gachon University', print the information
			printf("%d/%s/%s/%s/%d/%s/%s\n", data[i].tag, data[i].date, data[i].fee_paid, data[i].name, data[i].age, data[i].organization, data[i].job);
		}

	}
}

void SearchUniversityLinkedList() {//2-2
	char searchUniveristy[105];

	//seach in Linkedlist
	printf("\nStep 2 Linked List\n");
	printf("Input University name to search (Gachon University): ");
	getchar();
	scanf("%[^\n]", &searchUniveristy);

	char* University;

	while (node2) { //when node2, loop
		University = searchString(node2->organization, searchUniveristy); //if the searchUniversity is included in the node2, print the information


		if (University == NULL) { //if didn't find 'Gachon University'
			node2 = node2->next;
			continue;
		}
		else { //if find 'Gachon University', print the information
			printf("%d/%s/%s/%s/%d/%s/%s\n", node2->tag, node2->date, node2->fee_paid, node2->name, node2->age, node2->organization, node2->job);
			node2 = node2->next;
		}
	}
}
void p3_1(struct DATA* data, int n)//3-1,Sort array by tag
{
	int min_index; //To store the minimum value
	struct DATA temp; //Declare struct data temp to swap the data

	for (int i = 0; i < n - 1; i++)
	{
		min_index = i;

		for (int j = i + 1; j < n; j++)
		{

			if (data[j].tag < data[min_index].tag)
			{
				min_index = j;//If data[j].tag < data[min_index].tag, store j to min_index

			}
		}
		//Swap the data
		temp = data[i];
		data[i] = data[min_index];
		data[min_index] = temp;
	}
}
void p4_1(struct DATA* node, struct DATA* data, int n)//4-1, Sort linked list by tag and array by ages

{
	struct DATA* ptr1 = &node[0]; //Declare the ptr1 and initialize with the address of node[0]
	int min_index; //To store the minimum value for array
	struct DATA* min_ptr; //To store the minimum value for linked list
	struct DATA temp; //Declare struct data temp to swap the data

	 //Sort linked list by tag
	while (ptr1->next != NULL)
	{
		min_ptr = ptr1;

		struct DATA* ptr2 = ptr1->next; //Declare the ptr2 initialize with ptr1->next

		while (ptr2 != NULL)
		{
			if (ptr2->tag < min_ptr->tag)
			{
				min_ptr = ptr2;//If ptr2->tag < min_ptr->tag, store ptr2 to min_index
			}
			ptr2 = ptr2->next;//Change ptr2 to ptr2->next

		}
		//Swap the data
		temp.tag = ptr1->tag;
		ptr1->tag = min_ptr->tag;
		min_ptr->tag = temp.tag;

		temp.age = ptr1->age;
		ptr1->age = min_ptr->age;
		min_ptr->age = temp.age;

		strcpy(temp.date, ptr1->date);
		strcpy(ptr1->date, min_ptr->date);
		strcpy(min_ptr->date, temp.date);

		strcpy(temp.fee_paid, ptr1->fee_paid);
		strcpy(ptr1->fee_paid, min_ptr->fee_paid);
		strcpy(min_ptr->fee_paid, temp.fee_paid);

		strcpy(temp.name, ptr1->name);
		strcpy(ptr1->name, min_ptr->name);
		strcpy(min_ptr->name, temp.name);

		strcpy(temp.organization, ptr1->organization);
		strcpy(ptr1->organization, min_ptr->organization);
		strcpy(min_ptr->organization, temp.organization);

		strcpy(temp.job, ptr1->job);
		strcpy(ptr1->job, min_ptr->job);
		strcpy(min_ptr->job, temp.job);

		ptr1 = ptr1->next;//Change ptr to ptr->next
	}
	//Sort array list by age
	min_index = 0;

	for (int i = 0; i < n - 1; i++)
	{
		min_index = i;

		for (int j = i + 1; j < n; j++)
		{
			if (data[j].age < data[min_index].age)
			{
				min_index = j; //If data[j].age < data[min_index].age, store j to min_index
			}
		}
		//Swap the data
		temp = data[i];
		data[i] = data[min_index];
		data[min_index] = temp;
	}
}
void p5_1(struct DATA* data, int n)//5-1
{
	FILE* fp = fopen("5-1.txt", "w");//Declare the file pointer named fp with write mode

	if (fp == NULL) //For the defensive coding
	{
		printf("File Could Not Be Opened!");
		return; //If the file opening is failed, the return
	}
	int group = -1; //Declare the variable named group to sort data by the age group

	for (int i = 0; i < n; i++)
	{
		int temp_group = data[i].age / 10; //Indicate that the temp group age

		if (group != temp_group) //If group is not same with temp_group, the new age group created
		{
			fprintf(fp, "--------------------------------------%d Age Group--------------------------------------\n", temp_group * 10);
			group = temp_group; //Change the value of the varialbe named group

		}
		//Print the data to 5-1.txt
		fprintf(fp, "%d %s %s %s %d %s %s\n", data[i].tag, data[i].date, data[i].fee_paid, data[i].name, data[i].age,
			data[i].organization, data[i].job);
	}

	printf("Successfully Copied!");
}


// P6_1
void P6_1(struct DATA* data, int* n) {

	printf("6_1\n");

	int i = 0, j = 0, count = 0;

	while (i < (*n) - 1) {  // loop for find Choi 
		while (i < (*n) - 1) {
			if (strstr(data[i].name, "Choi") != NULL) {  // if find Choi
				count++;  // for reduce the number of n
				break;  // go to loop for string copy 
			}
			i++;
		}
		for (j = i; j < (*n) - 1; j++) {  // loop for string copy, delete Choi's data through string copy
			data[j].tag = data[j + 1].tag;  // copy tag
			strcpy(data[j].date, data[j + 1].date);  // copy datd
			strcpy(data[j].fee_paid, data[j + 1].fee_paid);  // copy fee_paid
			strcpy(data[j].name, data[j + 1].name);  // copy name
			data[j].age = data[j + 1].age;  // copy age
			strcpy(data[j].organization, data[j + 1].organization);  // copy organization
			strcpy(data[j].job, data[j + 1].job);  // copy job

		}
	}
	*n = *n - count;  // reduce the number of n


	for (int i = 0; i < *n; i++) {  // loop for print data
		printf("%d\t%s\t%s\t%s\t%d\t%s\t%s\n", data[i].tag, data[i].date, data[i].fee_paid, data[i].name, data[i].age, data[i].organization, data[i].job);
	}

}
// P6_2
void P6_2(struct DATA* node4, int* n) {

	printf("6_2\n");

	struct DATA* head;
	head = (struct DATA*)malloc(sizeof(struct DATA));
	head->next = &node4[0];

	struct DATA* p = head->next, *prev = head;

	while (p) {  // loop for find Choi
		while (p) {
			if (strstr(p->name, "Choi") != NULL) {  // if find Choi
				break;
			}
			else {
				prev = p;  // next node
				p = p->next;
			}
		}
		if (p) {
			prev->next = p->next;  // node delete, delete Choi's data
			p = p->next;
		}
	}
	printList(node);  // print node
}

// P7_1
struct DATA paik = { 100,"2020-11-30","yes","Ildang Paik",22,"Gachon University","engineer" };
void P7_1(struct DATA* data, struct DATA* node, int* n) {

	printf("7_1\n");

	p4_1(node, data, *n);  // call age sort of array

	int i = 0, j;

	int index = 0;

	for (i = 0; i < *n; i++) {
		if (data[i].age > paik.age) {  // find index for insert Paik's data
			index = i;
			break;
		}
	}
	for (j = (*n) - 1; j >= index; j--) {  // loop for string copy, make index for Paik's data
		data[j + 1].tag = data[j].tag;
		strcpy(data[j + 1].date, data[j].date);
		strcpy(data[j + 1].fee_paid, data[j].fee_paid);
		strcpy(data[j + 1].name, data[j].name);
		data[j + 1].age = data[j].age;
		strcpy(data[j + 1].organization, data[j].organization);
		strcpy(data[j + 1].job, data[j].job);
	}

	data[index].tag = paik.tag;  // insert Paik's data
	strcpy(data[index].date, paik.date);
	strcpy(data[index].fee_paid, paik.fee_paid);
	strcpy(data[index].name, paik.name);
	data[index].age = paik.age;
	strcpy(data[index].organization, paik.organization);
	strcpy(data[index].job, paik.job);

	for (i = 0; i <= *n; i++)  // loop for print data
	{
		printf("%d\t%s\t%s\t%s\t%d\t%s\t%s\n", data[i].tag, data[i].date, data[i].fee_paid, data[i].name, data[i].age,
			data[i].organization, data[i].job);
	}

}
// P7_2
void P7_2(struct DATA* node, struct DATA* data, int* n) {

	printf("7_2\n");

	p4_1(node, data, *n);  // call tag sort of node

	struct DATA* head;
	head = (struct DATA*)malloc(sizeof(struct DATA));
	head->next = &node[0];

	struct DATA* p = head->next, *prev = head;

	while (p) {  // loop for insert Paik's data
		if (p->tag == paik.tag) {  // find index for insert Paik's data
			break;
		}
		if (p->tag > paik.tag) { // find index for insert Paik's data
			break;
		}
		else {
			prev = p;  // next node
			p = p->next;
		}
	}

	struct DATA* new_node = (struct DATA*)malloc(sizeof(struct DATA));

	new_node->tag = paik.tag;   // insert Paik's data
	strcpy(new_node->date, paik.date);
	strcpy(new_node->fee_paid, paik.fee_paid);
	strcpy(new_node->name, paik.name);
	new_node->age = paik.age;
	strcpy(new_node->organization, paik.organization);
	strcpy(new_node->job, paik.job);

	prev->next = new_node;  // connect node
	new_node->next = p;

	printList(node);  // print node

}
void check(int n) {//8-1-2
	//Get Original Data's Checksum
	FILE* copyfile = fopen("8-1.txt", "w");//Create Files to Submit

	int check_sum = 0;

	//Checksum Part: Add the byte of each name to the sum and the sum to the checksum and xor operation
	for (int i = n - 5; i < n; i++)//during the last five rounds of original data
	{
		int sum = 0;
		for (int j = 0; j < strlen(data[i].name); j++)//loop for the length of each name,
		{

			sum += data[i].name[j];//Adds the total number of bytes in each name

		}
		check_sum ^= sum;//xor operation with stored names
	}
	fprintf(copyfile, "%d\n", check_sum);

	for (int i = n - 5; i < n; i++)//copt and Insert the Lastest 5 Names
	{
		fprintf(copyfile, "%s\n", data[i].name);
	}
	fclose(copyfile);
}

void copy_array(int n)//8-1-1
{
	check(n);//call the check function for the computing the checksum of original data
	struct DATA copy[5];//Structure to receive the last five names
	int cnt = 0;
	char name[100];
	int origin_check_sum;

	FILE* file = fopen("8-1.txt", "r");//Read the file for submission

	if (file == NULL)//defensive code for file
	{
		printf("ERROR");
		return;
	}
	char temp[100];

	fgets(temp, sizeof(temp), file);//Read the data that has size of (100) from copied 8-1txt and save to temp
	temp[strlen(temp) - 1] = NULL;//input null value at the last

	origin_check_sum = atoi(temp);//change the organinal checksum at the top from string to integer

	while (fgets(name, sizeof(name), file) != NULL)//Read the data that has size of (100) from copied 8-1txt and save to name
	{
		name[strlen(name) - 1] = NULL;//input null value at the last
		strcpy(copy[cnt].name, name);//Insert a name value into the structure to save
		cnt++;//next array
	}
	fclose(file);

	int check_sum = 0;
	//Checksum Part: Add the byte of each name to the sum and the sum to the checksum and xor operation
	//This is for copied data

	for (int i = 0; i < 5; i++)
	{
		int sum = 0;
		for (int j = 0; j < strlen(copy[i].name); j++)
		{
			sum += copy[i].name[j];//Adds the total number of bytes in each name
		}
		check_sum ^= sum;//xor operation with stored names
	}

	if (check_sum == origin_check_sum)//compare the two checksums, the orginal one and copied one
	{
		printf("Successfully Copied!");//if they have same checksum, the print it.
	}

}