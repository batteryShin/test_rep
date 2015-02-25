int Add1(int a, int b) {
	return a+b;
}

inline int Add2(int a, int b) {
	return a+b;
}

int main() {
	Add1(1,2);
	Add2(1,2);

	int(*f)(int,int);

	int n;
	cin >> n;
	if(n==0)	f = &Add1;
	else		f = &Add2;

	f(1,2);
}