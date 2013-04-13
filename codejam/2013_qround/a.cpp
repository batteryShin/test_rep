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

int check_rows(int** cells, int r, int c) {
    int res_prev = 0;
    int res = 0;
    for(int j=0; j<c; j++) {
        if((res=cells[0][j]&cells[1][j])==0 ) {
            continue;
        } else {
            res_prev = res;
        }

        for(int i=1; i<r-1; i++) {
            if( (res=cells[i][j]&cells[i+1][j])!=res_prev ) {
                res = 0;
                break;
            }
            res_prev = res;
        }

        if( res ){
            break;
        }
    }

    return res;
}

int check_cols(int** cells, int r, int c) {
    int res_prev = 0;
    int res = 0;
    for(int i=0; i<r; i++) {
        if((res=cells[i][0]&cells[i][1])==0 ) {
            continue;
        } else {
            res_prev = res;
        }
 
        for(int j=1; j<c-1; j++) {
            if( (res=cells[i][j]&cells[i][j+1])!=res_prev ) {
                res = 0;
                break;
            }
            res_prev = res;
        }

        if( res ){
            break;
        }
    }

    return res;
}


int check_diags(int** cells, int r, int c) {
    int res_prev = 0;
    int res = 0;

    if((res=cells[0][0]&cells[1][1])!=0 ) {
        res_prev = res;
        for(int j=1; j<c-1; j++) {
            if( (res=cells[j][j]&cells[j+1][j+1])!=res_prev ) {
                res = 0;
                break;
            }
        }
    }

    if( !res ) {
        if((res=cells[0][3]&cells[1][2])==0 ) {
            goto RESULT;
        } else {
            res_prev = res;
        }
        for(int j=1; j<c-1; j++) {
            if( (res=cells[j][c-1-j]&cells[j+1][c-1-j-1])!=res_prev ) {
                res = 0;
                break;
            }
        }
    }

RESULT:    
    return res;
}

int main()
{
    int tcases;
    cin >> tcases;
    cin.ignore();

    int **cells;
    cells = new int*[4];
    for(int i=0; i<4; i++) {
        cells[i] = new int[4];
        memset(cells[i], -1, sizeof(int)*4);
    }
    
    vector<int> elems;
    string str;
    for(int t=1; t<=tcases; t++) {
        int res = 0;
        bool completed = true;

        for(int i=0; i<4; i++) {
            getline(cin,str);
            for(int j=0; j<4; j++) {
                if( str[j]=='T' ) {
                    cells[i][j] = 3;
                } else if( str[j]=='O' ) {
                    cells[i][j] = 2;
                } else if(str[j]=='X') {
                    cells[i][j] = 1;
                } else if(str[j]=='.') {
                    cells[i][j] = 0;
                    completed = false;
                }
            }
            LOGD(str);
        }
        // dummy empty line
        getline(cin,str);

        res = check_rows(cells,4,4);
        LOGD("rows res = " << res);
        if( !res ) {
            res = check_cols(cells,4,4);
            LOGD("cols res = " << res);
        }

        if( !res ) {
            res = check_diags(cells,4,4);
            LOGD("diags res = " << res);
        }

        string res_str;
        switch( res ) {
            case 0:
                res_str = completed?"Draw":"Game has not completed"; 
                break;
            case 1:
                res_str = "X won";
                break;
            case 2:
                res_str = "O won";
                break;
        }

        cout << "Case #" << t << ": " << res_str << endl;
    }

    for(int i=0; i<4; i++) {
        delete [] cells[i];
    }
    delete [] cells;
}
