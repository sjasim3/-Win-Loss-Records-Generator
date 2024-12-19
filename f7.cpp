/*
* Project:		Focused Assignment 7
* File:			f7.cpp
* By:			Sarah Jasim
* Date:			11/25/2022
* Description:	This program is wrote to give me a practice at creating text and binary files with using file I/O.
*/

#include <stdio.h>
#pragma warning(disable: 4996)

int main()
{
	FILE *ptr = NULL;
	const unsigned short kBinaryData[] = {26946, 24942, 31090, 25632, 29793, 8289, 28518, 8306,28537, 33141, 39308};

	ptr = fopen("myTextFile.txt", "w");

    if (ptr == NULL)
    {
        printf("function call fopen failed, quitting program");
        return 0;
    }
    else
    {
        for (int S = 1; S < 3; S++)
        {
            fprintf(ptr, "This is Line %d\n", S);
        }
    }
    if (fclose(ptr) != 0)
    {
        printf("function call fclose failed, quitting program");
        return 0;
    }


    ptr = fopen("myBinaryFile.data", "wb");

    if (ptr == NULL)
    {
        printf("function call fopen failed, quitting program");
        return 0;
    }
    else
    {
        fwrite(kBinaryData, sizeof(kBinaryData), 1, ptr);
    }
    if (fclose(ptr) != 0)
    {
        printf("function call fopen failed, quitting program");
        return 0;
    }

    return 0;
}
