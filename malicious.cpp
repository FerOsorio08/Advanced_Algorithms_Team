#include <iostream>
#include <string>
#include <vector>
#include <fstream>  // Required for file operations

using namespace std;

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

string readFile(const string& filename) {
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

int main() {
    string text1 = readFile("transmission1.txt");
    string text2 = readFile("transmission2.txt");
    vector<string> mcodesFiles = {
        "mcode1.txt",
        "mcode2.txt",
        "mcode3.txt"
    };
    vector<string> mcodes;

    for (const string& file : mcodesFiles) {
        mcodes.push_back(readFile(file));
    }
    

    cout << "Parte 1:" << endl;
    
    for (string& mcode : mcodes) {
        int position = findPatternPosition(text1, mcode);
        if(position != -1) {
            cout << "true, the pattern: \"" << mcode << "\" from " << mcode << " appears in transmission1"  
                 << " from position " << position << " to position " << position + mcode.length() - 1 << endl;
        } else {
            cout << "false, the pattern: \"" << mcode << "\" from " << mcode << " does not appear in transmission1"  << endl;
        }
    }

    for (auto& mcode : mcodes) {
        int position = findPatternPosition(text2, mcode);
        if(position != -1) {
            cout << "true, the pattern: \"" << mcode << "\" from " << mcode << " appears in transmission2"  
                 << " from position " << position << " to position " << position + mcode.length() - 1 << endl;
        } else {
            cout << "false, the pattern: \"" << mcode << "\" from " << mcode << " does not appear in transmission2"  << endl;
        }
    }

    return 0;
}