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
vector<int> v[lim];
bool vis[lim];
int c[lim];
void dfs(int nd) {
    vis[nd] = 1;
    ll a = 0;
    for(auto i : v[nd]) {
        if(!vis[i])
            dfs(i);
        a += c[i];
    }
    if(v[nd].size() != 0)
        c[nd] = min((ll)c[nd], a);
}
void tc() {
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; ++i)
        v[i].clear(), vis[i] = 0;
    for(int i = 1; i <= n; ++i)
        cin >> c[i];
    int p[k + 1];
    for(int i = 1; i <= k; ++i)
        cin >> p[i];
    for(int i = 1; i <= k; ++i) {
        c[p[i]] = 0;
    }
    for(int i = 1; i <= n; ++i) {
        int m;
        cin >> m;
        for(int j = 1; j <= m; ++j) {
            int x;
            cin >> x;
            v[i].pb(x);
        }
    }
    for(int i = 1; i <= n; ++i) {
        if(!vis[i])
            dfs(i);
    }
    for(int i = 1; i <= n; ++i)
        cout << c[i] << " ";
    cout << endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--)
        tc();
    return 0;
}