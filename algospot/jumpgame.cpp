#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

static int solvable[100][100] = {0,};
static int cmap[100][100] = {0,};

void search(int msize, int dist, int loop) {
    // base condition..
    if( dist<0 ) {
        return;
    }

    // recursion..
    int i, j; 
    int px, py;
    if( dist>=msize ) {
        for(i=msize-1; i>=msize-1-loop; i--) {
            j = dist-i;

            if( ((py=i+cmap[i][j])<msize && solvable[ py ][ j ]==1) ||
                ((px=j+cmap[i][j])<msize && solvable[ i ][ px ]==1)     ) {
                solvable[i][j] = 1;
            } else {
                solvable[i][j] = -1;
            }
        }
    } else {
        for(i=dist; i>=0; i--) {
            j = dist-i;

            if( ((py=i+cmap[i][j])<msize && solvable[ py ][ j ]==1) ||
                ((px=j+cmap[i][j])<msize && solvable[ i ][ px ]==1)     ) {
                solvable[i][j] = 1;
            } else {
                solvable[i][j] = -1;
            }
        }
    }
    search(msize, dist-1, loop+1);
}

int main() {
    std::ios::sync_with_stdio(false);

    int msize;

    int tcases;
    cin >> tcases;
    cin.ignore();
    for(int t=1; t<=tcases; t++) {
        cin >> msize;
        for(int i=0; i<msize; i++) {
            for(int j=0; j<msize; j++) {
                cin >> cmap[i][j];
                solvable[i][j] = 0;
            }
            cin.ignore();
        }

        solvable[msize-1][msize-1] = 1;
        search(msize, msize*2-3, 1);

        if( solvable[0][0]==1 ) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}

