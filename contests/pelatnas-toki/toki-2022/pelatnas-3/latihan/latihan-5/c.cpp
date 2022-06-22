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
int mod = 1e9 + 7;
ll fact[3005];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n;
    cin >> n;
    fact[0] = 1;
    for(int i = 1; i < 3005; ++i)
        fact[i] = (fact[i - 1] * i) % mod;
    int a[n], b[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    for(int i = 0; i < n; ++i)
        cin >> b[i];
    sort(a, a + n);
    sort(b, b + n);
    // pos -> indicates first skipped is here, means all B[j] >= A[i] has to be taken
    // for each position, how to guarantee that all B[j] >= A[i] is chosen?
    // for each pos, dp[pos][taken] for each index, determine ada berapa
    // taken ada 2 state, taken yang lebih dari wajib dan taken yang kurang dari wajib
    // taken kurang dri wajib ga usah modif nilai taken
    // taken lebih dri wajib modif nilai taken
    // pake sweep line buat precalculate klo tiap indeks itu transisi taken ada brp, transisi not taken ada brp
    ll dp[n + 1][n + 1];
    memset(dp, 0, sizeof(dp));
    dp[n][0] = 1;
    for(int i = n - 1; i >= 0; --i) {
        // dp[pos][taken] = dp[pos + 1][taken] + if(possible) dp[pos + 1][taken - 1]
        int geq = 0;
        for(int j = 0; j < n; ++j) {
            if(b[j] >= a[i])
                ++geq;
        }
        for(int j = 0; j <= n; ++j) {
            // not take
            dp[i][j] = dp[i + 1][j];
            // take
            if(j > 0 && geq - j >= 0)
                dp[i][j] += (1ll * dp[i + 1][j - 1] * (geq - j + 1)) % mod;
            dp[i][j] %= mod;
        }
    }
    ll dp2[n + 1][n + 1];
    memset(dp2, 0, sizeof(dp2));
    for(int i = 0; i < n; ++i) {
        int le = 0;
        for(int j = 0; j < n; ++j) {
            if(b[j] < a[i])
                ++le;
        }
        // not take
        
        // take

        // there are invalid and valid takes
    }
    ll res = 0;
    for(int i = 0; i < n; ++i) {
        // find amount of geq and amount of le
        int geq = 0, le = 0, le_idx = -1; 
        for(int j = 0; j < n; ++j) {
            if(b[j] < a[i])
                ++le, le_idx = j;
            else
                ++geq;
        }
        // do local dp
        ll local_dp[i + 1][i + 1];
        memset(local_dp, 0, sizeof(local_dp));
        local_dp[i][0] = 1;
        int cur = le_idx + 1;
        // generate local dp by going to each index, finding how many le positions are available
        for(int j = i - 1; j >= 0; --j) {
            while(cur > 0 && b[cur - 1] >= a[j])
                --cur;
            //cout << le_idx - cur + 1 << endl;
            for(int k = 0; k < i + 1; ++k) {
                // tambah ge
                local_dp[j][k] = local_dp[j + 1][k];
                // tambah le
                if(k > 0 && le_idx - cur + 1 >= k)
                    local_dp[j][k] += (1ll * local_dp[j + 1][k - 1] * (le_idx - cur + 2 - k)) % mod;
                local_dp[j][k] %= mod;
                //cout << j << " " << k << " " << local_dp[j][k] << endl;
            }
        }
        for(int j = 0; j <= min(geq, i); ++j) {
            // find how many ways to choose geqs
            // local_dp ambil j ke geq
            // dp ambil geq - j
            ll tmp1 = local_dp[0][i - j], tmp2 = dp[i + 1][geq - j];
            // dari j, cek di geq sisa berapa slot, masukkan j
            //cout << i << " " << tmp1 << " " << tmp2 << " " << geq << " " << j << endl;
            res += (((tmp1 * tmp2) % mod) * fact[j]) % mod;
            res %= mod;
        }
    }
    cout << (res + dp[0][n]) % mod << endl;
    return 0;
}