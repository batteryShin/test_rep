#include <cstdlib>
#include <cstdio>
#include <iostream>

#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

#include <sys/time.h>
#include <unistd.h>

#define USE_PIPE_IO 0

using namespace std;

int main()
{
    /*  framework to solve problems - START   */
    struct timeval tstart, tend;
    gettimeofday(&tstart, NULL);

#if !USE_PIPE_IO
    freopen("C-large-practice.in", "rt", stdin);
    freopen("C-large-practice.out", "wt", stdout);
#endif
    int ncases;
    cin >> ncases;
    cin.ignore();
    /*  framework to solve problems - END   */

    string strin, strout;
    char *pb;
    int term;
    int  nchar;
    char prev_num, num;
    for(int i=0; i<ncases; i++) {
        getline(cin, strin);
//        printf("string was extracted - %d bytes\n", strin.size());

        char *pcharbuf = new char[strin.size()*5+1];
        memset(pcharbuf, 0, sizeof(char));
        pb = pcharbuf;
        prev_num = 'x';

        for(int j=0; j<strin.size(); j++) {
            term = strin[j] - 'a';
//            printf("term is - %d\n", term);

            switch(term) {
                case 0:
                case 1:
                case 2:
                    num = '2';
                    nchar = term+1;
                    break;
                case 3:
                case 4:
                case 5:
                    num = '3';
                    nchar = term-2;
                    break;
                case 6:
                case 7:
                case 8:
                    num = '4';
                    nchar = term-5;
                    break;
                case 9:
                case 10:
                case 11:
                    num = '5';
                    nchar = term-8;
                    break;
                case 12:
                case 13:
                case 14:
                    num = '6';
                    nchar = term-11;
                    break;
                case 15:
                case 16:
                case 17:
                case 18:
                    num = '7';
                    nchar = term-14;
                    break;
                case 19:
                case 20:
                case 21:
                    num = '8';
                    nchar = term-18;
                    break;
                case 22:
                case 23:
                case 24:
                case 25:
                    num = '9';
                    nchar = term-21;
                    break;
                default:
                    // space case
                    num = '0';
                    nchar = 1;
                    break;
            }

            if(num==prev_num)
                *(pb++) = ' ';

            for(int k=0; k<nchar; k++) {
                *(pb++) = num;
            }
//            printf("prev_num & num - %c, %c\n", prev_num, num);
//            printf("pcharbuf is - %s\n", pcharbuf);
            
            prev_num = num;
        }

        strout = string(pcharbuf);
        strout.resize(pb-pcharbuf);

        cout << "Case #" << i+1 << ": " << strout << endl;
    
        delete [] pcharbuf;
    }
    
    /*  framework to solve problems - START   */
    gettimeofday(&tend, NULL);
    unsigned long long elapsed_time = (tend.tv_sec-tstart.tv_sec)*1000000 + (tend.tv_usec-tstart.tv_usec);
    printf("Algorithm elapsed time is...%llu usec\n", elapsed_time);

    return 0;
    /*  framework to solve problems - END   */
}


