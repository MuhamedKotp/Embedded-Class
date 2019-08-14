/*
 ============================================================================
 Name        : EvenOdd.c
 Author      : Muhamed Kotp
 Version     : 1.0
 Copyright   : This is an open source code for all embedded systems students
 Description : This program prints the Even and Odd numbers that are exist
 	 	 	   between 1 - 50 based on the user selection
 ============================================================================
 */

/*Include header files*/
#include <stdio.h>


/*Main program*/
int main(void) {
	int userSelection = 0;		//Container for the user selection
	int i = 0;		//Iterator for loops

	printf("Welcome to Even Odd numbers Calculator\n"); // prints welcome on the console
	printf("This program prints even numbers or odd numbers between 1 and 50\n");	//Print message on the console
	printf("Please select: \n1-Even numbers \n2-Odd numbers \n");	//Print selection menu on the console
	fflush(stdout);		//Clean console output buffer

	scanf("%d", &userSelection);	//Receive the user selection
	fflush(stdin);	//Clean console input buffer

	switch (userSelection) {		//Check the user selection
	case 1:
		printf("You selected Even numbers\n");	//Print confirmation message to the user
		/*Print even numbers*/
		for (i = 0; i <= 50; i+=2) {
			printf("%d\n", i);
		}
		break;
	case 2:
		printf("You selected Odd numbers\n");		//Print confirmation message to the user
		/*Print odd numbers*/
		for (i = 1; i <= 50; i+=2) {
			printf("%d\n", i);
		}
		break;
	default:			//Handle wrong choices
		printf("You entered wrong option");
	}

	return 0;
}
