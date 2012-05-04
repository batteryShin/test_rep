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

struct Point {
    int x;
    int y;
};

class Item {
public:
    Item* lt;
    Item* rt;

    Point p;
    int depth;
};

int main()
{
    unsigned char map[201][201];

    int ncases, ntiles;
    cin >> ncases;
    cin.ignore();

    Point start, end;
    vector<Item> vec;
    vector<Item> remain;
    vector<Item> next_remain;

    for(int i=0; i<ncases; i++) {
        cin >> start.x;
        cin >> start.y;
        cin >> end.x;
        cin >> end.y;

        cin >> ntiles;

        vec.clear();
        remain.clear();
        next_remain.clear();
        for(int j=0; j<=200; j++) {
            memset((void*)map[j], 0, sizeof(unsigned char)*201 );
        }

        int x1, y1, x2, y2;
        for(int j=0; j<ntiles; j++) {
            cin >> x1; 
            cin >> y1; 
            cin >> x2; 
            cin >> y2; 

            for(int m=y1; m<=y2; m++) {
                for(int n=x1; n<=x2; n++) {
                    // 0x0XYZ ==> X for left, Y for right, Z for mapped
                    map[m][n] = 0x1;

                    if( m<y2 && map[m+1][n] ) {
                        map[m][n] = (map[m][n] | 0x2);
                    }
                    if( n<x2 && map[m][n+1] ) {
                        map[m][n] = (map[m][n] | 0x4);
                    }
                }
            }
        }

        printf("map[3][4] = %d\n", map[3][4]);

        Item* node = new Item();
        node->p.x = start.x;
        node->p.y = start.y;
        node->depth = 0;
        vec.push_back(*node);
        remain.push_back(*node);

        while( !(node->p.x==end.x && node->p.y==end.y) ) {
            while( !remain.empty() ) {
                *node = remain.back();
                printf("node inform : (%d,%d,%d)\n", node->p.x, node->p.y, node->depth);

                // check at bottom first
                if( node->p.y<end.y && (map[node->p.y][node->p.x]&0x2==0x2) ) {
                    node->lt = new Item();
                    node->lt->p.x = node->p.x;
                    node->lt->p.y = node->p.y+1;
                    node->lt->depth = node->depth+1;
                    vec.push_back(*(node->lt));
                    next_remain.push_back(*(node->lt));
                }

                // check at bottom first
                if( node->p.x<end.x && (map[node->p.y][node->p.x]&0x4==0x4) ) {
                    node->rt = new Item();
                    node->rt->p.x = node->p.x+1;
                    node->rt->p.y = node->p.y;
                    node->rt->depth = node->depth+1;
                    vec.push_back(*(node->rt));
                    next_remain.push_back(*(node->rt));
                }

                remain.pop_back();
            }

            if( next_remain.empty() ) {
                break;
            }
            remain = next_remain;
            next_remain.clear();
        }

        int res_cnt = 0;
        vector<Item>::iterator vit;
        for(vit=vec.begin(); vit!=vec.end(); vit++) {
            if( vit->depth == end.x-start.x+end.y-start.y ) {
                res_cnt++;
            }
        }

        cout << "Output for case #" << i+1 << " : " << res_cnt << endl;
    }

    return 0;
}
