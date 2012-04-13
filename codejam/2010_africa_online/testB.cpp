#include <cstdlib>
#include <cstdio>
#include <iostream>

#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

#include <sys/time.h>
#include <unistd.h>

//#define RELEASE_VEC(v)  

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

    int tnum, office, epnum;
    int home, d_cap;

    for(int i=0; i<ncases; i++) {
        cin >> tnum;
        cin >> office;
        cin >> epnum;

        vector<int>* vin = new vector<int>[tnum];
        int* nvs = new int[tnum];
        memset(nvs, 0, sizeof(int)*tnum);
        
        for(int j=0; j<epnum; j++) {
            cin >> home;
            cin >> d_cap;
            vin[home-1].push_back( d_cap );
        }
//        printf("vector elem - %d towns, %d office\n", tnum, office);
//        for(int j=0; j<tnum; j++) printf("%d town - %d people\n", j+1, vin[j].size());

        int k, sum;
        for(int j=0; j<tnum; j++) {
            if( vin[j].empty() || (j+1==office) )  continue;

            sort(vin[j].begin(), vin[j].end(), cmp_desc);

//            printf("sorted vector elems at %d - ", j+1);
//            for(int jj=0; jj<vin[j].size(); jj++) printf("%d ", vin[j][jj]);
//            printf("\n");

            k=0;
            sum=0;
            while( k<vin[j].size() ) {
                if( k+1 >= vin[j].size() ) {
                    k=-1;
//                    printf("impossible case happened!!!\n");
                    goto IMPOSSIBLE;
                }
                sum += vin[j][k];

                if( sum >= vin[j].size() ) {
                    nvs[j] = k+1;
                    break;
                }
                k++;
            }
        }

IMPOSSIBLE:
        if( k==-1 ) {
            cout << "Case #" << i+1 << ": " << "IMPOSSIBLE" << endl;
        } else {
            cout << "Case #" << i+1 << ": ";
            for(int j=0; j<tnum; j++) {
                cout << nvs[j] << " ";
            }
            cout << endl;
        }

        for(int j=0; j<tnum; j++)  vin[j].clear();

        delete [] vin;
        delete [] nvs;
    }
    
    /*  framework to solve problems - START   */
    gettimeofday(&tend, NULL);
    unsigned long long elapsed_time = (tend.tv_sec-tstart.tv_sec)*1000000 + (tend.tv_usec-tstart.tv_usec);
    printf("Algorithm elapsed time is...%llu usec\n", elapsed_time);

    return 0;
    /*  framework to solve problems - END   */
}


