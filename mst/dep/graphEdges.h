#pragma once

#include <iostream>
#include <vector>
#include <climits>
#include <cstring>
#include <time.h>
#include "pointInt2.h"

class graphEdges
{
private:
	int sizeX;
	int sizeY;
	pointInt2 start;
	std::vector< std::vector<int> > edges;
public:
	explicit graphEdges(int x, pointInt2 s = pointInt2(0,0));
	graphEdges(void);
	void changeWeight(int i, int j, int value);
	void cityWeights(void);
	void printWeights(void);
	void jarnikPrim(void);
	void kruskal(void);
};
