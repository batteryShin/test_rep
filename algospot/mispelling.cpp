#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

int main() {
    int tcases;
    int n = 0;
    int p;
    string str;

    std::ios::sync_with_stdio(false);
    cin >> tcases;
    while(tcases-->0) {
        cin >> p >> str;
        str.erase(str.begin()+p-1);
        cout << ++n << " " << str << "\n";
    }
}
