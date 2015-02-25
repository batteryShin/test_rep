#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

static int path[202][202];
static int cache[202][202];
static int N;

int solve(int y, int x) {
    // memoization
    int &ret = cache[y][x];
    if( ret!=-1 ) {
        return ret;
    }

    // base condition
    ret = path[y][x];
    if( y==2*N-1 ) {
        return ret;
    }

    // recursion
    if( y<N ) {
        if( x<N ) {
            ret += max(solve(y+1,x),solve(y+1,x+1));
        } else {
            ret += solve(y+1,x);
        }
    } else {
        if( x<N ) {
            ret += max(solve(y+1,x),solve(y+1,x-1));
        } else {
            ret += solve(y+1,x-1);
        }
    }
    return ret;
}

int main() {
    int T;

    std::ios::sync_with_stdio(false);
    cin >> T;
    while(T-->0) {
        cin >> N;

        memset(path, 0, sizeof(int)*202*202);
        memset(cache, -1, sizeof(int)*202*202);

        for(int i=1; i<=N; i++) {
            for(int j=1; j<=i; j++) {
                cin >> path[i][j];
            }
            cin.ignore();
        }
        for(int i=N-1; i>=1; i--) {
            for(int j=1; j<=i; j++) {
                cin >> path[N+N-i][j];
            }
            cin.ignore();
        }

        cout << solve(1,1) << "\n";
    }
}

