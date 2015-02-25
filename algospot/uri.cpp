#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    const string sp_str[11] = {" ", "!", "2", "3", "$", "%", 
                                "6", "7", "(", ")", "*"};
    int tcases;
    string str;
    int p;
    char ch;

    std::ios::sync_with_stdio(false);
    cin >> tcases;
    while(tcases-->0) {
        str.clear();
        cin >> str;

        p=0;
        while( (ch=str[p])!='\0' ) {
            if( ch=='%' ) {
                if((ch=str[p+2])=='a') {
                    ch = 58;
                }
                str.replace(p, 3, sp_str[(int)(ch-48)]);
            }
            p++;
        }

        cout << str << "\n";
    }
}
