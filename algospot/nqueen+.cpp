#include <stdio.h>
#include <iostream>

using namespace std;

static int mask, count;

void Backtrack(int y, int left, int down, int right, int n)
{
    int  bitmap, bit;

    if (y == n) {
        count++;
    } else {
        bitmap = mask & ~(left | down | right);
        while (bitmap) {
            bit = -bitmap & bitmap;
            bitmap ^= bit;
            Backtrack(y+1, (left | bit)<<1, down | bit, (right | bit)>>1, n);
        }
    }
}
int main(void)
{
    int n;
    int tcases;
	
    std::ios::sync_with_stdio(false);	
    cin >> tcases;

    while(tcases-->0) {
        cin >> n;
		mask = (1 << n) - 1;
		count = 0;
		Backtrack(0, 0, 0, 0, n);

		cout << count << "\n";
	}
    return 0;
}