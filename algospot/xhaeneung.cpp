#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int tcases;

    const string snum[11] = {"zero", "one", "two", "three", "four", "five", 
                        "six", "seven", "eight", "nine", "ten"};
    vector<string> vsnum;
    vsnum.assign(snum, snum+11);

    vector<string>::iterator it;
    vector<string>::iterator it_begin;
    it_begin = vsnum.begin();

    string slhs, op, srhs, sans;
    int lhs, rhs;
    string res;

    std::ios::sync_with_stdio(false);
    cin >> tcases;
    while(tcases-->0) {
        slhs.clear();
        op.clear();
        srhs.clear();
        sans.clear();
        res.clear();

        cin >> slhs >> op >> srhs;
        cin.ignore();
        cin.ignore();
        cin.ignore();
        cin >> sans;

        it = find(vsnum.begin(), vsnum.end(), slhs);
        lhs = distance(it_begin, it);

        it = find(vsnum.begin(), vsnum.end(), srhs);
        rhs = distance(it_begin, it);

        res = "";
        if( op=="+" ) {
            if( lhs+rhs<11 ) {
                res = snum[lhs+rhs];
            }
        } else if( op=="-" ) {
            if( lhs-rhs>=0 ) {
                res = snum[lhs-rhs];
            }
        } else {
            if( lhs*rhs<11 ) {
                res = snum[lhs*rhs];
            }
        }

        sort(res.begin(),res.end());
        sort(sans.begin(),sans.end());
        cout << (strcmp(res.c_str(),sans.c_str())?"No\n":"Yes\n");
    }
}


