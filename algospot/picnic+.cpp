#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string.h>

using namespace std;

int tcases;
int n;
int m;
int areFriends[10][10];
int nlist[10];

int search_recursive(int taken[10]) {
    int front_person = -1;

    for(int i=0; i<n; i++) {
        if( taken[i]==0 ) {
            front_person = i;
            break;
        }
    }

    // base condition..
    if( front_person==-1 ) {
        return 1;
    }

    int ret = 0;
    for(int i=front_person+1; i<n; i++) {
        if( !taken[i] && areFriends[front_person][i] ) {
            taken[front_person] = taken[i] = 1;
            ret += search_recursive(taken);
            taken[front_person] = taken[i] = 0;
        }
    }

    return ret;
}

int main() {
    cin >> tcases;
    cin.ignore();
    for(int t=1; t<=tcases; t++) {
        cin >> n >> m;
        cin.ignore();

        memset(nlist,0,sizeof(int)*10);
        memset(areFriends,0,sizeof(int)*10*10);
        int fa, fb;
        for(int i=0; i<m; i++) {
            cin >> fa >> fb;
            areFriends[fa][fb] = 1;
            areFriends[fb][fa] = 1;
        }

        int tot_cnt = search_recursive(nlist);
    
        cout << /*"Case #" << t << ": " << */tot_cnt << endl;
    }
}
