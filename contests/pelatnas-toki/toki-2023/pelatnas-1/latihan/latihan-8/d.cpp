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
int ans = 0, k;
const int lim = 1e5 + 5;
vector<int> edges[lim];
bool vis[lim], direct[lim];
int depth[lim];
int dfs(int nd) {
    vis[nd] = 1;
    int child_max_d = depth[nd];
    for(auto i : edges[nd]) {
        if(!vis[i]) {
            depth[i] = depth[nd] + 1;
            child_max_d = max(child_max_d, dfs(i));
        }
    }
    //cout << nd << " " << depth[nd] << " " << child_max_d << endl;
    if(!direct[nd] && nd != 1 && child_max_d - depth[nd] >= k - 1) {
        //cout << nd << endl;
        ++ans;
        return 0;
    }
    else
        return max(child_max_d, depth[nd]);
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n;
    cin >> n >> k;
    int x;
    cin >> x;
    if(x != 1)
        ++ans;
    for(int i = 2; i <= n; ++i) {
        int x;
        cin >> x;
        edges[x].pb(i);
        edges[i].pb(x);
        if(x == 1)
            direct[i] = 1;
    }
    dfs(1);
    cout << ans << endl;
    return 0;
}