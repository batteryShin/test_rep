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
    int tcases;
    cin >> tcases;
    cin.ignore();

    int n, k;
    int remain;
    int div;

    for(int i=0; i<tcases; i++) {
        cin >> n;
        cin >> k;

        div = pow(2,n);
        remain = k % div;

        cout << "Case #" << i+1 << ": ";
        if( remain==div-1 ) {
            cout << "ON" << endl;
        } else {
            cout << "OFF" << endl;
        }
    }
    
    return 0;
}

