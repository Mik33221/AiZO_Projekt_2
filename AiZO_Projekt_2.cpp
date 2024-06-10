#include <iostream>
#include "Matrix.h"
#include "DiMatrix.h"
#include "AdjList.h"
#include "DiAdjList.h"

int main() {
	Matrix* m = new Matrix(8,50);
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
	AdjList* al = new AdjList(6);
	cout << endl;
	al->fillGraph();
	cout << endl;
	al->printGraph();
	cout << endl;
	DiAdjList* dal = new DiAdjList(6,80);
	cout << endl;
	dal->fillGraph();
	cout << endl;
	dal->printGraph();
	cout << endl;
	return 0;
}