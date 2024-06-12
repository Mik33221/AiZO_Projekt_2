#include <iostream>
#include <fstream>
#include <string>

#include "Graph.h"
#include "Matrix.h"
#include "DiMatrix.h"
#include "AdjList.h"
#include "DiAdjList.h"

#include "Dijkstra.h"
#include "Prim.h"
#include "Kruskal.h"
#include "Ford-Bellman.h"

void mst() {
    int choice;
    bool isGraph = false;
    Matrix* matrix = new Matrix(5);
    AdjList* list = new AdjList(5);
    std::string fileName;
    std::ifstream* infile;
    do {
        std::cout << "Menu:\n";
        std::cout << "1. Wczytaj dane z pliku\n";
        std::cout << "2. Wygeneruj graf losowo\n";
        std::cout << "3. Wyswietl graf listowo i macierzowo na ekranie\n";
        std::cout << "4. Algorytm Prima listowo i macierzowo z wyswietleniem wynikow\n";
        std::cout << "5. Algorytm Kruskala listowo i macierzowo z wyswietleniem wynikow\n";
        std::cout << "0. Cofnij\n";
        std::cout << "Wybierz opcje: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            delete matrix;
            delete list;
            // Read data from file
            ;
            std::cout << "Podaj nazwe pliku: ";
            std::cin >> fileName;
            fileName += ".txt";

            infile = new std::ifstream(fileName);
            if (!*infile) {
                std::cerr << "Unable to open file " << fileName << std::endl;
                return;
            }

            int numberOfEdges, numberOfVertices;
            *infile >> numberOfEdges >> numberOfVertices;
            matrix = new Matrix(numberOfEdges, 100, false);
            list = new AdjList(numberOfEdges, 100, false);

            int start, end, weight;
            while (*infile >> start >> end >> weight) {
                matrix->addEdge(start, end, weight);
                list->addEdge(start, end, weight);
            }

            infile->close();
            // End
            isGraph = true;
            break;
        case 2:
            delete matrix;
            delete list;
            int vertices;
            int fillPercent;
            std::cout << "Podaj liczbe wierzcholkow: ";
            std::cin >> vertices;
            std::cout << "Podaj stopien wypelienia (max 100): ";
            std::cin >> fillPercent;
            matrix = new Matrix(vertices, fillPercent);
            matrix->fillGraph();
            list = new AdjList(vertices, fillPercent, false);
            // Copy list from matrix
            for (int i = 0; i < vertices; i++) {
				for (int j = i + 1; j < vertices; j++) {
                    if (i == j) {
						continue;
					}   
                    int weight = matrix->checkEdge(i,j);
					if (weight != 0) {
						list->addEdge(i, j, weight);
					}
				}
			}
            isGraph = true;
            break;
        case 3:
            if (isGraph) {
                list->printGraph();
                matrix->printGraph();
            }
            else {
                std::cout << "Najpierw wczytaj dane lub wygeneruj graf\n";
            }
            break;
        case 4:
            if (isGraph) {
                MSTPrim(list);
                cout << endl;
                MSTPrim(matrix);
                cout << endl;
            }
            else {
                std::cout << "Najpierw wczytaj dane lub wygeneruj graf\n";
            }
            break;
        case 5:
            if (isGraph) {
                MSTKruskal(list);
                cout << endl;
                MSTPrim(matrix);
                cout << endl;
            }
            else {
                std::cout << "Najpierw wczytaj dane lub wygeneruj graf\n";
            }
            break;
        case 0:
            std::cout << "Wyjscie z programu\n";
            break;
        default:
            std::cout << "Nieprawidlowa opcja\n";
            break;
        }
    } while (choice != 0);
    if (isGraph) {
        delete matrix;
        delete list;
    }
}

