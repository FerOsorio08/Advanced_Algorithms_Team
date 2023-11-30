#include <iostream>
#include <vector>
#include <cmath>
#include "cablear.h"
#include "read.h"

using namespace std;

double calculateDistance(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int findNearestCentral(const vector<pair<int, int> >& centrals, int x, int y) {
    int nearestCentral = 0;
    double minDistance = calculateDistance(x, y, centrals[0].first, centrals[0].second);

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
    // Read the graph from the file
    int n = readFirstLineFromFile("matriz.txt");
    vector<vector<int> > graph = readGraphFromFile("matriz.txt");


    // Assuming you have a Prim function, uncomment the following line if necessary
    // Prim(graph, n);

    int N;
    cout << "Ingrese el número de colonias: ";
    cin >> N;

    // Leer coordenadas de las centrales
    vector<pair<int, int> > centrals(N);
    cout << "Ingrese las coordenadas de las centrales:\n";
    for (int i = 0; i < N; i++) {
        cin >> centrals[i].first >> centrals[i].second;
    }

    // Parte 3: Encontrar la central más cercana
    int x, y;
    cout << "Ingrese las coordenadas del nuevo servicio:\n";
    cin >> x >> y;

    int nearestCentralIndex = findNearestCentral(centrals, x, y);
    cout << "La central más cercana es la ubicada en (" << centrals[nearestCentralIndex].first << "," << centrals[nearestCentralIndex].second << ")\n";

    return 0;
}
