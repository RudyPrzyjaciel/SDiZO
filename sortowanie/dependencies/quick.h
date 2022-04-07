#pragma once

#include <stdio.h>
#include <time.h>
#include "uni.h"

// based on https://www.programiz.com/dsa/quick-sort

void quickSort(int arr[], int lo, int hi);
int partition(int arr[], int lo, int hi);