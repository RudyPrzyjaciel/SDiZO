#include "sort.h"

#define count 500000
#define iter 10

int main()
{
	FILE* liczby = fopen("liczby.txt", "r");
	int* data = new int[count];
	int* toSortQuick = new int[count];
	int* toSortBubble = new int[count];
	int* toSortInsert = new int[count];
	for (size_t cnt = 0; cnt < count; ++cnt)
	{
		fscanf(liczby, "%d,", &data[cnt]);
		//toSortQuick[cnt] = data[cnt];
		//toSortBubble[cnt] = data[cnt];
		//toSortInsert[cnt] = data[cnt];
	}
	fclose(liczby);

	clock_t startTime, endTime;
	double cpuTimeUsed;

	////BubbleSort
	//printf("Sorting %d numbers using BubbleSort in:\n", count);
	//for (int i = 0; i < iter; i++)
	//{
	//	for (size_t cnt = 0; cnt < count; ++cnt)
	//	{
	//		toSortBubble[cnt] = data[cnt];
	//	}
	//	startTime = clock();
	//	bubble(toSortBubble, count);
	//	endTime = clock();
	//	cpuTimeUsed = ((double)(endTime - startTime)) / CLOCKS_PER_SEC;
	//	printf("%f\n", cpuTimeUsed);
	//}

	//InsertSort
	printf("Sorting %d numbers using InsertSort in:\n", count);
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
		printf("%f\n", cpuTimeUsed);
	}

	//QuickSort
	printf("Sorting %d numbers using quickSort in:\n", count);
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
		printf("%f\n", cpuTimeUsed);
	}

	uni::saveToFile(toSortBubble, count, "bubbleSort.csv");	
	uni::saveToFile(toSortInsert, count, "insertSort.csv");
	uni::saveToFile(toSortQuick, count, "quickSort.csv");

	delete[] data;
	delete[] toSortBubble;
	delete[] toSortInsert;
	delete[] toSortQuick;

	return 0;
}
