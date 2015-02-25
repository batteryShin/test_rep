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

#define UINT unsigned int

using namespace std;

int tcases;
int n, l;
int best;

int num;
string num_str;

vector<UINT> desire;
vector<UINT> cur;
vector< vector<UINT> > excepts;

UINT bconvert( string bnum ) {
    UINT res = 0;

    if( bnum[bnum.size()-1]=='1' ) {
        res = 1;
    }

    int k;
    for(int i=bnum.size()-2,k=1; i>=0; i--,k++) {
        if(bnum[i]=='1') {
            res += k*2;
        }
    }

    return res;
}

bool iscontain( vector<vector<UINT> >& pool, vector<UINT>& elem ) {
    bool res = false;
    if( pool.size()<=1 ) {
        return res;
    }

    for(int i=0; i<pool.size(); i++) {
        if( pool[i]==elem ) {
            res = true;
            break;
        }
    }
    return res;
}

void search(int fliped, vector<UINT>& cur, vector<UINT>& desire, vector< vector<UINT> >& excepts) {
    // *** simple pruning ***
    if( best>=0 && fliped>=best ) {
        return;
    }

    // base condition
    if( cur==desire ) {
        cout << "\t\t\t\t\t=====> matched!! " << fliped << endl;
        if( best<0 ) {
            best = fliped;
        } else {
            best = min(best, fliped);
        }
        return;
    }

    for(int i=0; i<l; i++) {
        // flip i-th bit..
        for(int j=0; j<cur.size(); j++) {
            if(i==0) {
                cur[j] ^= 1;
            } else {
                cur[j] ^= i*2;
            }
        }
        sort(cur.begin(), cur.end());
        fliped += 1;
        
        cout << "  [flip_" << i << "-th, " << " best=" << best << " " << fliped << "] : ";
        for(int j=0; j<cur.size(); j++)
            cout << cur[j] << " ";
        cout << endl;

        if( !iscontain(excepts,cur) ) {
            excepts.push_back( cur );
            search(fliped, cur, desire, excepts);
//            excepts.pop_back();
        }

        // un-flip i-th bit..
        for(int j=0; j<cur.size(); j++) {
            if(i==0) {
                cur[j] ^= 1;
            } else {
                cur[j] ^= i*2;
            }
        }
        sort(cur.begin(), cur.end());
        fliped -= 1;

        cout << "[unflip_" << i << "-th, " << " best=" << best << " " << fliped << "] : ";
        for(int j=0; j<cur.size(); j++)
            cout << cur[j] << " ";
        cout << endl;
        
    }
}

int main()
{
    cin >> tcases;
    cin.ignore();

    for(int t=1; t<=tcases; t++) {
        cur.clear();
        desire.clear();
        excepts.clear();
        best = -1;

        cin >> n >> l;
        for(int i=0; i<n; i++) {
            cin >> num_str;
            cur.push_back( bconvert(num_str) );
            num_str.clear();
        }
        sort(cur.begin(), cur.end());

        for(int i=0; i<n; i++) {
            cin >> num_str;
            desire.push_back( bconvert(num_str) );
            num_str.clear();
        }
        sort(desire.begin(), desire.end());

        excepts.push_back( cur );
        search(0, cur, desire, excepts);

        cout << "Case #" << t << ": ";
        if( best>=0 ) {
            cout << best << endl;
        } else {
            cout << "NOT POSSIBLE" << endl;
        }
    }
}
