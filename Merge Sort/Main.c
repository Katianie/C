/** MergeSort: Main.c
* MergeSort is one of the fastest/efficent sorting algorithms in existance.
* It uses the idea of "Divide and Conquer". The worst case efficency is O(n log(n))
* which is much better than most other sorting methods.
* 
* Divide: which is where we recursively divide
* all of our data in half until its size is 1.
* 
* Conquer: Is where we reassemble the array while also
* sorting the numbers.
* 
*
* Eddie O'Hagan
* Copyright © 2015 Katianie.com
*/
#include <stdio.h>
#include <stdlib.h>

int* tempNums = NULL;
void sort(int* nums, int length);
void divide(int* nums, int startIndex, int endIndex);
void conquer(int* nums, int startIndex, int midIndex, int endIndex);

void divide(int* nums, int startIndex, int endIndex)
{
	if (startIndex < endIndex)
	{
		int midIndex = startIndex + (endIndex - startIndex) / 2;

		//Divide the left side
		divide(nums, startIndex, midIndex);

		//Divide the right side
		divide(nums, midIndex + 1, endIndex);

		//Ride the kick back up the stack while combining and sorting
		conquer(nums, startIndex, midIndex, endIndex);
	}
}

void conquer(int* nums, int startIndex, int midIndex, int endIndex)
{
	int tempIndex = startIndex;
	int rightOfMid = midIndex + 1;
	int numsIndex = 0;

	for (int i = startIndex; i <= endIndex; i++)
	{
		tempNums[i] = nums[i];
	}

	//The numbers are semi sorted but they are interlaced so to fix that we use two indexes and the tempNums buffer.
	while (startIndex <= midIndex && rightOfMid <= endIndex)
	{
		if (nums[startIndex] < nums[rightOfMid])
		{
			tempNums[tempIndex++] = nums[startIndex++];
		}
		else
		{
			tempNums[tempIndex++] = nums[rightOfMid++];
		}
	}

	//Keep copying if one of the sides still has more.
	while (startIndex <= midIndex)
	{
		tempNums[tempIndex++] = nums[startIndex++];
	}
	while (rightOfMid <= endIndex)
	{
		tempNums[tempIndex++] = nums[rightOfMid++];
	}

	//Copy the numbers back into the buffer.
	while (endIndex >= 0)
	{
		nums[endIndex] = tempNums[endIndex];
		endIndex--;
	}
}

void sort(int* nums, int length)
{
	tempNums = calloc(length, length * sizeof(int));

	divide(nums, 0, length - 1);
}

int main()
{
	int nums[] = { 62, 23 , 42, 8, 6, 25, 91, 38, 74};
	int length = sizeof(nums) / sizeof(int);

	sort(nums, length);

	for (int i = 0; i < length; i++)
	{
		printf("%d ", nums[i]);
	}

	system("pause");
	return 0;
}