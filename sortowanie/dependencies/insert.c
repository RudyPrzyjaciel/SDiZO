#include "insert.h"

// based on https://www.programiz.com/dsa/insertion-sort

int insert(int data[], int count)
{
	for (int i = 1; i < count; i++)
	{
		int k = data[i];
		int j = i - 1;

		while (k < data[j] && j >= 0)
		{
			data[j + 1] = data[j];
			--j;
		}
		data[j + 1] = k;
	}
	return 0;
}
