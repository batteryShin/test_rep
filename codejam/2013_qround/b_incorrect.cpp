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

const int dxdy[2][2] = { {1, -1}, {-1, 1} };

bool check_linear_positive(vector<int>::iterator first, vector<int>::iterator last) {
    while (first!=last) {
        if ( (*first)<0 ) return false;
        ++first;
    }
    return true;
}

bool check_linear_negative(vector<int>::iterator first, vector<int>::iterator last) {
    while (first!=last) {
        if ( (*first)>0 ) return false;
        ++first;
    }
    return true;
}

void deviation( int **cells, int r, int c ) {
    for(int p=1; p<r-1; p++) {
        for(int q=1; q<c-1; q++) {
            cells[p][q] = cells[p][q]*dxdy[0][0] +
                cells[p][q+1]*dxdy[0][1] +
                cells[p+1][q]*dxdy[1][0] +
                cells[p+1][q+1]*dxdy[1][1];
        }
    }

    for(int p=0; p<r; p++) {
        cells[p][0] = 0;
        cells[p][c-1] = 0;
    }
    for(int p=0; p<c; p++) {
        cells[0][p] = 0;
        cells[r-1][p] = 0;
    }
}

int main()
{
    int tcases;
    cin >> tcases;
    cin.ignore();

    bool res = true;
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

        deviation( cells, n, m );
        for(int i=0; i<n; i++) {
            LOGD_INL( "cells[" << i << "] = " );
            for(int j=0; j<m; j++) {
                LOGD_INL( cells[i][j] << " " );
            }
            LOGD_INL( endl );
        }

        vector<int> v;
        // check for rows
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                v.push_back( cells[i][j] );
            }

            res = check_linear_positive(v.begin(), v.end()) ||
                check_linear_negative(v.begin(), v.end());
            LOGD("cells rows [" << i << "] = " << res); 

            v.clear();
            if( !res ) {
                break;
            }
        }

        // check for cols
        for(int j=0; j<m; j++) {
            for(int i=0; i<n; i++) {
                v.push_back( cells[i][j] );
            }

            res = check_linear_positive(v.begin(), v.end()) ||
                check_linear_negative(v.begin(), v.end());
            LOGD("cells cols [" << j << "] = " << res); 

            v.clear();
            if( !res ) {
                break;
            }
        }


        for(int i=0; i<n; i++) {
            delete [] cells[i];
        }
        delete [] cells;

        cout << "Case #" << t << ": " << (res?"YES":"NO") << endl;
    }

}

