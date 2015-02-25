#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <iomanip>

#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
#include <limits>
#include <climits>
#include <cmath>
#include <cfloat>

#include <assert.h>
#include <unistd.h>

#include "bigInt.h"

#define CODE_DEBUG 1
#if CODE_DEBUG
#define LOGD(str) do { std::cout << "+++++ " << str << std::endl; } while( false )
#define LOGD_INL(str) do{ std::cout << str; } while( false )
#else
#define LOGD(str) do { } while ( false )
#define LOGD_INL(str) do { } while ( false )
#endif

typedef unsigned long long int ULINT;
typedef BigInt::Rossi BigIntR;

using namespace std;

bool reverse_str_check(BigIntR &n) {
    BigIntR ncpy = n;
    string str = ncpy.toStrDec();
    char rstr[101];
    memset(rstr, 0, 101);

    int len = str.length();
    memcpy(rstr, str.c_str(), len);
    
    char *beg, *end;
    beg = rstr;
    end = rstr + len;
    reverse(beg,end);
//    LOGD("reverse check : " << str << " vs " << rstr);

    return ( !strcmp(str.c_str(),rstr) );
}

void accumulate_res(vector<BigIntR> &vres) {
    BigIntR nlimit(10);
    for(int i=0; i<14; i++) {
        nlimit = nlimit*10;
    }
    LOGD( "nlimit = " << nlimit );

    BigIntR i(1);
    BigIntR n(1);
    while( n<nlimit ) {
        if( reverse_str_check(n) && reverse_str_check(i) ) {
            vres.push_back(n);
            LOGD( n.toStrDec() << " " );
        }

        i++;
        n = i*i;
    }
}


int main()
{
    vector<BigIntR> v_res;
    accumulate_res(v_res);

    int tcases;
    cin >> tcases;
    cin.ignore();

    string stra, strb;
    BigIntR a, b;
    int cnt;
    bool res;
    for(int t=1; t<=tcases; t++) {
        cin >> stra >> strb;
        a = BigIntR(stra,10);
        b = BigIntR(strb,10);
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

