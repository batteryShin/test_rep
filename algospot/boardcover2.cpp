#include <cstdlib>
#include <cstdio>
#include <iostream>

#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <limits>
#include <math.h>

#include <assert.h>
#include <unistd.h>

#define SZMAX 10 

using namespace std;

bool cmp_asc(const int& ref, const int& cmp) { return (ref < cmp); }
bool cmp_desc(const int& ref, const int& cmp) { return (ref > cmp); }

int tcases;
int h, w, r, c;
int best;
int res;

string row_str;
    
int board[SZMAX][SZMAX];

int blockSize;
int blockRemain;
vector< vector< pair<int,int> > > rotations;
vector<string> gblock;

vector<string> rotate(const vector<string>& arr) {
    vector<string> ret(arr[0].size(), string(arr.size(),' '));
    for(int i=0; i<arr.size(); i++) {
        for(int j=0; j<arr[0].size(); j++) {
            ret[j][arr.size()-i-1] = arr[i][j];
        }
    }

    return ret;
}


void gen_rotations(vector<string>& block) {
    rotations.clear();
    rotations.resize(4);

    for(int k=0; k<4; k++) {
        int oy = -1, ox = -1;
        for(int i=0; i<block.size(); i++) {
            for(int j=0; j<block[0].size(); j++) {
                if( block[i][j]=='#' ) {
                    if( oy==-1 ) {
                        oy = i;
                        ox = j;
                    }
                    rotations[k].push_back(make_pair(i-oy,j-ox));
                }
            }
        }

        block = rotate(block);
    }

    sort(rotations.begin(), rotations.end());
    rotations.erase(unique(rotations.begin(),rotations.end()),rotations.end());

    blockSize = rotations[0].size();

/*    
    for(int i=0; i<rotations.size(); i++) {
        cout << "Rotations[" << i << "]" << endl;
        for(int j=0; j<rotations[0].size(); j++) {
            cout << "(" << rotations[i][j].first << "," << rotations[i][j].second << ") ";
        }
        cout << endl;
    }
*/    
}

bool set(int py, int px, vector< pair<int,int> >& block, int val) {
    bool res = true;
    int ypos = -1;
    int xpos = -1;

    // validation check
    for(int i=0; i<block.size(); i++) {
        ypos = py+block[i].first;
        xpos = px+block[i].second;
        if( ypos<0 || ypos>h-1 || xpos<0 || xpos>w-1 ) {
            res = false;
            break;
        }

        if( val==1 && board[ypos][xpos]==1 ) {
            res = false;
            break;
        }
        
        if( val==-1 && board[ypos][xpos]==0 ) {
            res = false;
            break;
        }
    }

    // if it is ok, then assign value
    if( res ) {
        for(int i=0; i<block.size(); i++) {
            ypos = py+block[i].first;
            xpos = px+block[i].second;

            board[ypos][xpos] += val;
        }
    }

    return res;
}

void search(int placed, int remained) {
    // find the top-left-most placed block
    int y = -1, x = -1;
    for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) {
            if(board[i][j]==0) {
                y = i;
                x = j;
                break;
            }
        }

        if( y!=-1 ) break;
    }

    // *** pruning by remained blocks ***
    if( placed+(remained/blockSize) <= best ) {
        return;
    }

    // base condition
    if( y==-1 ) {
        best = max(best, placed);
        return;
    }

    for(int i=0; i<rotations.size(); i++) {
        if( set(y,x,rotations[i],1) ) {
            remained -= blockSize;
            search(placed+1, remained);
        }
        set(y,x,rotations[i],-1);
        remained += blockSize;
    }

    board[y][x] = 1;
    remained -= 1;
    search(placed, remained);
    board[y][x] = 0;
    remained += 1;
}

int main()
{
    cin >> tcases;
    cin.ignore();

    for(int t=1; t<=tcases; t++) {
        memset(board, -1, sizeof(int)*SZMAX*SZMAX);
        gblock.clear();
        blockRemain = 0;

        cin >> h >> w >> r >> c;
        cin.ignore();

        for(int i=0; i<h; i++) {
            cin >> row_str;
            for(int j=0; j<w; j++) {
                if(row_str[j]=='#') {
                    board[i][j] = 1; 
                } else if(row_str[j]=='.') {
                    board[i][j] = 0;
                    blockRemain++;
                }
            }
            row_str.clear();
        }

        for(int i=0; i<r; i++) {
            cin >> row_str;
            gblock.push_back(row_str);
            row_str.clear();
        }
        gen_rotations(gblock);

        best = 0;
        search(best, blockRemain);

        cout << best << "\n";
    }
}
