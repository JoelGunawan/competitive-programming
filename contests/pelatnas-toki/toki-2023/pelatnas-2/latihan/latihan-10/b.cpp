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
const int lim = 1e6 + 5;
struct fenwick {
    ll a[lim];
    fenwick() {
        memset(a, 0, sizeof(a));
    }
    void upd(int idx, int val) {
        while(idx < lim) {
            a[idx] += val;
            idx += idx&-idx;
        }
    }
    ll q(int idx) {
        ll res = 0;
        while(idx) {
            res += a[idx];
            idx -= idx&-idx;
        }
        return res;
    }
};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    // k = 1 -> med optimal
    // k = 2 -> average optimal, tapi klo misal average itu koma, coba both aja just in case :3
    int n, m, k;
    cin >> n >> m >> k;
    int h[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> h[i];
    // alien trick to maximize segment count at M?
    ll cost[n + 1][n + 1];
    memset(cost, 0, sizeof(cost));
    ll pref[n + 1];
    memset(pref, 0, sizeof(pref));
    for(int i = 1; i <= n; ++i)
        pref[i] = pref[i - 1] + h[i];
    for(int i = 1; i <= n; ++i) {
        // di sini
        if(k == 1) {
            // simpen med
            // use set, nanti klo misal
            // simpan sum below med
            // simpan sum above med
            ll pre = 0, suff = 0;
            for(int j = i; j >= 1; --j) {
                // find sum of less than med and sum at med
                // 
                //cout << freq.q(median) * median << " " << tot.q(median) << " " << tot.q(1e6) - tot.q(median) << " " << freq.q(1e6) - freq.q(median) * median << endl;
                int median = (i + j) / 2;
                cost[j][i] = 1ll * (median - j + 1) * h[median] - pref[median] + pref[j - 1] + pref[i] - pref[median] - 1ll * (i - median) * h[median];
            }
        }
        else {
            // simpen average, get cost
            ll sum = 0, quad = 0;
            for(int j = i; j >= 1; --j) {
                sum += h[j];
                quad += 1ll * h[j] * h[j];
                ll len = i - j + 1, avg = sum / len;
                // try avg and avg + 1
                // calculatenya pake rumus
                // nanti tambah implementasi array cost buat k = 2
                // a1^2+a2^2+..+an^2+nx^2-2a1x-2a2x-2a3x
                // = a1^2+a2^2+...+an^2+nx^2-2x(a1+a2+a3+...+an)
                cost[j][i] = min(quad + len * avg * avg - 2 * avg * sum, quad + len * (avg + 1) * (avg + 1) - 2 * (avg + 1) * sum);
                //cout << cost[j][i] << " ";
            }
            //cout << endl;
        }
    }
    //cout << cost[1][n] << endl;
    // array cost nya udah bener, berarti skrg tinggal coba alien trick
    // tambahin penalty buat given run
    // tiap run O(N^2)
    // coba log n kali
    lll l = 0, r = 2e15, ans = -1;
    // penaltynya bs diganti" sesuai kebutuhan tergantunhg maksnya bs brp aja
    while(l <= r) {
        lll pen = (l + r) / 2;
        // buat dp O(N^2) tambahin pen tapi trus memo butuh minimal brp
        pair<lll, int> dp[n + 1];
        //cout << "DP" << endl;
        for(int i = 1; i <= n; ++i) {
            dp[i] = mp(dp[i - 1].fi + pen, dp[i - 1].se + 1);
            for(int j = i - 1; j >= 1; --j)
                dp[i] = min(dp[i], mp(dp[j - 1].fi + cost[j][i] + pen, dp[j - 1].se + 1));
            //cout << (ll)dp[i].fi << " " << dp[i].se << endl;
        }
        //cout << "DONE" << endl;
        //cout << pen << " " << dp[n].se << endl;
        if(dp[n].se <= m)
            ans = pen, r = pen - 1;
        else
            l = pen + 1;
        //cout << (ll)l << " " << (ll)r << " " << (ll) pen << " " << (ll)dp[n].fi << " " << dp[n].se << endl;
    }
    pair<lll, int> dp[n + 1];
    for(int i = 1; i <= n; ++i) {
        dp[i] = mp(dp[i - 1].fi + ans, dp[i - 1].se + 1);
        for(int j = i - 1; j >= 1; --j)
            dp[i] = min(dp[i], mp(dp[j - 1].fi + cost[j][i] + ans, dp[j - 1].se + 1));
    }
    //assert(ans != -1);
    //cout << dp[n].se << " " << (ll)dp[n].fi << endl;
    cout << (ll)(dp[n].fi - m * ans) << endl;
    return 0;
}