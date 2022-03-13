#pragma once
#include <stdio.h>
#include <cstring>

namespace uni
{
	void swap(int* a, int* b);
	void printArr(int* arr, int size);
	int saveToFile(int* arr, int len, const char* name);
}
