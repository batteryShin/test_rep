#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <iomanip>

#include <string>
#include <cstring>

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

int comb_cnt(int base, int cnt) {
    int upper, under;

    upper = under = 1.f;
    for(int i=1; i<=cnt; i++) {
        upper *= base-(i-1);
        under *= i;
    }

    return (upper/under);
}

int main()
{
    int tcases, tcnt;

    cin >> tcases;
    cin.ignore();

    int d, px, py;

    float res;
    int stage;
    int sub, dsub;
    int sbase[128];
    for(int i=0; i<128; i++) {
        sbase[i] = i*(2*i+3) + 1;
    }

    tcnt = tcases;
    while(tcnt-->0) {
        cin >> d >> px >> py;
        cin.ignore();

        if (px<0) px=-px;

        if( (px+py)==0 && d>0 ) {
            res = 1.f;
        } else {
            stage = (px+py)/2;

            int cnt = 0;
            while( (sub=d-sbase[cnt++])>=0 ) {
                dsub = sub;
                LOGD("dsub(" << cnt-1 << ") = " << dsub);
            }

            if( cnt-1>stage ) {
                res = 1.f;
            } else if( cnt-1<stage ) {
                res = 0.f;
            } else {
                if( dsub>=stage*2+py+1 ) {
                    res = 1.f;
                } else {
                    int sum = 0;
                    for(int i=py+1; i<=dsub; i++) {
                        sum += comb_cnt(dsub,i);
                    }
                    res = (float)sum/pow(2,dsub);
                }
            }
        }

        cout << "Case #" << tcases-tcnt << ": " << fixed << res << endl;
    }

    return 0;
}
