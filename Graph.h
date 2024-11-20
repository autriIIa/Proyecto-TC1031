
#pragma once
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "LinkedList.h"

template <typename T>
class Vertex {
   public:
    LinkedList<int> edges;
    T data;
};

template <typename T>
class Graph {
   private:
    int numberVertex;
    Vertex<T> *vertexes;

    bool checkVertex(int vertex) {
        return vertex >= numberVertex || vertex < 0;
    }

   public:
    Graph() {
        vertexes = nullptr;
        numberVertex = 0;
    }
    ~Graph() {
        deleteGraph();
    }
    unsigned int getSize() {
        return numberVertex;
    }

    void print() {
        if (!isEmpty()) {
            for (int i = 0; i < numberVertex; i++) {
                std::cout << "[" << i << "] " << vertexes[i].data << ": ";
                vertexes[i].edges.imprimirLista();
            }
        }
    }

    bool insertData(unsigned int vertex, T data) {
        if (isEmpty() || checkVertex(vertex))
            return false;
        vertexes[vertex].data = data;
        return true;
    }

    bool createGraph(int size) {
        if (!checkVertex(size))
            return false;

        vertexes = new (std::nothrow) Vertex<T>[size];

        if (!vertexes) {
            vertexes = nullptr;
            size = 0;
            return false;
        }

        numberVertex = size;
        return true;
    }

    bool insertEdge(int vertex, int nEdge) {
        if (checkVertex(vertex))
            return false;

        if (vertexes[vertex].edges.findData(nEdge))
            return false;

        return vertexes[vertex].edges.insertarInicio(nEdge);
    }

    bool removeEdge(int vertex, int rEdge) {
        if (isEmpty())
            return false;
        if (checkVertex(vertex))
            return false;

        return vertexes[vertex].eliminaDato(rEdge);
    }

    bool deleteGraph() {
        if (isEmpty())
            return false;
        delete[] vertexes;
        vertexes = nullptr;
        numberVertex = 0;
        return true;
    }

    bool isEmpty() {
        return vertexes == nullptr;
    }

    bool loadFile(const std::string &fileName) {
        std::ifstream file;
        file.open(fileName, std::ifstream::in);
        if (!file.is_open())
            return false;

        std::string line, word;
        std::getline(file, line);

        if (line != "Grafo")
            return false;

        if (!std::getline(file, line))
            return false;

        int numberVertex = std::stoi(line);

        if (numberVertex <= 0)
            return false;

        if (!createGraph(numberVertex))
            return false;

        int count = 0, edge;
        while (std::getline(file, line)) {
            std::stringstream words(line);
            while (std::getline(words, word, ' ')) {
                edge = std::stoi(word);
                if (!insertEdge(count, edge)) {
                    return false;
                }
            }
            count++;
        }
        file.close();
        return true;
    }
};
