/*
* Project:		Focused Assignment 8
* File:			f8.cpp
* By:			Sarah Jasim
* Date:			11/28/2022
* Description:	This program is wrote to give me a practice at working with C-style strings, files, command-line arguments, and structs.
*/

#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable: 4996)

struct MyData
{
    int howMany = 0;
    char theText[21];
    char directoryPath[50];
    char filename[21];
};

constexpr auto i = 0;

int main(int argc, char const* argv[])
{
    struct MyData myArgs;
    int i = 0;

    int howMany = 0;
    for (char i = 0; argv[1][i] != '\0'; i++)
    {
        howMany = howMany * 10 + (argv[1][i] - '0');
    }

    char theText[21];
    for (i = 0; argv[2][i] != '\0'; i++)
    {
        theText[i] = argv[2][i];
    }
    theText[i] = '\0';

    char directoryPath[21];
    for (i = 0; argv[3][i] != '\0'; i++)
    {
        directoryPath[i] = argv[3][i];
    }
    directoryPath[i] = '\0';

    char filename[21];
    for (i = 0; argv[4][i] != '\0'; i++)
    {
        filename[i] = argv[4][i];
    }
    filename[i] = '\0';


    if (argc != 4)
    {
        printf("\nIncorrct number of arguments, please input 4 arguments.\n");
        return 0;
    }

    myArgs.howMany = howMany;

    for (i = 0; theText[i] != '\0'; i++)
    {
        myArgs.theText[i] = theText[i];
    }
    myArgs.theText[i] = '\0';

    char location[45] = "";
    strcat(location, directoryPath);
    strcat(location, "C:\exe\\blah.txt");

    FILE *fptr = fopen(location, "w");
    for (char i = 0; i < myArgs.howMany; i++)
    {
        fprintf(fptr, "%s\n", myArgs.theText);
    }
    fclose(fptr);

    if (fptr == NULL)
    {
        printf("function call fopen failed, exitting program");
        return 0;
    }
    if (fclose(fptr) != 0)
    {
        printf("function call fclose failed, exiting program");
        return 0;
    }

    return 0;
}
