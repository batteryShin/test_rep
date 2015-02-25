#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);

    int cnt;
    string members, fans;
    int members_size, fans_size;
    vector<int> members_male;
    vector<int> fans_male;
    int react[200000];

    int tcases;
    cin >> tcases;
    for(int t=1; t<=tcases; t++) {
        cin >> members;
        cin >> fans;
        members_size = members.size();
        fans_size = fans.size();

        for(int i=0; i<members.size(); i++) {
            if( members[i]=='M' ) {
                members_male.push_back(i);
            }
        }
        members.clear();

        for(int i=0; i<fans.size(); i++) {
            if( fans[i]=='M' ) {
                fans_male.push_back(i);
            }
        }

        if( members_male.size()>100000 || fans_male.size()>100000 ) {
            cnt = 0;
            for(int i=0; i<fans_size-members_size+1; i++) {
                for(int j=0; j<members_male.size(); j++) {
                    if(fans[ members_male[j] + i ]=='M') {
                        cnt++;
                        break;
                    }
                }
            }
            fans.clear();
            members_male.clear();
            fans_male.clear();
        } else {
            int index;
            fans.clear();
            memset(react, 0, sizeof(int)*200000);
            cnt = 0;
            for(int i=0; i<members_male.size(); i++) {
                for(int j=0; j<fans_male.size(); j++) {
                    index = fans_male[j] - members_male[i];
                    if( index>=0 && index<=fans_size-members_size && react[index]==0 ) {
                        cnt++;
                        react[index] = 1;
                    }
                }
            }
            members_male.clear();
            fans_male.clear();
        }
        cout << fans_size-members_size+1-cnt << "\n";
    }
}
