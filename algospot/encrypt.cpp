#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

int main() {
    int tcases;
    string str;
    string strout;

    std::ios::sync_with_stdio(false);
    cin >> tcases;
    while(tcases-->0) {
        cin >> str;
        strout.clear();
        for(int i=0; i<str.size(); i=i+2) {
            strout += str[i];
        }
        for(int i=1; i<str.size(); i=i+2) {
            strout += str[i];
        }
        cout << strout << "\n";
    }
}


