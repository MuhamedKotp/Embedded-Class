/*
 ============================================================================
 Name        : ChangeCase.c
 Author      : Muhamed Kotp
 Version     : 1.0
 Copyright   : This is an open source code for all embedded systems students
 Description : This program receives string from the user and then print it in
 lower case
 ============================================================================
 */

/*Include header files*/
#include <stdio.h>


/*Main program*/
int main(void) {
	char userWord[51] = {0};		//Container for the user string with max length of 50 alphabet
	int i = 0;	//Iterator for loops

	printf("Welcome\n"
			"This program changes the case of the input string into lower case\n"); // prints welcome on the console

	printf("Please enter your string (max alength = 50 alphabet)\n");//Print to the console
	fflush(stdout);		//Clean console output buffer

	scanf("%[^\n]s", userWord);	//Receive the user string
	fflush(stdin);	//Clean console input buffer

	/*Loop on every alphabet*/
	for(i=0; i<50; i++){
		if(userWord[i] == '\0'){	//Check if the string is ended
			break;		//Go out the loop
		}
		if(userWord[i] >= 65 && userWord[i] <= 90){		//Check if it is in upper case
			userWord[i] += 32;		//Convert alphabet into lower case
		}
	}

	printf("Your string is\n%s\n", userWord);	//Print the converted string


	return 0;
}
