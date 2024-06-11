#pragma once
#include <iostream>
#include <vector>
#include <limits.h>

// Structure to represent a node in the graph
struct node {
    int Vertice;
    int Value;
};

// Class to represent a priority queue using a heap
class PriorityQueue {
private:
    std::vector<node> heap;

    // Helper function to maintain the heap property
    void heapifyUp(int index) {
        int parent = (index - 1) / 2;
        while (index > 0 && heap[index].Value < heap[parent].Value) {
            std::swap(heap[index], heap[parent]);
            index = parent;
            parent = (index - 1) / 2;
        }
    }

    // Helper function to maintain the heap property
    void heapifyDown(int index) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int smallest = index;

        if (leftChild < heap.size() && heap[leftChild].Value < heap[smallest].Value) {
            smallest = leftChild;
        }

        if (rightChild < heap.size() && heap[rightChild].Value < heap[smallest].Value) {
            smallest = rightChild;
        }

        if (smallest != index) {
            std::swap(heap[index], heap[smallest]);
            heapifyDown(smallest);
        }
    }

public:
    // Function to check if the priority queue is empty
    bool isEmpty() {
        return heap.empty();
    }

    // Function to insert a node into the priority queue
    void push(node newNode) {
        heap.push_back(newNode);
        heapifyUp(heap.size() - 1);
    }

    // Function to remove and return the node with the minimum value
    node pop() {
        if (isEmpty()) {
            std::cout << "Priority queue is empty";
        }

        node minNode = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);

        return minNode;
    }
};