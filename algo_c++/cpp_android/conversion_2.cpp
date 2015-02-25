#include <iostream>

using namespace std;

// 변환의 장단점
// 생성자 소멸자로 자원을 관리하자 - RAII
class OFile {
	FILE* file;

public:
	// explicit 생성자 : 인자가 1개인 생성자가 암시적 변환을 일으키는것을 막음.
	explicit OFile( const char* name, const char* mode = "wt" ) {
		file = fopen(name,mode);
	}

	~OFile() {
		fclose(file);
	}

	operator FILE*() {
		return file;
	}
};

void foo( OFile f ) {
}

int main() {
	OFile f("a.txt");

	foo(f);					// ok.
	foo("hello");			// no error. why?
}

/*
int main() {
	OFile f("a.txt");

	fputs("hello", f);		// OFile -> FILE* 변환이 필요.
	fprintf(f, "%d", 10);

	String s1 = "hello";
	char s2[10];
	strcpy(s2,s1);			// 정상 동작 하려면, String->const char* 변환이 되면 됨.
}
*/