// Lucia Barrenechea, Ian Holender, Fernanda Osorio
// 28 de noviembre del 2023
//Este header contiene las funciones necesarias para calcular 
//la forma óptima de cablear con fibra óptica conectando colonias
#include <iostream>
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

int firstMin(const vector<vector<int> >& graph, int i) {
    int minCost = INF;
    for (int j = 0; j < graph.size(); j++) {
        if (i != j && graph[i][j] < minCost) {
            minCost = graph[i][j];
        }
    }
    return minCost;
}

int secondMin(const vector<vector<int> >& graph, int i) {
    int firstMinValue = INF, secondMinValue = INF;
    for (int j = 0; j < graph.size(); j++) {
        if (i != j) {
            if (graph[i][j] <= firstMinValue) {
                secondMinValue = firstMinValue;
                firstMinValue = graph[i][j];
            } else if (graph[i][j] <= secondMinValue) {
                secondMinValue = graph[i][j];
            }
        }
    }
    return secondMinValue;
}

void tspBBUtil(const vector<vector<int> >& graph, vector<int>& path, vector<bool>& visited, int& currWeight, int& finalWeight, int currPos, int n, int count) {
    if (count == n) {
        // Complete the tour by returning to the initial node
        if (graph[currPos][0] != 0) {
            int currCost = currWeight + graph[currPos][0];
            if (currCost < finalWeight) {
                finalWeight = currCost;
                path[count - 1] = 0;  // Set the last element of the path to 0
            }
        }
        return;
    }

    // Branch and Bound
    for (int i = 0; i < n; i++) {
        if (!visited[i] && graph[currPos][i] != 0) {
            int temp = currWeight;
            int bound = currWeight - firstMin(graph, currPos) + graph[currPos][i] + secondMin(graph, i);
            // from which node to which node and weight
            cout << "from " << currPos << " to " << i << " weight " << graph[currPos][i] << endl;

            // Pruning condition
            if (bound < finalWeight) {
                currWeight += graph[currPos][i];
                if (currWeight < finalWeight) {
                    path[count] = i;
                    visited[i] = true;
                    tspBBUtil(graph, path, visited, currWeight, finalWeight, i, n, count + 1);
                    visited[i] = false;  // Backtrack
                }

                // Backtrack
                currWeight = temp;
            }
        }
    }
}

void tspBB(const vector<vector<int> >& graph) {
    int n = graph.size();
    vector<int> path(n, -1);
    vector<bool> visited(n, false);

    // Initialize path
    path[0] = 0;
    visited[0] = true;

    int currWeight = 0;  // Weight of the current path
    int finalWeight = INF;  // Initialize the final weight to a large value

    tspBBUtil(graph, path, visited, currWeight, finalWeight, 0, n, 1);
    // list of letters to represent the path
    vector<char> letters;
    for (int i = 0; i < n; i++) {
        letters.push_back('A' + i);
    }
    cout << "Minimum Cost: " << finalWeight << endl;
    cout << "Path Taken: ";
    for (int i : path) {
        // represent the path with letters
        cout << letters[i] << " ";
        // cout << i << " ";
    }
    cout << "A" << endl;  // Ensure the path returns to the initial node
}

// int main() {
//     // Example usage
//     vector<vector<int> > graph = {
//         {0, 10, 15, 20},
//         {10, 0, 35, 25},
//         {15, 35, 0, 30},
//         {20, 25, 30, 0}
//     };

//     tspBB(graph);

//     return 0;
// }









// // #include <iostream>
// // #include <limits.h>
// // #include <cstring>
// // using namespace std;

// // int N = 4;
// vector <int> finalPath;
// // int finalPath[N + 1];
// // bool visited[N];
// vector <bool> visited;
// int finalResult = INT_MAX;

// void copyToFinal(vector <int> currentPath, int num) {
//     for (int i = 0; i < num; i++)
//         finalPath[i] = currentPath[i];
//     finalPath[num] = currentPath[0];
// }

