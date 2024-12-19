/*
* Project:		Focused Assignment 5
* File:			f5.cpp
* By:			Sarah Jasim
* Date:			11/4/2022
* Description:	This program is wrote to Revise Focused 4 & to create & use other functions instead of everything in main.
*/

#include <stdio.h>
#pragma warning(disable: 4996) // required by Visual Studio

//prototype
int getNum(void);
void modifyArrayValues(int Arr[], int number);
int minArrayValue(int Arr[], int number);

int main()
{
	int Arr[10] = { 0,1,2,3,4,5,6,7,8,9 };
	modifyArrayValues(Arr, 10);
	int index = minArrayValue(Arr, 10);

	printf("The lowest value is %d at index %d\n", Arr[index], index);

	return 0;
}





void modifyArrayValues(int Arr[], int number)
{
	for (int i = 0; i < number; i++)
	{
		int number = 0;
		printf("Please input the value at index %d in the array: ", Arr[i]);
		Arr[i] = getNum();
	}
}





int minArrayValue(int Arr[], int number)
{
	int lowestValue = 1e9 + 7;
	int lowestIndexElement = 0;

	for (int i = 0; i < number; i++)
	{
		if (Arr[i] < lowestValue)
		{
			lowestValue = Arr[i];
			lowestIndexElement = i;
		}
	}
	return lowestIndexElement;
}





//Function: getNum()
//Parameters; none
//Return values: Returns the value that the user has entered
//Description: Using it to obtain user input

int getNum(void)
{
	/* the array is 121 bytes in size; we'll see in a later lecture how we can
	improve this code */
	char record[121] = { 0 }; /* record stores the string */
	int number = 0;
	/* NOTE to student: brace this function consistent with your others */
	/* use fgets() to get a string from the keyboard */
	fgets(record, 121, stdin);
	/* extract the number from the string; sscanf() returns a number
	* corresponding with the number of items it found in the string */
	if (sscanf(record, "%d", &number) != 1)
	{
		/* if the user did not enter a number recognizable by
		* the system, set number to -1 */
		number = -1;
	}
	return number;
}