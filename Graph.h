#pragma once
//Interfejs do reprezentacji grafow
class Graph
{
public:
	virtual int addEdge(int from, int to, int weight) = 0;
	virtual int checkEdge(int from, int to) = 0;
	virtual int printGraph() = 0;
	virtual int fillGraph() = 0;
};