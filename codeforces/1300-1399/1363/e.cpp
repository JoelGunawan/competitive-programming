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
const int lim = 200005;
int a[lim], b[lim], c[lim];
int cnt[lim][2];
// zero_cnt and one_cnt itu offsetnya
// yang ga ke offset ga usah simpen
bool vis[lim];
vector<int> edges[lim];
ll dfs(int nd, int minimum) {
    vis[nd] = 1;
    minimum = min(minimum, a[nd]);
    if(b[nd] != c[nd]) {
        ++cnt[nd][c[nd]];
    }
    ll res = 0;
    for(auto i : edges[nd]) {
        if(!vis[i]) {
            res += dfs(i, minimum);
            cnt[nd][0] += cnt[i][0];
            cnt[nd][1] += cnt[i][1];
        }
    }
    int tmp = min(cnt[nd][0], cnt[nd][1]);
    res += (2ll * tmp * minimum);
    cnt[nd][0] -= tmp;
    cnt[nd][1] -= tmp;
    return res;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int start[2], target[2];
    start[0] = 0, start[1] = 1, target[0] = 0, target[1] = 0;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i] >> b[i] >> c[i];
        ++start[b[i] & 1];
        ++target[c[i] & 1];
    }
    for(int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        edges[u].pb(v);
        edges[v].pb(u);
    }
    if(start[0] != target[0]) {
        cout << -1 << endl;
        return 0;
    }
    cout << dfs(1, INT_MAX) << endl;
    return 0;
}