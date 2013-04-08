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

bool cmp_asc(const int& ref, const int& cmp) { return (ref < cmp); }
bool cmp_desc(const int& ref, const int& cmp) { return (ref > cmp); }

int main()
{
    int ncs;
    cin >> ncs;
    cin.ignore();

    int typed, tot, b_remain;
    vector<float> pi;
    float tmp;

    vector<float> ei;
    vector<float>::iterator it;
    float min_e;
    
    for(int i=0; i<ncs; i++) {
        cin >> typed;
        cin >> tot;

        ei.clear();
        pi.clear();
        b_remain = tot-typed+1;
        min_e = 0.f;

        for(int j=0; j<typed; j++) {
            cin >> tmp;
            pi.push_back(tmp);
        }


        // case for each backspace
        float prob = 1.f;
        float exp_sum = 0.f;
        int bksp = typed;
        for(int j=0; j<typed; j++) {
            bksp = typed-j-1;
            prob *= pi[j];
            exp_sum = prob*(b_remain+2*bksp) + (1-prob)*(b_remain+2*bksp+tot+1);
            ei.push_back(exp_sum);
        }

        // case for backspace number is same as typed number
        exp_sum = b_remain+2*typed;
        ei.push_back(exp_sum);

        // case for return immediatly
        exp_sum = tot + 1 + 1;
        ei.push_back(exp_sum);

        min_e = ei[0];
        for(it=ei.begin(); it!=ei.end(); it++) {
            if( min_e > *it ) {
                min_e = *it;
            }
        }

        cout << "Case #" << i+1 << ": ";
        cout << fixed << setprecision(6) << min_e << endl; 
    }
    
    return 0;
}

