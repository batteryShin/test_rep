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

typedef multi_map< int, Item >  IMAP2;
typedef pair< int, Item > IPAIR2;
typedef multi_map< int, Item, greater<int> >  O_IMAP2;

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

    // add items to "items"
    items.insert( IMAP::value_type(item2.name, item2) );
    items.insert( IPAIR(item1.name, item1) );

    if( false == items.empty() )
    {
        cout << "Number of items in \"items\" - " << items.size() << endl;
    }

    for( it=items.begin(); it!=items.end(); ++it )
    {
        cout << "name: " << it->first << ", cost: " << it->second.cost << endl;
    }

    it = items.find("long sword");
    if( it == items.end() )   {
        cout << "There's no \"long sword\" in item list" << endl;
    }
    cout << endl;

    cout << "map(string key) - ordered by asc" << endl;

    O_IMAP Items2;
    O_IMAP::iterator IterPos2;

    Items2.insert( O_IMAP::value_type(item2.name, item2) );
    Items2.insert( O_IPAIR(item1.name, item1) );

    // save item using operator[]
    Items2[item3.name] = item3;

    for( IterPos2 = Items2.begin(); IterPos2 != Items2.end(); ++IterPos2 )
    {
        cout << "name: " << IterPos2->first << ", cost: " << IterPos2->second.cost << endl;
    }
    cout << endl;

    cout << "How much is the hammer? ";
    IterPos2 = Items2.find("hammer");
    if( IterPos2 != Items2.end() )   {
        cout << IterPos2->second.cost << endl;
    }
    else {
        cout << "There's no hammer in item list." << endl;
    }
    cout << endl;

    // remove item "long sword"
    IterPos2 = Items2.find("long sword");
    if( IterPos2 != Items2.end() )   {
        Items2.erase( IterPos2 );
    }

    cout << "Number of items in \"Items2\" - " << Items2.size() << endl;
    
    return 0;
}
