// Lucia Barrenechea, Ian Holender, Fernanda Osorio
// 28 de noviembre del 2023
//Este header contiene las funciones necesarias para encontrar solución
//al problema del travelling salesman
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <limits>
#include <cstring>
#ifndef tsp_H
#define tsp_H
#include "read.h"

using namespace std;


const int INF = INT_MAX;

//Esta función tiene Big O de O(n) ya que depende del tamaño del grafo que se esta analizando
//calcula el peso del nodo mas corto
int primerMin(const vector<vector<int> >& graph, int i) {
    int minCosto = INF;//guarda el costo minimo de la conexión entre i y los demas vertices
    for (int j = 0; j < graph.size(); j++) {
        if (i != j && graph[i][j] < minCosto) {//Si es mas chico que el actual se cambia.
            minCosto = graph[i][j];
        }
    }
    //cout<<"THe min cost is: "<<minCosto<<endl;
    return minCosto;
}

//Esta función tiene Big O de O(n) ya que depende del tamaño del grafo que se esta analizando
//Calcula el peso del segundo nodo más corto.
int segundoMin(const vector<vector<int> >& graph, int i) {
    int primerMinValue = INF, segundoMinValue = INF;
    for (int j = 0; j < graph.size(); j++) {
        if (i != j) {
            if (graph[i][j] <= primerMinValue) {//si es mas chico se intercambian
                segundoMinValue = primerMinValue;
                primerMinValue = graph[i][j];
            } else if (graph[i][j] <= segundoMinValue) {
                segundoMinValue = graph[i][j];
            }
        }
    }
    return segundoMinValue;
}

//Esta función tiene complejidad algoritmica de O(n^2) ya que dentro del for loop se llama la función de forma recursiva.
//busca encontrar el camino más corto que visite cada vértice una vez y regrese al vértice inicial. Usa branch and bound y recursión
void tspBranchBound(const vector<vector<int> >& graph, vector<int>& camino, vector<bool>& visited, int& currWeight, int& finalWeight, int currPos, int n, int count) {
    if (count == n) {//Indica cuando todos los vertices ya fueron visitados.
        // Complete the tour by returning to the initial node
        if (graph[currPos][0] != 0) {//Si si existe una conexión entre esos nodos
            int currCosto = currWeight + graph[currPos][0];//Suma el costo total + la nueva ultima conexión
            if (currCosto < finalWeight) {//Si el costo supera de bueno al pasad...
                finalWeight = currCosto; //Se aplica
                //cout<<"final weight"<<finalWeight<<endl;
                camino[count - 1] = 0;  // Set the last element of the camino to 0 //El nuevo camino es el actual
            }
        }
        return;
    }

    // Branch and Bound17
    for (int i = 0; i < n; i++) {
        if (!visited[i] && graph[currPos][i] != 0) {
            int temp = currWeight;
            int bound = currWeight - primerMin(graph, currPos) + graph[currPos][i] + segundoMin(graph, i);
            // from which node to which node and weight
            cout << "from " << currPos << " to " << i << " weight " << graph[currPos][i] << endl;

            // Pruning condition
            if (bound < finalWeight) {
                currWeight += graph[currPos][i];
                if (currWeight < finalWeight) {
                    camino[count] = i;
                    visited[i] = true;
                    tspBranchBound(graph, camino, visited, currWeight, finalWeight, i, n, count + 1);
                    visited[i] = false;  // Backtrack
                }

                // Backtrack
                currWeight = temp;
            }
        }
    }
}

//Tiene una complejidad de O(n^2) ya que llama a la función tspBranchBound que tiene complejidad de O(n^))
//Inicializa valores y llama a la función que lleva a acbo el branch and bound.
void tspBB(const vector<vector<int> >& graph) {
    int n = graph.size();
    vector<int> camino(n, -1);
    vector<bool> visited(n, false);

    // Initialize camino
    camino[0] = 0;
    visited[0] = true;

    int currWeight = 0;  // Weight of the current camino
    int finalWeight = INF;  // Initialize the final weight to a large value

    tspBranchBound(graph, camino, visited, currWeight, finalWeight, 0, n, 1);
    // list of letters to represent the camino
    vector<char> letters;
    for (int i = 0; i < n; i++) {
        letters.push_back('A' + i);
    }
    cout << "Minimum Cost: " << finalWeight << endl;
    cout << "camino Taken: ";
    for (int i : camino) {
        // represent the camino with letters
        cout << letters[i] << " ";
        // cout << i << " ";
    }
    cout << "A" << endl;  // Ensure the camino returns to the initial node
}

#endif







//Referencias
//Geek for geeks(2023).Traveling Salesman Problem using Branch And Bound. https://www.geeksforgeeks.org/traveling-salesman-problem-using-branch-and-bound-2/