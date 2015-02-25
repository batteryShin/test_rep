#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

static int max_jlis;
static int nseq_a, nseq_b;
static int seq_a[100];
static int seq_b[100];
static int cache[101][101];

int jlis(int ida, int idb) {
    // memoization..
    int& ret = cache[ida+1][idb+1];
    if( ret!=-1 ) {
        return ret;
    }

    // base condition..
    ret = 2;

    // recursion..
    long va = ida==-1?LONG_MIN:seq_a[ida];
    long vb = idb==-1?LONG_MIN:seq_b[idb];

    long max_elem = max(va,vb);

    for(int i=ida+1; i<nseq_a; i++) {
        if( (long)seq_a[i]>max_elem ) {
            ret = max(ret, 1+jlis(i,idb));
        }
    }

    for(int j=idb+1; j<nseq_b; j++) {
        if( (long)seq_b[j]>max_elem ) {
            ret = max(ret, 1+jlis(ida,j));
        }
    }

    return ret;
}

int main() {
    int tcases;
    int res;

    std::ios::sync_with_stdio(false);
    cin >> tcases;
    while(tcases-->0) {
        cin >> nseq_a >> nseq_b;
        memset(seq_a, 0, sizeof(int)*100);
        memset(seq_b, 0, sizeof(int)*100);
        memset(cache, -1, sizeof(int)*101*101);
        for(int i=0; i<nseq_a; i++) {
            cin >> seq_a[i];
        }
        cin.ignore();

        for(int i=0; i<nseq_b; i++) {
            cin >> seq_b[i];
        }
        cin.ignore();

        cout << jlis(-1,-1)-2 << "\n";
    }
}
