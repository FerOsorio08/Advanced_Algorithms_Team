
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#ifndef READ_H
#define READ_H

using namespace std;

//Declaraciones de funciones
vector<char> readFile(string filename);
vector<vector <char> > readFiles(const vector <string> & filenames);
void printVector(vector<string> vec);
void printFiles(const vector<string>& filenames, const vector<vector <string> >& fileContents);


//Definiciones de funciones

//Lee un archivo y lo guarda en un vector de strings
vector<char> readFile(string filename){
    vector<char> lines;
    ifstream file(filename);
    string line;
    if (file.is_open()){
        char c;
        while (file.get(c)){
            lines.push_back(c);
        }
        file.close();
    }
    else{
        cout << "No se pudo abrir el archivo" << endl;
    }
    return lines;
}


//Lee varios archivos y los guarda en un vector de vectores de strings
vector<vector<char> > readFiles(const vector<string>& filenames) {
    vector<vector<char> > fileContents;

    for (const string& filename : filenames) {
        vector<char> lines;
        ifstream file(filename);
        string line;

        if (file.is_open()) {
            char c;
            while (file.get(c)){
                lines.push_back(c);
            }
            file.close();
        } else {
            cout << "Could not open the file: " << filename << endl;
        }

        fileContents.push_back(lines);
    }

    return fileContents;
}

//Imprime un vector de strings
void printVector(vector<string> v){
    for (auto i = v.begin(); i != v.end(); ++i)
        cout << *i << " ";
    cout << endl;
    return;
}


//Imprime los archivos leidos
void printFiles(const vector<string>& filenames, const vector<vector <char> >& fileContents) {
    for (size_t i = 0; i < filenames.size(); ++i) {
        cout << "\x1B[1;32m" << "Contents of " << filenames[i] << ":" << "\x1B[0m"<< endl << endl;
        for (const char& line : fileContents[i]) {
            cout << line;
        }
    }
    cout << endl;
}




#endif