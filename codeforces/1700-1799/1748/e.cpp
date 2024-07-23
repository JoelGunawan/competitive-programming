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
const int lim = 2e5 + 5;
const int lim2 = 1 << 18;
struct segment_tree {
    pair<int, int> a[2 * lim2];
    segment_tree() {
        for(int i = 0; i < 2 * lim2; ++i)
            a[i] = mp(0, 0);
    }
    void update(int idx, int val) {
        idx += lim2;
        a[idx] = mp(val, -(idx - lim2));
        while(idx) {
            idx /= 2;
            a[idx] = max(a[idx << 1], a[(idx << 1) + 1]);
        }
    }
    pair<int, int> query(int nd, int cl, int cr, int l, int r) {
        if(cl >= l && cr <= r) {
            //cout << cl << " " << cr << " " << l << " " << r << endl;
            return a[nd]; 
        }
        else if(cl > r || cr < l) {
            return mp(0, 0);
        }
        else {
            int mid = (cl + cr) / 2;
            return max(query(2 * nd, cl, mid, l, r), query(2 * nd + 1, mid + 1, cr, l, r));
        }
    }
    pair<int, int> query(int l, int r) {
        return query(1, 0, lim2 - 1, l, r);
    }
};
vector<int> t[lim];
segment_tree seg;
vector<int> v;
int build(int l, int r) {
    // choose left most max
    // divide into left and right
    // return left most max index
    int lf = -seg.query(l, r).se;
    //cout << "DEBUG " << l << " " << r << " " << lf << endl;
    //cout << seg.query(l, r).fi << " " << l << " " << lf << " " << r << endl;
    if(lf > l)
        t[lf].pb(build(l, lf - 1));
    if(lf < r) 
        t[lf].pb(build(lf + 1, r));
    v.pb(lf);
    return lf;
}
int mod = 1e9 + 7;
void solve() {
    int n, m;
    cin >> n >> m;
    //seg.update(1, 3);
    //cout << seg.query(1, 5).fi << endl;
    for(int i = 1; i <= n; ++i)
        t[i].clear();
    v.clear();
    int a[n + 1];
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        seg.update(i, a[i]);
    }
    build(1, n);
    ll dp[n + 1][m + 1];
    memset(dp, 0, sizeof(dp));
    for(auto x : v) {
        if(t[x].empty()) {
            for(int i = 1; i <= m; ++i)
                dp[x][i] = i;
        }
        else {
            for(int i = 1; i <= m; ++i)
                dp[x][i] = 1;
            for(auto y : t[x]) {
                if(y < x) {
                    // left case
                    for(int i = 1; i <= m; ++i) {
                        dp[x][i] *= dp[y][i - 1];
                    }
                }
                else {
                    // right case
                    for(int i = 1; i <= m; ++i) {
                        dp[x][i] *= dp[y][i];
                    }
                }
            }
            for(int i = 1; i <= m; ++i)
                dp[x][i] += dp[x][i - 1], dp[x][i] %= mod;
        }
    }
    cout << dp[v.back()][m] << endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        // reset
        solve();
    }
    return 0;
}