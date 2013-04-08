#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <iomanip>

#include <string>
#include <cstring>

#include <list>
#include <vector>
#include <map>
#include <algorithm>

#include <cmath>
#include <limits>

using namespace std;

struct Stage {
    int one_st;
    int two_st;
};

bool cmp_stgs_asc(const Stage& ref, const Stage& cmp) {
    bool res;

    if(ref.two_st < cmp.two_st) {
        res = true;
    } else if(ref.two_st == cmp.two_st) {
        if( ref.one_st < cmp.one_st ) {
            res = true;
        } else {
            res = false;
        }
    } else {
        res = false;
    }

    return res;
}

int main()
{
    int ncs;
    cin >> ncs;
    cin.ignore();

    int cur_st;
    int nstgs;
    int niter;
    Stage stg;
    vector<Stage> stgs;
    vector<Stage>::iterator it;
    bool f_imps;

    for(int i=0; i<ncs; i++) {
        cin >> nstgs;

        stgs.clear();
        for(int j=0; j<nstgs; j++) {
            cin >> stg.one_st;
            cin >> stg.two_st;
            stgs.push_back(stg);
        }

        sort(stgs.begin(), stgs.end(), cmp_stgs_asc);

        f_imps = false;
        niter = 0;
        cur_st = 0;
        for(it=stgs.begin(); it<stgs.end(); it++) {

            while(true) {
                niter++;
                if( cur_st >= it->two_st ) {
                    cur_st += 2;
                    break;
                } else if(cur_st >= it->one_st ) {
                    cur_st += 1;
                } else {
                    f_imps = true;
                    break;
                }
            }

            if( f_imps ) {
                break;
            }
        }

        cout << "Case #" << i+1 << ": ";
        if(f_imps) {
            cout << "Too Bad" << endl; 
        } else {
            cout << niter << endl; 
        }
    }
    
    return 0;
}

