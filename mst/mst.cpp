#include "dep/pointInt2.h"
#include "dep/graphEdges.h"


int main()
{
	pointInt2 p = pointInt2();
	graphEdges test(10, p);
	test.cityWeights();
	test.printWeights();
	test.jarnikPrim();
	return 0;
}