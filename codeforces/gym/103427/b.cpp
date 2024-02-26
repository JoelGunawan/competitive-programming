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
bool vis[lim];
bool valid = 1;
int val[lim];
vector<pair<int, int>> edges[lim];
vector<int> component;
void dfs(int nd) {
    vis[nd] = 1;
    component.pb(nd);
    for(auto i : edges[nd]) {
        if(!vis[i.fi]) {
            val[i.fi] = val[nd] ^ i.se;
            dfs(i.fi);
        }
        else {
            if((val[nd] ^ val[i.fi]) != i.se)
                valid = 0;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[u].pb(mp(v, w));
        edges[v].pb(mp(u, w));
    }
    for(int i = 1; i <= n; ++i) {
        if(!vis[i]) {
            component.clear();
            dfs(i);
            if(!valid)
                break;
            for(int j = 0; j < 30; ++j) {
                int cnt0 = 0, cnt1 = 0;
                for(auto k : component) {
                    if(val[k] & (1 << j))
                        ++cnt1;
                    else
                        ++cnt0;
                }
                if(cnt1 > cnt0) {
                    for(auto k : component)
                        val[k] ^= (1 << j);
                }
            }
        }
    }
    if(!valid) {
        cout << -1 << endl;
    }
    else {
        ll res = 0;
        for(int i = 1; i <= n; ++i)
            res += val[i];
        cout << res << endl;
    }
    return 0;
}