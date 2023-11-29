// Lucia Barrenechea, Ian Holender, Fernanda Osorio
// 28 de noviembre del 2023
//Este header contiene las funciones necesarias para recibir los datos
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#ifndef read_H
#define read_H

using namespace std;

class Edge {
public:
    // Nodos que conecta la arista
    int start, end, weight;

    // Constructor para inicializar los miembros de la clase
    Edge(int s, int e, int w) : start(s), end(e), weight(w) {}
};

// class Edge {
// public:
//     int destination;  // End node of the edge
//     int weight;       // Weight (distance) of the edge

//     Edge(int dest, int w) : destination(dest), weight(w) {}
// };

//Declaraciones de funciones 
vector<vector<int> > readGraphFromFile(const string& filename) {
    ifstream file(filename);
    int n; // Tamaño de la matriz
    vector<vector<int> > graph;

    if (file.is_open()) {
        file >> n;
        graph.resize(n, vector<int>(n, 0));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                file >> graph[i][j];
            }
        }
        file.close();
    } else {
        cerr << "Error al abrir el archivo: " << filename << endl;
        exit(1);
    }

    return graph;
}

void printMatrix(const vector<vector<int> >& matrix) {
    int n = matrix.size();
    cout << "Matriz de adyacencia:" << endl;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << "  ";
        }
        cout << endl;
    }
}

//make vector<vector<int>> graph into vector<Edge> edges
vector<Edge> makeEdges(const vector<vector<int> >& graph) {
    int n = graph.size();
    vector<Edge> edges;

    //for each vertex
    for (int i = 0; i < n; ++i) {
        int start = graph[i][0]; //which vertex is this
        // cout << "Vertex START :"<< start << ": ";
        //which edges are connected to this vertex
        for (int j = 0; j < n; ++j) {
            int end = graph[j][0]; //which vertex is this
            edges.emplace_back(start, end, graph[i][j]);
            cout << "edge: " << start << " -> " << end << " : " << graph[i][j] << endl;
            
        }
    }

    return edges;
}


vector<Edge> readGraphFromFileEdge(const string& filename) {
    ifstream file(filename);
    int n; // Tamaño de la matriz
    vector<Edge> edges;

    if (file.is_open()) {
        file >> n;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int weight;
                file >> weight;
                if (weight > 0) {
                    edges.push_back(Edge(i, j, weight));
                }
            }
        }
        file.close();
    } else {
        cerr << "Error al abrir el archivo: " << filename << endl;
        exit(1);
    }

    return edges;
}

// vector<vector<Edge> > readGraphFromFile(const string& filename) {
//     ifstream file(filename);
//     int n; // Size of the matrix
//     vector<vector<Edge> > graph;

//     if (file.is_open()) {
//         file >> n;
//         graph.resize(n);

//         for (int i = 0; i < n; ++i) {
//             for (int j = 0; j < n; ++j) {
//                 int weight;
//                 file >> weight;
//                 if (weight > 0) {
//                     graph[i].emplace_back(j, weight);
//                 }
//             }
//         }
//         file.close();
//     } else {
//         cerr << "Error al abrir el archivo: " << filename << endl;
//         exit(1);
//     }

//     return graph;
// }

void printEdges(const vector<Edge>& edges) {
    cout << "Aristas:" << endl;
    
    for (const Edge& edge : edges) {
        cout << edge.start << " -> " << edge.end << " : " << edge.weight << endl;
    }
}

// void printGraph(const vector<vector<Edge> >& graph) {
//     int n = graph.size();
//     cout << "Matriz de adyacencia:" << endl;

//     for (const vector<Edge>& edges : graph) {
//         //which edges are connected to this vertex
//         cout << "Vertex "<< edges[0].destination << ": ";
//         for (const Edge& edge : edges) {
//             cout << edge.destination << "  ";
//             cout << edge.weight << "  ";
//         }
//         cout << endl;
//     }
// }


#endif
