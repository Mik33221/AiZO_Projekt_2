#pragma once
#include "Graph.h"

class DiMatrix : public Graph
{
private:
	int** incidencyMatrix;
	int maxEdge;
	int currentEdge;
	int maxVertice;
public:
	DiMatrix(int verticeCount, float fillPercent = 100, bool connected = true)
	{
		if (fillPercent > 100 || fillPercent < 0 || verticeCount < 0) {
			cout << "Blad w tworzeniu macierzy";
			return;
		}

		maxEdge = verticeCount * (verticeCount - 1) * (fillPercent / 100);
		currentEdge = 0;
		maxVertice = verticeCount;

		if (maxEdge < (verticeCount - 1) * 2) {
			cout << "Za mala ilosc krawedzi";
			return;
		}

		incidencyMatrix = new int* [verticeCount];

		for (int i = 0; i < verticeCount; i++) {
			incidencyMatrix[i] = new int[maxEdge];
			for (int j = 0; j < maxEdge; j++) {
				incidencyMatrix[i][j] = 0;
			}
		}

		//upewniamy sie, ze graf bedzie spojny
		if (connected)
			for (int i = 0; i < maxVertice - 1; i++) {
				int j = i + 1;
				int randomWeight = 1 + rand() % 99;
				addEdge(i, j, randomWeight);
				randomWeight = 1 + rand() % 99;
				addEdge(j, i, randomWeight);
			}

		//cout << "Stworzono skierowana macierz incydencji";
	}

	~DiMatrix()
	{
		for (int i = 0; i < maxVertice; i++) {
			delete[] incidencyMatrix[i];
		}
		delete[] incidencyMatrix;
		//cout << "Usunieto skierowana macierz incydencji";
	}

	int addEdge(int from, int to, int weight)
	{
		if (from > maxVertice || from < 0 || to > maxVertice || to < 0) {
			cout << "Blad w dodawaniu krawedzi";
			return 1;
		}
		if (currentEdge >= maxEdge) {
			cout << "Brak miejsca na dodanie krawedzi";
			return 1;
		}
		incidencyMatrix[from][currentEdge] = -1;
		incidencyMatrix[to][currentEdge] = weight;
		currentEdge++;
		return 0;
	}

	int checkEdge(int from, int to) {
		
		if (from >= maxVertice || from < 0 || to >= maxVertice || to < 0) {
			cout << "Invalid vertices";
			return 0;
		}
		for (int i = 0; i < maxEdge; i++) {
			if (incidencyMatrix[from][i] == -1 && incidencyMatrix[to][i] != 0) {
				return incidencyMatrix[to][i];
			}
		}
		return 0;
	}

	int printGraph() {
		int maxDigits = 0;
		for (int i = 0; i < maxVertice; i++) {
			for (int j = 0; j < maxEdge; j++) {
				int num = incidencyMatrix[i][j];
				int digits = 0;
				if (num == 0) {
					digits = 1;
				}
				else {
					int tempNum = abs(num); // Fix: Use absolute value to handle negative numbers
					while (tempNum != 0) {
						tempNum /= 10;
						digits++;
					}
				}
				if (num < 0) { // Add an extra space for negative numbers
					digits++;
				}
				if (digits > maxDigits) {
					maxDigits = digits;
				}
			}
		}

		for (int i = 0; i < maxVertice; i++) {
			for (int j = 0; j < maxEdge; j++) {
				int num = incidencyMatrix[i][j];
				int digits = 0;
				if (num == 0) {
					digits = 1;
				}
				else {
					int tempNum = abs(num); // Fix: Use absolute value to handle negative numbers
					while (tempNum != 0) {
						tempNum /= 10;
						digits++;
					}
				}
				if (num < 0) { // Add an extra space for negative numbers
					digits++;
				}
				int spaces = maxDigits - digits;
				for (int k = 0; k < spaces; k++) {
					cout << " ";
				}
				cout << incidencyMatrix[i][j] << " ";
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
				randomWeight = 1 + rand() % 99; // Generate a random number between 1 and 99
				if (addEdge(j, i, randomWeight))
					return 1;
			}
		}
		return 0;
	}

	int getVerticeCount() {
		return maxVertice;
	}

	vector <Edge> getEdges(int vertex) {
		vector <Edge> edges;
		for (int i = 0; i < maxEdge; i++) {
			if (incidencyMatrix[vertex][i] == -1) {
				for (int j = 0; j < maxVertice; j++) {
					if (j == vertex) {
						continue;
					}
					if (incidencyMatrix[j][i] > 0) {
						Edge edge(vertex, j, incidencyMatrix[j][i]);
						edges.push_back(edge);
						break;
					}
				}
			}
		}
		return edges;
	}

};