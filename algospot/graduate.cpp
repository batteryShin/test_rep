#include <stdio.h>
#include <stdlib.h>

using namespace std;

int T;
int N;
int K;
int M;
int L;
int req[12][12];
int sem[10][12];

int main() {
    cin >> T;

    while(T-->0) {
        cin >> N >> K >> M >> L;

        for(int i=0; i<N; i++) {
            cin >> num_req;
            for(int j=0; j<num_req; j++) {
                cin >> req[i][j];
            }
        }
        
        for(int i=0; i<M; i++) {
            cin >> num_sem;
            for(int j=0; j<num_sem; j++) {
                cin >> sem[i][j];
            }
        }
    }


}
