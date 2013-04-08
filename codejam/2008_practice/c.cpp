#include <cstdlib>
#include <cstdio>
#include <iostream>

#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <math.h>

#include <assert.h>
#include <unistd.h>

#define CODE_DEBUG 0

typedef unsigned int UINT;
typedef unsigned long long int ULINT;
static const ULINT F_LIMIT = 4294967296;

using namespace std;

bool cmp_asc(const int& ref, const int& cmp) { return (ref < cmp); }
bool cmp_desc(const int& ref, const int& cmp) { return (ref > cmp); }

typedef enum {
    NORTH = 1,
    SOUTH,
    WEST,
    EAST
} DIRS;

int log2(int val) {
    double res = (log(val)/log(2));
    return (int)(res+0.5);
}


ULINT comb_pbs(ULINT cur, ULINT base) {
    ULINT upper,under;

    // it is same if we change the selection number as (base-cur)
    if( cur>base-cur ) {
        cur = base - cur;
    }

    upper = under = 1;
    for(ULINT i=0; i<cur; i++) {
        upper *= base-i;
        under *= i+1;
        
        if( upper%under==0 ) {
            upper /= under;
            under = 1;
        }
    }
#if CODE_DEBUG
    cout << "+++++ base=" << base << ", cur=" << cur << " (" << upper << ")" << endl;
#endif

    return (upper/under);
}

ULINT sum_pbs(int drops, int breaks) {
    ULINT sum = 0;
    if( drops>=breaks ) {
        for(int i=0; i<=breaks; i++) {
            sum += comb_pbs(i, drops);
            if( sum>=F_LIMIT ) {
#if CODE_DEBUG
                cout << "+++++ overflow occured !!" << endl;
#endif
                sum = 0;
                break;
            }
        }
    } else {
        for(int i=0; i<=drops; i++) {
            sum += comb_pbs(i, drops);
            if( sum>=F_LIMIT ) {
#if CODE_DEBUG
                cout << "+++++ overflow occured !!" << endl;
#endif
                sum = 0;
                break;
            }
        }
    }

    return sum;
}

UINT find_fmax(int drops, int breaks) {
    ULINT res;

    if( res=sum_pbs(drops,breaks) ) {
        res -= 1;
    }
    
#if CODE_DEBUG
    printf("+++++ %s: res=%u\n", __func__, res);
#endif

    return (UINT)res;
}

int find_dmin(int floors, int breaks) {
    int res;
    ULINT p, cur;
    if( breaks==1 ) {
        return floors;
    }

    res = (int)(log2(floors+1) + 0.5);
    p = 1;
    for(int i=0; i<res; i++) {
        p *= 2;
    }
    while(true) {
        cur = sum_pbs(res,breaks) - 1;

#if CODE_DEBUG
        cout << "+++++ " << __func__ << ": cur=" << cur << " -> " << floors << ", (" << res << "), " << breaks << endl;
#endif
        if( floors<=cur || floors==res ) {
            break;
        }
        res++;
        p *= 2;
    }

    return res;
}

int find_bmin(int floors, int drops) {
    int res;
    ULINT cur;
    if( drops==floors ) {
        return 1;
    }

    res = 1;
    ULINT cmp_val = floors;
    while(true) {
        cur = sum_pbs(drops,res) - 1;
#if CODE_DEBUG
        cout << "+++++ " << __func__ << ": cur=" << cur << " vs " << cmp_val << " -> " << floors << ", " << drops << ", (" << res << ")" << endl;
#endif
        if( cmp_val<=cur || drops==res ) {
            break;
        }
        res++;
    }

    return res;
}

int main()
{
    int tcases;
    cin >> tcases;
    cin.ignore();

    UINT f;
    int d, b;
    UINT fmax=0;
    int dmin=0, bmin=0;

    for(int t=0; t<tcases; t++) {
        cin >> f;
        cin >> d;
        cin >> b;

        fmax = find_fmax(d,b);
        dmin = find_dmin(f,b);
        bmin = find_bmin(f,d);

        cout << "Case #" << t+1 << ": ";
        if( fmax ) {
            cout << fmax;
        } else {
            cout << "-1";
        }
        cout << " " << dmin << " " << bmin << endl;
    }
}
