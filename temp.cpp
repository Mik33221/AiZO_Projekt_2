/*
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
*/

/*
	int delEdge(int from, int to) {
		if (from >= maxVertice || from < 0 || to >= maxVertice || to < 0) {
			cout << "Invalid vertices";
			return 1;
		}
		for (int i = 0; i < maxEdge; i++) {
			if (incidencyMatrix[from][i] != 0 && incidencyMatrix[to][i] != 0) {
				incidencyMatrix[from][i] = 0;
				incidencyMatrix[to][i] = 0;
				return 0;
			}
		}
		cout << "Edge not found";
		return 1;
	}
	*/

/*
	// Check for negative cycles
	for (int u = 0; u < numNodes; u++) {
		for (int v = 0; v < numNodes; v++) {
			if (u == v) {
				continue;
			}
			int edgeWeight = graph->checkEdge(u, v);
			if (edgeWeight != 0 && distances[u] != INT_MAX && distances[u] + edgeWeight < distances[v]) {
				std::cout << "Negative cycle detected. No shortest path exists.";
				delete[] distances;
				return;
			}
		}
	}
*/