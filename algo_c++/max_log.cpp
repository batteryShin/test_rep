#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double n;
    cout << "Insert N : ";
    cin >> n; 

    int res_n = log2(n);

    int c=0;
    while(n>1) {
        c = c + 1;
        n = n / 2;
        n = floor(n);
    }

    cout << "Result is " << c << ", " << res_n << endl;
}
