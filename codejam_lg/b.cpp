#include <cstdlib>
#include <cstdio>
#include <iostream>

#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <limits>
#include <math.h>

#include <assert.h>
#include <unistd.h>

using namespace std;

bool cmp_asc(const int& ref, const int& cmp) { return (ref < cmp); }
bool cmp_desc(const int& ref, const int& cmp) { return (ref > cmp); }

int main()
{
    int ncases;
    cin >> ncases;
    cin.ignore();

    int nnum, snum, pnum;
    int p_sure, p_surp;
    vector<int> vscore;
    int score;
    int qnum; 
    
    for(int i=0; i<ncases; i++) {
        cin >> nnum;
        cin >> snum;
        cin >> pnum;

        if( pnum==0 ) {
            p_sure = p_surp = 0;
        } else if( pnum==1 ) {
            p_sure = p_surp = 1;
        } else {
            p_sure = pnum * 3 - 2;
            p_surp = p_sure - 2;
        }

        vscore.clear();
        qnum = 0;

        for(int j=0; j<nnum; j++) {
            cin >> score;
            vscore.push_back(score);
        }
        
        for(int j=0; j<vscore.size(); j++) {
            if(vscore[j] >= p_sure ) {
                qnum++;
            } else if( vscore[j] >= p_surp ) {
                if( snum>0 ) {
                    snum--;
                    qnum++;
                }
            }
        }

        cout << "Case #" << i+1 << ": " << qnum << endl; 
    }
    
    return 0;
}

