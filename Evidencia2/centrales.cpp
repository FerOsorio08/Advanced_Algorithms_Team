// Lucia Barrenechea, Ian Holender, Fernanda Osorio
// 29 de noviembre del 2023

#include <iostream>
#include <vector>
#include <cmath>
#include "cablear.h"
#include "read.h"

using namespace std;

// Función para calcular la distancia euclidiana entre dos puntos (x1, y1) y (x2, y2)
double calculateDistance(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

// Función para encontrar la central más cercana a un punto (x, y) entre un conjunto de centrales
int findNearestCentral(const vector<pair<int, int> >& centrals, int x, int y) {
    int nearestCentral = 0;
    double minDistance = calculateDistance(x, y, centrals[0].first, centrals[0].second);

    // Iterar sobre las centrales restantes para encontrar la más cercana
    for (int i = 1; i < centrals.size(); i++) {
        double distance = calculateDistance(x, y, centrals[i].first, centrals[i].second);
        if (distance < minDistance) {
            minDistance = distance;
            nearestCentral = i;
        }
    }

    return nearestCentral;
}

int main() {
    // Leer el tamaño de la matriz y la matriz de distancias desde un archivo de texto
    int n = readFirstLineFromFile("matriz.txt");
    vector<vector<int> > graph = readGraphFromFile("matriz.txt");

    // Opcional: Llamar a la función Prim si es necesario (descomentar si se utiliza)
    // Prim(graph, n);

    // Solicitar al usuario el número de colonias
    int N;
    cout << "Ingrese el número de colonias: ";
    cin >> N;

    // Leer las coordenadas de las centrales desde la entrada del usuario
    vector<pair<int, int> > centrals(N);
    cout << "Ingrese las coordenadas de las centrales:\n";
    for (int i = 0; i < N; i++) {
        cin >> centrals[i].first >> centrals[i].second;
    }

    // Encontrar la central más cercana a las coordenadas del nuevo servicio
    int x, y;
    cout << "Ingrese las coordenadas del nuevo servicio:\n";
    cin >> x >> y;

    int nearestCentralIndex = findNearestCentral(centrals, x, y);

    // Imprimir la central más cercana
    cout << "La central más cercana es la ubicada en (" << centrals[nearestCentralIndex].first << "," << centrals[nearestCentralIndex].second << ")\n";

    //Complejidad del codigo: 
    
    cout<< "\n";
    cout << "Complejidad del código: O(M^2 + N)\n";
    cout << "Esta complejidad se debe a la lectura de una matriz\n"; 
    cout<< "cuadrada de tamaño M y al procesamiento de N centrales.\n";
    cout<< "\n";

    return 0;
}
