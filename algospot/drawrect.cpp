#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

int main() {
    int tcases;
    int xpos[3];
    int ypos[3];
    int resx, resy;

    std::ios::sync_with_stdio(false);
    cin >> tcases;
    while(tcases-->0) {
        for(int i=0; i<3; i++) {
            cin >> xpos[i] >> ypos[i];
        }

        if( xpos[0]==xpos[1] ) {
            resx = xpos[2];
        } else if( xpos[0]==xpos[2] ) {
            resx = xpos[1];
        } else {
            resx = xpos[0];
        }

        if( ypos[0]==ypos[1] ) {
            resy = ypos[2];
        } else if( ypos[0]==ypos[2] ) {
            resy = ypos[1];
        } else {
            resy = ypos[0];
        }

        cout << resx << " " << resy << "\n";
    }
}


