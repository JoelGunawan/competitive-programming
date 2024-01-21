// header file
#include <bits/stdc++.h>
// pragma
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
// macros
#define endl "\n"
#define ll long long
#define mp make_pair
#define ins insert
#define lb lower_bound
#define pb push_back
#define ub upper_bound
#define lll __int128
#define fi first
#define se second
using namespace std;
const int lim = 1e5 + 5;
vector<int> edges[lim];
int disc[lim], low[lim], t;
bool active[lim];
vector<vector<int>> components;
vector<int> st;
void dfs(int nd) {
    disc[nd] = low[nd] = t++;
    active[nd] = 1;
    st.pb(nd);
    for(auto i : edges[nd]) {
        if(disc[i] == -1) {
            dfs(i);
            low[nd] = min(low[nd], low[i]);
        }
        else if(active[i]) {
            low[nd] = min(low[nd], disc[i]);
        }
    }
    if(disc[nd] == low[nd]) {
        components.pb({});
        do {
            components.back().pb(st.back());
            active[st.back()] = 0;
            st.pop_back();
        } while(components.back().back() != nd);
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        edges[u].pb(v);
    }
    memset(disc, -1, sizeof(disc));
    for(int i = 1; i <= n; ++i) {
        if(disc[i] == -1)
            dfs(i);
    }
    int c[n + 1];
    for(int i = 0; i < components.size(); ++i) {
        for(auto j : components[i]) {
            c[j] = i + 1;
        }
    }
    cout << components.size() << endl;
    for(int i = 1; i <= n; ++i) {
        cout << c[i] << " ";
    }
    cout << endl;
}