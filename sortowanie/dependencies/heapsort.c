#include "heapsort.h"


void heapify(int arr[], int n, int i)
{
	int larg = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	if (left < n && arr[left] > arr[larg])
		larg = left;
	if (right < n && arr[right] > arr[larg])
		larg = right;
	if (larg != i)
	{
		uni::swap(&arr[i], &arr[larg]);
		heapify(arr, n, larg);
	}
}

void heapSort(int arr[], int n)
{
	for (int i = n / 2 - 1; i >= 0; --i)
	{
		heapify(arr, n, i);
	}

	for (int i = n - 1; i >= 0; --i)
	{
		uni::swap(&arr[0], &arr[i]);
		heapify(arr, i, 0);
	}
}