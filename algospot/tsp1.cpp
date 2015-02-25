#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

using namespace std;

static int N;
static double edge[9][9];
static int visited[9];

double search(int start) {
    double ret = 1415 * 2;

    // base condition
    int next = -1;
    for(int i=1; i<=N; i++) {
        if( !visited[i] ) {
            next = i;
            break;
        }
    }

    if( next==-1 ) {
        return 0;
    }


    // recursion
    for(int i=1; i<=N; i++) {
        if(i==start || visited[i]) {
            continue;
        }
        visited[i] = 1;
        ret = min(ret, edge[start][i]+search(i));
        visited[i] = 0;
    }

    return ret;
}

int main() {
    int T;
    cin >> T;
    while(T-->0) {
        cin >> N;

        for(int i=1; i<=N; i++) {
            for(int j=1; j<=N; j++) {
                cin >> edge[i][j];
            }
            cin.ignore();
        }

        memset(visited, 0, sizeof(int)*9);

        printf("%.10f\n", search(0));
    }
}
