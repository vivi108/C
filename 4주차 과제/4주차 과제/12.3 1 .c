#include<stdio.h>

//define struct data type globally for it to be known to the function being called
struct Date { //declare the struct Date following Date structure
	int month;
	int day;
	int year;
};

int Days(struct Date); //prototype of Days()

main() {
	struct Date date; // declare 'struct Date' data type named date
	
	printf("\nEnter the year :");// get input value in the order of year, month, day
	scanf_s("%d", &date.year);
	printf("\nEnter the  month :");
	scanf_s("%d",  &date.month);
	printf("\nEnter the day :");
	scanf_s("%d", &date.day);

	int num= Days(date); //function call by value
	printf("\nnumber of days : %d\n",num);
}

int Days(struct Date call) { //definition of Days()
	int num = 0; // to sum the days calculated

	//fomula for num, which calculate from the date 1/1/2000 for any date passed as a structure
	//Assume that all years have 360 days and each month has 30 days
	num = call.day + (call.month - 1) * 30 + (call.year - 2000) * 360;
	
	return num;
}