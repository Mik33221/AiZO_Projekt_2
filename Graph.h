#pragma once
//Interfejs do reprezentacji grafow
class Graph 
{
public:
	virtual int addEdge() = 0;
	virtual int delEdge() = 0;
	virtual int checkEdge() = 0;
	virtual int printGraph() = 0;
};