void shortestPath() {
    int choice;
    bool isGraph = false;
    DiMatrix* matrix = new DiMatrix(5);
    DiAdjList* list = new DiAdjList(5);
    std::string fileName;
    std::ifstream* infile;
    do {
        std::cout << "Menu:\n";
        std::cout << "1. Wczytaj dane z pliku\n";
        std::cout << "2. Wygeneruj graf losowo\n";
        std::cout << "3. Wyswietl graf listowo i macierzowo na ekranie\n";
        std::cout << "4. Algorytm Dijkstry listowo i macierzowo z wyswietleniem wynikow\n";
        std::cout << "5. Algorytm Forda-Bellmana listowo i macierzowo z wyswietleniem wynikow\n";
        std::cout << "0. Cofnij\n";
        std::cout << "Wybierz opcje: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            // Read data from file
            ;
            std::cout << "Podaj nazwe pliku: ";
            std::cin >> fileName;
            fileName += ".txt";

            infile = new std::ifstream(fileName);
            if (!*infile) {
                std::cerr << "Unable to open file " << fileName << std::endl;
                return;
            }

            int numberOfEdges, numberOfVertices;
            *infile >> numberOfEdges >> numberOfVertices;
            matrix = new DiMatrix(numberOfEdges, 100, false);
            list = new DiAdjList(numberOfEdges, 100, false);

            int start, end, weight;
            while (*infile >> start >> end >> weight) {
                matrix->addEdge(start, end, weight);
                list->addEdge(start, end, weight);
            }

            infile->close();
            // End
            isGraph = true;
            break;
        case 2:
            delete matrix;
            delete list;
            int vertices;
            int fillPercent;
            std::cout << "Podaj liczbe wierzcholkow: ";
            std::cin >> vertices;
            std::cout << "Podaj stopien wypelienia (max 100): ";
            std::cin >> fillPercent;
            matrix = new DiMatrix(vertices, fillPercent);
            matrix->fillGraph();
            list = new DiAdjList(vertices, fillPercent, false);
            // Copy list from matrix
            for (int i = 0; i < vertices; i++) {
                for (int j = i + 1; j < vertices; j++) {
                    if (i == j) {
                        continue;
                    }
                    int weight = matrix->checkEdge(i, j);
                    if (weight != 0) {
                        list->addEdge(i, j, weight);
                    }
                    weight = matrix->checkEdge(j, i);
                    if (weight != 0) {
                        list->addEdge(j, i, weight);
                    }
                }
            }
            isGraph = true;
            break;
        case 3:
            if (isGraph) {
                list->printGraph();
                matrix->printGraph();
			}
			else {
				std::cout << "Najpierw wczytaj dane lub wygeneruj graf\n";
			}
            break;
        case 4:
            if (isGraph) {
                int startVertex, endVertex;
                std::cout << "Podaj wierzcholek poczatkowy: ";
                std::cin >> startVertex;
                std::cout << "Podaj wierzcholek koncowy: ";
                std::cin >> endVertex;
                ShortestPathDijkstra(list, startVertex, endVertex);
                std::cout << std::endl;
                ShortestPathDijkstra(matrix, startVertex, endVertex);
            }
			else {
				std::cout << "Najpierw wczytaj dane lub wygeneruj graf\n";
			}
            break;
        case 5:
            if (isGraph) {
                int startVertex, endVertex;
                std::cout << "Podaj wierzcholek poczatkowy: ";
                std::cin >> startVertex;
                std::cout << "Podaj wierzcholek koncowy: ";
                std::cin >> endVertex;
                ShortestPathFordBellman(list, startVertex, endVertex);
                std::cout << std::endl;
                ShortestPathFordBellman(matrix, startVertex, endVertex);
                }
            else {
                std::cout << "Najpierw wczytaj dane lub wygeneruj graf\n";
			}
            break;
        case 0:
            std::cout << "Wyjscie z programu\n";
            break;
        default:
            std::cout << "Nieprawidlowa opcja\n";
            break;
        }
    } while (choice != 0);
    if (isGraph) {
        delete matrix;
        delete list;
    }
}

void run() {
    int choice;
    do {
        std::cout << "Ktory problem chcesz rozwiazac?:\n";
        std::cout << "1. MST - minimalne drzewo spinajace\n";
        std::cout << "2. Najktorszej sciezki w grafie\n";
        std::cout << "0. Wyjscie\n";
        std::cout << "Wybierz opcje: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            mst();
            break;
        case 2:
            shortestPath();
            break;
        case 0:
            std::cout << "Wyjscie z programu\n";
            break;
        default:
            std::cout << "Nieprawidlowa opcja\n";
            break;
        }
    } while (choice != 0);
    return;
}