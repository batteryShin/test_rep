#include <cstdlib>
#include <cstdio>
#include <iostream>

#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <limits>

#include <sys/time.h>
#include <unistd.h>

//#define RELEASE_VEC(v)  

#define USE_PIPE_IO 1
#define USE_TIME_CMD 1

typedef unsigned long long int ULINT;

using namespace std;

bool cmp_asc(const int& ref, const int& cmp) { return (ref < cmp); }
bool cmp_desc(const int& ref, const int& cmp) { return (ref > cmp); }



int main()
{
    /*  framework to solve problems - START   */
#if !USE_TIME_CMD
    struct timeval tstart, tend;
    gettimeofday(&tstart, NULL);
#endif

#if !USE_PIPE_IO
    freopen("A-large-practice.in", "rt", stdin);
    freopen("A-large-practice.out", "wt", stdout);
#endif
    int ncases;
    cin >> ncases;
    cin.ignore();
    /*  framework to solve problems - END   */

    int pnum, cnum;
    ULINT si_elem;

    for(int i=0; i<ncases; i++) {
        cin >> pnum;
        cin >> cnum;

        ULINT max_pass = 0;
        ULINT sum = 0;
        ULINT minnum = numeric_limits<ULINT>::max();
        for(int j=0; j<pnum; j++) {
            cin >> si_elem;
        
            sum += si_elem;
            if( si_elem<minnum ) {
                minnum = si_elem;
            }
        }

        if(cnum==pnum) {
            max_pass = minnum;
        } else if(cnum==1) {
            max_pass = sum;
        } else {
            max_pass = sum / cnum;
        }

        cout << "Case #" << i+1 << ": " << max_pass << endl;
    }
    
    /*  framework to solve problems - START   */
#if !USE_TIME_CMD
    gettimeofday(&tend, NULL);
    unsigned long long elapsed_time = (tend.tv_sec-tstart.tv_sec)*1000000 + (tend.tv_usec-tstart.tv_usec);
    printf("Algorithm elapsed time is...%llu usec\n", elapsed_time);
#endif

    return 0;
    /*  framework to solve problems - END   */
}


