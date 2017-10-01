/** BinarySearch: Is a way of searching for a particular item in a collection.
* The BinarySearch is one of the most efficent ways to search for something
* because each iteration, we cut our collection size in half.
*
* If we have all the numbers (sorted) beween 1-100 and we want to find the
* number 69, we first ask:
*
* "Is it greater than 50 or less than 50" -> greater
* "Is it greater than 75 or less than 75" -> less
*
* By this point we only have to check the numbers between 51 - 74.
*
* This was uploaded to Katianie.com, Feel free to use this
* code and share it with others, Just give me credit ^_^.
*
* Eddie O'Hagan
* Copyright © 2014 Katianie.com
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

///This algorithm only works if the numbers in the collection is sorted.
///For simplicity I am using a bubble sort to initaly sort the numbers.
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

bool search(int numToLookFor, int* nums,int startIndex, int endIndex)
{
	int midPoint = startIndex + (endIndex - startIndex) / 2;
	int numVal = nums[midPoint];

	//Base case for when to stop looking.
	if ((endIndex - startIndex) <= 0)
	{
		return false;
	}
	else
	{
		//Check if we found our number.
		if (numToLookFor == numVal)
		{
			return true;
		}
		else
		{
			//We did not find our number so check either the left or the right side.
			if (numToLookFor < numVal)
			{
				//Go Left.
				return search(numToLookFor, nums, 0, midPoint);
			}
			else //if (numToLookFor > numVal)
			{
				//Go Right.
				return search(numToLookFor, nums, midPoint + 1, endIndex);
			}
		}
	}
}

bool binarySearch(int numToLookFor, int* nums, int numsLength)
{
	//The collection must be sorted for the search to work.
	sortArray(nums, numsLength);

	return search(numToLookFor, nums, 0, numsLength - 1);
}

int main()
{
	int nums[] = { 69, 25, 61, 82, 27, 33, 42, 11, 3, 9, 46 };
	int length = sizeof(nums) / sizeof(int);
	int numToLookFor = 69;

	bool result = binarySearch(numToLookFor, nums, length);

	if (result == true)
	{
		printf("%s\n\0", "Found it!");
	}
	else
	{
		printf("%s %d\n\0", "Could not find", numToLookFor);
	}

	system("pause");
	return 0;
}