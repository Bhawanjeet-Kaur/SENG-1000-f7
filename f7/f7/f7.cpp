/*
* FILE : f7.cpp
* PROJECT : SENG1000- focused assignment 7
* PROGRAMMER : Bhawanjeet Kaur Gill
* FIRST VERSION : 2024-03-22
* DESCRIPTION : Write a program to give you practice at creating text and binary files.
*/
#include <stdio.h>
#pragma warning(disable: 4996)
int main(void)
{
	//For text file
	FILE* firstFilePointer = NULL;
	firstFilePointer = fopen("myTextFile.txt", "w");
	if (firstFilePointer == NULL)
	{
		printf("Unable to create file.\n");
		return -1;
	}
	if (fprintf(firstFilePointer, "This is line 1.\n") < 0)
	{
		printf("Can't write to file.\n");
		return -2;
	}
	if (fprintf(firstFilePointer, "This is line 2.\n") < 0)
	{
		printf("Can't write to file.\n");
		return -2;
	}
	fclose(firstFilePointer);


	return 0;
}
