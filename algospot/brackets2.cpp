#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    char ch_open[3] = { '(', '[', '{' };
    char ch_close[3] = { ')', ']', '}' };

    int tcases;
    vector<char> stack;
    string str;
    char ch;
    bool checked;

    std::ios::sync_with_stdio(false);
    cin >> tcases;
    while(tcases-->0) {
        stack.clear();
        str.clear();
        cin >> str; 
        for(int i=0; i<str.size(); i++) {
            checked = false;
            ch = str[i];
            for(int j=0; j<3; j++) {
                if( ch==ch_open[j] ) {
                    stack.push_back(ch_close[j]);
                    checked = true;
                    break;
                }
            }

            if( checked ) {
                continue;
            } else {
                if( stack.empty() ) {
                    stack.push_back(ch);
                    break;
                }

                if( stack.back()==ch ) {
                    stack.pop_back();
                } else {
                    break;
                }
            }
        }

        cout << (stack.empty()?"YES\n":"NO\n");
    }
}
