#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

const long long NEGINF = numeric_limits<long long>::min();

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
    long long a = (ida==-1? NEGINF: seq_a[ida]);
    long long b = (idb==-1? NEGINF: seq_b[idb]);
    long long maxElement = max(a,b);

    for(int na=ida+1; na<nseq_a; na++) {
        if(maxElement < seq_a[na]) {
            ret = max(ret, jlis(na,idb)+1);
        }
    }

    for(int nb=idb+1; nb<nseq_b; nb++) {
        if(maxElement < seq_b[nb]) {
            ret = max(ret, jlis(ida,nb)+1);
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
