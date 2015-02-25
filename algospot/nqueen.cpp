#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

using namespace std;

void set(int (&board)[12][12], int n, int y, int x, int value) {
    int sets = 0;
    board[y][x] += value;

    for(int i=0; i<n; i++) {
        if(i!=x) {
            board[y][i] += value;
        }
        if(i!=y) {
            board[i][x] += value;
        }
    }

    for(int i=1; i<n; i++) {
        if( y+i<n && x+i<n ) {
            board[y+i][x+i] += value;
        }
        if( x-i>=0 && y+i<n ) {
            board[y+i][x-i] += value;
        }
        if( y-i>=0 && x+i<n ) {
            board[y-i][x+i] += value;
        }
        if( y-i>=0 && x-i>=0 ) {
            board[y-i][x-i] += value;
        }
    }
}

int search(int (&board)[12][12], int n, int qfound) {
    // base condition..

    if( n-qfound==1 ) {
		int remains = 0;
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				if( board[i][j]==0 ) {
					remains++;
				}
			}
		}
        return remains;
    }

    // recursion..
    int count = 0;
    for(int i=0; i<n; i++) {
        if( board[qfound][i]==0 ) {
            set(board, n, qfound, i, 1);
            count += search(board, n, qfound+1);
            set(board, n, qfound, i, -1);
        }
        board[qfound][i]++;
    }

    for(int i=0; i<n; i++) {
        board[qfound][i]--;
    }

    return count;
}

int main() {
    int board[12][12] = {0,};
    int n;
    int tcases;
	
    std::ios::sync_with_stdio(false);	
    cin >> tcases;

    while(tcases-->0) {
        cin >> n;
        cout << search(board, n, 0) << "\n";
    }
}
