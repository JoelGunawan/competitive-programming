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
typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> edges[n + 1];
    for(int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        edges[u].pb(v);
        edges[v].pb(u);
    }
    bool vis[n + 1];
    memset(vis, 0, sizeof(vis));
    priority_queue<pair<int, int>> pq;
    for(int i = 1; i <= k; ++i) {
        int p, h;
        cin >> p >> h;
        pq.push(mp(h, p));
    }
    vector<int> ans;
    while(pq.size()) {
        int rem = pq.top().fi, nd = pq.top().se;
        pq.pop();
        if(vis[nd])
            continue;
        vis[nd] = 1;
        ans.pb(nd);
        if(rem >= 1) {
            for(auto i : edges[nd]) {
                if(!vis[i]) {
                    pq.push(mp(rem - 1, i));
                }
            }
        }
    }
    cout << ans.size() << endl;
    sort(ans.begin(), ans.end());
    for(auto i : ans)
        cout << i << " ";
    cout << endl;
    return 0;
}