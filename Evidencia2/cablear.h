// Lucia Barrenechea, Ian Holender, Fernanda Osorio
// 28 de noviembre del 2023
//Este header contiene las funciones necesarias para calcular 
//la forma óptima de cablear con fibra óptica conectando colonias
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <limits>
#ifndef Floyd_H
#define Floyd_H
#include "read.h"

using namespace std;


//Declaraciones de funciones
vector<vector<int> > FloydWarshall(const vector<vector<int> >& matrizAdyacente);

//Funciones para Floyd-Warshall
//recibe la matriz de adyacencia
//regresa la matriz de adyacencia con los caminos mas cortos
//Complejidad = O(V^3), donde V es el numero de vertices
vector<vector<int> > FloydWarshall(const vector<vector<int> >& matrizAdyacente) {
    int n = matrizAdyacente.size();
    vector<vector<int> > A = matrizAdyacente;

    // Inicializar la matriz con valor de infinito
    //numeric_limits<int>::max() es el valor maximo que puede tener un int
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (A[i][j] == -1) {
                A[i][j] = numeric_limits<int>::max();
            }
        }
    }
    // Floyd-Warshall algorithm
    //para cada nodo k en el grafo se checa si el camino de i a j es mas corto pasando por k 
    //y si es asi se actualiza el valor de la matriz
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                //si el camino de i a k y de k a j es menor que el camino de i a j
                if (A[i][k] != numeric_limits<int>::max() && A[k][j] != numeric_limits<int>::max()) {
                    if (A[i][k] + A[k][j] < A[i][j]) {
                        A[i][j] = A[i][k] + A[k][j];
                    }
                }
            }
        }
    }

    return A;
}

//Floyd-Warshall algorithm using vector of edges
vector< vector < int > > FloydWarshallEdges(const vector<Edge>& Edges ){
    int n = Edges.size();
    vector<vector<int> > A;
    A.resize(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        A[Edges[i].start][Edges[i].end] = Edges[i].weight;
    }
    // Floyd-Warshall algorithm
    //para cada nodo k en el grafo se checa si el camino de i a j es mas corto pasando por k 
    //y si es asi se actualiza el valor de la matriz
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j) {
                //si el camino de i a k y de k a j es menor que el camino de i a j
                if (A[i][k] != numeric_limits<int>::max() && A[k][j] != numeric_limits<int>::max()) {
                    if (A[i][k] + A[k][j] < A[i][j]) {
                        A[i][j] = A[i][k] + A[k][j];
                    }
                }
            }
        }
    }
    return A;
}


int minKey(int key[], bool mstSet[],int V) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (mstSet[v] == false && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }

    return min_index;
}

void printMST(int parent[], vector<vector<int> >& graph, int V) {
    cout << "Forma óptima de cablear con fibra óptica:\n";
    for (int i = 1; i < V; i++) {
        cout << "Colonia " << parent[i] + 1 << " conectada con Colonia " << i + 1 << " - Distancia: " << graph[i][parent[i]] << " km\n";
    }
}

void Prim(vector<vector<int> >& graph, int V) {
    int parent[V];
    int key[V];
    bool mstSet[V];

    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet,V);

        mstSet[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph,V);
}

#endif