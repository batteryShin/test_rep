#include <cstdlib>
#include <cstdio>
#include <iostream>

#include <vector>
#include <algorithm>

#include <sys/time.h>
#include <unistd.h>

//#define SMALL 1
#define LARGE 1

using namespace std;

class DataItem {
public:
    DataItem(int lhs, int rhs):ord(lhs),val(rhs) {}
    ~DataItem() {}


    int ord;
    int val;
};


bool cmp_asc(const DataItem& ref, const DataItem& cmp) { return (ref.val < cmp.val); }
bool cmp_desc(const DataItem& ref, const DataItem& cmp) { return (ref.val > cmp.val); }


int main()
{
    struct timeval tstart, tend;
    gettimeofday(&tstart, NULL);

    int n, credit, items;
    vector<DataItem> vin;

#if SMALL
    freopen("A-small.in", "rt", stdin);
    freopen("A-small.out", "wt", stdout);
#elif LARGE
    freopen("A-large.in", "rt", stdin);
    freopen("A-large.out", "wt", stdout);
#endif

    cin >> n;

    for(int i=0; i<n; i++) {
        vin.clear();
        cin >> credit;
        cin >> items;

        for(int j=0; j<items; j++) {
            DataItem *item = new DataItem(j+1,0);
            cin >> item->val;
            vin.push_back( *item );
        }

        sort(vin.begin(), vin.end(), cmp_asc);
        printf("sort complete... %d items are sorted\n", items);

        for(int j=0; j<items; j++) {
            int sum, k=j+1;
            int first, secnd;
            while( (k<vin.size()) && ((sum=vin[j].val+vin[k].val) < credit) ) {
//                printf("credit=%d, sum=%d, j=%d, k=%d\n", credit, sum, j, k);
                k++;
            }
            
            if(sum==credit) {
                if(vin[j].ord > vin[k].ord) {
                    first=vin[k].ord;
                    secnd=vin[j].ord;
                } else {
                    first=vin[j].ord;
                    secnd=vin[k].ord; 
                }
                cout << "Case #" << i+1 << " :  " << first << " " << secnd << endl;
                break;
            }
        }
    }

    
    gettimeofday(&tend, NULL);
    unsigned long long elapsed_time = (tend.tv_sec-tstart.tv_sec)*1000000 + (tend.tv_usec-tstart.tv_usec);
    printf("Algorithm elapsed time is...%llu\n", elapsed_time);

    fclose(stdin);
    fclose(stdout);

    return elapsed_time;
}


