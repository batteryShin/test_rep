#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

static int prev_y = 0;

struct Node {
    int id;
    int sp;
    int y;
    Node* l;
    Node* r;
};

void draw(struct Node* nd) {
    if( prev_y!=nd->y ) {
        cout << endl << endl;
        prev_y = nd->y;
    }
    for(int i=0; i<nd->sp; i++) {
        cout << " ";
    }
    cout << nd->id;
    for(int i=0; i<nd->sp; i++) {
        cout << " ";
    }
    
}

void traverse(int n, struct Node* nd, vector<Node*>& stack) {
    Node* t;
    int outer_path_len = 0;
    bool flag;

    stack.push_back(nd);
    while( !stack.empty() ) {
        flag = false;
        t = stack.front();
        draw(t);

        if( n>=t->id*2 ) {
            t->l = new Node();
            t->l->id = t->id*2;
            t->l->y = t->y + 1;
            t->l->sp = t->sp / 2 + log10(t->id);
            stack.push_back(t->l);
            flag = true;
        }

        if( n>=t->id*2+1 ) {
            t->r = new Node();
            t->r->id = t->id*2+1;
            t->r->y = t->y + 1;
            t->r->sp = t->sp / 2 + log10(t->id);
            stack.push_back(t->r);
            flag = true;
        }

        stack.erase(stack.begin());
        delete t;

        if( !flag ) {
            outer_path_len += t->y;
        }
    }

    cout << endl << endl << "Outer path length is : " << outer_path_len << endl;
}


int main()
{
    int n=0, lnd=0, rnd=0;

    cout << "Insert tree node numbers : ";
    cin >> n;
    cout << "Insert tree display size : ";
    cin >> rnd;

    vector<Node*> stack;
    Node *rt = new Node();
    rt->id = 1;
    rt->y = 0;
    rt->sp = (lnd + rnd) / 2;
    traverse(n, rt, stack);
}
