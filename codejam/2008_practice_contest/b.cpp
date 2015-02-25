#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <iomanip>

#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <set>
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

struct classcmp {
    bool operator() (const pair<int,int> &lhs, const pair<int,int> &rhs) const {
        return (sqrt(pow(lhs.first,2)+pow(lhs.second,2)) < 
                sqrt(pow(rhs.first,2)+pow(rhs.second,2)) );
    }
} cmpobj;

bool compare_sets( set<pair<int,int> > *lhs, set<pair<int,int> > *rhs) {

}

void compute_kmeans( set<pair<int,int>,classcmp> *s, int nelems, int kclusters ) {
    // TODO: need to consider if (nelem<=kcluster) cases
    //       in this problem does not occur that kind of cases.
       
    set<pair<int,int>,classcmp>::iterator it;
    set<pair<int,int>,classcmp>::iterator itt;
    pair<double,double> *kmean;
    kmean = new pair<double,double>[kclusters];

    // initially all elements are in the s[0]
    set<pair<int,int>,classcmp> sor;
    set<pair<int,int>,classcmp> *scpy = new set<pair<int,int>,classcmp>[kclusters];
    set<pair<int,int>,classcmp> *scmp = new set<pair<int,int>,classcmp>[kclusters];
    sr = scpy[0] = scmp[0] = s[0];
    s.clear();

    it = scpy[0].begin();
    for(int i=0; i<kclusters; i++) {
        kmean[i] = it;
        scpy[i].insert(it);
        itt = it;
        itt++;
        scpy[0].erase(it);
        it = itt;
    }


    while( !compare_sets(scpy,scmp) ) {
        // for comparison (exit condition)
        for(int i=0; i<kclusters; i++) {
            scmp[i] = scpy[i];
        }

        // assignment step
        vector<pair<int,int> > *vtmp;
        vtmp = new vector<pair<int,int> >[nelems];
        for(int i=0; i<sor.size(); i++) {
            for(int j=0; j<kclusters; j++) {
                vtmp[i].push_back( pair<int,int>(abs(sor[i].first-kmean[j].first),abs(sor[i].second-kmean[j].second)) );
            }

            // ---TODO: vector doesn't have find api
            // (need to do additional implementation to check where is the minimum distance element)
            vtmp[i].find( min_element(vtmp[i].begin(),vtmp[i].end(),cmpobj) );
        }
        assign_cluster( kmean, k, scpy );

        // updating mean step
        for(int i=0; i<kclusters; i++) {
            sum_x = sum_y = 0;
            for(int j=0; j<scpy[i].size(); j++) {
                sum_x += scpy[i][j].first;
                sum_y += scpy[i][j].second;
            }
            kmean[i].first = sum_x / scpy[i].size();
            kmean[i].second = sum_y / scpy[i].size();
        }
    }

    delete [] kmean;
}

int main()
{
    int tcases;
    cin >> tcases;
    cin.ignore();

    int res;

    set<pair<int,int>,classcmp> *s;
    pair<int,int> pa;

    int n, k;
    for(int t=1; t<=tcases; t++) {
        cin >> n >> k;
        cin.ignore();

        s = new set< pair<int,int> >[k];
        for(int i=0; i<n; i++) {
            cin >> pa.first >> pa.second;
            cin.ignore();
            s[0].insert( pa );
        }

        compute_kmeans( s, n, k );
        res = max( max(abs(s[0].begin.first-s[0].end.first),abs(s[0].begin.second-s[0].end.second)),
                    max(abs(s[k-1].begin.first-s[k-1].end.first),abs(s[k-1].begin.second-s[k-1].end.second)) );

        cout << "Case #" << t << ": " << res << endl;

        for(int i=0; i<k; i++) {
            s[i].clear();
        }
        delete [] s;
    }
}

