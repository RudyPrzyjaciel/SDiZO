#include "counting.h"

void countingSort(int array[], int size)
{
	int output[10];
	int max = array[0];

	for (int i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	int count[65001]; //must be at least max+1

	for (int i = 0; i <= max; ++i)
	{
		count[i] = 0;
	}

	for (int i = 0; i < size; i++)
	{
		count[array[i]]++;
	}

	for (int i = 1; i <= max; i++)
	{
		count[i] += count[i - 1];
	}

	for (int i = size - 1; i >= 0; i--)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}

	for (int i = 0; i < size; i++)
	{
		array[i] = output[i];
	}
}