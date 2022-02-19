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
vector<int> edges[100001];
multiset<int> res[100001];
int x[100001];
bool vis[100001];
void dfs(int nd) {
    res[nd].ins(x[nd]);
    vis[nd] = 1;
    for(auto i : edges[nd]) {
        if(!vis[i]) {
            dfs(i);
            for(auto j : res[i])
                res[nd].ins(j);
        }
    }
    while(res[nd].size() > 20)
        res[nd].erase(res[nd].begin());
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; ++i)
        cin >> x[i];
    for(int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        edges[u].pb(v);
        edges[v].pb(u);
    }
    dfs(1);
    for(int i = 0; i < q; ++i) {
        int v, k;
        cin >> v >> k;
        auto it = res[v].end();
        while(k--)
            --it;
        cout << *it << endl;
    }
    return 0;
}