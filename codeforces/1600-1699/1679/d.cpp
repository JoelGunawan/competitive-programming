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
int a[lim];
vector<int> edges[lim];
bool vis[lim], active[lim];
int max_ans[lim], gl;
ll k;
bool get_ans(int nd, int up) {
    vis[nd] = 1;
    active[nd] = 1;
    max_ans[nd] = max(max_ans[nd], 1);
    bool tmp = 0;
    for(auto i : edges[nd]) {
        //cout << nd << " " << i << " " << (int)active[i] << " " << up << endl;
        if(active[i])
            return 1;
        else if(a[i] <= up) {
            if(vis[i]) {
                max_ans[nd] = max(max_ans[nd], max_ans[i] + 1); 
            }
            else {
                //cout << "SEARCH" << endl;
                tmp |= get_ans(i, up), max_ans[nd] = max(max_ans[nd], max_ans[i] + 1);
            }
        }
    }
    //cout << nd << " " << max_ans[nd] << endl;
    gl = max(gl, max_ans[nd]);
    active[nd] = 0;
    return tmp;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m >> k;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for(int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        edges[u].pb(v);
    }
    int l = 1, r = 1e9, ans = -1;
    while(l <= r) {
        memset(vis, 0, sizeof(vis));
        memset(max_ans, 0, sizeof(max_ans));
        memset(active, 0, sizeof(active));
        gl = 0;
        int mid = (l + r) / 2;
        bool x = 0;
        for(int i = 1; i <= n; ++i) {
            //cout << (int)vis[i] << " " << a[i] << " " << mid << endl;
            if(!vis[i] && a[i] <= mid)
                x |= get_ans(i, mid);
            if(x)
                break;
        }
        if(x || gl >= k)
            r = mid - 1, ans = mid;
        else
            l = mid + 1;
    }
    cout << ans << endl;
    return 0;
}