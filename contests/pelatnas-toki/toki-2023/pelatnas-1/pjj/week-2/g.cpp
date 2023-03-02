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
const int lim = 5e5 + 5, lim2 = 18;
struct sparse_table {
    int log[lim];
    int a[lim][lim2 + 1];
    sparse_table() {
        log[0] = 0, log[1] = 0;
        for(int i = 2; i < lim; ++i) {
            log[i] = log[i / 2] + 1;
        }
        memset(a, -1, sizeof(a));
    }
    void build() {
        for(int i = 1; i <= lim2; ++i) {
            for(int j = 0; j + (1 << i) <= lim; ++j) {
                a[j][i] = min(a[j][i - 1], a[j + (1 << (i - 1))][i - 1]);
            }
        }
    }
    int query(int l, int r) {
        int tmp = log[r - l + 1];
        //cout << "QUERY " << " " << l << " " << r << " " << l << " " << (r - (1 << tmp) + 1) << " " << tmp << " " << min(a[l][tmp], a[r - (1 << (tmp)) + 1][tmp]) << endl;
        return min(a[l][tmp], a[r - (1 << (tmp)) + 1][tmp]);
    }
};
int depth[lim], to_nd[lim], ett[lim], sz[lim], t = 0;
vector<int> child[lim];
sparse_table sp;
void dfs(int nd) {
    ett[nd] = t;
    to_nd[t] = nd;
    sp.a[t++][0] = depth[nd];
    sz[nd] = 1;
    for(auto i : child[nd]) {
        depth[i] = depth[nd] + 1;
        dfs(i);
        sz[nd] += sz[i];
        to_nd[t] = nd;
        //cout << to_nd[t] << " " << depth[nd] << endl;
        sp.a[t++][0] = depth[nd];
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n;
    cin >> n;
    int par[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> par[i], child[par[i]].pb(i);
    dfs(0);
    sp.build();
    int q;
    cin >> q;
    /*
    for(int i = 0; i <= 2 * n; ++i)
        cout << sp.a[i][0] << " ";
    cout << endl;
    for(int i = 0; i <= 2 * n; ++i)
        cout << to_nd[i] << " ";
    cout << endl;
    for(int i = 1; i <= n; ++i) {
        cout << ett[i] << " ";
    }
    cout << endl;
    for(int i = 1; i <= n; ++i)
        cout << depth[i] << " ";
    cout << endl;
    */
    while(q--) {
        int x;
        cin >> x;
        int a[x];
        for(int i = 0; i < x; ++i)
            cin >> a[i];
        int res = 0;
        for(int i = 0; i < x; ++i) {
            bool cnt = 1;
            for(int j = 0; j < x; ++j) {
                if(i != j) {
                    //cout << "QUERYING " << a[i] << " " << a[j] << endl;
                    if(sp.query(min(ett[a[i]], ett[a[j]]), max(ett[a[i]], ett[a[j]])) == depth[a[j]])
                        cnt = 0;
                }
            }
            if(cnt)
                res += sz[a[i]];
            //cout << "OUT " << a[i] << " " << (int)cnt << endl;
        }       
        cout << res << endl;
    }    
    return 0;
}