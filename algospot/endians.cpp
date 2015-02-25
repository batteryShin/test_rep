#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

int main() {
    int tcases;
    unsigned int num;
    unsigned int num_out;
    string str;

    std::ios::sync_with_stdio(false);
    cin >> tcases;
    while(tcases-->0) {
        cin >> num;
        num_out = ((num & 0xff000000)>>24) |
            ((num & 0x00ff0000)>>8) |
            ((num & 0x0000ff00)<<8) |
            ((num & 0x000000ff)<<24);

        cout << num_out << "\n";
    }
}


