#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

static int cache[101][101];

int search(string& w_str, string& s_str, int w, int s) {
    cout << "search for " << w << "," << s << " !!!\n";
    // memoization..
    int& ret = cache[w][s];
    if( ret!=-1 ) {
        return ret;
    }

    // recursion..
    if( (w<w_str.size() && s<s_str.size()) && 
            (w_str[w]=='?' || w_str[w]==s_str[s]) ) {
        return (ret=search(w_str, s_str, w+1, s+1));
    }

    // check & return based on why recursion if over..
    if( w==w_str.size() ) {
        return (ret=(s==s_str.size()));
    }

    if( w_str[w]=='*' ) {
        if( search(w_str,s_str,w+1,s) || 
            (s<s_str.size() && search(w_str,s_str,w,s+1)) ) {
            return (ret=1);
        }
    }

    return (ret=0);
}

int main() {
    string w_str, s_str;
    vector<string> results;
    int num;
    int tcases;
    cin >> tcases;
    while(tcases-->0) {
        cin >> w_str;
        cin >> num;
        for(int i=0; i<num; i++) {
            cin >> s_str;

            memset(cache, -1, sizeof(int)*101*101);
            if( search(w_str,s_str,0,0) ) {
                results.push_back( s_str );
            }
        }

        sort( results.begin(), results.end() );

        for(int i=0; i<results.size(); i++) {
            cout << results[i] << "\n";
        }
        results.clear();
    }
}
