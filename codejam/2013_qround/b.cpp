#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <iomanip>

#include <string>
#include <cstring>
#include <vector>
#include <map>
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
bool cmp_sec_desc(const pair<int,int> &lhs, const pair<int,int> &rhs) {
    return (lhs.second<rhs.second);
}

bool check_rows(int **cells, int r, int c) {
    bool res = true;
    pair<int,int> max_val;

    vector<pair<int,int> > v;
    // check for rows
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            v.push_back( pair<int,int>(j,cells[i][j]) );
        }

        max_val = *max_element(v.begin(), v.end(), cmp_sec_desc);
        sort(v.begin(), v.end(), cmp_sec_desc);

        for(int j=0; j<c; j++) {
            if( max_val.second==v.at(j).second ) {
                break;
            }
           
            for(int k=0; k<r; k++) {
                if( cells[k][v.at(j).first] > v.at(j).second ) {
                    res = false;
                    break;
                }
            }

            if( !res ) {
                break;
            }
        }
        v.clear();
    }

    return res;
}


bool check_cols(int **cells, int r, int c) {
    bool res = true;
    pair<int,int> max_val;

    vector<pair<int,int> > v;
    // check for cols
    for(int j=0; j<c; j++) {
        for(int i=0; i<r; i++) {
            v.push_back( pair<int,int>(i,cells[i][j]) );
        }

        max_val = *max_element(v.begin(), v.end(), cmp_sec_desc);
        sort(v.begin(), v.end(), cmp_sec_desc);

        for(int i=0; i<r; i++) {
            if( max_val.second==v.at(i).second ) {
                break;
            }
           
            for(int k=0; k<c; k++) {
                if( cells[v.at(i).first][k] > v.at(i).second ) {
                    res = false;
                    break;
                }
            }

            if( !res ) {
                break;
            }
        }
        v.clear();
    }

    return res;
}

int main()
{
    int tcases;
    cin >> tcases;
    cin.ignore();

    bool res;
    int n, m;
    int **cells;
    for(int t=1; t<=tcases; t++) {
        cin >> n >> m;
        cin.ignore();

        cells = new int*[n];
        for(int i=0; i<n; i++) {
            cells[i] = new int[m];

            for(int j=0; j<m; j++) {
                cin >> cells[i][j];
            }
            cin.ignore();
        }

        res = (check_rows(cells,n,m) || check_cols(cells,n,m));

        for(int i=0; i<n; i++) {
            delete [] cells[i];
        }
        delete [] cells;

        cout << "Case #" << t << ": " << (res?"YES":"NO") << endl;
    }

}

