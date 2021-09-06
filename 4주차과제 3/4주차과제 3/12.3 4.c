#include<stdio.h>

//define struct data type globally for it to be known to the function being called
struct Date { //declare the struct Date following Date structure
	int month;
	int day;
	int year;
};

struct Date later;// declare 'struct Date' data type to get return value of recent()
void recent(struct Date, struct Date); //prototype of Days()

main() {
	struct Date date1, date2; // declare 'struct Date' data type named date1, date2
	
	// get input value to the date1 in the order of year, month, day
	printf("\nEnter the year, month, day :");
	scanf_s("%d%d%d", &date1.year, &date1.month, &date1.day);
	
	// get input value to the date2 in the order of year, month, day
	printf("\nEnter the year, month, day :");
	scanf_s("%d%d%d", &date2.year, &date2.month, &date2.day);

	recent(date1, date2); //function call by value with two parameters
	printf("\nthe later date : %d/%d/%d\n", later.year, later.month, later.day);// print the memebers of 'later'
}

 void recent(struct Date c1, struct Date c2) { //definition of Days()
	
	 /*The comparison of dates begins with the difference in years. 
	 If the years are the same, compare the months and if the months are the same, 
	 compare the days and save the most recent date to the seperate structure*/
	
	 if (c1.year > c2.year)//differences in years
		later = c1;
	else if (c1.year < c2.year) 
		later = c2;
	
	else { 
		if (c1.month>c2.month)//differences in months
			later = c1;
		else if (c1.month < c2.month) 
			later = c2;
		
		else { //differences in days
			if (c1.day > c2.day)
				later = c1;
			else if (c1.day < c2.day) 
				later = c2;
			else later = c1;
			}
	}
	return later; // return the sturcture
}