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

#define CODE_DEBUG 0

using namespace std;

typedef unsigned long long int ULINT;
typedef long long LLINT;

int main()
{
    int tcases, tcnt;
    LLINT res;

    cin >> tcases;
    cin.ignore();

    int nelems, elem;
    vector<int> v1, v2;

    tcnt = tcases;
    while(tcnt-->0) {
        res = 0;
        v1.clear();
        v2.clear();

        cin >> nelems;
        cin.ignore();

        for(int i=0; i<nelems; i++) {
            cin >> elem;
            v1.push_back(elem);
        }
        cin.ignore();

        for(int i=0; i<nelems; i++) {
            cin >> elem;
            v2.push_back(elem);
        }
        cin.ignore();

        sort(v1.begin(), v1.end(), less<int>());
        sort(v2.begin(), v2.end(), greater<int>());

        for(int i=0; i<nelems; i++) {
            res += (LLINT)(v1.at(i))*v2.at(i);
        }

        cout << "Case #" << tcases-tcnt << ": " << res << endl;
    }

    return 0;
}


