class AAA {
public:
	//...
	// static int DWORD;
	typedef int DWORD;
};

int p = 0;

template<typename T> void foo(T a) {
	typename T::DWORD * p;	// �ؼ�??
							// 1. DWORD�� static �����ε� ���ϱ� p�ϰ� �ִ�. - C++ default
							// 2. DWORD�� typedef�� Ÿ���̴�. �����ͺ��� p�� �����ϰ� �ִ�. - typename Ű���� ����ؾ� ��
}

int main() {
//	typename AAA::DWORD* p;		// error. typename�� T�϶��� ���.

	AAA aaa;
	foo(aaa);
}