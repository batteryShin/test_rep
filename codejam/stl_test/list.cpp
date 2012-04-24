#include <cstdlib>
#include <cstdio>
#include <iostream>

#include <string>
#include <cstring>

#include <list>
#include <vector>
#include <algorithm>

#define PTNUM   6

using namespace std;

template<typename T>
class Point {
public:
    Point() {}

    void setval(char nval, T xval, T yval) {
        name = nval;
        x = xval;
        y = yval;
    }

    char name;
    T x;
    T y;
};

template<typename T>
class Is_same_XY : public binary_function<T, T, bool> {
public:
    bool operator( ) ( T& v1, T& v2 ) {
        return ( v1.x==v2.x && v1.y==v2.y );
    }
};

template<typename T>
class Is_name_C : public unary_function<T, bool> {
public:
    bool operator( ) ( T& val ) {
        return ( val.name=='c' );
    }
};

typedef list< Point<int> >  LP;
typedef LP::iterator        LPIT;

int main()
{
    Point<int> *ppoint = new Point<int>[PTNUM];
    ppoint[0].setval('a', 50,200);
    ppoint[1].setval('b', 20,80);
    ppoint[2].setval('c', 75,10);
    ppoint[3].setval('d', 130,80);
    ppoint[4].setval('e', 100,200);
    ppoint[5].setval('f', 180,150);

    LP ptlist;
    LPIT it;

    // insert
    for(int i=0; i<PTNUM; i++) {
        ptlist.push_back( ppoint[i] );
    }

    // modify
    for(it=ptlist.begin(); it!=ptlist.end(); it++) {
        if( (*it).name=='d' ) {
            (*it).x = 200;
            (*it).y = 100;
        }
    }
    
    // remove
    ptlist.remove_if( Is_name_C< Point<int> >() ) ;

    

    for(it=ptlist.begin(); it!=ptlist.end(); it++) {
        cout << (*it).name << "\t" << (*it).x << "\t" << (*it).y << endl;
    }

    delete [] ppoint;
}
