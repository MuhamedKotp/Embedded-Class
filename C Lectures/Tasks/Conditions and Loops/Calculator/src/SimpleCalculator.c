/*
 ============================================================================
 Name        : SimpleCalculator.c
 Author      : Muhamed Kotp
 Version     : 1.0
 Copyright   : This is an open source code for all embedded systems students
 Description : This is a simple calculator which perform the following operations:
 1-Addition
 2-Subtraction
 3-Multiplication
 4-Division
 5-Power
 ============================================================================
 */

/*Include header files*/
#include <stdio.h>

/*Main program*/
int main(void) {
	int userSelection = 0;		//Container for the user selection
	int firstNumber = 0;	//First parameter for calculations
	int secondNumber = 0;	//Second parameter for calculations
	int result = 0;		//Will hold the result of calculations
	int i = 0;		//Iterator for loops

	printf("Welcome to Calculator project\n"); // prints welcome on the console

	/*Receive user required operation*/
	printf("Please select: \n1-Add \n2-Sub \n3-Mul \n4-Div \n5-Power \n"); //Print selection menu on the console
	fflush(stdout);		//Clean console output buffer
	scanf("%d", &userSelection);	//Receive the user selection
	fflush(stdin);	//Clean console input buffer

	/*Receive first argument for calculations*/
	printf("Please enter your first number \n");//Print demonstration message
	fflush(stdout);		//Clean console output buffer
	scanf("%d", &firstNumber);	//Receive the user parameter
	fflush(stdin);	//Clean console input buffer

	/*Receive second argument for calculations*/
	printf("Please enter your second number \n");//Print demonstration message
	fflush(stdout);		//Clean console output buffer
	scanf("%d", &secondNumber);	//Receive the user parameter
	fflush(stdin);	//Clean console input buffer

	switch (userSelection) {		//Check the user selection
	case 1:
		result = firstNumber + secondNumber;	//Perform summation
		printf("%d + %d = %d\n", firstNumber, secondNumber, result); //Print the sum of user parameters
		break;
	case 2:
		result = firstNumber - secondNumber;	//Perform subtraction
		printf("%d - %d = %d\n", firstNumber, secondNumber, result); //Print the subtraction of user parameters
		break;
	case 3:
		result = firstNumber * secondNumber;	//Perform multiplication
		printf("%d x %d = %d\n", firstNumber, secondNumber, result); //Print the multiplication of user parameters
		break;
	case 4:
		/*Check for division over zero*/
		if (secondNumber == 0) {
			printf("Error: Can't divide over zero");	//print error
			break;
		}
		result = firstNumber / secondNumber;	//Perform division
		printf("%d / %d = %d\n", firstNumber, secondNumber, result); //Print the division of user parameters
		break;
	case 5:
		result = 1;
		/*Calculate the power*/
		for(i=0; i<secondNumber; i++){
			result *= firstNumber;
		}
		printf("%d ^ %d = %d\n", firstNumber, secondNumber, result); //Print the reult
		break;
	default:			//Handle wrong choices
		printf("You entered wrong option");
	}

	return 0;
}
