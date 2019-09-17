/*
 ============================================================================
 Name        : Structures.c
 Author      : Muhamed Kotp
 Version     : 1.0
 Date		 : 17/09/2019
 Copyright   : This is an open source code for all embedded systems students
 Description : This program teaches the basic operations on structures

 ============================================================================
 */

/*Include header files*/
#include <stdio.h>

/*Define data type for gender*/
typedef enum {
	FEMALE,
	MALE
} Gender;

/*Define the employee data type*/
typedef struct {
	char name[50];
	int salary;
	Gender gender;
} Employee;

/*Main program*/
int main(void) {

	Employee salesEmployees[3];		//Define 3 employees
	int i = 0;

	/*Scan the 3 employees data*/
	for (i = 0; i < 3; i++) {
		printf("Please enter name\n");
		fflush(stdout);
		scanf("%[^\n]s", salesEmployees[i].name);	//Scan the employee name
		fflush(stdin);
		printf("Please enter salary\n");
		fflush(stdout);
		scanf("%d", &salesEmployees[i].salary);		//Scan the employee salary
		fflush(stdin);
		printf("Please enter gender 0-Female or 1-Male\n");
		fflush(stdout);
		scanf("%d", &salesEmployees[i].gender);		//Scan the employee gender
		fflush(stdin);
	}

	/*Print the 2 employees data*/
	for (i = 0; i < 3; i++) {
		printf("Employee name = %s\n", salesEmployees[i].name);		//Print the employee name
		fflush(stdout);
		printf("Employee salary = %d\n", salesEmployees[i].salary);	//Print the employee salary
		fflush(stdout);
		(salesEmployees[i].gender == FEMALE) ?				//Print the employee gender as a text
				printf("Employee gender is Female\n") :
				printf("Employee gender is Male\n");
		fflush(stdout);
	}

	return 0;
}
