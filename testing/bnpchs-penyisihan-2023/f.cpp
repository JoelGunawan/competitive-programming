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
    int a[2 * lim];
    segment_tree() {
        memset(a, 0, sizeof(a));
    }
    void update(int idx, int val) {
        idx += lim;
        a[idx] = max(a[idx], val);
        while(idx) {
            idx /= 2;
            a[idx] = max(a[2 * idx], a[2 * idx + 1]);
        }
    }
    int query(int nd, int cl, int cr, int l, int r) {
        if(cl >= l && cr <= r) 
            return a[nd];
        else if(cr < l || cl > r)
            return 0;
        else {
            int mid = (cl + cr) / 2;
            return max(query(2 * nd, cl, mid, l, r), query(2 * nd + 1, mid + 1, cr, l, r));
        }
    }
};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    // use set
    int n, m;
    cin >> n >> m;
    int a[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    segment_tree seg;
    for(int i = 1; i <= m; ++i) {
        int l, r;
        cin >> l >> r;
        seg.update(l, r);
    }
    vector<int> v;
    for(int i = 1; i <= n; ++i) {
        v.pb(a[i]);
    }
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    for(int i = 1; i <= n; ++i) {
        a[i] = lb(v.begin(), v.end(), a[i]) - v.begin();
    }
    set<int> s[v.size()];
    for(int i = 1; i <= n; ++i)
        s[a[i]].insert(i);
    int ops = 0;
    for(int i = 0; i < v.size(); ++i) {
        int cur = 0;
        while(s[i].ub(cur) != s[i].end()) {
            cur = *s[i].ub(cur);
            int mxr = seg.query(1, 0, lim - 1, 1, cur);
            while(s[i].ub(cur) != s[i].end() && *s[i].ub(cur) <= mxr)
                s[i].erase(s[i].ub(cur)), ++ops;
        }
    }
    cout << ops << endl;
    return 0;
}