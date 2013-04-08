#include <cstdlib>
#include <cstdio>
#include <iostream>

#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <math.h>

#include <assert.h>
#include <unistd.h>

#define CODE_DEBUG 0

typedef unsigned long long int ULINT;

using namespace std;

bool cmp_asc(const int& ref, const int& cmp) { return (ref < cmp); }
bool cmp_desc(const int& ref, const int& cmp) { return (ref > cmp); }

typedef enum {
    NORTH = 1,
    SOUTH,
    WEST,
    EAST
} DIRS;

class Node {
public:
    int rpos;
    int cpos;
    char state;

    Node(int r, int c) {
        rpos = r;
        cpos = c;
        state = 0xF;
    }

    const bool operator ==(const Node &n) const {
        bool res = false;
        if(rpos==n.rpos && cpos==n.cpos) {
            res = true;
        }
        return res;
    }
/*
    void move(int direction) {
        switch(direction) {
            case EAST:
                cpos++;
                break;
            case SOUTH:
                rpos++;
                break;
            case WEST:
                cpos--;
                break;
            case NORTH:
                rpos--;
                break;
        }
    };
*/
    void block(int direction) {
        switch(direction) {
            case NORTH:
                state &= 0xE;
                break;
            case SOUTH:
                state &= 0xD;
                break;
            case WEST:
                state &= 0xB;
                break;
            case EAST:
                state &= 0x7;
                break;
        }
    }
};

inline int turn_cw(int direction) {
    int res = 0;
    switch(direction) {
        case NORTH:
            res = EAST;
            break;
        case SOUTH:
            res = WEST;
            break;
        case WEST:
            res = NORTH;
            break;
        case EAST:
            res = SOUTH;
            break;
    }

    return res;
}

inline int turn_ccw(int direction) {
    int res = 0;
    switch(direction) {
        case NORTH:
            res = WEST;
            break;
        case SOUTH:
            res = EAST;
            break;
        case WEST:
            res = SOUTH;
            break;
        case EAST:
            res = NORTH;
            break;
    }

    return res;
}

void move(int *r, int *c, int direction) {
    switch(direction) {
        case EAST:
            (*c)++;
            break;
        case SOUTH:
            (*r)++;
            break;
        case WEST:
            (*c)--;
            break;
        case NORTH:
            (*r)--;
            break;
    }
}

int nodein(vector<Node *> vnp, Node *np) {
    int res = -1;
    for(int i=0; i<vnp.size(); i++) {
        if( *vnp.at(i)==*np ) {
            res = i;
            break;
        }
    }

    return res;
}

void reindex(vector<Node *> vnp, int *maxr, int *maxc, int *minr, int *minc) {
    *minr = *minc = INT_MAX;
    *maxr = *maxc = 0;

    for(int i=0; i<vnp.size(); i++) {
        if( vnp.at(i)->rpos > *maxr ) {
            *maxr = vnp.at(i)->rpos;
        } 
        
        if( vnp.at(i)->rpos < *minr ) {
            *minr = vnp.at(i)->rpos;
        }

        if( vnp.at(i)->cpos > *maxc ) {
            *maxc = vnp.at(i)->cpos;
        } 
        
        if( vnp.at(i)->cpos < *minc ) {
            *minc = vnp.at(i)->cpos;
        }
    }
}

int main()
{
    int tcases;
    cin >> tcases;
    cin.ignore();

    string path1, path2;
    int rpos, cpos;
    int prev_rpos, prev_cpos;
    vector<Node*> arrnp;
    Node *np;
    int pos;
    int cur_dir;
    bool l_flag;
    char **res;
    int maxr, maxc, minr, minc;

    for(int t=0; t<tcases; t++) {
        path1 = path2 = "";
        rpos = cpos = 0;
        prev_rpos = prev_cpos = 0;
        arrnp.clear();

        cin >> path1;
        cin >> path2;

        cur_dir = SOUTH;
        l_flag = false;
        for(int i=1; i<path1.length(); i++) {
            np = new Node(rpos,cpos); 
            if( (pos=nodein(arrnp,np))==-1 ) {
                arrnp.push_back( np );
            } else {
                delete np;
                np = arrnp.at(pos);
            }

            switch( path1.at(i) ){
                case 'L':
                    cur_dir = turn_ccw(cur_dir);
                    l_flag = true;
                    break;
                case 'W':
                    if( !l_flag ) {
                        np->block( turn_ccw(cur_dir) );
                    }
                    prev_rpos = rpos;
                    prev_cpos = cpos;
                    move(&rpos,&cpos,cur_dir);
                    l_flag = false;
                    break;
                case 'R':
                    np->block( turn_ccw(cur_dir) );
                    cur_dir = turn_cw(cur_dir);
                    break;
                default:
                    break;
            }
        }

        cur_dir = turn_cw( turn_cw(cur_dir) );
        rpos = prev_rpos;
        cpos = prev_cpos;
        for(int i=1; i<path2.length(); i++) {
            np = new Node(rpos,cpos); 
            if( (pos=nodein(arrnp,np))==-1 ) {
                arrnp.push_back( np );
            } else {
                delete np;
                np = arrnp.at(pos);
            }

            switch( path2.at(i) ){
                case 'L':
                    cur_dir = turn_ccw(cur_dir);
                    l_flag = true;
                    break;
                case 'W':
                    if( !l_flag ) {
                        np->block( turn_ccw(cur_dir) );
                    }
                    move(&rpos,&cpos,cur_dir);
                    l_flag = false;
                    break;
                case 'R':
                    np->block( turn_ccw(cur_dir) );
                    cur_dir = turn_cw(cur_dir);
                    break;
                default:
                    break;
            }
        }

#if CODE_DEBUG
        for(int i=0; i<arrnp.size(); i++) {
            cout << "+++++ #" << i << " (" << arrnp.at(i)->rpos << "," << arrnp.at(i)->cpos << ") ";
            cout << "state=" << (int)arrnp.at(i)->state << endl;
        }
#endif

        reindex(arrnp, &maxr, &maxc, &minr, &minc);
#if CODE_DEBUG
        cout << "r = (" << minr << " ~ " << maxr << ")" << endl;
        cout << "c = (" << minc << " ~ " << maxc << ")" << endl;
#endif
        res = new char*[maxr-minr+1];
        for(int i=0; i<maxr-minr+1; i++) {
            res[i] = new char[maxc-minc+1];
        }
        char ch[2];
        for(int i=0; i<arrnp.size(); i++) {
            sprintf( ch, "%x", (int)arrnp.at(i)->state );
#if CODE_DEBUG
            cout << "res[" << i << "] = " << ch[0] << endl;
#endif
            res[arrnp.at(i)->rpos][arrnp.at(i)->cpos-minc] = ch[0];
        }

        cout << "Case #" << t+1 << ": " << endl;
        for(int r=0; r<maxr-minr+1; r++) {
            for(int c=0; c<maxc-minc+1; c++) {
                cout << res[r][c];
            }
            cout << endl;
        }

        for(int i=0; i<arrnp.size(); i++) {
            delete arrnp.at(i);
        }
        for(int i=0; i<maxr-minr+1; i++) {
            delete [] res[i];
        }
        delete [] res;
    }
    
    return 0;
}

