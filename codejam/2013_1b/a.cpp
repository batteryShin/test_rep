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

bool cmp_asc(const ULL& ref, const ULL& cmp) { return (ref < cmp); }

int main()
{
    int tcases, tcnt;
    int n;
    ULL a;

    ULL elem;
    vector<ULL> motes;
    vector<ULL>::iterator it;


    cin >> tcases;
    cin.ignore();

    tcnt = tcases;
    while(tcnt-->0) {
        cin >> a >> n;
        cin.ignore();

        motes.clear();
        for(int i=0; i<n; i++) {
            cin >> elem;
            motes.push_back(elem);
        }

        sort(motes.begin(), motes.end(), cmp_asc);
        LOGD_INL("initial=" << a << ", motes=");
        for(int i=0; i<motes.size(); i++) {
            LOGD_INL( " " << motes.at(i) );
        }
        LOGD_INL(endl);

        ULL cur = a;
        int crank = 0;
        int cnt;
        for(int i=0; i<motes.size(); i++) {
            if( cur<=motes.at(i) ) {
                cnt = 0;
                while( cur<=motes.at(i) ) {
                    cur += cur-1;
                    crank++;
                    LOGD("(" << i << ") cur_crank = " << cur);

                    if( (++cnt)==motes.size()-i ) {
                        LOGD("It's better to remove remainees");
                        goto LOOP_OUT;
                    }
                }
            }

            cur += motes.at(i);
            LOGD("(" << i << ") cur = " << cur);
        }

LOOP_OUT:
        if( crank>motes.size() ) {
            LOGD("It's better to remove all elems");
            crank = motes.size();
        }
        cout << "Case #" << tcases-tcnt << ": " << crank << endl;
    }

    return 0;
}

