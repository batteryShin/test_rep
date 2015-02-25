#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {

    int i, j, N, t;

    long long v[101];
    long long A, sum;

    cin >> t;
    for (int test=1; test<=t; ++test) {

	cin >> A >> N;
	for (int i=0; i<N; ++i) {
	    cin >> v[i];
	}
	sort(v, v+N);

	sum = A;
	int result = 0;
	for (int i=0, j=N-1; i<=j;) {

//cout << i << " : " << v[i] << " _ " << sum << endl;
	    if (v[i] < sum) {
		sum += v[i];
		i++;
	    }
	    else {
		long long tmp = sum;
		int addCnt = 0;
		bool reachZero = false;
		while (true) {
		    if (tmp -1 == 0) {
			reachZero = true;
			break;
		    }
		    tmp += tmp -1;
		    addCnt++;
		    if (v[i] < tmp) break;
		}
		int removeCnt = j - i;
		
//		cout << addCnt << " " << removeCnt << endl;
		if (reachZero == false  && addCnt <= removeCnt) {
		    sum += sum - 1;
		    result++;
		}
		else {
		    j--;
		    result++;
		}
	    }
	}
	cout << "Case #" << test << ": ";
	cout << result;
	cout << endl;
    }

    return 0;
}

