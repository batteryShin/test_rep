#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    const char ch_open[4] = { '(', '[', '{', '<' };
    const char ch_close[4] = { ')', ']', '}', '>' };
    int ch_order[4];
    int ch_refer[4];

    int tcases;
    vector< pair<int,int> > stack;
    string str;
    string str_order;

    char ch;
    bool checked;
    int k;

    std::ios::sync_with_stdio(false);
    cin >> tcases;
    while(tcases-->0) {
        stack.clear();
        str.clear();
        cin >> str >> str_order; 
        for(int i=0; i<4; i++) {
            for(int j=0; j<4; j++) {
                if( str_order[i]==ch_open[j] ) {
                    ch_order[j] = i;
                    ch_refer[i] = j;
                    break;
                }
            }
        }

        for(int i=0; i<str.size(); i++) {
            checked = false;
            ch = str[i];

            for(int j=0; j<4; j++) {
                if( ch==ch_open[j] ) {
                    stack.push_back( pair<int,int>(i,j) );
                    checked = true;
                    break;
                }
            }

            if( checked ) {
                continue;
            } else {
                for(int j=0; j<4; j++) {
                    if( ch==ch_close[j] ) {
                        k = ch_order[stack.back().second];
                        if( k<ch_order[j]) {
                            str.replace(i, 1, 1, ch_close[ch_refer[k]]);
                        } else if( k>ch_order[j] ) {
                            str.replace(stack.back().first, 1, 1, ch_open[ch_order[ch_refer[j]]]);
                        }
                        stack.pop_back();
                        break;
                    }
                }
            }
        }

        cout << str << "\n";
    }
}

