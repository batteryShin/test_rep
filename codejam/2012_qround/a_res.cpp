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
    // this look-up table comes from problem description & sample.
    char trans[] = {'a','b','c','d','e','f','g','h','i','j','k',
        'l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    char origin[] = {'y','h','e','s','o','c','v','x','d','u','i',
        'g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};

    int ncases;
    cin >> ncases;
    cin.ignore();

    int nch;
    string strin, strout;
    for(int i=0; i<ncases; i++) {
        getline(cin, strin);
        strout = strin;

        for(int j=0; j<strin.size(); j++) {
            nch = strin[j] - 'a';
            
            if( nch>=0 && nch<26 ) {
                strout[j] = origin[nch];
            } else {
                strout[j] = ' ';
            }
        }

        cout << "Case #" << i+1 << ": " << strout << endl; 
    }

    return 0;
}


