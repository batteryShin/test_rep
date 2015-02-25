#include <stdio.h>

/*

	extern "C" : c++ �����Ϸ����� có�� �������ش޶�� ���þ�
				name mangling�� ���� �� �ִ�.

	��� c++ �����Ϸ��� __cplusplus ��� ��ũ�θ� �����ϰ� �ֽ��ϴ�.
	���� ������ �Լ��� c/c++���� ��� ����Ϸ���,
	�Լ� ������ .c�� �ؼ� mangling�� ����
	����� �Ʒ�ó�� ���Ǻ� �������� �ؼ� c/c++ ����� ��θ� ����ؾ� �մϴ�

*/

#ifdef __cplusplus
extern "C" {
#endif

int square( int a );

#ifdef __cplusplus
}
#endif