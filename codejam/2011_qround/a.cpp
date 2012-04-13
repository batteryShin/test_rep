#include <cstdlib>
#include <cstdio>
#include <iostream>

#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <limits>
#include <math.h>

#include <assert.h>
#include <unistd.h>

typedef unsigned long long int ULINT;

using namespace std;

bool cmp_asc(const int& ref, const int& cmp) { return (ref < cmp); }
bool cmp_desc(const int& ref, const int& cmp) { return (ref > cmp); }

typedef enum {ORANGE, BLUE, NONE} COLOR;

class Node {
public:
    COLOR robot;
    int btn; 
};

int main()
{
    int ncases;
    cin >> ncases;
    cin.ignore();

    int nnum;
    
    char ch;
    Node n, pn;
    int prev_o, prev_b, dist_o, dist_b;
    int dist_sum, cnt_sum, total;

    for(int i=0; i<ncases; i++) {
        cin >> nnum;

        total = dist_sum = cnt_sum = 0;
        prev_o = prev_b = 1;
        pn.robot = COLOR(NONE);
        pn.btn = 1;
        for(int j=0; j<nnum; j++) {
            cin >> ch;
            cin >> n.btn;
            
            if( ch=='O' ) {
                n.robot = COLOR(ORANGE);
                dist_o = abs(prev_o - n.btn);
                prev_o = n.btn;

                if( pn.robot==COLOR(NONE) || pn.robot == n.robot ) {
                    dist_sum += dist_o;
                    cnt_sum++;
                } else {
                    dist_sum = (dist_sum+cnt_sum>dist_o)?dist_sum+cnt_sum:dist_o;
                    total += dist_sum;
                    dist_sum = 0;
                    cnt_sum = 1;
                }
                
            } else if( ch=='B' ) {
                n.robot = COLOR(BLUE);
                dist_b = abs(prev_b - n.btn);
                prev_b = n.btn;

                if( pn.robot==COLOR(NONE) || pn.robot == n.robot ) {
                    dist_sum += dist_b;
                    cnt_sum++;
                } else {
                    dist_sum = (dist_sum+cnt_sum>dist_b)?dist_sum+cnt_sum:dist_b;
                    total += dist_sum;
                    dist_sum = 0;
                    cnt_sum = 1;
                }
            }

            pn.robot = n.robot;
            pn.btn = n.btn;
        }

        total += dist_sum+cnt_sum;
        cout << "Case #" << i+1 << ": " << total << endl; 
    }
    
    return 0;
}

