#include <bits/stdc++.h>
using namespace std;
const int lim = 1e5 + 5;
bool vis[lim], active[lim];
int disc[lim], low[lim];
vector<vector<int>> component;
vector<int> s, edges[lim];
int t = 0;
void tarjan(int nd) {
    vis[nd] = 1;
    low[nd] = disc[nd] = ++t;
    active[nd] = 1;
    s.push_back(nd);
    for(auto i : edges[nd]) {
        if(!vis[i]) {
            tarjan(i);
            low[nd] = min(low[nd], low[i]);
        }
        else if(active[i]) {
            low[nd] = min(low[nd], disc[i]);
        }
    }
    if(disc[nd] == low[nd]) {
        vector<int> new_component;
        do {
            new_component.push_back(s.back());
            active[s.back()] = 0;
            s.pop_back();
        } while(new_component.back() != nd);
        component.push_back(new_component);
    }
}