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

#define U_STATE  (0)   // unknown
#define T_STATE  (-1)   // truthtown
#define L_STATE  (-2)   // liarville

#define S_STATE     (-4)    // same state (for Statement class)
#define D_STATE     (-8)   // different state (for Statement class)

#define FROM_TA     (1)
#define FROM_PA     (2)


typedef unsigned long long int ULINT;

using namespace std;

class Statement {
public:
    Statement() {}
    ~Statement() {}

    Statement operator=(Statement& ins) {
        this.talker = ins.talker;
        this.state = ins.state;
        this.lhs = ins.lhs;
        this.rhs = ins.rhs;
    }

    int talker;
    int state;
    int lhs;
    int rhs;
};

bool cmp_asc(const int& ref, const int& cmp) { return (ref < cmp); }
bool cmp_desc(const int& ref, const int& cmp) { return (ref > cmp); }

bool cmp_talker_asc(const Statement& ref, const Statement& cmp) { return (ref.talker < cmp.talker); }
bool cmp_lhs_asc(const Statement& ref, const Statement& cmp) { return (ref.lhs < cmp.lhs); }
bool cmp_rhs_asc(const Statement& ref, const Statement& cmp) { return (ref.rhs < cmp.rhs); }

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

    int nnum, mnum;
    ULINT si_elem;

    string str;
    char* pstr;
    Statement s;

    vector<Statement> slist;

    for(int i=0; i<ncases; i++) {
        cin >> nnum;
        cin >> mnum;

        // for the result & buffer array --> -1:Liarville, 0:Truthtown
        int *pa = new int[nnum];
        int *truth = new int[nnum];

        for(int j=0; j<mnum; j++) {
            s = new Statement();
            cin >> s.talker;
            cin >> s.state;

            cin >> s.lhs;

            if( s.state==S_STATE || s.state==D_STATE )  cin >> s.rhs;

            slist.push_back(s);
        }

        sort(slist.begin(), slist.end(), cmp_talker_asc);


        // loop while there's no change in truth_remain(ta or pa).
        // or else, we prove all of them
        int prev_remain = nnum * 2;
        int truth_remain = nnum * 2;
        while( truth_remain ) {
            truth_remain = apply_statements(nnum, slist, truth, pa);

            if(prev_remain==truth_remain) {
                break;
            }
            else {
                prev_remain = truth_remain;
            }
        }

        cout << "Case #" << i+1 << ": " << truth[0];
        for(int j=1; j<nnum; j++)   cout << " " << truth[j];
        cout << endl;

        delete [] pa;
        delete [] truth;
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

int apply_statements( int nnum, vector<Statement>& vin, int* tr, int* pa) {
    int idx=0;
    int *tmp_arr = new int[nnum];
    int *origin_arr = new int[nnum];
    memset(tmp_arr, 0, sizeof(int)*nnum);
    memset(origin_arr, 0, sizeof(int)*nnum);
    
    // to skip after find 1st item of target number and it is changed..(cuz, it's sorted)
    int front = vin[0].talker;
    for(int i=front; i<=nnum; i++) {
        // copy truth_arr[] or pa_arr[],
        // and make origin_arr[] to check where the each elem came from.
        for(int j=0; j<nnum; j++) {
            if( tr[j] ) {
                tmp_arr[j] = tr[j];
                origin_arr[j] = FROM_TA;
            } else if ( pa[j] ) {
                tmp_arr[j] = pa[j];
                origin_arr[j] = FROM_PA;
            }
        }

        while( vin[idx].talker==i ) {
            switch(vin[idx].state) {
                case T_STATE:
                    conflict_chk(tmp_arr, ta, pa, origin, vin[idx].lhs, T_STATE, i);
                    break;
                case L_STATE:
                    conflict_chk(tmp_arr, ta, pa, origin, vin[idx].lhs, L_STATE, i);
                    break;
                case S_STATE:
                    conflict_chk(tmp_arr, ta, pa, origin, vin[idx].lhs, vin[idx].rhs, S_STATE, i);
                    break;
                case D_STATE:
                    conflict_chk(tmp_arr, ta, pa, origin, vin[idx].lhs, vin[idx].rhs, D_STATE, i);
                    break;
            }

            idx++;
        }
    }

    delete [] tmp_arr;
    delete [] origin_arr;

    // return how many people we checked.
    int res = 0;
    for(int i=0; i<nnum; i++) {
        if(ta[nnum])    res++;
        if(pa[nnum])    res++;
    }

    return res;
}

void conflict_chk(int *arr, int *ta, int *pa, int *ori, int t_idx, int chk_state, int talker) {
    if( !arr[t_idx] ) {
        arr[t_idx] = chk_state;
    } else if( arr[t_idx] != chk_state ) {
        if( ori[t_idx]==FROM_TA ) {
            ta[talker] = L_STATE;
            arr[talker] = L_STATE;
            ori[talker] = FROM_TA;
        } else if( ori[t_idx]==FROM_PA ) {
            pa[talker] = L_STATE;
            arr[talker] = L_STATE;
            ori[talker] = FROM_PA;
        }
    }
}

void conflict_chk(int *arr, int *ta, int *pa, int *ori, int l_idx, int r_idx, int chk_state, int talker) {

    switch(chk_state) {
        case S_STATE:
            if( !arr[l_idx] && !arr[r_idx] ) {
                arr[l_idx] = 1;
                arr[r_idx] = 1;
            } else if( !arr[l_idx] && arr[r_idx] ) {
                arr[l_idx] =  arr[r_idx];
            } else if( arr[l_idx] && !arr[r_idx] ) {
                arr[r_idx] = arr[l_idx];
            } else if( arr[l_idx] && arr[r_idx] ) {
                if( arr[l_idx]!=arr[r_idx] ) {
                    if( ori[l_idx]==FROM_TA ) {
                        ta[talker] = L_STATE;
                        arr[talker] = L_STATE;
                        ori[talker] = FROM_TA;
                    } else if( ori[r_idx]==FROM_TA ) {
                        ta[talker] = L_STATE;
                        arr[talker] = L_STATE;
                        ori[talker] = FROM_TA;
                    }
                    
                    if( ori[l_idx]==FROM_PA ) {
                        pa[talker] = L_STATE;
                        arr[talker] = L_STATE;
                        ori[talker] = FROM_PA;
                    } else if( ori[r_idx]==FROM_PA ) {
                        pa[talker] = L_STATE;
                        arr[talker] = L_STATE;
                        ori[talker] = FROM_PA;
                    }
                }
            }
            break;
        case D_STATE:
            if( !arr[l_idx] && !arr[r_idx] ) {
                arr[l_idx] = 1;
                arr[r_idx] = 2;
            } else if( !arr[l_idx] && arr[r_idx] ) {
                arr[l_idx] = (arr[r_idx]>1) ? arr[r_idx]-1 : 2;
            } else if( arr[l_idx] && !arr[r_idx] ) {
                arr[r_idx] = (arr[l_idx]>1) ? arr[l_idx]-1 : 2;
            } else if( arr[l_idx] && arr[r_idx] ) {
                if( arr[l_idx]==arr[r_idx] ) {
                    if( ori[l_idx]==FROM_TA ) {
                        ta[talker] = L_STATE;
                        arr[talker] = L_STATE;
                        ori[talker] = FROM_TA;
                    } else if( ori[r_idx]==FROM_TA ) {
                        ta[talker] = L_STATE;
                        arr[talker] = L_STATE;
                        ori[talker] = FROM_TA;
                    }
                    
                    if( ori[l_idx]==FROM_PA ) {
                        pa[talker] = L_STATE;
                        arr[talker] = L_STATE;
                        ori[talker] = FROM_PA;
                    } else if( ori[r_idx]==FROM_PA ) {
                        pa[talker] = L_STATE;
                        arr[talker] = L_STATE;
                        ori[talker] = FROM_PA;
                    }
                }
            }
            break;
    }

}

