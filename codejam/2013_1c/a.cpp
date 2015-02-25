#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <iomanip>

#include <string>
#include <cstring>
#include <sstream>

#include <list>
#include <vector>
#include <map>

#include <algorithm>
#include <limits.h>
#include <math.h>
#include <cfloat>

#include <assert.h>
#include <unistd.h>

#define CODE_DEBUG 0
#if CODE_DEBUG
#define LOGD(str) do { std::cout << "+++++ " << str << std::endl; } while( false )
#define LOGD_INL(str) do{ std::cout << str; } while( false )
#else
#define LOGD(str) do { } while ( false )
#define LOGD_INL(str) do { } while ( false )
#endif

typedef unsigned long long ULL;

using namespace std;

bool cmp_asc(const ULL& ref, const ULL& cmp) { return (ref < cmp); }

void expand_insert( map<string,int> &rcnt, int* tr, string &s, int sz, int beg, int end) {
    stringstream ss;
    string sl;
    if( beg>0 ) {
        if(tr[beg-1]) {
            ss << '1';
        } else {
            ss << '0';
        }
        ss << s;
        ss >> sl;
        expand_insert( rcnt, tr, sl, sz, beg-1, end );
        ss.clear();
    }

    string sin;
    ss << beg << "#";
    ss << s;
    ss >> sin;

    rcnt.insert(pair<string,int>(sin,1));
    LOGD("insert string = " << sin);
    ss.clear();

    string sr;
    if( end<sz ) {
        ss << s;
        if(tr[end+1]) {
            ss << '1';
        } else {
            ss << '0';
        }
        ss >> sr;
        expand_insert( rcnt, tr, sr, sz, beg, end+1 );
        ss.clear();
    }

}

int all_same(int* arr, int start, int end) {
    int val = arr[start];
    for(int i=start+1; i<=end; i++) {
        if (arr[i]!=val) return -1;
    }
    return val;
};

int main()
{
    int tcases, tcnt;

    string str;
    int cs;
    int tr[100001];
    string s;
    stringstream ss;
    map<string,int> rcnt;

    cin >> tcases;
    cin.ignore();

    tcnt = tcases;
    while(tcnt-->0) {
        cin >> str;
        cin >> cs;
        cin.ignore();

        for(int i=0; i<str.size(); i++) {
            if( str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u' ) {
                tr[i] = 0;
            } else {
                tr[i] = 1;
            }
        }

        LOGD("str = " << str);
        LOGD_INL("tr = " << tr[0]);
        for(int i=1; i<str.size(); i++) {
            LOGD_INL(tr[i]);
        }
        LOGD_INL(endl);

        int val;
        rcnt.clear();
        for(int i=0; i<str.size()-cs+1; i++) {
            if( (val=all_same(tr, i, i+cs-1))!=-1 ) {
                for(int j=1; j<=cs; j++) {
                    if(val) {
                        ss << '1';
                    } else {
                        ss << '0';
                    }
                }
                ss >> s;
                expand_insert(rcnt, tr, s, str.size()-cs+1, i, i+cs-1);
                ss.clear();
            }
        }

        cout << "Case #" << tcases-tcnt << ": " << rcnt.size() << endl;
    }

    return 0;
}

