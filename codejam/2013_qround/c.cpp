#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <iomanip>

#include <string>
#include <cstring>
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

typedef unsigned long long int ULINT;

using namespace std;

bool reverse_str_check(ULINT n) {
    char str[15], rstr[15];
    memset(str, 0, 15);
    memset(rstr, 0, 15);

    int len = sprintf(str, "%llu", n);
    memcpy(rstr, str, len);
    
    char *beg, *end;
    beg = rstr;
    end = rstr + len;
    reverse(beg,end);

    return ( !strcmp(str,rstr) );
}

void accumulate_res(vector<ULINT> &vres) {
    ULINT nlimit = pow(10,14);
    LOGD( "nlimit = " << nlimit );

    long double nsqrt;
    ULINT i = 1;
    ULINT n = 1;
    while( n<nlimit ) {
        if( reverse_str_check(n) ) {
            nsqrt = sqrt(n);
            if( nsqrt==(double)((ULINT)nsqrt) && reverse_str_check(nsqrt) ) {
                vres.push_back(n);
                LOGD( n << " " );
            }
        }

        i++;
        n = i*i;
    }
}


int main()
{
    vector<ULINT> v_res;
    accumulate_res(v_res);

    int tcases;
    cin >> tcases;
    cin.ignore();

    ULINT a, b;
    int cnt;
    bool res;
    for(int t=1; t<=tcases; t++) {
        cin >> a >> b;
        cin.ignore();

        cnt = 0;
        for(int i=0; i<v_res.size(); i++) {
            if( v_res.at(i)>=a && v_res.at(i)<=b ) {
                LOGD( "cnt++ because = " << v_res.at(i) );
                cnt++;
            }
        }

        cout << "Case #" << t << ": " << cnt << endl;
    }

    v_res.clear();
}

