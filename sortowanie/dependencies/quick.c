#include "quick.h"

// based on https://www.programiz.com/dsa/quick-sort

int partition(int arr[], int lo, int hi)
{
	int pivot = arr[hi];
	int i = (lo - 1);
	for (int j = lo; j <= hi - 1; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;
			uni::swap(&arr[i], &arr[j]);
		}
	}
	uni::swap(&arr[i + 1], &arr[hi]);
	return (i + 1);
}

void quickSort(int arr[], int lo, int hi)
{
	if (lo < hi)
	{
		int pi = partition(arr, lo, hi);
		quickSort(arr, lo, pi - 1);
		quickSort(arr, pi + 1, hi);
	}
}

