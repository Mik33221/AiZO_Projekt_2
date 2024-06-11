#include <iostream>
#include "Matrix.h"
#include "DiMatrix.h"
#include "AdjList.h"
#include "DiAdjList.h"

#include "Dijkstry.h"
#include "Prim.h"
#include "Kruskal.h"
#include "Forda-Bellmana.h"

#include <cassert>

//2000 wierzcholkow to taki max
int main() {
	srand(time(NULL));
	
	/*
	Matrix* m = new Matrix(6, 50);
	cout << endl;
	m->fillGraph();
	cout << endl;
	m->printGraph();
	DiMatrix* dm = new DiMatrix(6,40);
	cout << endl;
	dm->fillGraph();
	cout << endl;
	dm->printGraph();
	cout << endl;
	AdjList* al = new AdjList(30);
	cout << endl;
	al->fillGraph();
	cout << endl;
	al->printGraph();
	cout << endl;
	DiAdjList* dal = new DiAdjList(6);
	cout << endl;
	dal->fillGraph();
	cout << endl;
	dal->printGraph();
	cout << endl;
	*/
	
	DiAdjList* m = new DiAdjList(100);
	cout << endl;
	m->fillGraph();
	cout << endl;
	//m->printGraph();
	cout << endl;
	ShortestPathFordBellman(m,1,2);
	delete m;
	
	return 0;
}
