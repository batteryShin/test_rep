#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;
/*
struct node {
    int key;
    struct node *next;
};

int main()
{
    int n, m;
    cout << "Josephus problem solver" << endl;
    cout << "N? ";
    cin >> n;
    cout << "M? ";
    cin >> m;

    struct node *t, *x;
    t = new node;
    t->key = 1;
    x = t;
    for(int i=2; i<=n; i++) {
        t->next = new node;
        t = t->next;
        t->key = i;
    }
    t->next = x;

    while( t!=t->next ) {
        for(int i=1; i<m; i++) {
            t = t->next;
        }
        cout << t->next->key << ' ';
        x = t->next;
        t->next = x->next;
        delete x;
    }

    cout << "(" << t->key << ")" << endl;
}
*/
int chk_empty(int *p, int np) {
    int res = 1;
    for(int i=0; i<np; i++) {
        if( p[i]!=-1 ) {
            res = 0;
            break;
        }
    }

    return res;
}

int main()
{
    int n, m;
    cout << "Josephus problem solver" << endl;
    cout << "N? ";
    cin >> n;
    cout << "M? ";
    cin >> m;

    int *x, *t;
    t = new int[n];
    x = new int[n];
    memset(x, -1, sizeof(int)*n);

    int i;
    for(i=0; i<n; i++) {
        t[i] = i+1;
        x[i] = t[i];
    }
    x[n-1] = 0;

    bool flag = false;
    int prev = n-1;
    int next = 0;
    int out = 0;
    while( !chk_empty(x,n) ) {

        i=1;
        while(i<m) {
            prev = next;
            next = x[prev];

            if( prev==next ) {
                flag = true;
            }
            i++;
        }

        if( flag ) {
            cout << "(" << t[next] << ")" << ' ';
        } else {
            cout << t[next] << ' ';
        }

        x[prev] = x[next];
        x[next] = -1;
        next = x[prev];
    }

    delete [] t;
    delete [] x;
}

