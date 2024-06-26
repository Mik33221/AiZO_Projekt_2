#pragma once
#include <vector>
#include "Edge.h"

//Interfejs do reprezentacji grafow
class Graph
{
public:
	virtual int addEdge(int from, int to, int weight) = 0;
	virtual int checkEdge(int from, int to) = 0;
	virtual int printGraph() = 0;
	virtual int fillGraph() = 0;
	virtual int getVerticeCount() = 0;

	virtual std::vector<Edge> getEdges(int vertex) = 0;
};