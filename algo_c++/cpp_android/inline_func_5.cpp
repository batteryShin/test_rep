

struct less {
	bool operator()(int a, int b) {
		return a<b;
	}
};

struct greater {
	bool operator()(int a, int b) {
		return a>b;
	}
};

template<typename T> void Sort(int* x, int n, T cmp ) {
	for(int i=0; i<n-1; i++) {
		for(int j=i+1; j<n; j++) {
			if( cmp(x[i],x[j]) ) {
				swap(x[i], x[j]);
			}
		}
	}
}

int main() {
	int x[10] = {1,3,5,7,9,2,4,6,8,10};

	less f1;
	Sort(x, 10, f1);
	greater f2;
	Sort(x, 10, f2);
}