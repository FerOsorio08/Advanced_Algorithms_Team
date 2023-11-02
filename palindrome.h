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

void even(){
    for (int i = 0; i < text.size(); i++) {
        palindrome.push_back('0');
        palindrome.push_back(text[i]);
        cout<<palindrome[i]<<" ";
    }
    palindrome.push_back('0');
}

void findPalindrome(){
    even();
    int count=0;
    int j=0;
    int x=0;
    int textLength=palindrome.size();
    char left;
    char right;
    int len=0;
    int max=0;
    int indexl;
    int indexr;
    // if(textLength<=1){ //If the text has only one letter or none.
    //     return;
    // }
    for (int i=0; i<textLength; i++){
        j=i;
        x=i;
        len=1;
        // cout<<palindrome[2*i+1]<<endl;
        while(count==0){
            if(2*(j-1)+1>=0 && 2*(j+1)+1<=textLength){
                if(palindrome[2*(j-1)+1]==palindrome[2*(x+1)+1]){ //if the char to the left and right are the same
                    // cout<<"palindrome: "<<palindrome[2*(j-1)+1]<<palindrome[2*j+1]<<palindrome[2*(j+1)+1]<<endl;
                    len=len+2; //added the two new chars that are a part of the palindrome.
                    j=j-1; //moves the "index" to the left.
                    x=x+1; //moves the "index" to the right.
                }
                else{
                    count=1;
                    // cout<<palindrome[2*(j-1)+1]<<palindrome[2*(j+1)+1]<<endl;
                    // cout<<"Palindrome has ended"<<endl;
                    // cout<<"adding counting: "<<len<<endl;
                    // cout<<i<<endl;
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
    for (unsigned long i = 0; i < text.size(); i++) {
       cout<<text[i]<<" ";
    }
    cout<<endl;
    for (unsigned long i = 0; i < palSize.size(); i++) {
       cout<<palSize[i]<<" ";
    }
    cout<<endl;
    cout<<"The largest palindrome starts in index: "<<indexl<<endl;
    cout<<"The largest palindrome ends in index: "<<indexr<<endl;

}

// int main(){
//     text.push_back('h');
//     text.push_back('7');
//     text.push_back('a');
//     text.push_back('n');
//     text.push_back('a');
//     text.push_back('b');
//     text.push_back('c');
//     text.push_back('n');
//     text.push_back('c');
//     text.push_back('b');
//     //text.push_back('f');
//     //cout<<"hola"<<endl;
//     // for (unsigned long i = 0; i < text.size(); i++) {
//     //    cout<<text[i]<<" ";
//     // }
//     findPalindrome();
//     return 0;
// }




#endif