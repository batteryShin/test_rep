#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

using namespace std;

string str;

string solve(int start, int end, int &p) {
    // base condition..
    if( end-start+1 < 4 )
        return "";

    string sstr[4];
    for(int i=0; i<4; i++) {
        sstr[i] = "";
    }

    int pcnt = 0;
    while( pcnt<4 && p<end ) {
        sstr[pcnt] = str[p];
        if( str[p]=='x' ) {
            p++;
            sstr[pcnt] += solve(p,end,p);
            p--;
        }
        
        pcnt++;
        p++;
    }

    return (sstr[2]+sstr[3]+sstr[0]+sstr[1]);
}

int main() {
    int tcases;

    cin >> tcases;
    for(int t=1; t<=tcases; t++) {
        cin >> str;

        int p = 0;
        if( str[0]=='x' ) {
            cout << solve(0,str.length(),p) << endl;
        } else {
            cout << str[0] << endl;
        }
    }
}
