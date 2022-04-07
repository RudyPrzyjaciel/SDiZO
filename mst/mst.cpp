#include "dep/pointInt2.h"
#include "dep/graphEdges.h"


int main()
{
	int size = 50;
	pointInt2 p = pointInt2();
	graphEdges graph(size, p);
	graph.cityWeights(); 
	if (size <= 10)
	{
		graph.printWeights();
	}
	graph.jarnikPrim();
	graph.kruskal();
	return 0;
}