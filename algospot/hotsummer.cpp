#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int tcases;
    int goal, use;

    std::ios::sync_with_stdio(false);
    cin >> tcases;
    while(tcases-->0) {
        cin >> goal;
        for(int i=0; i<9; i++) {
            cin >> use;
            goal -= use;
        }

        cout << ((goal>=0)?"YES\n":"NO\n");
    }
}

