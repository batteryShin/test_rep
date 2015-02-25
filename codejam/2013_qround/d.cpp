#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <iomanip>

#include <string>
#include <cstring>

#include <list>
#include <vector>
#include <map>
#include <unordered_map>

#include <algorithm>
#include <limits.h>
#include <math.h>
#include <cfloat>

#include <assert.h>
#include <unistd.h>

#define CODE_DEBUG 1
#if CODE_DEBUG
#define LOGD(str) do { std::cout << "+++++ " << str << std::endl; } while( false )
#define LOGD_INL(str) do{ std::cout << str; } while( false )
#else
#define LOGD(str) do { } while ( false )
#define LOGD_INL(str) do { } while ( false )
#endif

using namespace std;

struct Chest {
    int n_room;
    int r_key;
    multimap<int,int> c_keys;
};

typedef unordered_multimap<int,Chest> RMAP;

bool room_cmp(const Chest &lhs, const Chest &rhs) {
    return (lhs.n_room<rhs.n_room);
}

bool permutation_cmp(const pair<int,int> &lhs, const pair<int,int> &rhs) {
    return (lhs.first<rhs.first);
}


void check_lexicographical( multimap<int,int> &keys, RMAP &chests, list<pair<int,int> > &res ) {
    list<pair<int,int> >::iterator it;
    multimap<int,int>::iterator itt;
    multimap<int,int>::iterator ittt;
    RMAP::iterator itc;

    bool next_flag;
    multimap<int,int> keyscpy;

    do {
        keyscpy.clear();
        keyscpy = keys;

        next_flag = false;
        for(it=res.begin(); it!=res.end(); it++) {
            if( (itt=keyscpy.find(it->second))!=keyscpy.end() ) {
                itc = chests.find(it->first);
                for(ittt=itc->second.c_keys.begin(); ittt!=itc->second.c_keys.end(); ittt++) {
                    keyscpy.insert(*ittt);
                }
                keyscpy.erase(itt);

                LOGD_INL("+++++ keys[] = ");
                for(itt=keyscpy.begin(); itt!=keyscpy.end(); itt++) {
                    LOGD_INL(itt->first << " ");
                }
                LOGD_INL(endl);
            } else {
                next_flag = true;
                break;
            }
        }
        
        if(!next_flag) {
            break;
        }

        LOGD_INL("+++++ res[] = ");
        for(it=res.begin(); it!=res.end(); it++) {
            LOGD_INL(it->first << " ");
        }
        LOGD_INL("(" << next_flag << ")" << endl);

    } while( next_permutation(res.begin(),res.end(),permutation_cmp) );

    if( next_flag ) {
        res.clear();
        res.push_back(pair<int,int>(0,0));
    }
}

int get_separated_line(istream &is, char *sep, vector<string> &v) {
    string str;
    char *w, *pw;
    int n_w = 0;

    getline(is, str);

    w = new char[str.size()+1];
    strcpy(w, str.c_str());

    pw = strtok(w, sep);
    while(pw!=NULL) {
        v.push_back( string(pw) );
        pw = strtok(NULL, sep);
        n_w++;
    }

    delete [] w;

    return n_w;
}

int main()
{
    int tcases;
    int k, n;

    multimap<int,int> keys;
    int key, key_needed;

    RMAP chests;
    RMAP::iterator it;
    Chest chest;
    multimap<int,int>::iterator itt;

    vector<string> vstr;
    char cseps[3] = { ' ', '\r', '\n' };

    list<pair<int,int> > res;
    list<pair<int,int> >::iterator ittt;

    cin >> tcases;
    cin.ignore();
    for(int t=1; t<=tcases; t++) {
        cin >> k >> n;
        cin.ignore();

        for(int i=0; i<k; i++) {
            cin >> key;
            keys.insert(pair<int,int>(key,key));
        }
        cin.ignore();

        for(int i=0; i<n; i++) {
            get_separated_line(cin, cseps, vstr);

            key_needed = (int)strtol(vstr.front().c_str(),NULL,10);
            chest.n_room = i+1;
            chest.r_key = key_needed;
            res.push_back(pair<int,int>(i+1,key_needed));

            it = chests.insert( pair<int,Chest>(i+1,chest) );
            vstr.erase(vstr.begin());

            while( !vstr.empty() ) {
                if( strcmp(vstr.front().c_str(),"0") ) {
                    key = (int)strtol(vstr.front().c_str(),NULL,10);
                    it->second.c_keys.insert(pair<int,int>(key,key));
                }
                
                vstr.erase(vstr.begin());
            }

            LOGD_INL("+++++ chest[" << i+1 << "] : " << it->first << " / ");
            if( !(it->second.c_keys.empty()) ) {
                LOGD_INL( (itt=it->second.c_keys.begin())->second );
                itt++;
                for(;itt!=it->second.c_keys.end(); itt++) {
                    LOGD_INL("," << itt->second);
                }
            }
            LOGD_INL(endl);
        }

        check_lexicographical( keys, chests, res );

        cout << "Case #" << t << ": ";
        if( (ittt=res.begin())->first ) {
            cout << ittt->first;
            for(;ittt!=res.end();ittt++) {
                cout << " " << ittt->first;
            }
            cout << endl;
        } else {
            cout << "IMPOSSIBLE" << endl;
        }

        // initialization for next case
        for(it=chests.begin(); it!=chests.end(); it++) {
            it->second.c_keys.clear();
        }
        chests.clear();
        keys.clear();
        res.clear();
    }
}

