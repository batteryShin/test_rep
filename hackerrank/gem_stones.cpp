#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main() {
    int res = 0;
    int gems[100][26] = {0,};
    string str;
    int n;
    
    cin >> n;
    for(int t=0; t<n; t++) {
        str.clear();
        cin >> str;
        
        for(int i=0; i<str.size(); i++) {
            gems[t][(int)(str[i]-97)] = 1;
        }
    }
    
    bool flag;
    for(int i=0; i<26; i++) {
        flag = true;
        for(int j=0; j<n; j++) {
            if( !gems[j][i] ) {
                flag = false;
                break;
            }
        }
        
        if(flag) {
            res++;
        }
    }
    
    cout << res << "\n";
}
