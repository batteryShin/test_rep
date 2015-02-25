#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

using namespace std;

int main() {
    int tri[101][101];
    int trisum[101][101];
    int tcases;
    int n;

    cin >> tcases;
    while(tcases-->0) {
        memset(tri, 0, sizeof(int)*101*101);
        memset(trisum, 0, sizeof(int)*101*101);
        cin >> n;
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=i; j++) {
                cin >> tri[i][j];
            }
        }

        for(int i=1; i<=n; i++) {
            trisum[n][i] = tri[n][i];
        }
        for(int i=n-1; i>=0; i--) {
            for(int j=1; j<=i; j++) {
                trisum[i][j] = max(trisum[i+1][j],trisum[i+1][j+1]) + tri[i][j];
            }
        }

        cout << trisum[1][1] << "\n";
    }

}
