//Lucia Barrenechea, Ian Holender, Fernanda Osorio
//2 de noviembre del 2023
//Header para leer archivos de transmision y código malisioso
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
vector<string> readFile(string filename);
vector<vector <string> > readFiles(const vector <string> & filenames);
void printVector(vector<string> vec);
void printFiles(const vector<string>& filenames, const vector<vector <string> >& fileContents);


//Definiciones de funciones

//Lee un archivo y lo guarda en un vector de strings
vector<string> readFile(string filename){
    vector<string> lines;
    ifstream file(filename);
    string line;
    if (file.is_open()){
        while (getline(file, line)){
            lines.push_back(line);
        }
        file.close();
    }
    else{
        cout << "No se pudo abrir el archivo" << endl;
    }
    return lines;
}


//Lee varios archivos y los guarda en un vector de vectores de strings
vector<vector<string> > readFiles(const vector<string>& filenames) {
    vector<vector<string> > fileContents;

    for (const string& filename : filenames) {
        vector<string> lines;
        ifstream file(filename);
        string line;

        if (file.is_open()) {
            while (getline(file, line)) {
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

//Imprime un vector de strings
void printVector(vector<string> v){
    for (auto i = v.begin(); i != v.end(); ++i)
        cout << *i << " ";
    cout << endl;
    return;
}


//Imprime los archivos leidos
void printFiles(const vector<string>& filenames, const vector<vector <string> >& fileContents) {
    for (size_t i = 0; i < filenames.size(); ++i) {
        cout << "\x1B[1;32m" << "Contents of " << filenames[i] << ":" << "\x1B[0m"<< endl << endl;
        for (const string& line : fileContents[i]) {
            cout << line << endl;
        }
    }
    cout << endl;
}




#endif