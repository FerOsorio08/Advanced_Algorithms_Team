// Lucia Barrenechea, Ian Holender, Fernanda Osorio
// 29 de noviembre del 2023
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
int minKey(int key[], bool mstSet[],int V);
void printMST(int parent[], vector<vector<int> >& graph, int V);
void Prim(vector<vector<int> >& graph, int V);

//Definiciones de funciones

// Función para encontrar el vértice con la distancia mínima de los vértices que aún no se incluyen en el árbol de expansión mínima
//recibe el arreglo de distancias, el arreglo de booleanos que indica si el vértice ya está incluido en el árbol y el tamaño del grafo
//regresa el índice del vértice con la distancia mínima
//Complejidad: O(V)
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

// Función para imprimir el árbol de expansión mínima
//recibe el arreglo de padres, el grafo y el tamaño del grafo
//no regresa nada
//Complejidad: O(V)
void printMST(int parent[], vector<vector<int> >& graph, int V) {
    cout << "Forma óptima de cablear con fibra óptica:\n";
    for (int i = 1; i < V; i++) {
        cout << "Colonia " << parent[i] + 1 << " conectada con Colonia " << i + 1 << " - Distancia: " << graph[i][parent[i]] << " km\n";
    }
}

// Función para implementar el algoritmo de Prim para encontrar el árbol de expansión mínima
//recibe el grafo y el tamaño del grafo
//no regresa nada
//Complejidad: O(V^2), por la llamada a minKey()
void Prim(vector<vector<int> >& graph, int V) {
    // parent array to store constructed MST
    // the parent is used to print the MST 
    int parent[V];
    // key values used to pick minimum weight edge in cut
    int key[V];
    // to represent set of vertices not yet included in MST
    bool mstSet[V];

    for (int i = 0; i < V; i++) {
        // for all vertices, initialize key as infinite and mstSet as false
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet,V);

        mstSet[u] = true;

        for (int v = 0; v < V; v++) {
            // if edge graph[u][v] is smaller than key[v] and v is not yet in mstSet
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) {
                // update key value and parent index of vertex v
                parent[v] = u;
                // update minimmum distance
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph,V);
}

#endif