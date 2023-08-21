// header file
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// pragma
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,sse4,avx2,mmx,tune=native")
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
const int lim = 100005;
const int klim = 25;
int pref[lim];
int cl, cr, a[lim];
ll cur;
int cnt[lim];
ll get_cost(int l, int r) {
    while(cl < l) {
        --cnt[a[cl]];
        cur -= cnt[a[cl]];
        //cout << "REDL " << cnt[a[cl]] << endl;
        ++cl;
    }
    while(cl > l) {
        --cl;
        //cout << "ADDL " << cnt[a[cl]] << endl;
        cur += cnt[a[cl]];
        ++cnt[a[cl]];
    }
    while(cr < r) {
        ++cr;
        //cout << "ADD " << cnt[a[cr]] << endl;
        cur += cnt[a[cr]];
        ++cnt[a[cr]];
    }
    while(cr > r) {
        --cnt[a[cr]];
        cur -= cnt[a[cr]];
        //cout << "RED " << cnt[a[cr]] << endl;
        --cr;
    }
    //cout << l << " " << r << " " << cur << endl;
    return cur;
}
ll dp[klim][lim];
void calc(int depth, int l, int r, int optl, int optr) {
    if(l > r)
        return;
    if(l == r) {
        // calc dp value only
        for(int i = optl; i <= optr && i < l; ++i) {
            dp[depth][l] = min(dp[depth][l], dp[depth - 1][i] + get_cost(i + 1, l));
        }
        return;
    }
    ll tmp = 0;
    // calc opt and dp val
    int m = (l + r) / 2;
    for(int i = optl; i < m && i <= optr; ++i) {
        if(get_cost(i + 1, m) + dp[depth - 1][i] < dp[depth][m]) {
            tmp = i;
            dp[depth][m] = dp[depth - 1][i] + get_cost(i + 1, m);
        }
    }
    calc(depth, l, m - 1, optl, tmp);
    calc(depth, m + 1, r, tmp, optr);
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    // ini soal dr cf ga sih
    // dp dnc
    // gmn cara calculate cost?
    // observe calculate cost bisa sliding window
    // two pointers
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    for(int i = 1; i <= n; ++i) {
        pref[i] = pref[i - 1] + (a[i] == 1);
    }
    for(int i = 0; i <= n; ++i) {
        for(int j = 0; j <= k; ++j)
            dp[j][i] = 1e18;
    }
    dp[0][0] = 0;
    cl = 1, cr = 1, cnt[a[1]]++;
    for(int i = 1; i <= k; ++i) {
        calc(i, 1, n, 0, n);
    }
    cout << dp[k][n] << endl;
    /*
    ll dp[n + 1][k + 1];
    for(int i = 0; i <= n; ++i)
        for(int j = 0; j <= k; ++j)
            dp[i][j] = 1e18;
    dp[0][0] = 0;
    int cnt[n + 1];
    for(int j = 1; j <= k; ++j) {
        for(int i = j; i <= n; ++i) {
            // coba cek optimal
            // cek previous
            ll cost = 0;
            memset(cnt, 0, sizeof(cnt));
            for(int l = i; l >= j; --l) {
                cost += cnt[a[l]];
                ++cnt[a[l]];
                //cout << i << " " << j << " " << l << " " << cost << " " << dp[i - 1][l - 1] << endl;
                dp[i][j] = min(dp[i][j], cost + dp[l - 1][j - 1]);
            }
            //cout << dp[i][j] << endl;
        }
        //cout << endl;
    }
    cout << dp[n][k] << endl;
    */
    // sub 1 -> buat prefix/suffix cost
    // sub 2 -> buat dp O(N^2K)
    // sub 3 -> easy cost calculation (bisa O(1)) jadi pake dp dnc biasa
    /*
    ll pref[n + 1], suff[n + 2];
    memset(pref, 0, sizeof(pref));
    memset(suff, 0, sizeof(suff));
    int cnt[n + 1];
    memset(cnt, 0, sizeof(cnt));
    for(int i = 1; i <= n; ++i) {
        pref[i] = pref[i - 1] + cnt[a[i]];
        ++cnt[a[i]];
    }
    memset(cnt, 0, sizeof(cnt));
    for(int i = n; i >= 1; --i) {
        suff[i] = suff[i + 1] + cnt[a[i]];
        ++cnt[a[i]];
    }
    ll ans = 1e18;
    for(int i = 1; i <= n; ++i) {
        ans = min(ans, pref[i] + suff[i + 1]);
    }
    if(k == 2)
        cout << ans << endl;
    else
        cout << pref[n] << endl;
    */
    return 0;
}