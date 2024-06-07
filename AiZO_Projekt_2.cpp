#include <iostream>
#include <cstdlib> // dla funkcji malloc i free

struct Node {
    int vertex;
    int weight;
    Node* next;
};

struct HeadNode {
    Node* head;
};

class Graph {
private:
    int numVertices;
    HeadNode* headNodeList;

public:
    Graph(int vertices);
    ~Graph();
    void addEdge(int src, int dest, int weight);
    void printGraph();
};

Graph::Graph(int vertices) {
    numVertices = vertices;
    headNodeList = new HeadNode*[vertices * sizeof(HeadNode)];

    for (int i = 0; i < vertices; ++i) {
        headNodeList[i].head = nullptr;
    }
}

Graph::~Graph() {
    for (int i = 0; i < numVertices; ++i) {
        Node* temp = headNodeList[i].head;
        while (temp) {
            Node* next = temp->next;
            free(temp);
            temp = next;
        }
    }
    free(headNodeList);
}

void Graph::addEdge(int src, int dest, int weight) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = dest;
    newNode->weight = weight;
    newNode->next = headNodeList[src].head;
    headNodeList[src].head = newNode;

    // Jeśli graf jest nieskierowany, dodaj krawędź w drugą stronę
    // newNode = (Node*)malloc(sizeof(Node));
    // newNode->vertex = src;
    // newNode->weight = weight;
    // newNode->next = array[dest].head;
    // array[dest].head = newNode;
}

void Graph::printGraph() {
    for (int i = 0; i < numVertices; ++i) {
        Node* temp = headNodeList[i].head;
        std::cout << "Wierzchołek " << i << ":";
        while (temp) {
            std::cout << " -> (" << temp->vertex << ":" << temp->weight << ")";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
}

int main() {
    Graph graph(5);

    graph.addEdge(0, 1, 10);
    graph.addEdge(0, 4, 20);
    graph.addEdge(1, 2, 30);
    graph.addEdge(1, 3, 40);
    graph.addEdge(1, 4, 50);
    graph.addEdge(2, 3, 60);
    graph.addEdge(3, 4, 70);

    graph.printGraph();

    return 0;
}
