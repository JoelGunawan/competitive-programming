// header file
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// pragma
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
// macros
//#define endl "\n"
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
void find_mask(int num, int n, vector<int> &res) {
    vector<int> zeropos;
    for(int i = 0; i < n; ++i) {
        if(!((1 << i) & num))
            zeropos.pb(i);
    }
    for(int i = 0; i < 1 << zeropos.size(); ++i) {
        int cur = 0;
        for(int j = 0; j < zeropos.size(); ++j) {
            if((1 << j) & i) {
                cur += 1 << zeropos[j];
            }
        }
        res.pb(cur);
    }
}
int main() {
    //ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    int p[n], q[m + 1];
    for(int i = 0; i < n; ++i)
        cin >> p[i];
    for(int i = 1; i <= m; ++i)
        cin >> q[i];
    sort(q + 1, q + m + 1);
    // coba meja ke-i kita insert
    // or with every non intersecting mask
    // n * n * 3^13
    // utk n dan n - 1 bisa di brute force saja
    // buat dp[n][1 << n];
    int ans = m * a;
    int sz = min(n, m);
    int dp[sz + 1][1 << n];
    for(int i = 0; i <= sz; ++i)
        for(int j = 0; j < 1 << n; ++j)
            dp[i][j] = 1e9;
    dp[0][0] = 0;
    // pilih submask yang bisa untuk i (pilih jika optimal saja (tidak ada meja yang "buang"))
    // find non intersecting masks?
    // how though :thinking:
    // inverse of submasks :)
    // every position yang 1 -> harus jadi 0
    // every position yang 0 -> terserah
    // 2^zeropos
    vector<int> bitmasks[1 << n];
    for(int i = 0; i < 1 << n; ++i)
        find_mask(i, n, bitmasks[i]);
    for(int i = 1; i <= sz; ++i) {
        for(int j = 1; j < 1 << n; ++j) {
            // proses bitmask sekarang, apakah optimal answer?
            vector<int> tables;
            int sum = 0;
            for(int k = 0; k < n; ++k) {
                if((1 << k) & j)
                    tables.pb(p[k]), sum += p[k];
            }
            //cout << i << " " << j << " " << sum << " " << tables.front() << " " << q[i] << endl;
            if(tables.size() && (sum - tables.front() < q[i]) && sum >= q[i]) {
                for(auto k : bitmasks[j]) {
                    dp[i][j | k] = min(dp[i][j | k], dp[i - 1][k] + ((int)tables.size() - 1) * b);
                    //cout << i << " " << (j | k) << " " << dp[i][j | k] << endl;
                    ans = min(ans, dp[i][j | k] + (m - i) * a);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}