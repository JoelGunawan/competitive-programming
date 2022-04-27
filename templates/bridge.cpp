#include <bits/stdc++.h>
using namespace std;
const int lim = 1e5 + 5;
bool vis[lim];
int disc[lim], low[lim];
vector<vector<int>> component;
vector<int> s, edges[lim];
int t = 0;
void bridge(int nd, int prev = -1) {
    vis[nd] = 1;
    low[nd] = disc[nd] = ++t;
    for(auto i : edges[nd]) {
        if(i == prev)
            continue;
        else if(!vis[i]) {
            bridge(i, nd);
            low[nd] = min(low[nd], low[i]);
            if(low[i] > disc[nd]) {
                // the edge nd to i is a bridge
                
            }
        }
        else {
            low[nd] = min(low[nd], disc[i]);
        }
    }
    
}