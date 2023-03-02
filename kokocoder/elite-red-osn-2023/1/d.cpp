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
int res[lim], par[lim], n, ans;
void st(int nd) {
    res[nd] = 1;
    for(auto i : edges[nd]) {
        if(i != par[nd])
            st(i);
    }
}
int dfs(int nd) {
    int tmp = 1;
    for(auto i : edges[nd]) {
        if(i != par[nd]) {
            par[i] = nd;
            tmp += dfs(i);
        }
    }
    if(tmp == n / 2)
        ans = nd;
    return tmp;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        edges[u].pb(v);
        edges[v].pb(u);
    }
    dfs(1);
    if(ans == 0)
        cout << "NO" << endl;
    else {
        cout << "YES" << endl;
        st(ans);
        for(int i = 1; i <= n; ++i)
            cout << res[i] << " ";
        cout << endl;
    }
    return 0;
}