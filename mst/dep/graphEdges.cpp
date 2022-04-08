#include "graphEdges.h"

graphEdges::graphEdges(int x, pointInt2 s) : sizeX(x), sizeY(x), start(s)
{
	edges = std::vector< std::vector<int> >(sizeX, std::vector<int>(sizeY, 0));
}

graphEdges::graphEdges(void) : sizeX(0), sizeY(0), start(pointInt2(0, 0))
{
	edges = std::vector< std::vector<int> >(sizeX, std::vector<int>(sizeY, 0));
}

void graphEdges::cityWeights(void)
{
	srand(time(NULL));
	for (int i = 0; i < sizeX; i++)
	{
		for (int j = 0; j < sizeY; j++)
		{
			//set upper triangle in matrix
			if (i < j)
			{
				edges[i][j] = rand() % 25 + (j - i);
				// edges[i][j] = (j - i);
				edges[j][i] = edges[i][j];
			}
		}
	}
}

void graphEdges::changeWeight(int i, int j, int value = 0)
{
	std::cout << "Nothing here yet, its on my TODO list" << std::endl;
}

void graphEdges::printWeights(void)
{
	for (int i = 0; i < sizeX; i++)
	{
		for (int j = 0; j < sizeY; j++)
		{
			std::cout << edges[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void graphEdges::jarnikPrim(void)
{
	std::cout << "starting Jarnik-Prim MST algorithm" << std::endl;

	clock_t startTime, endTime;
	double cpuTimeUsed;
	startTime = clock();

	int no_edge = 0;
	bool selected[this->sizeX];
	memset(selected, false, sizeof(selected));

	selected[0] = true;
	int x;
	int y;
	if (sizeX <= 10)
	{
		std::cout << "Edge" << " : " << "Weight" << std::endl;
	}
	while (no_edge < this->sizeX - 1)
	{
		int min = INT_MAX;
		x = 0;
		y = 0;
		for (int i = 0; i < this->sizeX; i++)
		{
			if (selected[i])
			{
				for (int j = 0; j < this->sizeX; j++)
				{
					if (!selected[j] && this->edges[i][j])
					{
						if (min > this->edges[i][j])
						{
							min = this->edges[i][j];
							x = i;
							y = j;
						}
					}
				}
			}
		}
		if (sizeX <= 10)
		{
			std::cout << x << " to " << y << " : " << this->edges[x][y] << std::endl;
		}
		selected[y] = true;
		no_edge++;
	}
	endTime = clock();
	cpuTimeUsed = ((double)(endTime - startTime)) / CLOCKS_PER_SEC;
	std::cout << "Finished Jarnik-Prim MST algorithm in " << cpuTimeUsed << std::endl;
}

void graphEdges::kruskal(void)
{
	std::cout << "(NOT)starting Kruskal MST algorithm" << std::endl;

	clock_t startTime, endTime;
	double cpuTimeUsed;

	startTime = clock();
	endTime = clock();
	cpuTimeUsed = ((double)(endTime - startTime)) / CLOCKS_PER_SEC;
	std::cout << "(NOT)Finished Jarnik-Prim MST algorithm in " << cpuTimeUsed << std::endl;
}


void graphEdges::saveEdges(void)
{
	std::ofstream file;
	file.open("edges.txt");
	for (int i = 0; i < sizeX; i++)
	{
		for (int j = 0; j < sizeY - 1; j++)
		{
			file << edges[i][j] << ",";
		}
		file << edges[i][sizeY-1];
		if(i != sizeX-1)
		{
			file << ",\n";
		}
	}
	file.close();
}

void graphEdges::loadEdges(void)
{
	int i = 0;
	int j = 0;
	std::ifstream file;
	std::string line;
	std::string value;
	file.open("edges.txt");
	if(file.is_open())
	{
		while(getline(file, line))
		{
			if (!(j < sizeX)) break;
			i = 0;
			while(i < sizeX)
			{
				std::size_t index = line.find_first_of(",");
				value = line.substr(0, index);
				line.erase(0, index+1);
				line.shrink_to_fit();
				edges[i][j] = stoi(value);
				i++;
			}
			j++;
		}
	}
	file.close();
}