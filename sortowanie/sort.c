#include "sort.h"

#define count 500
#define iter 10

int main()
{
	FILE* liczby = fopen("liczby.txt", "r");
	int* data = new int[count];
	for (size_t cnt = 0; cnt < count; ++cnt)
	{
		fscanf(liczby, "%d,", &data[cnt]);
	}
	fclose(liczby);

	clock_t startTime, endTime;
	double cpuTimeUsed;
	double cpuTimeUsedAvg;

	//BubbleSort
	{
		int* toSortBubble = new int[count];
		cpuTimeUsedAvg = 0;
		printf("Sorting %d numbers using BubbleSort on average in:\n", count);
		for (int i = 0; i < iter; i++)
		{
			for (size_t cnt = 0; cnt < count; ++cnt)
			{
				toSortBubble[cnt] = data[cnt];
			}
			startTime = clock();
			bubble(toSortBubble, count);
			endTime = clock();
			cpuTimeUsed = ((double)(endTime - startTime)) / CLOCKS_PER_SEC;
			//cpuTimeUsedAvg = (cpuTimeUsedAvg + cpuTimeUsed) / (i + 1);
			cpuTimeUsedAvg = (cpuTimeUsedAvg * i + cpuTimeUsed) / (i + 1);
		}
		printf("%f\n", cpuTimeUsedAvg);
		uni::saveToFile(toSortBubble, count, "bubbleSort.csv");
		delete[] toSortBubble;
	}

	//InsertSort
	{
		int* toSortInsert = new int[count];
		cpuTimeUsedAvg = 0;
		printf("Sorting %d numbers using InsertSort on average in:\n", count);
		for (int i = 0; i < iter; i++)
		{
			for (size_t cnt = 0; cnt < count; ++cnt)
			{
				toSortInsert[cnt] = data[cnt];
			}
			startTime = clock();
			insert(toSortInsert, count);
			endTime = clock();
			cpuTimeUsed = ((double)(endTime - startTime)) / CLOCKS_PER_SEC;
			//cpuTimeUsedAvg = (cpuTimeUsedAvg + cpuTimeUsed) / (i + 1);
			cpuTimeUsedAvg = (cpuTimeUsedAvg * i + cpuTimeUsed) / (i + 1);
		}
		printf("%f\n", cpuTimeUsedAvg);
		uni::saveToFile(toSortInsert, count, "insertSort.csv");
		delete[] toSortInsert;
	}

	//QuickSort
	{
		int* toSortQuick = new int[count];
		cpuTimeUsedAvg = 0;
		printf("Sorting %d numbers using quickSort on average in:\n", count);
		for (int i = 0; i < iter; i++)
		{
			for (size_t cnt = 0; cnt < count; ++cnt)
			{
				toSortQuick[cnt] = data[cnt];
			}
			startTime = clock();
			quickSort(toSortQuick, 0, count);
			endTime = clock();
			cpuTimeUsed = ((double)(endTime - startTime)) / CLOCKS_PER_SEC;
			//cpuTimeUsedAvg = (cpuTimeUsedAvg + cpuTimeUsed) / (i+1);
			cpuTimeUsedAvg = (cpuTimeUsedAvg * i + cpuTimeUsed) / (i + 1);
		}
		printf("%f\n", cpuTimeUsedAvg);
		uni::saveToFile(toSortQuick, count, "quickSort.csv");
		delete[] toSortQuick;
	}

	//CountingSort
	{
		int* toSortCount = new int[count];
		cpuTimeUsedAvg = 0;
		printf("Sorting %d numbers using countingSort on average in:\n", count);
		for (int i = 0; i < iter; i++)
		{
			for (size_t cnt = 0; cnt < count; ++cnt)
			{
				toSortCount[cnt] = data[cnt];
			}
			startTime = clock();
			countingSort(toSortCount, count);
			endTime = clock();
			cpuTimeUsed = ((double)(endTime - startTime)) / CLOCKS_PER_SEC;
			//cpuTimeUsedAvg = (cpuTimeUsedAvg + cpuTimeUsed) / (i+1);
			cpuTimeUsedAvg = (cpuTimeUsedAvg * i + cpuTimeUsed) / (i + 1);
		}
		printf("%f\n", cpuTimeUsedAvg);
		uni::saveToFile(toSortCount, count, "countSort.csv");
		delete[] toSortCount;
	}

	//HeapSort
	{
		int* toSortHeap = new int[count];
		cpuTimeUsedAvg = 0;
		printf("Sorting %d numbers using heapSort on average in:\n", count);
		for (int i = 0; i < iter; i++)
		{
			for (size_t cnt = 0; cnt < count; ++cnt)
			{
				toSortHeap[cnt] = data[cnt];
			}
			startTime = clock();
			heapSort(toSortHeap, count);
			endTime = clock();
			cpuTimeUsed = ((double)(endTime - startTime)) / CLOCKS_PER_SEC;
			//cpuTimeUsedAvg = (cpuTimeUsedAvg + cpuTimeUsed) / (i + 1);
			cpuTimeUsedAvg = (cpuTimeUsedAvg * i + cpuTimeUsed) / (i + 1);
		}
		printf("%f\n", cpuTimeUsedAvg);
		uni::saveToFile(toSortHeap, count, "heapSort.csv");
		delete[] toSortHeap;
	}


	delete[] data;
	return 0;
}
