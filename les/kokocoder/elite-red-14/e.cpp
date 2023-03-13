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
const int lim = 2e5 + 5;
vector<int> child[lim];
int d[lim], ett_idx[lim], sz[lim], t = 0;
void dfs(int nd) {
    sz[nd] = 1;
    ett_idx[nd] = t++;
    for(auto i : child[nd]) {
        d[i] = d[nd] + 1;
        dfs(i);
        sz[nd] += sz[i];
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    // euler tour
    int n;
    cin >> n;
    int p[n + 1];
    for(int i = 2; i <= n; ++i)
        cin >> p[i], child[p[i]].pb(i);
    int q;
    cin >> q;
    dfs(1);
    vector<int> mem[n + 1];
    for(int i = 1; i <= n; ++i) {
        mem[d[i]].pb(ett_idx[i]);
    }
    //for(int i = 0; i <= n; ++i) {
    //    for(auto j : mem[i])
    //        cout << j << " ";
    //    cout << endl;
    //}
    //for(int i = 1; i <= n; ++i)
    //    cout << ett_idx[i] << " ";
    //cout << endl;
    //for(int i = 1; i <= n; ++i) 
    //    cout << d[i] << " ";
    //cout << endl;
    while(q--) {
        int u, d;
        cin >> u >> d;
        int l = ett_idx[u], r = l + sz[u] - 1;
        cout << ub(mem[d].begin(), mem[d].end(), r) - lb(mem[d].begin(), mem[d].end(), l) << endl;
    }
    return 0;
}