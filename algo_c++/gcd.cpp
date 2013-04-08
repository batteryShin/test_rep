#include <cstdlib>
#include <cstdio> 
#include <iostream>

using namespace std;

int gcd(int u, int v) {
    int s=0;
    if(u>v) {
        while( (s=u%v) ) {
            u = v;
            v = s;
        }
    } else if(u<v) {
        while( (s=v%u) ) {
            v = u;
            u = s;
        }
    }

    return (u>v)?v:u;    
}

int main()
{
    int u, v;

    cout << "Input 1st number : ";
    cin >> u;
    cout << "Input 2nd number : ";
    cin >> v;

    cout << "GCD between " << u << " & " << v << " is " << gcd(u,v);
}

