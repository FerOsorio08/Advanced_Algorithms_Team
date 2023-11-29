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

#endif