#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

#include "List.h"		// native/include/utils/List.h
using namespace android;


int main() {
	List<int> s;
	s.push_front(10);
	s.push_front(20);
	s.push_front(30);

//	reverse(s.begin(), s.end());		// 1
//	s.reverse();						// 2

	List<int>::iterator p = s.begin();
	while( p!=s.end() ) {
		cout << *p << endl;
		++p;
	}
}