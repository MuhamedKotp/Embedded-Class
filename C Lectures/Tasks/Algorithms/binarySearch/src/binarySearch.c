/*
 ============================================================================
 Name        : binarySearch.c
 Author      : Muhamed Kotp
 Version     : 1.0
 Date		 : 17/09/2019
 Copyright   : This is an open source code for all embedded systems students
 Description : Binary search algorithm implementation
 ============================================================================
 */

/*Include header files*/
#include <stdio.h>

// Binary search function. It returns location of x in
// given array arr[l..r] if present, otherwise -1
int binarySearch(int arr[], int arrSize, int num);

/*Main program*/
int main(void) {
	int arr[] = { 2, 3, 4, 10, 40 };	//Define the array
	int arr_size = sizeof(arr) / sizeof(arr[0]);	//Calculate the array size
	int x = 2;	//The desired number to search for

	int result = binarySearch(arr, arr_size, x);	//Search for the number

	/*Print the output*/
	(result == -1) ?
			printf("Element is not present in array") :
			printf("Element is present at index %d", result);

	return 0;
}


// Binary search function. It returns location of x in
// given array arr[l..r] if present, otherwise -1
int binarySearch(int arr[], int arrSize, int num) {
	int left = 0;
	int right = arrSize - 1;
	int mid = 0;

	do {
		mid = ((right - left) / 2) + left;	//Set the mid value

		if (arr[mid] == num) {		//Check the number at the middle
			return mid;
		}

		if (arr[mid] < num) {		//Check whether the num is in the right half
			left = mid + 1;		//Set array boundaries to search in the right half
		} else {
			right = mid - 1;	//Set array boundaries to search in the left half
		}
	} while (left <= right);	//End condition

	// We reach here when element is not present in array
	return -1;
}
