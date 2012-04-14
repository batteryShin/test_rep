#include <cstdlib>
#include <cstdio>
#include <iostream>

#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

#include <sys/time.h>
#include <unistd.h>

using namespace std;

int main()
{
    int ncases = 3;

    string strin, strout;
    int inp, oup;
    int chrs[26];
    memset( chrs, -1, sizeof(int)*26 );
    
    for(int i=0; i<ncases; i++) {
        getline(cin, strin);
        getline(cin, strout);

        for(int j=0; j<strin.size(); j++) {
            inp = strin[j] - 'a';
            oup = strout[j] - 'a';
            
            printf("results %c(%d) --> %c(%d)\n", strin[j], inp, strout[j], oup);
            if( inp>=0 && inp<26 )  chrs[inp] = oup;
        }
    }

    for(int i=0; i<26; i++) {
        cout << "'" << (char)('a'+i) << "',";
    }
    cout << endl;

    for(int i=0; i<26; i++) {
        cout << "'" << (char)('a'+chrs[i]) << "',";
    }
    cout << endl;
    
    return 0;
}


