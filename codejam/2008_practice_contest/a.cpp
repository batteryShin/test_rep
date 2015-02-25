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

struct Shop {
    pair<int,int> pos;
    vector< pair<string,int> > s_items;
    int rep;
    bool perishable;
};

bool cmp_asc(const Shop& ref, const Shop& cmp) { return (ref.rep < cmp.rep); }
bool cmp_desc(const Shop& ref, const Shop& cmp) { return (ref.rep > cmp.rep); }

int main()
{
    int tcases;
    cin >> tcases;
    cin.ignore();
    int nw, nb;
    string res;
    for(int t=1; t<=tcases; t++) {
        cin >> nw >> nb;
        if( nb==0 || nb%2==0 ) {
            res = "WHITE";
        } else {
            res = "BLACK";
        }

        cout << "Case #" << t << ": " << res << endl;
    }
}

