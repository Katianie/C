/** Hashing: Main.c
* Given an array of integers, output the number of occurrences for each.
*
* For instance: [8, 8, 8, 9, 9, 11, 15, 16, 16, 16]
* should output something like :
* 8 : 3
* 9 : 2
* 11 : 1
* 15 : 1
* 16 : 3
*
* Worst Case: O(n)
*
* Eddie O'Hagan
* Copyright © 2014 Katianie.com
*/
#include <stdio.h>
#include <stdlib.h>

int* countOccurrences(int* theArray, int len)
{
	int largestVal = theArray[0];
	int currNum = 0;
	int* hashMap;

	//Find the largest value in the array.
	for (int i = 0; i < len; i++)
	{
		if (theArray[i] > largestVal)
		{
			largestVal = theArray[i];
		}
	}

	//Create and initialize a hash map as large as the largest number.
	hashMap = calloc(largestVal, sizeof(int));
	for (int i = 0; i < len; i++)
	{
		currNum = theArray[i];
		hashMap[currNum - 1]++; 
	}

	for (int i = 0; i < largestVal; i++)
	{
		if (hashMap[i] != 0)
		{
			printf("%d: %d\n", (i + 1), hashMap[i]);
		}
	}

	free(hashMap);
}

int main()
{
	int theArray[14];
	int* hashMap;

	theArray[0] = 8;
	theArray[1] = 54;
	theArray[2] = 1;
	theArray[3] = 8;
	theArray[4] = 1;
	theArray[5] = 15;
	theArray[6] = 9;
	theArray[7] = 11;
	theArray[8] = 1;
	theArray[9] = 81;
	theArray[10] = 16;
	theArray[11] = 9;
	theArray[12] = 91;
	theArray[13] = 16;

	countOccurrences(&theArray, 14);

	system("pause");
	return 0;
}