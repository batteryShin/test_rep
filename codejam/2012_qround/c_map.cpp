#include <cstdlib>
#include <cstdio>
#include <iostream>

#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
#include <limits>
#include <cmath>

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

    int min;
    char str_min[8];

    int max;
    char str_max[8];

//    vector<int> vcnted;
    map<int,int> cntmap;
    map<int,int>::iterator it;
    pair<map<int,int>::iterator,bool> ret;
    int cnt;

    int str_sz;
    char str[8];

    int skip_flag, skip_inner_flag;
    char skip_str[8];

    for(int i=0; i<ncases; i++) {
        cin >> min;
        cin >> max;
        
        memset(str_min, 0, sizeof(char)*8);
        sprintf(str_min, "%d", min);

        memset(str_max, 0, sizeof(char)*8);
        sprintf(str_max, "%d", max);

        cnt = 0;
//        vcnted.clear();

        for(int j=min; j<=max; j++) {
//            skip_flag = 0;
//            for(int k=0; k<vcnted.size(); k++) {
//                if( vcnted[k]==j ) {
//                    vcnted.erase( vcnted.begin()+k );
//                    skip_flag = 1;
//                    break;
//                }
//            }
//            if( skip_flag ) {
//                cout << "$$$$ skip to check = " << j << endl;
//                continue;
//            }

            memset( str, 0, sizeof(char)*8 );
            sprintf(str, "%d", j);

            str_sz = (int)(log10(j)) + 1;
            skip_flag = 1;
            for(int k=0; k<str_sz-1; k++) {
                if(str[k]!=str[k+1]) {
                    skip_flag = 0;
                    break;
                }
            }
            if( skip_flag ) {
//                cout << "#### skip to check = " << j << endl;
                continue;
            }
            
            for(int k=1; k<str_sz; k++) {
                if( str[k]<str_min[0] || str[k]>str_max[0] ) {
                    continue;
                }

                if( str[k]==str_min[0] ) {
                    for(int l=0; l<str_sz; l++) {
                        if( str[(k+l)%(str_sz)]>str_min[l] ) {
                            skip_inner_flag = 0;
                            break;
                        } else if( str[(k+l)%(str_sz)]<str_min[l] ) {
                            skip_inner_flag = 1;
                            break;
                        }
                    }

                    if( skip_inner_flag )   continue;
                }

                if( str[k]==str_max[0] ) {
                    skip_inner_flag = 0;
                    for(int l=0; l<str_sz; l++) {
                        if( str[(k+l)%(str_sz)]<str_max[l] ) {
                            skip_inner_flag = 0;
                            break;
                        } else if( str[(k+l)%(str_sz)]>str_max[l] ) {
                            skip_inner_flag = 1;
                            break;
                        }
                    }

                    if( skip_inner_flag )   continue;
                }

                memset(skip_str, 0, sizeof(char)*8);
                int idx=0;
                for(int l=k; l<str_sz; l++) {
                    skip_str[idx++] = str[l];
                }
                for(int l=0; l<k; l++) {
                    skip_str[idx++] = str[l];
                }
                skip_str[idx] = str[str_sz+1];
                
//                vcnted.push_back(idx=atoi(skip_str));
                int key, val;
                if( (key=atoi(str)) < (val=atoi(skip_str)) ) {
//                    cout << str << "," << skip_str << endl;
                    cntmap.insert( pair<int,int>(key,val) );
                }
            }

        }

        cout << "Case #" << i+1 << ": " << cntmap.size() << endl; 
    }
    
    return 0;
}

