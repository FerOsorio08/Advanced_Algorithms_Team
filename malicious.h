// Lucia Barrenechea, Ian Holender, Fernanda Osorio
// 2 de noviembre del 2023
// Header para encontrar el substring mas largo común entre dos archivos
#include <iostream>
#include <vector>
#include <string>
#include <fstream> 
#ifndef malicious_h
#define malicious_h

using namespace std;

//Declaraciones de funciones
int findPatternPosition(const string& text, const string& pattern);
string readFileM(const string& filename);
void findAndDisplayPattern(const string& text, const string& pattern, const string& transmissionName);


//Definicones de Funciones
int findPatternPosition(const string& text, const string& pattern) {
    int n = text.length();
    int m = pattern.length();

    if (m > n) {
        return -1;
    }

    for (int i = 0; i <= n - m; i++) {
        if (text.substr(i, m) == pattern) {
            return i;
        }
    }
    return -1;
}

string readFileM(const string& filename) {
    ifstream file(filename);
    string content, line;

    if (!file.is_open()) {
        cerr << "Failed to open file: " << filename << endl;
        return "";
    }

    while (getline(file, line)) {
        content += line;
    }

    file.close();
    return content;
}

void findAndDisplayPattern(const string& text, const string& pattern, const string& transmissionName) {
    size_t position = text.find(pattern);
    if (position != string::npos) {
        cout << "true, the pattern: \"" << pattern << "\" from " << pattern << " appears in " << transmissionName
             << " from position " << position << " to position " << position + pattern.length() - 1 << endl;
    } else {
        cout << "false, the pattern: \"" << pattern << "\" from " << pattern << " does not appear in " << transmissionName << endl;
    }
}



#endif