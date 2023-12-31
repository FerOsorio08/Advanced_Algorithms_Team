#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#ifndef Palindrome_H
#define Palindrome_H

using namespace std;

vector <char> text;
vector <char> palindrome;
vector <int> palSize;

//Big O complexity of O(n)
void even(vector <char> text){
    palindrome.clear();
    palSize.clear();
    for (int i = 0; i < text.size(); i++) {
        palindrome.push_back('0');
        palindrome.push_back(text[i]);
    }
    palindrome.push_back('0');
}
//Big O complexity of O(n^2)
void findPalindrome(vector <char> text){
    even(text);
    int count=0;
    int j=0;
    int x=0;
    int textLength=palindrome.size();
    char left;
    char right;
    int len=0;
    int max=0;
    int indexl=0;
    int indexr=0;
    for (int i=0; i<textLength; i++){
        j=i;
        x=i;
        len=1;
        while(count==0){
            if(2*(j-1)+1>=0 && 2*(j+1)+1<=textLength){
                if(palindrome[2*(j-1)+1]==palindrome[2*(x+1)+1]){ //if the char to the left and right are the same
                    len=len+2; //added the two new chars that are a part of the palindrome.
                    j=j-1; //moves the "index" to the left.
                    x=x+1; //moves the "index" to the right.
                }
                else{
                    count=1;
                    palSize.push_back(len); //adds the palindrome size to the vector
                    if(len > max){
                        max=len;
                        indexl=i-(max/2); //defines the start of the palondrime
                        indexr=i+(max/2); //defines the endo of the palindrome
                    }
                }
            }
            else{
                // cout<<"OUT OF BOUNDS"<<endl;
                palSize.push_back(len); //adds the palindrome size to the vector
                if(len > max){
                        max=len;
                        indexl=i-(max/2); //defines the start of the palondrime
                        indexr=i+(max/2); //defines the endo of the palindrome
                    }
                count=1;
            }
        }
        count=0;
    }
    cout<<endl;
    cout<<indexl<<" "<<indexr<<endl;
}

#endif