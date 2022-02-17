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
struct segtree {
    int a[1 << 18];
    int lazy[1 << 18];
    int arr_size = 1 << 17;
    segtree() {
        for(int i = 0; i < 1 << 18; ++i)
            a[i] = 1e9;
    }
    int merge(int a, int b) {
        return min(a, b);
    }
    void update(int nd, int cur_left, int cur_right, int left, int right, int value) {
        //cout << nd << " " << cur_left << " " << cur_right << " " << left << " " << right << " " << value << endl;
        if(cur_left >= left && cur_right <= right) {
            a[nd] += value;
            lazy[nd] += value;
        }
        else if(cur_left > right || cur_right < left)
            return;
        else {
            int mid = (cur_left + cur_right) / 2;
            if(lazy[nd] != 0) {
                update(2 * nd, cur_left, mid, cur_left, mid, lazy[nd]);
                update(2 * nd + 1, mid + 1, cur_right, mid + 1, cur_right, lazy[nd]);
                lazy[nd] = 0;
            }
            update(2 * nd, cur_left, mid, left, right, value);
            update(2 * nd + 1, mid + 1, cur_right, left, right, value);
            a[nd] = merge(a[2 * nd], a[2 * nd + 1]);
        }
    }
    int query(int nd, int cur_left, int cur_right, int left, int right) {
        if(cur_left >= left && cur_right <= right) {
            return a[nd];
        }
        else if(cur_left > right || cur_right < left) {
            return 2e9;
        }
        else {
            int mid = (cur_left + cur_right) / 2;
            if(lazy[nd] != 0) {
                update(2 * nd, cur_left, mid, cur_left, mid, lazy[nd]);
                update(2 * nd + 1, mid + 1, cur_right, mid + 1, cur_right, lazy[nd]);
                lazy[nd] = 0;
            }
            return merge(query(2 * nd, cur_left, mid, left, right), query(2 * nd + 1, mid + 1, cur_right, left, right));
        }
    }
};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    segtree seg;
    int n, m;
    cin >> n >> m;
    // find the amount of segments that are not touching the current index
    // O(nm)
    // lazy max query segtree
    // O(n^2m) for easy, O(nmlogn) for hard
    int a[n];
    pair<int, int> segments[m];
    for(int i = 0; i < n; ++i)
        cin >> a[i], seg.update(1, 0, seg.arr_size - 1, i, i, a[i] - 1e9);
    //for(int i = 0; i < n; ++i)
    //    cout << seg.query(1, 0, seg.arr_size - 1, i, i) << " ";
    //cout << endl;
    for(int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        segments[i] = mp(--u, --v);
        seg.update(1, 0, seg.arr_size - 1, u, v, -1);
    }
    pair<int, pair<bool, int>> sweep[2 * m];
    for(int i = 0; i < m; ++i) {
        sweep[2 * i] = mp(segments[i].fi, mp(0, segments[i].se));
        sweep[2 * i + 1] = mp(segments[i].se, mp(1, segments[i].fi));
    }
    sort(sweep, sweep + 2 * m);
    int res = 0, res_idx = -1, idx = 0;
    for(int i = 0; i < n; ++i) {
        // choose all segments that do not intersect with the current segment
        // and decrease all the values by 1
        while(idx < 2 * m && sweep[idx].fi == i && !sweep[idx].se.fi) {
            seg.update(1, 0, seg.arr_size - 1, sweep[idx].fi, sweep[idx].se.se, 1);
            ++idx;
        }
        int minimum = seg.query(1, 0, seg.arr_size - 1, 0, n - 1);
        if(a[i] - minimum >= res)
            res_idx = i, res = a[i] - minimum;
        while(idx < 2 * m && sweep[idx].fi == i && sweep[idx].se.fi) {
            seg.update(1, 0, seg.arr_size - 1, sweep[idx].se.se, sweep[idx].fi, -1);
            ++idx;
        }
        //for(int j = 0; j < n; ++j)
        //    cout << seg.query(1, 0, seg.arr_size - 1, j, j) << " ";
        //cout << endl;
    }
    cout << res << endl;
    vector<int> ans;
    for(int i = 0; i < m; ++i) {
        if(!(res_idx >= segments[i].fi && res_idx <= segments[i].se))
            ans.pb(i + 1);
    }
    cout << ans.size() << endl;
    for(auto i : ans)
        cout << i << " ";
    cout << endl;
    return 0;
}