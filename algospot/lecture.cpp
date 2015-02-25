#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp_string(const string& lhs, const string& rhs) {
    return (lhs.compare(rhs)<0);
}

int main() {
    int tcases;
    int p, pn;
    string str;
    vector<string> sstr;

    std::ios::sync_with_stdio(false);
    cin >> tcases;
    while(tcases-->0) {
        cin >> str;
        p = pn = 0;
        sstr.clear();
        while(p<str.size()-1) {
            sstr.push_back(str.substr(p,2));
            pn++;
            p += 2;
        }
        
        sort(sstr.begin(), sstr.end(), cmp_string);
        for(int i=0; i<pn; i++) {
            cout << sstr[i];
        }
        cout << "\n";
    }
}


