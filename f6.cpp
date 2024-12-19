/*
* Project:		Focused Assignment 6
* File:			f6.cpp
* By:			Sarah Jasim
* Date:			11/14/2022
* Description:	This program is wrote to practice using pointer variables to modify parameters.
*/

#include <stdio.h>
#pragma warning(disable: 4996)

double getNum(void);
int getDouble(double *pNumber);
void calculateStats(double d1, double d2, double d3, double d4, double *pSum, double *pAverage);
void calculateArrayStats(double values[], int numArray, double *pSum, double *pAverage);
void fillArray(double values[], int numArray, double fillValue);

int main()
{
	double d1 = 0;
	double d2 = 0;
	double d3 = 0;
	double d4 = 0;
	int returnValue;

	printf("Enter a floating point number: ");
	returnValue = getDouble(&d1);

	if (returnValue == 0)
	{
		return 0;
	}
	
	printf("Enter another floating point number: ");
	returnValue = getDouble(&d2);

	if (returnValue == 0)
	{
		return 0;
	}

	printf("Enter another floating point number: ");
	returnValue = getDouble(&d3);

	if (returnValue == 0)
	{
		return 0;
	}

	printf("Enter another floating point number: ");
	returnValue = getDouble(&d4);

	if (returnValue == 0)
	{
		return 0;
	}

	double average;
	double sum;

	calculateStats(d1, d2, d3, d4, &sum, &average);
	printf("The average and sum of the variables: %lf %lf\n\n", average, sum);

	double numArray = 7;
	double values[] = { 0, 0, 0, 0, 0, 0, 0 };

	for (int i = 0; i < numArray; i++)
	{
		printf("Enter a number:");
		returnValue = getDouble (&values[i]);

		if (returnValue == 0)
		{
			return 0;
		}
	}

	calculateArrayStats(values, numArray, &sum, &average);
	printf("The average and sum of the array elements: %lf, %lf\n\n", average, sum);

	fillArray(values, numArray, 40);

	printf("New Array elements: ");
	printf("%lf, %lf, %lf, %lf, %lf, %lf, %lf\n\n", values[0], values[1], values[2], values[3], values[4], values[5], values[6]);
	
	return 0;
}

/*
Function: getDouble()
Parameter: double *pNumber: pointer to a variable that is
filled in by the user input, if valid
Return Value: int: 1 if the user entered a valid floating-
point number, 0 otherwise
Description: This function gets a floating-point number
from the user. If the user enters a valid floating-point
number, the value is put into the variable pointed to by
the parameter and 1 is returned. If the user-entered value
is not valid, 0 is returned.
*/
int getDouble(double *pNumber)
{
	if (*pNumber = getNum())
		return 1;

	else
		return 0;
}





/*
Function: calculateStats()
Parameters: double d1, d2, d3, d4: four floating-point
numbers
double *pAverage: pointer to a variable that
is filled in by this function with the average of d1, d2,
d3, and d4
double *pSum: pointer to a variable that is
filled in by this function with the sum of d1, d2, d3, and
d4
Return Value: none
Description: This function takes four floating-point
numbers passed as doubles and calculates the average and
sum of the numbers. Once calculated, the average gets put
into the variable pointed to by the pAverage parameter and
the sum gets put into the variable pointed to by the pSum
parameter.
*/
void calculateStats(double d1, double d2, double d3, double d4, double *pSum, double *pAverage)
{
	*pSum = d1 + d2 + d3 + d4;
	*pAverage = (*pSum) / 4;
}





/*
Function: calculateArrayStats()
Parameters: double values[]: floating-point numbers
int numArray: number of array elements
double *pSum: pointer to a variable that is
filled in by this function with the sum of all elements in
the array
double *pAverage: pointer to a variable that
is filled in by this function with the average of all
elements in the array
Return Value: none
Description: This function takes an array of floating-point
(double) numbers, given the number of elements in the array
as a parameter, and calculates the average and sum of the
numbers. Once calculated, the average gets put into the
variable pointed to by the pAverage parameter and the sum
gets put into the variable pointed to by the pSum
parameter.
*/
void calculateArrayStats(double values[], int numArray, double *pSum, double *pAverage)
{
	*pSum = 0;
	for (int i = 0; i < numArray; i++)
	{
		*pSum += values[i];
	}

	if (numArray > 0)
		*pAverage = *pSum / numArray;
	else 
		*pAverage = 0;
}





/*
Function: fillArray()
Parameters: double values[]: floating-point numbers
int numArray: number of array elements
double fillValue: value to put into array elements
Return Value: none
Description: This function takes an array of floating-point
(double) numbers, given the number of elements in the array
as a parameter, and puts the fillValue into each element of
the array.
*/
void fillArray(double values[], int numArray, double fillValue)
{
	for (int i = 0; i < numArray; i++)
		values[i] = fillValue;
}





//Function: getNum()
//Parameters; none
//Return values: Returns the value that the user has entered
//Description: Using it to obtain user input as a double / floating point value.

double getNum(void)
{
	char record[121] = { 0 }; 
	double number = 0;

	fgets(record, 121, stdin);
	
	if (sscanf(record, "%lf", &number) != 1)
	{
		number = 0;
	}
	return number;
}