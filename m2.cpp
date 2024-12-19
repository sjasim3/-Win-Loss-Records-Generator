/*
* filename: m2.cpp
* Project : Major Assignment 2
* By : Sarah Jasim
* Date : 2022 - 10 - 17
* Description : This program is wrote to calculate powers using a function that I created.
*/

#include <stdio.h>
#pragma warning(disable: 4996) 

//prototypes
int getNum(void);
int powerCalculation(int base, int exponent);
int rangeChecker(int value, int min, int max);


int main()
{
	int input = 0;
	int total = 0;
	int base = 1;
	int exponent = 1;

	while (input != 4)
	{
		printf("\n\nPower Menu:\n\n");
		printf("	1. Change base\n");
		printf("	2. Change exponent\n");
		printf("	3. Display base raised to exponent\n");
		printf("	4. Exit program\n");
		printf("\nOption?	");

		input = getNum();

		if (input == 1)
		{
			printf("\nChange Base:	");
			base = getNum();
			if (rangeChecker(base, 1, 25) == 0)
			{
				printf("Base value is out of range!\n");
			}
		}
		else if (input == 2)
		{
			printf("\nChange Exponent:	");
			exponent = getNum();
			if (rangeChecker(exponent, 1, 5) == 0)
			{
				printf("Exponent value is out of range!\n");
			}
		}
		else if (input == 3)
		{
			total = powerCalculation(base, exponent);
			printf("\n%d to the power of %d is %d", base, exponent, total);
		}
		else if (input == 4)
		{
			break;
		}
		else
		{
			printf("\nInvalid entry\n\n");
		}
	}

	return 0;
}





//Function: powerCalculation()
//Parameters: int base, int exponent
//Return values: Returns the value to total within the while body statment and returning a value of 0 before closing the braces of the function
//Description: Using it to calculate the base and exponent that the user enters

int powerCalculation(int base, int exponent)
{
	{
		int total = 1;

		while (exponent)
		{
			total = total * base;
			exponent--;
		}
		return total;
	}

	return 0;
}





//Function: rangeChecker()
//Parameters: int value, int min, int max
//Return values: Returns 0 if value is less than minimum or if value is more than maximum, and 1 if the value is within the value range.
//Description: Using it to check for the range of the number(s) the user enters

int rangeChecker(int value, int min, int max)
{
	if (value >= min && value <= max)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}





//Function: getNum()
//Parameters; none
//Return values: Returns the value number that the user has entered
//Description: Using it to obtain user input

#pragma warning(disable: 4996)
int getNum(void)
{
	/* we will see in a later lecture how we can improve this code */
	char record[121] = { 0 }; /* record stores the string */
	int number = 0;
	/* NOTE to student: indent and brace this function consistent with
	your others */
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