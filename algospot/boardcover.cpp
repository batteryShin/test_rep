#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string.h>
#include <cstring>

using namespace std;

int tcases;
int h;
int w;

int shapes[8][2] = {
    {1, 0}, {1, 1},
    {1, -1}, {1, 0},
    {0, 1}, {1, 1},
    {0, 1}, {1, 0}
};

vector<string> bdmap;

void set_covered(int (&covered)[20][20], int ypos, int xpos, int nshape, int value) {
    int pt1y = ypos+shapes[nshape*2][0];
    int pt1x = xpos+shapes[nshape*2][1];
    int pt2y = ypos+shapes[nshape*2+1][0];
    int pt2x = xpos+shapes[nshape*2+1][1];

    covered[ypos][xpos] += value;
    covered[pt1y][pt1x] += value;
    covered[pt2y][pt2x] += value;
}

bool is_shape_appropriate(int (&covered)[20][20], int ypos, int xpos, int nshape) {
    bool ret = false;

    int pt1y = ypos+shapes[nshape*2][0];
    int pt1x = xpos+shapes[nshape*2][1];
    int pt2y = ypos+shapes[nshape*2+1][0];
    int pt2x = xpos+shapes[nshape*2+1][1];
//    cout << "checking... " << pt1y << "," << pt1x;
//    cout << " & " << pt2y << "," << pt2x << endl;

    if( pt1y>=0 && pt1y<20 &&
        pt1x>=0 && pt1x<20 &&
        pt2y>=0 && pt2y<20 &&
        pt2x>=0 && pt2x<20 &&
        !covered[pt1y][pt1x] && !covered[pt2y][pt2x] ) {
        ret = true;
    }

    return ret;
}

void search(int (&covered)[20][20], int ypos, int xpos, int &cnt) {
    int tg_x=-1, tg_y=-1;
    for(int r=ypos; r<h; r++) {
        for(int c=0; c<w; c++) {
            if(r==ypos && c<xpos) continue;

            if( !covered[r][c] ) {
                tg_x = c;
                tg_y = r;
                break;
            }
        }
        if( tg_y!=-1 ) {
            break;
        }
    }

    // base condition..
    if( tg_y==-1 ) {
        for(int r=0; r<h; r++) {
        for(int c=0; c<w; c++) {
            if( !covered[r][c] ) {
                return;
            }
        }
        }
       
        cnt++;
        return;
    }
    
    for(int i=0; i<4; i++) {
        if( is_shape_appropriate(covered, tg_y, tg_x, i) ) {
//            cout << "checked! " << tg_y << "," << tg_x << endl;
            set_covered(covered, tg_y, tg_x, i, 1);
            search(covered, tg_y, tg_x, cnt);
            set_covered(covered, tg_y, tg_x, i, -1);
        }
    }
}

int main() {
    cin >> tcases;
    for(int t=1; t<=tcases; t++) {
        cin >> h >> w;

        bdmap.clear();
        string str;
        for(int r=0; r<h; r++) {
            cin >> str;
            bdmap.push_back(str);
        }

        int covered[20][20];
        int empty_cnt = 0;
        memset(covered, -1, sizeof(int)*20*20);
        for(int r=0; r<h; r++) {
            for(int c=0; c<w; c++) {
                if( bdmap[r][c]=='#' ) {
                    covered[r][c] = 1;
                } else {
                    covered[r][c] = 0;
                    empty_cnt++;
                }
            }
        }

        int cnt = 0;
        if(empty_cnt%3==0) {
            search(covered,0,0,cnt);
        }
        cout << cnt << endl;
    }

}
