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

int same_until(int* arr, int sz, int start) {
    int val = arr[start];
    int cnt = 0;
    while( arr[start]==val ) {
        if( start<sz ) {
            start++;
        } else {
            break;
        }
        cnt++;
    }
    return cnt;
}

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

        int val, val_sum;
        int sub_total;
        int p = 0;
        rcnt.clear();
        val = str.size()-cs+1;
        int total = val*(val+1)/2;

        sub_total = 0;
        while( p<str.size() ) {
            val_sum = 0;
            while( (val=same_until(tr,str.size(),p))<cs && p<str.size() ) {
                val_sum += val;
                p += val;
            }
            sub_total += val_sum*(val_sum+1)/2;
            p += val;
        }

        cout << "Case #" << tcases-tcnt << ": " << total-sub_total << endl;
    }

    return 0;
}

