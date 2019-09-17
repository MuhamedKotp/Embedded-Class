/*
 ============================================================================
 Name        : C-Exercise.c
 Author      : Muhamed Kotp
 Version     : 1.0
 Date		 : 17/09/2019
 Copyright   : This is an open source code for all embedded systems students
 Description : This is the solution of the C exercise attached with
 ============================================================================
 */

/*Include header files*/
#include <stdio.h>

/*Uncomment the macro of the required question*/
//#define QUESTION_1
//#define QUESTION_2
//#define QUESTION_3


/*Functions prototypes*/
void swap(int *first, int *second);

/*Main program*/
int main() {

#ifdef QUESTION_1
	int arr[] = { 2, 5, 3, 5, 1, 2, 5, 8 };		//Define the array
	int num = 0;
	int i = 0;
	int arr_size = 0;
	/*Read the number from the user*/
	printf("Please enter the required number\n");
	fflush(stdout);
	scanf("%d", &num);
	fflush(stdin);

	/*Find the size of the array*/
	arr_size = sizeof(arr) / sizeof(arr[0]);

	/*Loop across the array elements*/
	int counter = 0;	//Define counter to store the number of occurrence
	for (i = 0; i < arr_size; i++) {
		if (arr[i] == num) {	//Check if the current element equals the required number
			counter++;	//Increment the number counter
		}
	}
	/*Print the result*/
	printf("%d occured %d times\n", num, counter);
#endif

#ifdef QUESTION_2
	int arr[] = { 2, 5, 3, 5, 1, 2, 5, 8 };	//Define the array
	int num = 0;
	int i = 0;
	int j = 0;
	int arr_size;
	/*Read the number from the user*/
	printf("Please enter the required number\n");
	fflush(stdout);
	scanf("%d", &num);
	fflush(stdin);

	/*Find the size of the array*/
	arr_size = sizeof(arr) / sizeof(arr[0]);

	/*Loop across the array elements*/
	for (i = 0; i < arr_size - 1; i++) {
		if (arr[i] == num) {		//Check if the element equals the desired number
			/*Swap the number with the following number till reach end*/
			for (j = i + 1; j < arr_size; j++) {
				swap(&arr[j], &arr[j - 1]);
			}
		}
	}

	/*Print the result*/
	for (i = 0; i < arr_size; i++) {
		printf("arr[%d] = %d\n", i, arr[i]);
	}

#endif

#ifdef QUESTION_3
	int x = 3;
	int arr[7] = { 1, 2, 3, 4, 5 };
	int *ptr_X = &x;
	int *ptr_Arr = arr;
	printf("x = %d\n", x);			//Prints x
	printf("++x = %d\n", ++x);		//Prints value of x+1
	printf("*ptr_X = %d\n", *ptr_X);	//Prints the value of x
	printf("ptr_Arr[6] = %d\n", ptr_Arr[6]);	//Prints value of arr[6]
	printf("arr[7] = %d\n", arr[7]);	//Out of boundary value
#endif

	return 0;

}


/*Functions definitions*/
void swap(int *first, int *second) {
	int temp = *first;
	*first = *second;
	*second = temp;
}

