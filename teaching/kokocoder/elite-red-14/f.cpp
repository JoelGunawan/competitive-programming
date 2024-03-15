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
const int lim = 1 << 19;
struct segment_tree {
    pair<int, int> a[2 * lim];
    void update(int idx, pair<int, int> val) {
        idx += lim;
        a[idx] = val;
        while(idx > 1) {
            idx /= 2;
            a[idx] = max(a[2 * idx], a[2 * idx + 1]);
        }
    }
    pair<int, int> query(int nd, int cl, int cr, int l, int r, int low) {
        //cout << cl << " " << cr << endl;
        //cout << a[nd].fi << endl;
        if(a[nd].fi < low)
            return mp(1e9, 1e9);
        else if(cl >= l && cr <= r) {
            //cout << "TEST" << endl;
            //cout << cl << " " << cr << " " << a[nd].fi << " " << a[2 * nd].fi << " " << a[2 * nd + 1].fi << " " << low << endl;
            int mid = (cl + cr) / 2;
            if(cl == cr)
                return a[nd];
            else if((a[2 * nd].fi < a[2 * nd + 1].fi && a[2 * nd].fi >= low) || a[2 * nd + 1].fi < low)
                return query(2 * nd, cl, mid, l, r, low);
            else
                return query(2 * nd + 1, mid + 1, cr, l, r, low);
        }
        else if(cl > r || cr < l) {
            return mp(1e9, 1e9);
        }
        else {
            int mid = (cl + cr) / 2;
            return min(query(2 * nd, cl, mid, l, r, low), query(2 * nd + 1, mid + 1, cr, l, r, low));
        }
    }
};
segment_tree seg;
vector<int> child[lim];
int sz[lim], ett_idx[lim], t = 0;
void dfs(int nd) {
    sz[nd] = 1;
    ett_idx[nd] = t++;
    for(auto i : child[nd]) {
        dfs(i);
        sz[nd] += sz[i];
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    // node with smallest size that is bigger than half inside the subtree
    int n, q, e;
    cin >> n >> q;
    for(int i = 2; i <= n; ++i)
        cin >> e, child[e].pb(i);
    dfs(1);
    for(int i = 1; i <= n; ++i) {
        seg.update(ett_idx[i], mp(sz[i], i));
        //cout << ett_idx[i] << " ";
    }
    //cout << endl;
    //for(int i = 1; i <= n; ++i)
    //    cout << sz[i] << " ";
    //cout << endl;
    while(q--) {
        int x;
        cin >> x;
        //cout << ett_idx[x] << " " << ett_idx[x] + sz[x] - 1 << " " << sz[x] / 2 + sz[x] % 2 << endl;
        cout << seg.query(1, 0, lim - 1, ett_idx[x], ett_idx[x] + sz[x] - 1, sz[x] / 2 + sz[x] % 2).se << endl;
    }
    return 0;
}