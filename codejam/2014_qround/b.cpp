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

using namespace std;

double make_farm(double c, double f, int steps) {
    double res = 0;
    for(int i=0; i<steps; i++) {
        res += c/(2+(i*f));
    }

    return res;
}

int main()
{
    int tcases;
    cin >> tcases;
    cin.ignore();

    double c, f, x;
    int cur_step;
    double prev_comp, next_comp;

    for(int t=1; t<=tcases; t++) {
        cin >> c >> f >> x;

        cur_step = 1;
        prev_comp = x/2;
        next_comp = c/2 + x/(2+f);
        while( prev_comp>next_comp ) {
            cur_step += 1;
            prev_comp = next_comp;
            next_comp = make_farm(c,f,cur_step) + x/(2+(cur_step*f));
        }

        cout << "Case #" << t << ": ";
        cout << fixed;
        cout.precision(7);
        cout <<prev_comp << endl;
    }

}

