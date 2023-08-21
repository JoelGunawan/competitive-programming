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
    // fi -> max element
    // se -> index
    priority_queue<pair<int, int>> a[2 * lim];
    void update(int idx, pair<int, int> val) {
        idx += lim;
        while(idx) {
            a[idx].push(val);
            idx >>= 1;
        }
    }
    // find last position dimana max element > k
    int query(int nd, int cl, int cr, int k, int batas) {
        while(a[nd].size() && a[nd].top().se > batas) {
            a[nd].pop();
        }
        if(a[nd].empty() || a[nd].top().fi <= k)
            return -1;
        if(cl == cr)
            return cl;
        int mid = (cl + cr) >> 1;
        int ret = query(2 * nd + 1, mid + 1, cr, k, batas);
        if(ret != -1)
            return ret;
        ret = query(2 * nd, cl, mid, k, batas);
        return ret;
    }
};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n, d;
    cin >> n >> d;
    int a[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    int ans = 0;
    segment_tree seg;
    for(int i = n; i >= 1; --i) {
        int cur_len = seg.query(1, 0, lim - 1, a[i], i + d);
        if(cur_len == -1)
            ++cur_len;
        seg.update(cur_len + 1, mp(a[i], i));
        ans = max(ans, cur_len + 1);
    }
    // kasus turun naik
    return 0;
}