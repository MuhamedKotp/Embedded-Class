/*
 ============================================================================
 Name        : StrLength.c
 Author      : Muhamed Kotp
 Version     : 1.0
 Date 		 : 17/09/2019
 Copyright   : This is an open source code for all embedded systems students
 Description : This program receives string from the user then counts it's alphabets
 and print the string length
 ============================================================================
 */

/*Include header files*/
#include <stdio.h>


/*Main program*/
int main(void) {
	char userWord[50] = {0};		//Container for the user string with max length of 50 alphabet
	int i = 0;	//Iterator for loops

	printf("Please enter your sentence\n"); // prints
	fflush(stdout);		//Clean console output buffer

	scanf("%[^\n]s", userWord);	//Receive the user string
	fflush(stdin);	//Clean console input buffer

	while(userWord[i] != '\0'){
		i++;
	}

	printf("The length of string = %d", i);

	return 0;
}
