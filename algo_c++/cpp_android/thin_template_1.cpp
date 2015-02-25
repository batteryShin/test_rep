/*
	1. Code Bloat : template을 잘못 사용해서 코드 메모리가 커지는 현상.
					=> thin template Idioms를 사용하여 해결
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
//	T를 사용하지 않는 모든 멤버는 template이 아닌 부모를 만들어서 뽑아낸다.
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

// void* 를 바로 사용하면 casting 때문에 불편.
// 자식을 template으로 만들면서 casting을 책임지도록 만듦
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
	Vector<short> v3;		// Vector관련 함수는...12개 생성?
}