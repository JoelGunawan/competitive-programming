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
const int lim = 5e5 + 5;
int a[lim];
vector<int> edges[lim];
bool vis[lim];
ll sub[lim], ans[lim];
void dfs(int nd) {
    vis[nd] = 1;
    ans[nd] = max(0, a[nd]), sub[nd] = a[nd];
    vector<int> c;
    ll mxchild = -1e18;
    for(auto i : edges[nd]) {
        if(!vis[i]) {
            c.pb(i);
            dfs(i);
            mxchild = max(mxchild, sub[i]);
        }
    }
    // options:
    // choose max child
    // choose only cur
    // choose cur and more than one child
    if(c.size() == 0) {
        //cout << nd << " " << sub[nd] << " " << ans[nd] << endl;
        return;
    }
    vector<ll> vals;
    for(auto i : c)
        vals.pb(sub[i]);
    sort(vals.begin(), vals.end());
    reverse(vals.begin(), vals.end());
    if(vals.size() == 1)
        ans[nd] = max({ans[nd], a[nd] + vals[0]}), sub[nd] = max(sub[nd], vals[0]);
    else {
        int pos_cnt = 0;
        ll pos_sum = 0;
        for(auto i : vals) {
            if(i >= 0)   
                ++pos_cnt, pos_sum += i;
        }
        sub[nd] = max({sub[nd], vals[0], sub[nd] + vals[0] + vals[1]});
        ans[nd] = max({ans[nd], vals[0] + a[nd], vals[0] + vals[1]});
        if(pos_cnt > 1) {
            sub[nd] = max(sub[nd], pos_sum + a[nd]);
        }
        if(pos_cnt > 2) {
            ans[nd] = max(ans[nd], pos_sum + a[nd]);
        }
        if(vals.size() > 2)
            ans[nd] = max(ans[nd], vals[0] + vals[1] + vals[2] + a[nd]);
    }
    //cout << "TST "<< nd << " " << sub[nd] << " " << ans[nd] << endl;
}
void tc() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i], edges[i].clear();
    // case line graph:
    // choose two maximum
    // otherwise choose node with 3 edges as root
    // for everything else other than root transition:
    // if more than 1 child, find maximum result from child
    // if exactly one child, then it has choice to inherit either the child value or the current value
    for(int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        edges[u].pb(v);
        edges[v].pb(u);
    }
    int root = -1;
    for(int i = 1; i <= n; ++i) {
        if(edges[i].size() > 2) {
            root = i;
        }
    }
    if(root == -1) {
        sort(a + 1, a + n + 1);
        if(n == 1)
            cout << max(0, a[1]) << endl;
        else
            cout << max({0, a[n], a[n] + a[n - 1]}) << endl;
        return;
    }
    for(int i = 1; i <= n; ++i)
        vis[i] = 0;
    dfs(root);
    ll res = 0;
    for(int i = 1; i <= n; ++i) {
        res = max(res, ans[i]);
    }
    cout << res << endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--)
        tc();
    return 0;
}