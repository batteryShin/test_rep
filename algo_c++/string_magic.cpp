#include <stdlib.h>
#include <stdio.h>
#include <cstdio>
#include <iomanip>

#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

int T;

string str[3];
string op;
int *(number[3][101]);

static string abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int cache[26];
int val[26];


void solve_recursion(int* val) {


}

void solve(string (&strs)[3], string& op, int *(numbers[3][101])) {
    char* pch;
    for(int i=0; i<3; i++) {
        for(int j=0; j<strs[i].size(); j++) {
            pch = strchr(abc.c_str(), strs[i][j]);
            cache[pch-abc] = 1;
            numbers[i][j] = &(val[pch-abc]);
        }
    }

   
    solve_recursion(val);

}

int main() {
    cin >> T;
    while(T-->0) {
        cin >> str[0] >> op >> str[1] >> str[2];
        memset(cache, 0, sizeof(int)*26);
        memset(val, 0, sizeof(int)*26);
        solve(str, op, number);

        for(int i=0; i<3; i++) {
            cout << number[i][0];
            for(int j=1; j<str[i].size(); j++) {
                cout << " " << number[i][j];
            }
            cout << "\n";
        }
    }
}
