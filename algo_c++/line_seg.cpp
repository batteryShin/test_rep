#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <vector>
#include <memory.h>
#include <cmath>

using namespace std;

struct Vec2d {
    int x1;
    int y1;
    int x2;
    int y2;
};

int main()
{
    Vec2d iv;
    cout << "Insert start point (x1, y1) : ";
    cin >> iv.x1 >> iv.y1;
    cout << "Insert end point (x2, y2) : ";
    cin >> iv.x2 >> iv.y2;

    int mx = max(iv.x1,iv.x2) + 1;
    int my = max(iv.y1,iv.y2) + 1;
    bool **segs = new bool*[my];
    for(int i=0; i<my; i++) {
        segs[i] = new bool[mx];
        memset(segs[i], 0, sizeof(bool)*mx);
    }
    segs[iv.y1][iv.x1] = segs[iv.y2][iv.x2] = true;

    vector<Vec2d> stack;
    int cx, cy;

    stack.push_back(iv);
    while( !stack.empty() ) {
        Vec2d pv;
        Vec2d cv = stack.front();

        cx = (int)( (cv.x1 + cv.x2) / 2.f + 0.5f ); 
        cy = (int)( (cv.y1 + cv.y2) / 2.f + 0.5f );
        segs[cy][cx] = true;

        if( abs(cx-cv.x1)>1 || abs(cy-cv.y1)>1 ) {
            pv.x1 = cv.x1;
            pv.x2 = cx;
            pv.y1 = cv.y1;
            pv.y2 = cy;

            stack.push_back(pv);
        }

        if( abs(cx-cv.x2)>1 || abs(cy-cv.y2)>1 ) {
            pv.x1 = cx;
            pv.x2 = cv.x2;
            pv.y1 = cy;
            pv.y2 = cv.y2;

            stack.push_back(pv);
        }

        stack.erase( stack.begin() );
    }

    
    cout << endl;
    cout << "start point = (" << iv.x1 << "," << iv.y1 << ")" << endl;
    cout << "end point = (" << iv.x2 << "," << iv.y2 << ")" << endl;
    cout << "   ";
    for(int i=0; i<mx; i++) {
        if(i<10) {
            cout << "  " << i;
        } else if(i<100) {
            cout << " " << i;
        } else {
            cout << i;
        }
    }

    for(int i=0; i<my; i++) {
        cout << endl;

        if(i<10) {
            cout << "  " << i;
        } else if(i<100) {
            cout << " " << i;
        } else {
            cout << i;
        }

        for(int j=0; j<mx; j++) {
            if( segs[i][j] ) {
                cout << " * ";
            } else {
                cout << "   ";
            }
        }
    }

    for(int i=0; i<my; i++) {
        delete [] segs[i];
    }
    delete segs;
    
}

