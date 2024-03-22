/*
* FILE : f7.cpp
* PROJECT : SENG1000- focused assignment 7
* PROGRAMMER : Bhawanjeet Kaur Gill
* FIRST VERSION : 2024-03-22
* DESCRIPTION : Write a program to give you practice at creating text and binary files.
*/
#include <stdio.h>
#pragma warning(disable: 4996)
const unsigned short kBinaryData[] = { 26946, 24942, 31090, 25632, 29793, 8289, 28518, 8306, 28537, 33141, 39308 };
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


	//For binary file
	FILE* secondFilePointer = NULL;
	secondFilePointer = fopen("myEvenDataList.data", "wb");
	int arraySize = sizeof(kBinaryData) / sizeof(kBinaryData[0]);
	if (secondFilePointer == NULL)
	{
		printf("Unable to create file.\n");
		return -1;
	}
	for (int indexNumber = 0; indexNumber < arraySize; indexNumber++)
	{
		if (kBinaryData[indexNumber] % 2 == 0)
		{
			// Write the even numbers to the file
			if (fwrite(&kBinaryData[indexNumber], sizeof(unsigned short), 1, secondFilePointer) < 1)
			{
				printf("Error while writing data to the file.\n");
				return -3;
			}
		}
	}
	fclose(secondFilePointer);
	return 0;

	return 0;
}
