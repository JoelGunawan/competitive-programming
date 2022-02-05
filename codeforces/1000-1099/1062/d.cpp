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
const int lim = 100001;
ll node_val[lim];
bool vis[lim];
vector<int> edges[lim];
ll dfs(int nd) {
    vis[nd] = 1;
    ll res = node_val[nd];
    for(auto i : edges[nd])
        if(!vis[i])
            res += dfs(i);  
    return res;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    // create a graph and dfs through it (find largest connected component)
    for(int i = 2; i <= n; ++i) {
        for(int j = 2 * i; j <= n; j += i)
            edges[i].pb(j), edges[j].pb(i), node_val[i] += j / i, node_val[j] += j / i;
    }
    ll res = 0;
    for(int i = 2; i <= n; ++i)
        if(!vis[i]) {
            res = max(res, dfs(i));
        }
    cout << 2 * res << endl;
    return 0;
}