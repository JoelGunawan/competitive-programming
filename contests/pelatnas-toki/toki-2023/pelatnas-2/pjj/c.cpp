#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
const int lim = 1 << 16;
struct segment_tree {
    int a[2 * lim], lazy[2 * lim];
    segment_tree() {
        fill(a, a + 2 * lim, 2e9);
        fill(lazy, lazy + 2 * lim, 0);
    }
    void propagate(int nd, int cl, int cr) {
        if(cl != cr) {
            lazy[2 * nd] += lazy[nd];
            lazy[2 * nd + 1] += lazy[nd];
        }
        a[nd] += lazy[nd];
        lazy[nd] = 0;
    }
    void update(int nd, int cl, int cr, int l, int r, int val) {
        propagate(nd, cl, cr);
        if(cl >= l && cr <= r) {
            lazy[nd] += val;
            propagate(nd, cl, cr);
        }
        else if(cl > r || cr < l) {
            
        }
        else {
            int mid = (cl + cr) / 2;
            update(2 * nd, cl, mid, l, r, val);
            update(2 * nd + 1, mid + 1, cr, l, r, val);
            a[nd] = min(a[2 * nd], a[2 * nd + 1]);
        }
        //cout << cl << " " << cr << " " << a[nd] << endl;
    }
    int query(int nd, int cl, int cr, int l, int r) {
        propagate(nd, cl ,cr);
        //cout << cl << " " << cr << " " << l << " " << r << " " << a[nd] << endl;
        if(cl >= l && cr <= r) {
            return a[nd];
        }
        else if(cr < l || cl > r)
            return 2e9;
        else {
            int mid = (cl + cr) / 2;
            return min(query(2 * nd, cl, mid, l, r), query(2 * nd + 1, mid + 1, cr, l, r));
        }
    }
};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, k;
    cin >> n >> k;
    int a[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    // dp[n][k]
    // ambil dari [n - i][k - 1]
    // cost -> last_occur - first_occur
    // elemen kedua terakhir +x1
    // elemen ketiga terakhir +x2 
    // ...
    // tentuin x pake map atau array jg bs
    // x -> jarak dr last occur
    int occur[n + 1];
    memset(occur, -1, sizeof(occur));
    segment_tree seg[k + 1];
    int dp[k + 1][n + 1];
    for(int i = 0; i <= k; ++i)
        for(int j = 0; j <= n; ++j)
            dp[i][j] = 2e9;
    dp[0][0] = 0;
    seg[0].update(1, 0, lim - 1, 0, 0, -2e9);
    for(int i = 1; i <= n; ++i) {
        if(occur[a[i]] == -1) {
            occur[a[i]] = i;
        }
        else {
            //cout << i - occur[a[i]] << endl;
            for(int j = 0; j <= k; ++j) {
                //cout << "j " << j << endl;
                seg[j].update(1, 0, lim - 1, 0, occur[a[i]] - 1, i - occur[a[i]]);
            }
            occur[a[i]] = i;
        }
        for(int j = 1; j <= k; ++j) {
            dp[j][i] = seg[j - 1].query(1, 0, lim - 1, 0, i - 1);
            //cout << dp[j][i] << " ";
            seg[j].update(1, 0, lim - 1, i, i, -2e9 + dp[j][i]);
        }   
        //cout << endl;
    }
    cout << dp[k][n] << endl;
}