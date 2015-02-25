#include <iostream>

using namespace std;

// ��ȯ�� �����
// ������ �Ҹ��ڷ� �ڿ��� �������� - RAII
class OFile {
	FILE* file;

public:
	// explicit ������ : ���ڰ� 1���� �����ڰ� �Ͻ��� ��ȯ�� ����Ű�°��� ����.
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

	fputs("hello", f);		// OFile -> FILE* ��ȯ�� �ʿ�.
	fprintf(f, "%d", 10);

	String s1 = "hello";
	char s2[10];
	strcpy(s2,s1);			// ���� ���� �Ϸ���, String->const char* ��ȯ�� �Ǹ� ��.
}
*/