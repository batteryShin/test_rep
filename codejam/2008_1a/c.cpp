#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <iomanip>

#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <limits>
#include <math.h>

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

using namespace std;

typedef unsigned long long ULINT;
typedef long long LLINT;

int main()
{
    int tcases, tcnt;

    cin >> tcases;
    cin.ignore();

    char buf[200];
    char *pbuf;
    string str, res;
    int n;
    long double base[31];
    base[0] = 1;
    base[1] = 5.2360679774997896964091736687313;
    for(int i=2; i<31; i++) {
        base[i] = base[i-1]*base[1];
        LOGD("base[" << i << "] = " << setprecision(20) << base[i]);
    }

    tcnt = tcases;
    while(tcnt-->0) {
        cin >> n;
        sprintf(buf, "%LF", base[n]);
        pbuf = strtok(buf,".");
        str = string(pbuf);
        LOGD("buf = " << buf << ", string = " << str);
        if( str.length()>=3 ) {
            res = str.substr(str.length()-3,str.length());
        } else {
            res = str;
            while( res.length()<3 ) {
                res.insert(0, "0");
            }
        }

        cout << "Case #" << tcases-tcnt << ": " << res << endl;
    }

    return 0;
}


