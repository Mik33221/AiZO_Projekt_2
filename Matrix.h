#pragma once
#include "Graph.h"
#include <cstdio>

//macierz incydencji
class Matrix : public Graph
{
private:
	int** incidencyMatrix;
	/*  K1 K2  K3  K4
	(0) [10,-1, 0,  8]
	(1) [-1, 0, 2,  0]
	(2) [0,  6, -1, -1]
	*/
public:
	Matrix() {
		cout << 
	}

	int addEdge() {

		return 1;
	}
};