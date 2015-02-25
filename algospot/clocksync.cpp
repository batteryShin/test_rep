#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

static const int switches[10][16] = {
    { 1,1,1,0,  0,0,0,0,  0,0,0,0,  0,0,0,0 },
    { 0,0,0,1,  0,0,0,1,  0,1,0,1,  0,0,0,0 },
    { 0,0,0,0,  1,0,0,0,  0,0,1,0,  0,0,1,1 },
    { 1,0,0,0,  1,1,1,1,  0,0,0,0,  0,0,0,0 },
    { 0,0,0,0,  0,0,1,1,  1,0,1,0,  1,0,0,0 },
    { 1,0,1,0,  0,0,0,0,  0,0,0,0,  0,0,1,1 },
    { 0,0,0,1,  0,0,0,0,  0,0,0,0,  0,0,1,1 },
    { 0,0,0,0,  1,1,0,1,  0,0,0,0,  0,0,1,1 },
    { 0,1,1,1,  1,1,0,0,  0,0,0,0,  0,0,0,0 },
    { 0,0,0,1,  1,1,0,0,  0,1,0,0,  0,1,0,0 },
};

void search(int (&ns)[10], int (&clocks)[16], int cur, int &min_cnt) {
    // base condition..
    bool aligned = true;
    for(int i=0; i<16; i++) {
        if( clocks[i]!=0 ) {
            aligned = false;
            break;
        }
    }

    if( aligned ) {
        int cnt = 0;
        for(int i=0; i<10; i++) {
            cnt += ns[i];
        }

        if( cnt<min_cnt ) {
/*            
            for(int i=0; i<10; i++) {
                if( ns[i] ) {
                    cout << "switch #" << i << " is triggered " << ns[i] << " times!!" << endl;
                }
            }
*/            
            min_cnt = cnt;
        }
        return;
    }

    if( cur>=10 ) {
        return;
    }

    // computation..
    for(int n=0; n<=4; n++) {
        if( n>0 ) {
            ns[cur] += 1;
            for(int i=0; i<16; i++) {
                if( switches[cur][i] ) {
                    if(++(clocks[i])==4) {
                        clocks[i] = 0;
                    }
                }
            }
        }
        search(ns, clocks, cur+1, min_cnt);
    }

    ns[cur] -= 4;
}

int main() {
    int tcases;

    int clocks[16] = {0,};
    int nswitches[10] = {0,};


    cin >> tcases;
    for(int t=1; t<=tcases; t++) {
        for(int i=0; i<16; i++) {
            cin >> clocks[i];

            clocks[i] /= 3;
            if( clocks[i]==4 ) {
                clocks[i] = 0;
            }
        }

        int min_cnt = 59050;
        search(nswitches, clocks, 0, min_cnt);

        if( min_cnt==59050 ) {
            cout << -1 << endl;
        } else {
            cout << min_cnt << endl;
        }
    }
}
