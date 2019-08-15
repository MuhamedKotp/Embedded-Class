/*
 ============================================================================
 Name        : ChangeCase.c
 Author      : Muhamed Kotp
 Version     : 1.0
 Copyright   : This is an open source code for all embedded systems students
 Description : This program checks whether the number is prime or not
 ============================================================================
 */

/*Include header files*/
#include <stdio.h>

/*Functions prototype*/
char isPrime(int num);

/*Main program*/
int main(void) {
	int userNumber = 0;		//Container for the user input number
	char result = 0;	//The result of the check operation

	printf("Welcome\n"
			"This program checks whether the number is prime or not\n"); // prints welcome on the console
	printf("Please enter a positive number\n"); //Print to the console
	fflush(stdout);		//Clean console output buffer

	scanf("%d", &userNumber);	//Receive the user number
	fflush(stdin);	//Clean console input buffer

	/*Call the check function*/
	result = isPrime(userNumber);

	/*Check the function result*/
	if(result == -1){	//If function returns error
		printf("Number is neither a prime nor a composite number.");
	}
	else if (result == 0) {		//If function returns prime
		printf("The number is prime");	//Print the check result
	} else {
		printf("The number is not prime because it is divisable by %d", result);	//Print the check result
	}

	return 0;
}

/*Function Body*/
char isPrime(int num) {
	int i = 0;	//Iterator for loops

	/*Check if the number is 0 or 1*/
	if (num == 0 || num == 1) {
		return -1;	//Return error
	}

	//Loop and check if the number is divisible by another numbers
	for (i = 2; i <= num/2; i++) {
		// condition for non prime numbers
		if (num % i == 0) {
			return i;		//return the number that the input number is divisible by it
		}
	}

	return 0;	//If the number is not divisible by any other number then return the number is prime
}
