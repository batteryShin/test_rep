#include <cstdlib>
#include <cstdio>
#include <iostream>

#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <limits>
#include <math.h>

#include <assert.h>
#include <unistd.h>

using namespace std;

template <typename T>
class Stack {
public:
    Stack()
    {
        Clear();
    }

    // �ʱ�ȭ �Ѵ�.
    void Clear()
    {
        m_Count = 0;
    }

    // ���ÿ� ����� ����
    int Count()
    {
        return m_Count;
    }

    // ����� �����Ͱ� ���°�?
    bool IsEmpty()
    {
        return 0 == m_Count ? true : false;
    }

    // �����͸� �����Ѵ�.
    bool push( T data )
    {
        // ���� �Ҽ� �ִ� ������ �Ѵ��� �����Ѵ�.
        if( m_Count >= MAX_COUNT )
        {
            return false;
        }

        // ������ ������ �ϳ� �ø���.
        m_aData[ m_Count ] = data;
        ++m_Count;

        return true; 
    }

    // ���ÿ��� ������.
    T pop()
    {
        // ����� ���� ���ٸ� 0�� ��ȯ�Ѵ�.
        if( m_Count  < 1 )
        {
            return 0;
        }

        // ������ �ϳ� ���� �� ��ȯ�Ѵ�.
        --m_Count;
        return m_aData[ m_Count ];
    }

private:
    T  m_aData[MAX_COUNT];
    int    m_Count;
};


void main()
{
    ExpStack kExpStack;

    cout << "ù��° ���� ����- ���� ����ġ 145.5f" << endl;
    kExpStack.push( 145.5f );

    cout << "�ι�° ���� ����- ���� ����ġ 183.25f" << endl;
    kExpStack.push( 183.25f );

    cout << "����° ���� ����- ���� ����ġ162.3f" << endl;
    kExpStack.push( 162.3f );


    int Count = kExpStack.Count();
    for( int i = 0; i < Count; ++i )
    {
        cout << "���� ����ġ->" << kExpStack.pop() << endl;
    }
}
