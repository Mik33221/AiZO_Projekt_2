#pragma once
#include "Graph.h"
//lista incydencji
class AdjList : public Graph
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
	int* verticeListSize;
	int maxEdge;
	int currentEdge;
	int maxVertice;
public:
	AdjList(int verticeCount, float fillPercent = 100, bool connected = true) {
		if (fillPercent > 100 || fillPercent < 0 || verticeCount < 0) {
			cout << "Blad w tworzeniu listy";
			return;
		}

		maxEdge = (verticeCount * (verticeCount - 1) / 2) * (fillPercent / 100);
		currentEdge = 0;
		maxVertice = verticeCount;

		if (maxEdge < verticeCount - 1) {
			cout << "Za mala ilosc krawedzi";
			return;
		}

		verticeList = new node * [verticeCount];
		verticeListSize = new int[verticeCount];
		for (int i = 0; i < verticeCount; i++) {
			verticeListSize[i] = 0;
		}

		//upewniamy sie, ze graf bedzie spojny
		if (connected)
			for (int i = 0; i < maxVertice - 1; i++) {
				int j = i + 1;
				int randomWeight = 1 + rand() % 99;
				addEdge(i, j, randomWeight);
			}

		//cout << "Stworzono liste sasiedztwa";
	}

	~AdjList() {
		for (int i = 0; i < maxVertice; i++) {
			if (verticeListSize[i] != 0)
				delete[] verticeList[i];
		}
		delete[] verticeList;
		//cout << "Usinieto liste sasiedztwa";
	}

	int addEdge(int from, int to, int weight) {
		if (from < 0 || from >= maxVertice || to < 0 || to >= maxVertice) {
			cout << "Invalid vertex index";
			return 1;
		}

		if (currentEdge >= maxEdge) {
			cout << "Lista pelna";
			return 1;
		}
		currentEdge++;

		// Create a new node
		node* newNode = new node;
		newNode->Vertice = to;
		newNode->Value = weight;

		// Add the new node to the 'from' vertex list
		if (verticeListSize[from] == 0) {
			verticeList[from] = new node[1];
			verticeList[from][0] = *newNode;
			verticeListSize[from]++;
		}
		else {
			int size = verticeListSize[from];
			verticeListSize[from]++;
			node* temp = new node[size + 1];
			for (int i = 0; i < size; i++) {
				temp[i] = verticeList[from][i];
			}
			temp[size] = *newNode;
			delete[] verticeList[from];
			verticeList[from] = temp;
		}

		node* newNode2 = new node;
		newNode->Vertice = from;
		newNode2->Value = weight;

		// Add the new node to the 'to' vertex list
		if (verticeListSize[to] == 0) {
			verticeList[to] = new node[1];
			verticeList[to][0] = *newNode;
			verticeListSize[to]++;
		}
		else {
			int size = verticeListSize[to];
			verticeListSize[to]++;
			node* temp = new node[size + 1];
			for (int i = 0; i < size; i++) {
				temp[i] = verticeList[to][i];
			}
			temp[size] = *newNode;
			delete[] verticeList[to];
			verticeList[to] = temp;
		}

		return 0;
	}

	int checkEdge(int from, int to) {
		

		if (from < 0 || from >= maxVertice || to < 0 || to >= maxVertice) {
			cout << "Invalid vertex index";
			return 1;
		}

		for (int i = 0; i < verticeListSize[from]; i++) {
			if (verticeList[from][i].Vertice == to) {
				return verticeList[from][i].Value;
			}
		}

		return 0;
	}

	int printGraph() {
		for (int i = 0; i < maxVertice; i++) {
			cout << "(" << i << ")";
			if (verticeListSize[i] != 0)
				for (int j = 0; j < verticeListSize[i]; j++) {
					cout << "[" << verticeList[i][j].Vertice << ":" << verticeList[i][j].Value << "]";
				}
			cout << endl;
		}
		return 0;
	}

	int fillGraph() {
		for (int i = 0; i < maxVertice - 2; i++) {
			for (int j = i + 2; j < maxVertice; j++) {
				int randomWeight = 1 + rand() % 99; // Generate a random number between 1 and 99
				if (addEdge(i, j, randomWeight))
					return 1;
			}
		}
		return 0;
	}

	int getVerticeCount() {
		return maxVertice;
	}

	std::vector<Edge> getEdges(int vertex) {
		std::vector<Edge> edges;
		return edges;
	}
};
