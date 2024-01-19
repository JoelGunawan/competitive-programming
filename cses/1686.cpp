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
ll c[lim];
vector<int> edges[lim], st;
int low[lim], disc[lim], t = 0;
vector<vector<int>> components;
bool active[lim];
void dfs(int nd) {
    disc[nd] = low[nd] = t++;
    active[nd] = 1;
    st.pb(nd);
    for(auto i : edges[nd]) {
        if(disc[i] == -1) {
            // down edge
            dfs(i);
            low[nd] = min(low[nd], low[i]);
        }
        else if(active[i]) {
            // back edge
            low[nd] = min(low[nd], disc[i]);
        }
        else {
            // cross edge
        }
    }
    if(low[nd] == disc[nd]) {
        components.pb({});
        do {
            active[st.back()] = 0;
            components.back().pb(st.back());
            st.pop_back();
        } while(components.back().back() != nd);
    }
}
struct disjoint_set {
    int h[lim], sz[lim];
    disjoint_set() {
        memset(h, -1, sizeof(h));
        fill(sz, sz + lim, 1);
    }
    int fh(int nd) {
        return (h[nd] == -1) ? nd : h[nd] = fh(h[nd]);
    }
    bool merge(int x, int y) {
        x = fh(x), y = fh(y);
        if(x != y) {
            if(sz[x] < sz[y])
                swap(x, y);
            sz[x] += sz[y];
            h[y] = x;
        }
        return x != y;
    }
};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
        cin >> c[i];
    }
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
    disjoint_set dsu;
    ll cnt[n + 1];
    memset(cnt, 0, sizeof(cnt));
    for(auto i : components) {
        for(auto j : i) {
            dsu.merge(j, i.back());
        }
        for(auto j : i)
            cnt[dsu.fh(j)] += c[j];
    }
    reverse(components.begin(), components.end());
    ll dp[n + 1];
    memset(dp, 0, sizeof(dp));
    for(auto i : components) {
        dp[dsu.fh(i.back())] = max(dp[dsu.fh(i.back())], cnt[dsu.fh(i.back())]);
        for(auto j : i) {
            for(auto k : edges[j]) {
                if(dsu.fh(k) != dsu.fh(j))
                    dp[dsu.fh(k)] = max(dp[dsu.fh(k)], dp[dsu.fh(j)] + cnt[dsu.fh(k)]);
            }
        }
    }
    ll mx = 0;
    for(int i = 1; i <= n; ++i) {
        mx = max(mx, dp[i]);
    }
    cout << mx << endl;
    return 0;
}