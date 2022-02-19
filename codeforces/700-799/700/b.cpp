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
bool univ[200001];
vector<int> edges[200001];
vector<int> child[200001];
int par[200001];
bool vis[200001];
int subtree[200001];
void fill_graph(int nd) {
    vis[nd] = 1;
    for(auto i : edges[nd]) {
        if(!vis[i])
            par[i] = nd, child[nd].pb(i), fill_graph(i);
    }
}
int get_subtree(int nd) {
    subtree[nd] = univ[nd];
    for(auto i : child[nd])
        subtree[nd] += get_subtree(i);
    return subtree[nd];
}
ll solve(int nd) {
    // important factors:
    // don't count the parent but greedy to parent
    // we need to check how many nodes go through from nd to par[nd]
    ll parents = subtree[1] - subtree[nd];
    ll our = subtree[nd];
    ll res = min(parents, our);
    for(auto i : child[nd])
        res += solve(i);
    return res;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < 2 * k; ++i) {
        int x;
        cin >> x;
        univ[x] = 1;
    }
    for(int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        edges[u].pb(v);
        edges[v].pb(u);
    }
    fill_graph(1);
    memset(vis, 0, sizeof(vis));
    get_subtree(1);
    cout << solve(1) << endl;
    return 0;
}