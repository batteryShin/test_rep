#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int solve(vector<int>& v, int start, int end) {
    // base condition..
    if( start==end ) {
        return v[start];
    }

    // recursion..
    int center = (start+end) / 2;
    int lmax = solve(v, start, center);
    int rmax = solve(v, center+1, end);
    int cmax = 0;

    int l, r, vnl, vnr, min_h, area;
    l = center;
    r = center + 1;
    if(v[l]>v[r]) {
        min_h = v[r];
        area = min_h * (r-l+1);
    } else {
        min_h = v[l];
        area = min_h * (r-l+1);
    }
    cmax = area;

    while( l>start || r<end ) {
        // check adjoint values
        vnl = vnr = 0;
        if( l-1>=start ) {
            vnl = v[l-1];
        }
        if( r+1<=end ) {
            vnr = v[r+1];
        }

        // area computation
        if( vnl>vnr ) {
            l--;
            if(vnl!=0 && min_h>vnl)   min_h=vnl;
        } else if( vnl<vnr ) {
            r++;
            if(vnr!=0 && min_h>vnr)   min_h=vnr;
        } else {
            l--;
            r++;
            if(min_h>vnr)   min_h=vnr;
        }
        area = min_h * (r-l+1);


        // area comparison
        if( cmax < area ) {
            cmax = area;
        }
    }

    return max(max(lmax,rmax), cmax);
}

int main() {
    int tcases;
    int nval, val;
    vector<int> varr;

    std::ios::sync_with_stdio(false);
    cin >> tcases;
    for(int t=1; t<=tcases; t++) {
        cin >> nval;
        for(int i=0; i<nval; i++) {
            cin >> val;
            varr.push_back(val);
        }

        cout << solve(varr,0,varr.size()-1) << "\n";

        varr.clear();
    }
}
