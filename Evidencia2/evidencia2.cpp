// Lucia Barrenechea, Ian Holender, Fernanda Osorio
// 28 de noviembre del 2023
// Archivo main para solución en CPP
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "cablear.h"
#include "read.h"

using namespace std;

int main(int argc, char *argv[]){

    vector<vector<int> > graph = readGraphFromFile("matriz.txt");
    vector<Edge> edges = readGraphFromFileEdge("matriz.txt");
    vector<Edge> edges2 = makeEdges(graph);
    // vector<vector<Edge> >  nodes = readGraphFromFile("matriz.txt");
    cout << endl;
    cout << "EDGES:" << endl;
    // printGraph(nodes);
    // printEdges(edges2);
    printMatrix(graph);
    cout << endl;
    cout << "Shortest paths:" << endl;
    // vector<vector<int> > shortestPaths = FloydWarshallEdges(edges2);
    // printMatrix(shortestPaths);

    // printMatrix(graph);
    // Floyd-Warshall algorithm
    vector<vector<int> > shortestPaths = FloydWarshall(graph);
    cout << "Matriz de caminos mas cortos:" << endl;
    printMatrix(shortestPaths);

}