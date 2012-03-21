#include <cstdlib>
#include <cstdio>
#include <iostream>

#include <cstring>
#include <vector>
#include <algorithm>

#include <sys/time.h>
#include <unistd.h>

#define USE_PIPE_IO 0

using namespace std;

int main()
{
    struct timeval tstart, tend;
    gettimeofday(&tstart, NULL);

#if !USE_PIPE_IO
    freopen("B-large.in", "rt", stdin);
    freopen("B-large.out", "wt", stdout);
#endif
    int n;
    string str;
    char *w, *pw;
    vector<string> vin;

    cin >> n;
    cin.ignore();

    for(int i=0; i<n; i++) {
        vin.clear();

        getline(cin, str);
//        printf("string was extracted - %d bytes\n", str.size());

        w = new char[str.size()+1];
        strcpy(w, str.c_str());

//        printf("string was copied - %d bytes\n", str.size()+1);
        pw = strtok(w, " ");
        int n_w = 0;
        while(pw!=NULL) {
            vin.push_back( string(pw) );
            pw = strtok(NULL, " ");
            n_w++;
        }
//        printf("string was distributed - %d pieces\n", n_w);

        cout << "Case #" << i+1 << ": ";
        while(!vin.empty()) {
            cout << vin.back() << " ";
            vin.pop_back();
        }
        cout << endl;
    
        delete [] w;
    }
    
    gettimeofday(&tend, NULL);
    unsigned long long elapsed_time = (tend.tv_sec-tstart.tv_sec)*1000000 + (tend.tv_usec-tstart.tv_usec);
    printf("Algorithm elapsed time is...%llu usec\n", elapsed_time);

    return elapsed_time;
}


