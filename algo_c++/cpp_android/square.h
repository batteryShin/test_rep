#include <stdio.h>

/*

	extern "C" : c++ 컴파일러에게 c처럼 컴파일해달라는 지시어
				name mangling을 막을 수 있다.

	모든 c++ 컴파일러는 __cplusplus 라는 매크로를 정의하고 있습니다.
	따라서 임의의 함수를 c/c++에서 모두 사용하려면,
	함수 구현은 .c로 해서 mangling을 막고
	헤더는 아래처럼 조건부 컴파일을 해서 c/c++ 사용자 모두를 고려해야 합니다

*/

#ifdef __cplusplus
extern "C" {
#endif

int square( int a );

#ifdef __cplusplus
}
#endif