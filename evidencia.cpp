// Lucia Barrenechea, Ian Holender, Fernanda Osorio
// 2 de noviembre del 2023
// Archivo main para solución en CPP
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
    names.push_back("./texts/transmission1.txt");
    names.push_back("./texts/transmission2.txt");
    names.push_back("./texts/mcode1.txt");
    names.push_back("./texts/mcode2.txt");
    names.push_back("./texts/mcode3.txt");

    vector<vector<string> > fileContents = readFiles(names);
    // printFiles(names, fileContents);

    vector<string> malcodes;
    malcodes.push_back("./texts/mcode1.txt");
    malcodes.push_back("./texts/mcode2.txt");
    malcodes.push_back("./texts/mcode3.txt");
    vector<string> mcodes;
    for (const string &file : malcodes){
        mcodes.push_back(readFileM(file));
    }

    string text1 = readFileM("./texts/transmission1.txt");
    string text2 = readFileM("./texts/transmission2.txt");

    cout << "\x1B[1;33m"
         << "Malicious Code in Transmissions:"
         << ":"
         << "\x1B[0m" << endl;

    for (const string &mcode : mcodes){
        findAndDisplayPattern(text1, mcode, "transmission1");
    }

    for (const string &mcode : mcodes){
        findAndDisplayPattern(text2, mcode, "transmission2");
    }

    cout << "\x1B[1;34m"
         << "Longest Common Substring"
         << ":"
         << "\x1B[0m" << endl;
    vector<char> T1 = readFileC("./texts/transmission1.txt");
    vector<char> T2 = readFileC("./texts/transmission2.txt");
    cout << LCS(T1, T2) << endl;
    cout << "\x1B[1;31m"
         << "Printing Palindromes"
         << ":"
         << "\x1B[0m" << endl;
    cout << "\x1B[1m"
         << "Transmission 1"
         << ":"
         << "\x1B[0m" << endl;
    findPalindrome(T1);
    cout << "\x1B[1m"
         << "Transmission 2"
         << ":"
         << "\x1B[0m" << endl;
    findPalindrome(T2);
}