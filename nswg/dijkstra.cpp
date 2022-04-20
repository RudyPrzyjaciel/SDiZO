// modified code from https://www.programiz.com/dsa/dijkstra-algorithm

#include <iostream>
#include <vector>
#include <limits.h>
#include <fstream>
#include <cstring>
#include <time.h>

using namespace std;

void RunDijkstra(const int& sizeNodes);

int main() {
    const int nodesCount = 25; //number of nodes to read from file, max 1k!
    RunDijkstra(nodesCount);
    return 0;
}

class Node;
class Edge;

void Dijkstras();
vector<Node*>* AdjacentRemainingNodes(Node* node);
Node* ExtractSmallest(vector<Node*>& nodes);
int Distance(Node* node1, Node* node2);
bool Contains(vector<Node*>& nodes, Node* node);
void PrintShortestRouteTo(Node* destination);

vector<Node*> nodes;
vector<Edge*> edges;

class Node {
public:
    Node(int id)
        : id(id), previous(NULL), distanceFromStart(INT_MAX) {
        //nodes.push_back(this);
    }
    Node()
        : id(-1), previous(NULL), distanceFromStart(INT_MAX) {
        nodes.push_back(this);
    }

public:
    int id;
    Node* previous;
    int distanceFromStart;
};

class Edge {
public:
    Edge(Node* node1, Node* node2, int distance)
        : node1(node1), node2(node2), distance(distance) {
        edges.push_back(this);
    }
    Edge()
        : node1(NULL), node2(NULL), distance(INT_MAX) {
        edges.push_back(this);
    }
    bool Connects(Node* node1, Node* node2) {
        return (
            (node1 == this->node1 &&
                node2 == this->node2) ||
            (node1 == this->node2 &&
                node2 == this->node1));
    }

public:
    Node* node1;
    Node* node2;
    int distance;
};



void RunDijkstra(const int& sizeNodes) {
    const int edgeCount = (sizeNodes * sizeNodes - sizeNodes) / 2; //edges if all nodes are connected

    Node* testNodes = new Node[sizeNodes];
    for (int i = 0; i < sizeNodes; ++i)
    {
        testNodes[i] = Node(i);
    }
    Edge* testEdges = new Edge[edgeCount];

    // load graph edges from txt file
    std::vector<std::vector<int>>edges = std::vector<std::vector<int>>(sizeNodes, std::vector<int>(sizeNodes, 0));
    int i = 0;
    int j = 0;
    std::ifstream file;
    std::string line;
    std::string value;
    file.open("edges.txt");
    if (file.is_open())
    {
        while (getline(file, line))
        {
            if (!(j < sizeNodes)) break;
            i = 0;
            while (i < sizeNodes)
            {
                std::size_t index = line.find_first_of(",");
                value = line.substr(0, index);
                line.erase(0, index + 1);
                line.shrink_to_fit();
                edges[i][j] = stoi(value);
                i++;
            }
            j++;
        }
    }
    file.close();


    int n = 0;
    for (int i = 0; i < sizeNodes; ++i)
    {
        for (int j = i+1; j < sizeNodes; ++j)
        {
            testEdges[n] = Edge(&testNodes[i], &testNodes[j], edges[i][j]);
            ++n;
        }
    }

    testNodes[0].distanceFromStart = 0;

    clock_t startTime, endTime;
    double cpuTimeUsed;
    startTime = clock();

    Dijkstras();

    endTime = clock();
    cpuTimeUsed = ((double)(endTime - startTime)) / CLOCKS_PER_SEC;


    std::cout << "Finished Dijkstra's algorithm in " << cpuTimeUsed << std::endl;
    if (sizeNodes <= 25)
    {
        for (int i = 0; i < sizeNodes; ++i)
        {
            PrintShortestRouteTo(&testNodes[i]);
            std::cout << "-------------------------------------" << std::endl;
        }
        std::cout << "Finished Dijkstra's algorithm in " << cpuTimeUsed << std::endl;
    }
    delete[] testEdges;
    delete[] testNodes;
}


void Dijkstras() {
    std::cout << "DEBUG: nodes.size = " << nodes.size() << std::endl;
    while (nodes.size() > 0) {
        Node* smallest = ExtractSmallest(nodes);
        vector<Node*>* adjacentNodes =
            AdjacentRemainingNodes(smallest);

        const int size = adjacentNodes->size();
        for (int i = 0; i < size; ++i) {
            Node* adjacent = adjacentNodes->at(i);
            int distance = Distance(smallest, adjacent) +
                smallest->distanceFromStart;

            if (distance < adjacent->distanceFromStart) {
                adjacent->distanceFromStart = distance;
                adjacent->previous = smallest;
            }
        }
        delete adjacentNodes;
    }
}

// Find the node with the smallest distance,
// remove it, and return it.
Node* ExtractSmallest(vector<Node*>& nodes) {
    int size = nodes.size();
    if (size == 0) return NULL;
    int smallestPosition = 0;
    Node* smallest = nodes.at(0);
    for (int i = 1; i < size; ++i) {
        Node* current = nodes.at(i);
        if (current->distanceFromStart <
            smallest->distanceFromStart) {
            smallest = current;
            smallestPosition = i;
        }
    }
    nodes.erase(nodes.begin() + smallestPosition);
    return smallest;
}

// Return all nodes adjacent to 'node' which are still
// in the 'nodes' collection.
vector<Node*>* AdjacentRemainingNodes(Node* node) {
    vector<Node*>* adjacentNodes = new vector<Node*>();
    const int size = edges.size();
    for (int i = 0; i < size; ++i) {
        Edge* edge = edges.at(i);
        Node* adjacent = NULL;
        if (edge->node1 == node) {
            adjacent = edge->node2;
        }
        else if (edge->node2 == node) {
            adjacent = edge->node1;
        }
        if (adjacent && Contains(nodes, adjacent)) {
            adjacentNodes->push_back(adjacent);
        }
    }
    return adjacentNodes;
}

// Return distance between two connected nodes
int Distance(Node* node1, Node* node2) {
    const int size = edges.size();
    for (int i = 0; i < size; ++i) {
        Edge* edge = edges.at(i);
        if (edge->Connects(node1, node2)) {
            return edge->distance;
        }
    }
    return -1;  // should never happen
}

// Does the 'nodes' vector contain 'node'
bool Contains(vector<Node*>& nodes, Node* node) {
    const int size = nodes.size();
    for (int i = 0; i < size; ++i) {
        if (node == nodes.at(i)) {
            return true;
        }
    }
    return false;
}


void PrintShortestRouteTo(Node* destination) {
    Node* previous = destination;
    cout << "Distance from start to node " << previous->id << ": " 
        << destination->distanceFromStart << endl;
    while (previous) {
        cout << previous->id << " ";
        previous = previous->previous;
    }
    cout << endl;
}