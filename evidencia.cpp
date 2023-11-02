//Lucia Barrenechea, Ian Holender, Fernanda Osorio
//2 de noviembre del 2023
//Archivo main para solución en CPP
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <vector>
#include "read.h"


using namespace std;

int main(int argc, char *argv[]){
    vector<string> names;
    names.push_back("transmission1.txt");
    names.push_back("transmission2.txt");
    names.push_back("mcode1.txt");
    names.push_back("mcode2.txt");
    names.push_back("mcode3.txt");
  
    vector<vector <string> > fileContents = readFiles(names);
    printFiles(names, fileContents);
}