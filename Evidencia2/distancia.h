#include <iostream>
#include <vector>
#include <cmath>
#include "cablear.h"
#include "read.h"
#ifndef distancia_H
#define distancia_H

using namespace std;



// Complejidad del código: O(M^2 + N)
// Esta complejidad se debe a la lectura de una matriz
// cuadrada de tamaño M y al procesamiento de N centrales.


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

void readCoordinatesFromUser(vector<pair<int, int> >& coordinates, const string& prompt) {
    cout << prompt << ":\n";
    for (auto& coord : coordinates) {
        cin >> coord.first >> coord.second;
    }
}

void printNearestCentral(const vector<pair<int, int> >& centrals, int nearestCentralIndex) {
    cout << "La central más cercana es la ubicada en (" << centrals[nearestCentralIndex].first << "," << centrals[nearestCentralIndex].second << ")\n";
}

vector<pair<int, int> > readCoordinatesFromFile(const string& filename) {
    vector<pair<int, int> > coordinates;
    ifstream file(filename);

    if (file.is_open()) {
        int n; // Assuming the first line contains the size (not used in this function)
        file >> n;

        // Skip the lines with matrix values
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int value;
                file >> value;
            }
        }

        // Read coordinates
        string line;
        while (getline(file, line)) {
            istringstream iss(line);
            char openParen, comma, closeParen;
            int x, y;

            if (iss >> openParen >> x >> comma >> y >> closeParen) {
                coordinates.push_back(make_pair(x, y));
            }
        }

        file.close();
    } else {
        cerr << "Unable to open file: " << filename << endl;
    }

    return coordinates;
}

#endif