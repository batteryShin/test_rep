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

#define CH_A    1
#define CH_S    (CH_A<<1)
#define CH_D    (CH_A<<2) 
#define CH_F    (CH_A<<3) 
#define CH_Q    (CH_A<<4) 
#define CH_W    (CH_A<<5) 
#define CH_E    (CH_A<<6) 
#define CH_R    (CH_A<<7) 

using namespace std;

typedef unsigned long long int ULINT;


bool cmp_asc(const int& ref, const int& cmp) { return (ref < cmp); }
bool cmp_desc(const int& ref, const int& cmp) { return (ref > cmp); }

int main()
{
    int ncases;
    cin >> ncases;
    cin.ignore();

    int cnum, dnum, nnum;
    char (*mlist)[3];
    char (*clist)[3];
    char *strin;
    vector<char> strout;

    vector<char> ccand;
    
    for(int i=0; i<ncases; i++) {
        cin >> cnum;

        if(cnum)  mlist = new char[cnum][3];
        for(int j=0; j<cnum; j++) {
            cin >> mlist[j];
//            cout << "merge_list : " << j+1 << " -> " << mlist[j] << endl;
        }

        cin >> dnum;
        if(dnum)    clist = new char[dnum][3];
        for(int j=0; j<dnum; j++) {
            cin >> clist[j];
//            cout << "clear_list : " << j+1 << " -> " << clist[j] << endl;
        }

        cin >> nnum;    strin = new char[nnum];
        if( nnum ) {
            cin >> strin;
//            cout << "str_in : " << strin << endl;
        }

        int j=0;
        while(j<nnum) {
            for(int k=0; k<cnum; k++) {
                if(strin[j] == mlist[k][0]) { 
                    if( !strout.empty() && strout.back()==mlist[k][1] ) {
                        strout.pop_back();
                        strout.push_back(mlist[k][2]);
                        goto NEXT_STR;
                    }
                } else if(strin[j]==mlist[k][1]) {
                    if( !strout.empty() && strout.back()==mlist[k][0] ) {
                        strout.pop_back();
                        strout.push_back(mlist[k][2]);
                        goto NEXT_STR;
                    }
                }
            }

            for(int k=0; k<dnum; k++) {
                if(strin[j]==clist[k][0]) {
                    for(int iter=ccand.size()-1; iter>=0; iter--) {
                        if( ccand[iter]==clist[k][1] ) {
                            strout.clear();
                            goto NEXT_STR;
                        }
                    }
                    ccand.push_back(clist[k][0]);

                } else if(strin[j]==clist[k][1]) {
                    for(int iter=ccand.size()-1; iter>=0; iter--) {
                        if( ccand[iter]==clist[k][0] ) {
                            strout.clear();
                            goto NEXT_STR;
                        }
                    }
                }
                ccand.push_back(clist[k][1]);

            }
            strout.push_back(strin[j]);
NEXT_STR:
            j++;
        }


        cout << "Case #" << i+1 << ": [";
        if( !strout.empty() ) {
            cout << strout[0];
        }
        for(int iter=1; iter<strout.size(); iter++) {
            cout << ", " << strout[iter];
        }
        cout << "]" << endl; 

        ccand.clear();
        strout.clear();
        for(int j=0; j<cnum; j++)   delete [] mlist[j];
        for(int j=0; j<dnum; j++)   delete [] clist[j];
        if(nnum)    delete [] strin;
    }
    
    return 0;
}
