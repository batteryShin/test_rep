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

#define SZMAX 10 

#define UINT unsigned int

using namespace std;

int tcases;
int num;

int p, q;
double judge_val;

bool absoluteEqual(double a, double b) {
    return fabs(a-b)<1e-10;
}

int main()
{
    cin >> tcases;
    cin.ignore();

    for(int t=1; t<=tcases; t++) {

        cin >> p;
        cin.ignore();
        cin >> q;
//        cout << "values = " << p << " " << q << endl; 

        judge_val = p * (2.0/q);
        if( absoluteEqual(judge_val,1.0) ) {
            num = 1;
        } else {
            if( judge_val>1.0 ) {
                judge_val -= 1.0;
                num = 0;
            } else {
                num = 1;
            }

            while( judge_val<1.0 ) {
                judge_val *= 2;
                num++;
            }
        }

        cout << "Case #" << t << ": ";
        if( judge_val>1.0 ) {
            cout << "impossible" << endl;
        } else {
            cout << num << endl;
        }
    }
}
