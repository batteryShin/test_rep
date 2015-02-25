#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <vector>

using namespace std;

void find_lis(vector<int>& vseq, int (&covered)[501], int (&computed)[501], int& max_len, int len, int prev, int p) {
    // base condition..
    int next = -1;
    for(int i=p; i<vseq.size(); i++) {
        if( !covered[i] ) {
            next = i;
            break;
        }
    }

//    cout << "lis computing at " << p << ", next=" << next << ", len=" << len << "\n";
    if( next==-1 ) {
        if( max_len<len ) {
            max_len = len;
        }
        return;
    }

    // recursion..
    int prev_tmp;
    for(int i=next; i<vseq.size(); i++) {
        if( covered[i] ) {
            continue;
        }

        if( vseq[prev]>=vseq[i] ) {
            covered[i] = 1;
            continue;
        }

        // memoization..
        if( computed[i] ) {
//            cout << "using precomputed[" << i << "] value\n";
            for(int j=i; j<vseq.size(); j++) {
                covered[j] = 1;
            }
            prev_tmp = prev;
            prev = i;
            find_lis(vseq, covered, computed, max_len, len+computed[i], prev, vseq.size());
            for(int j=i; j<vseq.size(); j++) {
                covered[j] = 0;
            }
            prev = prev_tmp;
        } else {
            covered[i] = 1;
            prev_tmp = prev;
            prev = i;
            find_lis(vseq, covered, computed, max_len, len+1, prev, i+1);
            covered[i] = 0;
            prev = prev_tmp;
        }
    }

    prev = vseq.size();
    find_lis(vseq, covered, computed, max_len, len, prev, vseq.size());
}

int main() {
    int covered[501];
    int computed[501];

    vector<int> vseq;
    int seg;
    int snum;
    int max_len;
    int local_max;

    int tcases;
    cin >> tcases;
    while(tcases-->0) {
        vseq.clear();
        memset(covered, 0, sizeof(int)*501);
        memset(computed, 0, sizeof(int)*501);

        cin >> snum;
        for(int i=0; i<snum; i++) {
            cin >> seg;
            vseq.push_back(seg);
        }

        max_len = 0;
        for(int i=vseq.size()-1; i>=0; i--) {
            local_max = 0;
            for(int j=0; j<=i; j++) {
                covered[j] = 1;
            }
            for(int j=i+1; j<vseq.size(); j++) {
                covered[j] = 0;
            }
            find_lis(vseq, covered, computed, local_max, 1, i, i+1);

            computed[i] = local_max;
            if( max_len<local_max ) {
                max_len = local_max;
            }
        }
        cout << max_len << "\n";
    }
}
