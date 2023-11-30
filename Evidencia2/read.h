// Lucia Barrenechea, Ian Holender, Fernanda Osorio
// 29 de noviembre del 2023
//Este header contiene las funciones necesarias para recibir los datos
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#ifndef read_H
#define read_H

using namespace std;


//Declaraciones de funciones 
vector<vector<int> > readGraphFromFile(const string& filename);
int readFirstLineFromFile(const string& filename);
void printMatrix(const vector<vector<int> >& matrix);


//Definiciones de funciones

// Función para leer el grafo de un archivo
//recibe el nombre del archivo
//regresa el grafo en forma de matriz de adyacencia
//Complejidad: O(n^2)
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

// Función para leer la primera línea de un archivo
//recibe el nombre del archivo
//regresa el primer número de la primera línea del archivo
//Complejidad: O(1)
int readFirstLineFromFile(const string& filename) {
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Error opening the file: " << filename << endl;
        return -1; // Return -1 to indicate an error
    }

    string firstLine;
    getline(file, firstLine);

    file.close();

    // Convert the first line to an integer
    int result;
    stringstream(firstLine) >> result;

    return result;
}

// Función para imprimir una matriz
//recibe la matriz a imprimir
//no regresa nada
//Complejidad: O(n^2)
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





#endif
