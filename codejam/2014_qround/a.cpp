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

int main()
{
    int tcases;
    int pre_ans;
    int pre_deck[4][4];
    int *pre_list;

    int post_ans;
    int post_deck[4][4];
    int *post_list;

    vector<int> res;

    cin >> tcases;
    cin.ignore();

    for(int t=1; t<=tcases; t++) {
        cin >> pre_ans;
        for(int i=0; i<4; i++) {
            for(int j=0; j<4; j++) { 
                cin >> pre_deck[i][j];
            }
            cin.ignore();
        }
        pre_list = pre_deck[pre_ans-1];

        cin >> post_ans;
        for(int i=0; i<4; i++) {
            for(int j=0; j<4; j++) { 
                cin >> post_deck[i][j];
            }
            cin.ignore();
        }
        post_list = post_deck[post_ans-1];

        res.clear();
        for(int i=0; i<4; i++) {
            for(int j=0; j<4; j++) {
                if( pre_list[i]==post_list[j] ) {
                    res.push_back(pre_list[i]);
                }
            }
        }

        cout << "Case #" << t << ": ";
        if( res.size()==0 ) {
            cout << "Volunteer cheated!" << endl;
        } else if( res.size()==1 ) {
            cout << res[0] << endl;
        } else {
            cout << "Bad magician!" << endl;
        }
    }
}
