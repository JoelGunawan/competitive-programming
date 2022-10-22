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
int memo[(int)1e5 + 5];
ll powmod(ll a, ll b) {
    if(b <= 0)
        return 1;
    else if(memo[b] != -1)
        return memo[b];
    else {
        ll tmp = powmod(a, b >> 1);
        tmp = (tmp * tmp) % mod;
        return memo[b] = b & 1 ? (tmp * a) % mod : tmp;
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    memset(memo, -1, sizeof(memo));
    int n;
    cin >> n;
    int cnt[71];
    memset(cnt, 0, sizeof(cnt));
    for(int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        ++cnt[x];
    }
    int dp[71][1 << 19];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    vector<int> primes;
    for(int i = 2; i <= 70; ++i) {
        bool prime = 1;
        for(int j = 2; j < i; ++j) {
            if(i % j == 0)
                prime = 0;
        }
        if(prime)
            primes.pb(i);
    }
    for(int i = 1; i <= 70; ++i) {
        int x = 0, tmp = i;
        for(int j = 0; j < primes.size(); ++j) {
            if(tmp % primes[j] == 0) {
                int cnt = 0;
                while(tmp % primes[j] == 0) {
                    tmp /= primes[j];
                    ++cnt;
                }
                if(cnt & 1) {
                    x += 1 << j;
                }
            }
        }
        for(int j = 0; j < 1 << 19; ++j) {
            if(cnt[i] == 0)
                dp[i][j] = dp[i - 1][j];
            else {
                dp[i][j] = (1ll * powmod(2, cnt[i] - 1) * dp[i - 1][j]) % mod + (1ll * powmod(2, cnt[i] - 1) * dp[i - 1][j ^ x]) % mod;
                dp[i][j] %= mod;
            }
        }
    }
    cout << dp[70][0] - 1 << endl;
    return 0;
}