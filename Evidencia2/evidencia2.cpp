// Lucia Barrenechea, Ian Holender, Fernanda Osorio
// 29 de noviembre del 2023
// Archivo main para solución en CPP
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "cablear.h"
#include "read.h"
#include "tsp.h"
#include "distancia.h"

using namespace std;

int main(int argc, char *argv[]){

    vector<vector<int> > graph = readGraphFromFile("matriz.txt");
    vector <pair<int, int> > coordinates = readCoordinatesFromFile("matriz.txt");
    int n = readFirstLineFromFile("matriz.txt");
    Prim(graph,n);
    tspBB(graph);
    int x, y;
    cout << "Ingrese las coordenadas del nuevo servicio:\n";
    cin >> x >> y;

    int nearestCentralIndex = findNearestCentral(coordinates, x, y);
    printNearestCentral(coordinates, nearestCentralIndex);

}