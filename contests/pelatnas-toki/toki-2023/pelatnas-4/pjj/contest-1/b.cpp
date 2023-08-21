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
int mod = 1e9 + 7;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    // pake dp[l][r][cnt]
    // nanti transisinya harus pake yg di dalam l, r
    // boleh given l, r bisa ke l, r - x, dkk
    // base case: dp[l][r][1] = 1
    // dp[l][r][cnt] = dp[l + 1][r][cnt - 1] + dp[l][r - 1][cnt - 1] -> kasus tambah count
    // dp[l][r][cnt] = dp[l + 1][r][cnt] + dp[l][r - 1][cnt] -> kasus tidak tambah count
    // how to avoid double counting in case 2?
    // count manual, only add during transitions? O(n^wtf)
    // coba dlu, cek transisi case 1 bener ga
    int n, k;
    cin >> n >> k;
    if(k == 1)
        cout << 1 << endl, exit(0);
    int dp[n][n][k];
    int isi[n][n][k];
    memset(isi, 0, sizeof(isi));
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i < n; ++i) {
        for(int j = i + 2; j < n; ++j) {
            if(i == 0 && j == n - 1)
                continue;
            dp[i][j][1] = 1;
            for(int e = 0; e <= i; ++e) {
                for(int f = j; f < n; ++f) {
                    isi[e][f][1] = (isi[e][f][1] + dp[i][j][1]) % mod;
                }
            }
        }
    }
    for(int i = 2; i < n; ++i) {
        for(int l = 0; i + l < n; ++l) {
            for(int j = 2; j < k; ++j) {
                // dp[i][j][l] = dp[x][y][l - 1]
                int r = l + i;
                if(l == 0 && r == n - 1)
                    continue;
                // buat prefix
                // kasus segitiga (bisa gabung dengan segment luar karena boleh menempel dengan segment lain?)
                // find amount completely within a certain L, R
                // nanti jalanin prefix, suffix
                // prefix boleh dipasangkan sama suffix, nanti dikali aja
                for(int x = l + 1; x < r; ++x) {
                    for(int y = 0; y < k; ++y) {
                        dp[l][r][j] = (dp[l][r][j] + 1ll * max(1, isi[l][x][y]) * max(1, isi[x][r][k - y - 1])) % mod;
                    }
                }
                for(int e = 0; e <= l; ++e) {
                    for(int f = r; f < n; ++f) {
                        isi[e][f][j] = (isi[e][f][j] + dp[l][r][j]) % mod;
                    }
                }
                cout << l << " " << r << " " << j << " " << dp[l][r][j] << endl;
            }
        }
    }
    ll res = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            res += dp[i][j][k - 1];
        }
    }
    cout << res % mod << endl;
    // buat supaya ordered pair menaik terus aja
    return 0;
}