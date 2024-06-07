#pragma once
#include "Graph.h"
//lista incydencji
class AdjList : Graph
{
private:
	struct node {
		int Vertice;
		int Value;
	};

	node** verticeList; //lista trzymajaca w miejscu [0] przejscia z wierzcholka 0
	/*
	(0)[2:6]
	(1)[0:10]
	(2)[1:6, 0:8]
	*/
public:

};
