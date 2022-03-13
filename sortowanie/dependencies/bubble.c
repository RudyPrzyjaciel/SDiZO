#include "bubble.h"

// based on https://www.programiz.com/dsa/bubble-sort

int bubble(int* data, int count)
{
	bool swapped = false;
	do
	{
		swapped = false;
		for (int i = 1; i < count; ++i)
		{
			if (data[i - 1] > data[i])
			{
				uni::swap(&data[i], &data[i - 1]);
				swapped = true;
			}
		}
	} while (swapped);
	return 0;
}
