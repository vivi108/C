#include<stdio.h> // call from the Headerfile
#include<stdlib.h>// for rand() and srand()
#include<time.h>// for time()

#define BAR 1 // equate 4 outcomes to 4 integers
#define BELL 2
#define LEMON 3
#define CHERRY 4;
#define RMAX 4; // for four values

main() {
	int num, slotnum; //declaration
	srand(time(NULL));// To change seed values to diversify random numbers

	while (1) { //iterate indefinitely

		int slot1 = 1 + rand() % RMAX; // declare slot1 
		int slot2 = 1 + rand() % RMAX; // declare slot2
		int slot3 = 1 + rand() % RMAX; // declare slot3

		printf("\nWelcome to KW Land\n Please pull the slot machine\n"); //Print the Welcome comment
		printf("\nslot1 = %d slot2 = %d slot3 = %d\n", slot1, slot2, slot3); //To check the random number of each slot

		if (slot1 == 4 && slot2 == 4 &&slot3 == 4) printf("Jackpot"); //CHERRY in all 3 slots
		else if (slot1 == 4 || slot2 == 4 || slot3 == 4) printf("One Dime");// CHERRY in any one slot
		else if (slot1 == slot2 && slot2 == slot3 && slot1!=4 ) printf("NICKEL");// same outcome in all 3 slots
		else printf("\nNO WINNING\n");

		getchar(); // take any char as input because of while loop
	}
}