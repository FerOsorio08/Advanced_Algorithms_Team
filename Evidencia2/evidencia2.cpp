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

using namespace std;

int main(int argc, char *argv[]){

    vector<vector<int> > graph = readGraphFromFile("matriz.txt");
    int n = readFirstLineFromFile("matriz.txt");
    Prim(graph,n);
    tspBB(graph);

}