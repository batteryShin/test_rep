#include <cstdio>
#include <cstdlib>
#include <iostream>

#include <string>
#include <cstring>

#include <list>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct Item {
    char name[32];
    char kind;
    int cost;
    int scode;
};

typedef map< char*, Item >  IMAP;
typedef pair< char*, Item > IPAIR;
typedef map< string, Item, less<string> >  O_IMAP;
typedef pair< string, Item > O_IPAIR;

int main()
{
    IMAP items;
    IMAP::iterator it;
    
    Item item1;
    sprintf(item1.name, "%s", "long sword");
    item1.kind = 1;
    item1.cost = 200;
    item1.scode = 0;

    Item item2;
    sprintf(item2.name, "%s", "heritic shield");
    item2.kind = 2;
    item2.cost = 1000;
    item2.scode = 4;

    Item item3;
    sprintf(item3.name, "%s", "hammer");
    item3.kind = 1;
    item3.cost = 500;
    item3.scode = 0;

    // Items에 아이템 추가
    items.insert( IMAP::value_type(item2.name, item2) );
    items.insert( IPAIR(item1.name, item1) );

    // Items가 비어 있지않다면
    if( false == items.empty() )
    {
        cout << "저장된 아이템 개수- " << items.size() << endl;
    }

    for( it=items.begin(); it!=items.end(); ++it )
    {
        cout << "이름: " << it->first << ", 가격: " << it->second.cost << endl;
    }

    it = items.find("long sword");
    if( it == items.end() )   {
        cout << "아이템'긴칼'이 없습니다." << endl;
    }
    cout << endl;

    cout << "올림차순으로 정렬되어있는 map(Key 자료형으로string 사용)" << endl;

    O_IMAP Items2;
    O_IMAP::iterator IterPos2;

    Items2.insert( O_IMAP::value_type(item2.name, item2) );
    Items2.insert( O_IPAIR(item1.name, item1) );

    // operator[]를 사용하여 저장
    Items2[item3.name] = item3;

    for( IterPos2 = Items2.begin(); IterPos2 != Items2.end(); ++IterPos2 )
    {
        cout << "이름: " << IterPos2->first << ", 가격: " << IterPos2->second.cost << endl;
    }
    cout << endl;

    cout << "해머의 가격은 얼마? ";
    IterPos2 = Items2.find("hammer");
    if( IterPos2 != Items2.end() )   {
        cout << IterPos2->second.cost << endl;
    }
    else {
        cout << "해머는 없습니다" << endl;
    }
    cout << endl;

    // 아이템 "긴칼"을 삭제한다.
    IterPos2 = Items2.find("long sword");
    if( IterPos2 != Items2.end() )   {
        Items2.erase( IterPos2 );
    }

    cout << "Items2에 있는 아이템 개수: " << Items2.size() << endl;
    
    return 0;
}
