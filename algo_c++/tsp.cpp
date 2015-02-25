#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <vector>
#include <memory.h>
#include <cmath>

using namespace std;

const double INF = 1e200;
const int MAX = 30;
int n;
double dist[MAX][MAX];  // distance of each nodes to other nodes
double best;

double minEdge[MAX];    // minimum distance edge of each nodes

double simpleHeuristic(vector<bool>& visited) {
    double ret = minEdge[0];
    for(int i=0; i<n; ++i)
        if(!visited[i])
            ret += minEdge[i];
    return ret;
}

void search(vector<int>& path, vector<bool>& visited, double currentLength) {
    if(best <= currentLength + simpleHeuristic(visited))    return;
    int here = path.back();

    if(path.size() == n) {
        best = min(best, currentLength + dist[here][0]);
        return;
    }

    for(int next=0; next<n; ++next) {
        if(visited[next])   continue;
        path.push_back(next);
        visited[next] = true;

        search(path, visited, currentLength+dist[here][next]);
        visited[next] = false;
        path.pop_back();
    }
}

int main()
{
    best = INF;
    vector<bool> visited(n, false);
    vector<int> path(1,0);
    visited[0] = true;
    search(path, visited, 0);
    return best;
}
