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
#include "palindrome.h"
#include "malicious.h"
#include "substring.h"


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

    cout << "\x1B[1;34m" << "Longest Common Substring" << ":" << "\x1B[0m"<< endl;
    vector<char> T1 = readFileC("transmission1.txt");
    vector<char> T2 = readFileC("transmission2.txt");
    cout << LCS(T1,T2) << endl;
    cout<<"Printing Palindromes"<<endl;
    findPalindrome(T1);
    findPalindrome(T2);
}