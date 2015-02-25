#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <iomanip>

#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
#include <limits>
#include <math.h>

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

typedef unsigned long long ULINT;
typedef long long LLINT;

void desirable_to_malted(int n, vector<multimap<bool,int> > &mperson, vector<int> &nres) {

    for(int i=0; i<=n; i++) {
        nres.push_back(0);
    }

    vector<int> mres;
    vector<multimap<bool,int> >::iterator it;
    multimap<bool,int>::iterator itt;
    // check there's any person who likes only malted beverage
    for(it=mperson.begin(); it!=mperson.end(); it++) {
        if( it->find(false)==it->end() ) {
            itt = it->find(true);
            nres.at(itt->second) = 1;
            mres.push_back(itt->second);
        }
    }

    // check possibility
    bool p_flag = true;
    bool loop_out = false;
    pair<multimap<bool,int>::iterator,multimap<bool,int>::iterator> ret;
    for(it=mperson.begin(); it!=mperson.end(); it++) {
        for(int i=0; i<mres.size(); i++) {
            if( (itt=it->find(true))!=it->end() && itt->second==mres.at(i) ) {
                loop_out = true;
                break;
            }
        }

        if( loop_out ) {
            continue;
        }

        ret = it->equal_range(false);
        for(itt=ret.first; itt!=ret.second; itt++) {
            if( !nres.at(itt->second) ) {
                break;
            }

            p_flag = false;
        }

        if( !p_flag ) {
            nres.clear();
            break;
        }
    }

    mres.clear();
}

int main()
{
    int tcases, tcnt;

    cin >> tcases;
    cin.ignore();
    
    int n, m, t;
    int likes;
    bool malted;
    multimap<bool,int> person;
    vector<multimap<bool,int> > mperson;
    vector<int> nres;

    tcnt = tcases;
    while(tcnt-->0) {
        cin >> n >> m;

        for(int i=0; i<m; i++) {
            cin >> t;

            person.clear();
            for(int j=0; j<t; j++) {
                cin >> likes >> malted;
                person.insert(pair<bool,int>(malted,likes));
            }
            mperson.push_back(person);

            cin.ignore();
        }

        desirable_to_malted(n, mperson, nres);

        cout << "Case #" << tcases-tcnt << ": ";
        if( nres.empty() ) {
            cout << "IMPOSSIBLE" << endl;
        } else {
            cout << nres.at(1);
            for(int i=2; i<=n; i++) {
                cout << " " << nres.at(i);
            }
            cout << endl;
        }

        mperson.clear();
        nres.clear();
    }

    return 0;
}


