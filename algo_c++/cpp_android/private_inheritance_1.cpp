class Base {
private:	int a;
protected:	int b;
public:		int c;
};

class Derived : private Base {
};

int main() {
	Base base;
	base.c = 10;		// ok. public

	Derived derv;
	derv.c = 10;		// error. ���� �����ڰ� private�̹Ƿ� private�� �����
}