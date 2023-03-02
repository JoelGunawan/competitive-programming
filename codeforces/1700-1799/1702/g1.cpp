// header file
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
const int lim = 2e5 + 5;
vector<int> edges[lim];
bool ans = 1, vis[lim];
int sz[lim], k;
void dfs(int nd) {
    int cnt = 0;
    vis[nd] = 1;
    for(auto i : edges[nd]) {
        if(!vis[i]) {
            dfs(i);
            if(sz[i])
                ++cnt;
            sz[nd] += sz[i];
        }
    }
    //cout << nd << " " << cnt << endl;
    if((sz[nd] != k && cnt > 1) || cnt > 2)
        ans = 0;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        edges[u].pb(v);
        edges[v].pb(u);
    }
    int q;
    cin >> q;
    // find most left and most right based on ett numbers
    // has to form a straight line
    // find lca of entire thing
    // find left most and right most
    // right most -> use ett (the lower, the higher the number)
    // left most -> use the same, but invert the adj list

    // everything has to be parent of left most and right most
    while(q--) {
        cin >> k;
        memset(vis, 0, sizeof(vis));
        memset(sz, 0, sizeof(sz));
        ans = 1;
        for(int i = 0; i < k; ++i) {
            int x;
            cin >> x;
            ++sz[x];
        }
        dfs(1);
        if(ans)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}