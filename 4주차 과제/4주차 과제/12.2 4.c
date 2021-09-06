#include<stdio.h>

main1() {
	struct {  //declaration of stucture which  has following data
		int car_num;
		int miles_driven;
		int gallons_used;
	}car[5] = { {25, 1450, 62},{36, 3240, 136},{44, 1792, 76},{52, 2360, 105},{68, 2114, 67} };

	float sum = 0; //for Sum before getting miles per gallon
	float  milespergallon[5]; //for report listing each car miles per gallon achieved by the car
	float average_gallon_used = 0; // for average miles per gallon achieved by five cars
	
	// report listing start from here
	printf("\ncar_number : miles per gallon \n=======================================\n");
	
	for (int i = 0; i < 5; i++) {
		milespergallon[i] = (float)(car[i].miles_driven) / car[i].gallons_used ; //Enter formula at milespergallon[5]
		printf("number %d : %f\n", car[i].car_num, milespergallon[i]);
		sum += milespergallon[i];
	}
	
	average_gallon_used = sum / 5.0; //define the average miles per gallon
	//at the end of the report, include the average miles per gallon achieved
	printf("\n===========================================\n  average miles per gallon: %f\n", average_gallon_used); 
	//listing end
}