// int firstMin(vector<vector <int> > matrix, int i, int num) {//Inicializa ocn un valor muy alto para encontrar
//     int minValue = INT_MAX;
//     for (int k = 0; k < num; k++)
//         if (matrix[i][k] < minValue && i != k)
//             minValue = matrix[i][k];
//     return minValue;
// }

// int secondMin(vector<vector <int> > matrix, int i, int num) {
//     int firstMinValue = INT_MAX;
//     int secondMinValue = INT_MAX;
//     for (int j = 0; j < num; j++) {
//         if (i == j)
//             continue;
//         if (matrix[i][j] <= firstMinValue) {
//             secondMinValue = firstMinValue;
//             firstMinValue = matrix[i][j];
//         } else if (matrix[i][j] <= secondMinValue && matrix[i][j] != firstMinValue)
//             secondMinValue = matrix[i][j];
//     }
//     return secondMinValue;
// }

// void TSPRec(vector<vector <int> > matrix, int currentBound, int currentWeight, int level, vector <int> currentPath, int num, vector<bool> &visited) {
//     if (level == num) {
//         if (matrix[currentPath[level - 1]][currentPath[0]] != 0) {
//             int currentResult = currentWeight + matrix[currentPath[level - 1]][currentPath[0]];
//             if (currentResult < finalResult) {
//                 copyToFinal(currentPath, num);
//                 finalResult = currentResult;
//             }
//         }
//         return;
//     }

//     for (int i = 0; i < num; i++) {
//         if (matrix[currentPath[level - 1]][i] != 0 && !visited[i]) {
//             int temp = currentBound;
//             currentWeight += matrix[currentPath[level - 1]][i];

//             if (level == 1)
//                 currentBound -= ((firstMin(matrix, currentPath[level - 1], num) + firstMin(matrix, i, num)) / 2);
//             else
//                 currentBound -= ((secondMin(matrix, currentPath[level - 1], num) + firstMin(matrix, i, num)) / 2);

//             if (currentBound + currentWeight < finalResult) {
//                 currentPath[level] = i;
//                 visited[i] = true;
//                 TSPRec(matrix, currentBound, currentWeight, level + 1, currentPath, num, visited);
//             }

//             currentWeight -= matrix[currentPath[level - 1]][i];
//             currentBound = temp;

//             vector<int> visited(num+1, 0);;
//             for (int j = 0; j <= level - 1; j++)
//                 visited[currentPath[j]] = true;
//         }
//     }

// }

// void tsp(vector <vector<int> > matrix, int num) {
//     //int currentPath[num + 1];
//     int currentBound = 0;
//     //memset(currentPath, -1, sizeof(currentPath));
//     vector<int> currentpath(num+1, -1);
//     vector<bool> visited(num+1, 0);
//     //memset(visited, 0, sizeof(currentPath));

//     for (int i = 0; i < num; i++)
//         currentBound += (firstMin(matrix, i, num) + secondMin(matrix, i, num));

//     currentBound = (currentBound & 1) ? currentBound / 2 + 1 : currentBound / 2;

//     visited[0] = true;
//     currentpath[0] = 0;

//     TSPRec(matrix, currentBound, 0, 1, currentpath, num, visited);
// }

// // int main() {
// //     int adj[N][N] = {{0, 10, 15, 20},
// //                      {10, 0, 35, 25},
// //                      {15, 35, 0, 30},
// //                      {20, 25, 30, 0}};

// //     TSP(adj);

// //     cout << "Minimum cost: " << finalResult << endl;
// //     cout << "Path Taken: ";
// //     for (int i = 0; i <= N; i++)
// //         cout << finalPath[i] << " ";

// //     return 0;
// // }


// // void tsp(vector<vector <int> > graph, int boundaries){
// //     vector <int> path(boundaries+1); //Initialize size to boundaries +1
// //     int small=0;
// //     vector <bool>visited;
// // }


#endif