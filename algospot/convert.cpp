#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int tcases;
    int n = 0;
    float p;
    string str;
    
    float cp;
    string unit;

    std::ios::sync_with_stdio(false);
    cin >> tcases;
    while(tcases-->0) {
        cin >> p >> str;
        if( str[0]=='l' ) {
            if( str[1]=='b' ) {
                unit = "kg";
                cp = p * 0.4536;
            } else {
                unit = "g";
                cp = p * 0.2642;
            }
        } else if( str[0]=='k' ) {
            unit = "lb";
            cp = p * 2.2046;
        } else {
            unit = "l";
            cp = p * 3.7854; 
        }

        printf("%d %.4f %s\n", ++n, cp, unit.c_str());
    }
}

