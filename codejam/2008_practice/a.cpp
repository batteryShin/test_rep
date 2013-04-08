#include <cstdlib>
#include <cstdio>
#include <iostream>

#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <limits>
#include <math.h>

#include <assert.h>
#include <unistd.h>

#define CODE_DEBUG 0

typedef unsigned long long int ULINT;

using namespace std;

bool cmp_asc(const int& ref, const int& cmp) { return (ref < cmp); }
bool cmp_desc(const int& ref, const int& cmp) { return (ref > cmp); }

typedef enum {ORANGE, BLUE, NONE} COLOR;

class Node {
public:
    COLOR robot;
    int btn; 
};

int main()
{
    int tcases;
    cin >> tcases;
    cin.ignore();

    string nstr, src, tgt;
    vector<int> n_src, n_tgt;
    int len_n, len_src, len_tgt;
    int nth = 0;

    for(int t=0; t<tcases; t++) {
        nth = 0;
        nstr = src = tgt = "";
        n_src.clear();
        n_tgt.clear();

        cin >> nstr;
        cin >> src;
        cin >> tgt;
       
        len_n = nstr.length();
        len_src = src.length();
        len_tgt = tgt.length();
        
#if CODE_DEBUG
        cout << "+++++ nstr[" << t << "] : " << nstr << "(" << len_n << ")" << endl;
        cout << "+++++ src[" << t << "] : " << src << "(" << len_src << ")" << endl;
        cout << "+++++ tgt[" << t << "] : " << tgt << "(" << len_tgt << ")" << endl;
#endif

        // convert "nth" to "n_src"
        for(int i=0; i<len_n; i++) {
            for(int j=0; j<len_src; j++) {
                if( nstr.at(i)==src.at(j) ) {
                    n_src.push_back( j );
                    break;
                }
            }
        }

#if CODE_DEBUG
        cout << "+++++ n_src[" << t << "] : ";
        for(int i=0; i<n_src.size(); i++) {
            cout << n_src.at(i);
        }
        cout << endl;
#endif

        // convert "n_src" to "nth"
        for(int i=n_src.size()-1; i>=0; i--) {
            nth += n_src.at(i)*pow(len_src,n_src.size()-1-i);
        }

#if CODE_DEBUG
        cout << "+++++ nth[" << t << "] : " << nth << endl;
#endif

        // convert "nth" to "n_tgt(reversed)"
        while( true ) {
            if( nth>=len_tgt ) {
                n_tgt.push_back( nth%len_tgt );
            } else {
                n_tgt.push_back( nth );
                break;
            }
            nth /= len_tgt;
        }

#if CODE_DEBUG
        cout << "+++++ n_tgt[" << t << "] : ";
        for(int i=0; i<n_tgt.size(); i++) {
            cout << n_tgt.at(i);
        }
        cout << endl;
#endif

        cout << "Case #" << t+1 << ": ";
        for(int i=n_tgt.size()-1; i>=0; i--) {
            cout << tgt.at( n_tgt.at(i) );
        }
        cout << endl;
    }
    
    return 0;
}


