#include <cstdlib>
#include <cstdio>
#include <iostream>

#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

#include <sys/time.h>
#include <unistd.h>

#define USE_PIPE_IO 1
typedef unsigned int UINT;

using namespace std;

bool cmp_asc(const int& ref, const int& cmp) { return (ref < cmp); }
bool cmp_desc(const int& ref, const int& cmp) { return (ref > cmp); }

int main()
{
    /*  framework to solve problems - START   */
    struct timeval tstart, tend;
    gettimeofday(&tstart, NULL);

#if !USE_PIPE_IO
    freopen("A-large-practice.in", "rt", stdin);
    freopen("A-large-practice.out", "wt", stdout);
#endif
    int ncases;
    cin >> ncases;
    cin.ignore();
    /*  framework to solve problems - END   */

    int gnum;
    UINT velem;
    vector<UINT> vin;

    for(int i=0; i<ncases; i++) {
        vin.clear();
        cin >> gnum;
        
        for(int j=0; j<gnum; j++) {
            cin >> velem;
            vin.push_back(velem);
        }

        sort(vin.begin(), vin.end(), cmp_asc);

        int k=0;
        while( vin[k]==vin[k+1] ) {
            k=k+2;
        }
        cout << "Case #" << i+1 << ": " << vin[k] << endl;
    }
    
    /*  framework to solve problems - START   */
    gettimeofday(&tend, NULL);
    unsigned long long elapsed_time = (tend.tv_sec-tstart.tv_sec)*1000000 + (tend.tv_usec-tstart.tv_usec);
    printf("Algorithm elapsed time is...%llu usec\n", elapsed_time);

    return 0;
    /*  framework to solve problems - END   */
}


