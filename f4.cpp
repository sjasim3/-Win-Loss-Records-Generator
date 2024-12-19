/*
* Project:		Focused Assignment 4
* File:			f4.cpp
* By:			Sarah Jasim
* Date:			10/14/2022
* Description:	This program is wrote to get integers from the user and determines which is the lowest.
*/

#include <stdio.h>
#pragma warning(disable: 4996) // required by Visual Studio

//prototype
int getNum(void);

int main()
{
	//Declare and inisialize array to create 10 ints.
	int index[10] = { 0,1,2,3,4,5,6,7,8,9};

	int i = 0;
	int number = 0;
	while(i < 10)

	{
		int number = 0;
		printf("Please input the value at index %d in the array: ",index[i]);
		number = getNum();
		++i;

		if(number < index [i])
		{
			number = index[i];
			number++;
		}
	}
	printf("The lowest value is %d at index %d\n", number, i);

	return 0;
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