// Lucia Barrenechea, Ian Holender, Fernanda Osorio
// 2 de noviembre del 2023
// Header para encontrar el substring mas largo común entre dos archivos
#include <iostream>
#include <vector>
#ifndef substring_h
#define substring_h

using namespace std;

//Declaraciones de funciones
vector<char> readFileC(const string& filename);
string LCS(const vector<char>& S1, const vector<char>& S2);
vector < vector < char > > readFilesChar (const vector <string> & filenames);
void printVectorChar(vector<vector<char> > v);


//Definicones de Funciones

vector<char> readFileC(const string& filename) {
    vector<char> content;
    ifstream file(filename);

    if (file.is_open()) {
        char character;
        while (file.get(character)) {
            content.push_back(character);
        }
        file.close();
    } else {
        cout << "Could not open the file: " << filename << endl;
    }

    return content;
}


string LCS(const vector<char>& S1, const vector<char>& S2) {
    int m = S1.size();
    int n = S2.size();
    // Crear una matriz de (m+1)x(n+1) para guardar los valores de LCS
    vector<vector<int> > LCS_table(m + 1, vector<int>(n + 1, 0));
    int max_len = 0;   // Longitud maxima
    int end_index = 0; // indice final del CS en S1

    // Usar una matriz de "abajo para arriba"
    for (int i = 1; i <= m; i++) {
        // Recorrer S2
        for (int j = 1; j <= n; j++) {
            // Si los caracteres son iguales
            if (S1[i - 1] == S2[j - 1]) {
                // Sumar 1 al valor de la diagonal
                LCS_table[i][j] = LCS_table[i - 1][j - 1] + 1;
                // Si el valor es mayor al maximo se debe actualizar
                if (LCS_table[i][j] > max_len) {
                    max_len = LCS_table[i][j];
                    end_index = i - 1;
                }
            }
        }
    }

    if (max_len == 0) {
        return "No hay common substring"; // Si no hay CS
    }

    // Sacar el CS de S1
    string commonSubstring(S1.begin() + end_index - max_len + 1, S1.begin() + end_index + 1);

    cout << "Initial Position: " << (end_index - max_len + 1) + 1 << endl;
    cout << "Final Position: " << (end_index) + 1 << endl;
    cout << "Common Substring: ";
    return commonSubstring;
}

vector < vector < char > > readFilesChar (const vector <string> & filenames){
    vector<vector<char> > fileContents;

    for (const string& filename : filenames) {
        vector<char> lines;
        ifstream file(filename);
        char line;

        if (file.is_open()) {
            while (file.get(line)) {
                lines.push_back(line);
            }
            file.close();
        } else {
            cout << "Could not open the file: " << filename << endl;
        }

        fileContents.push_back(lines);
    }

    return fileContents;

}


void printVectorChar(vector<vector<char> > v){
    for (auto i = v.begin(); i != v.end(); ++i){
        for (auto j = i->begin(); j != i->end(); ++j){
            cout << *j << " ";
        }
        cout << endl;
    }
    cout << endl;
    return;
}



#endif