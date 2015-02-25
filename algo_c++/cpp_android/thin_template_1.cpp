/*
	1. Code Bloat : template�� �߸� ����ؼ� �ڵ� �޸𸮰� Ŀ���� ����.
					=> thin template Idioms�� ����Ͽ� �ذ�
*/

/*
template<typename T> class Vector {
	T* buff;
	int sz;

public:
	void push_front(const T& a) {}
	T& front() { return buff; }
	int size() { return sz; }
	bool empty() { return sz==0; }
};
*/

/*
//	T�� ������� �ʴ� ��� ����� template�� �ƴ� �θ� ���� �̾Ƴ���.
class VectorImpl {
	int sz;

public:
	int size() { return sz; }
	bool empty() { return sz==0; }
};

template<typename T> class Vector : public VectorImpl {
	T* buff;

public:
	void push_front(const T& a) {}
	T& front() { return buff; }
};
*/

class VectorImpl {
	int sz;
	void* buff;

public:
	void push_front(const void* item) {}
	void* front() { return buff; }
	int size() { return sz; }
	bool empty() { return sz==0; }
};

// void* �� �ٷ� ����ϸ� casting ������ ����.
// �ڽ��� template���� ����鼭 casting�� å�������� ����
template<typename T> class Vector : private VectorImpl {
	T* buff;

public:
	inline void push_front(const T& a) {
		VectorImpl::push_front(&a);
	}

	inline T& front() {
		return *(static_cast<T*>(VectorImpl::front()));
	}

	inline int size() { return VectorImpl::size(); }
	inline bool empty() { return VectorImpl::empty(); }
};

int main() {
	Vector<int> v1;
	int n = v1.front();

	Vector<double> v2;
	Vector<short> v3;		// Vector���� �Լ���...12�� ����?
}