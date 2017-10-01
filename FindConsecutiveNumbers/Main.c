/** Find Consecutive Numbers: Main.c
* This program finds consecutive numbers in an array.
*
* Eddie O'Hagan
* Copyright © 2013 Katianie.com
*/
#include <stdlib.h>
#include <stdio.h>

int mostNumAdj = 0;

void sortArray(int* arr, int len)
{
	int juggler;

	//A simple bubble sort implementation.
	for (int i = 0; i < len; i++)
	{
		for (int j = i + 1; j < len; j++)
		{
			if (arr[i] > arr[j])
			{
				juggler = arr[j];
				arr[j] = arr[i];
				arr[i] = juggler;
			}
		}
	}
}

int* findConsecutiveNums(int* nums, int length)
{
	int* diffs = malloc((length - 1) * sizeof(int));
	int* consecNums;
	int consecNumsIndex = 0;
	int temp = 0;
	int startIndex = 0;
	int endIndex = 0;

	sortArray(nums, length);

	//Take the diffrences of all the adjacent numbers.
	for (int i = 0; i < length - 1; i++)
	{
		diffs[i] = nums[i] - nums[i + 1];
	}

	//Go through all the diffrences and figure out the longest "run" of 1's next to eachother.
	for (int i = 0; i < length - 1; i++)
	{
		if (abs(diffs[i]) == 1)
		{
			temp++;

			//Keep track of the largest run thus far.
			if (mostNumAdj < temp)
			{
				mostNumAdj = temp;
				endIndex = i;
			}
		}
		else
		{
			temp = 0;
		}
	}

	//Add one because the diff array is always one less in size then the nums array.
	endIndex++;
	mostNumAdj++;

	//Figure out the start index baised on the run length and the end index.
	startIndex = endIndex - (mostNumAdj-1);

	consecNums = malloc(mostNumAdj * sizeof(int));
	for (int i = startIndex; i <= endIndex; i++)
	{
		consecNums[consecNumsIndex++] = nums[i];
	}

	free(diffs);

	return consecNums;
}

int main()
{
	int nums[8];
	int* conNums;

	nums[0] = 4;
	nums[1] = 5;
	nums[2] = 34;
	nums[3] = 33;
	nums[4] = 32;
	nums[5] = 11;
	nums[6] = 10;
	nums[7] = 31;

	conNums = findConsecutiveNums(nums, 8);

	for (int i = 0; i < mostNumAdj; i++)
	{
		printf("%d ", conNums[i]);
	}

	system("pause");
	return 0;
}