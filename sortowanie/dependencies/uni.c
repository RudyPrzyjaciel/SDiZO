#include "uni.h"


void uni::swap(int* a, int* b)
{
	long int t = *a;
	*a = *b;
	*b = t;
}

void uni::printArr(int* arr, int size)
{
	printf("---------------------\n");
	for (int i = 0; i < size; ++i)
	{
		printf("%d\n", arr[i]);
	}
	printf("---------------------\n");
}

int uni::saveToFile(int* arr, int len,const char* name)
{
	int l = strlen(name);
	FILE* newFile;
	newFile = fopen(name, "w+");
	fprintf(newFile, "%d", arr[0]);
	for (int i = 1; i < len; ++i)
	{
		fprintf(newFile, ", %d", arr[i]);
	}
	fclose(newFile);
	printf("Saved data to file \"%s\"\n", name);
	printf("---------------------\n");
	return 0;
}