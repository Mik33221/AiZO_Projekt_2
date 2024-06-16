#pragma once

// Structure to represent an edge in a graph
struct Edge {
    int vertex1;
    int vertex2;
    int weight;

    Edge(int vertex1, int vertex2, int weight) {
        this->vertex1 = vertex1;
        this->vertex2 = vertex2;
        this->weight = weight;
    }

    Edge() {
        this->vertex1 = 0;
        this->vertex2 = 0;
        this->weight = 0;
    }

    bool operator>(const Edge& other) const {
        return weight > other.weight;
    }

    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }

    int getVertex1() {
        return vertex1;
    }

    int getVertex2() {
        return vertex2;
    }

    int getWeight() {
		return weight;
	}
};