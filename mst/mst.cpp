#include "dep/pointInt2.h"
#include "dep/graphEdges.h"


int main()
{
	int size = 1000;
	// int size = 10;
	pointInt2 p = pointInt2();
	graphEdges graph(size, p);
	graph.loadEdges();
	// graph.cityWeights(); 
	// if (size <= 10)
	// {
	// graph.printWeights();
	// }
	// graph.saveEdges();
	graph.jarnikPrim();
	// graph.kruskal();
	return 0;
}