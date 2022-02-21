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
vector<int> edges[200001];
int seg_size[200001];
bool vis[200001];
int get_size(int nd) {
    vis[nd] = 1;
    for(auto i : edges[nd]) {
        if(!vis[i])
            seg_size[nd] += get_size(i);
    }
    if(seg_size[nd] == 0)
        seg_size[nd] = 1;
    return seg_size[nd];
}
pair<int, int> ans[200001];
void dfs(int nd, int cur_idx) {
    vis[nd] = 1;
    ans[nd] = mp(cur_idx, cur_idx + seg_size[nd] - 1);
    for(auto i : edges[nd]) {
        if(!vis[i]) {
            dfs(i, cur_idx);
            cur_idx += seg_size[i];
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        edges[u].pb(v);
        edges[v].pb(u);
    }
    get_size(1);
    memset(vis, 0, sizeof(vis));
    dfs(1, 1);
    for(int i = 1; i <= n; ++i) 
        cout << ans[i].fi << " " << ans[i].se << endl;
    return 0;
}