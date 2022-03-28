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
int mod = 998244353;
ll powmod(ll a, ll b) {
    if(b == 0)
        return 1;
    else {
        ll tmp = powmod(a, b / 2);
        tmp = (tmp * tmp) % mod;
        return b & 1 ? (tmp * a) % mod : tmp;
    }
}
unordered_map<int, unordered_map<int, int>> memo;
unordered_map<int, unordered_map<int, bool>> vis;
ll dnc(int x, int n) {
    if(x == 1) {
        return (n * n) % mod;
    }
    else if(x > n)
        return 0;
    if(!vis[x][n]) {
        vis[x][n] = 1;
        ll res = 0;
        for(int i = 0; i <= n; ++i) {
            res += dnc(x / 2, i) * dnc(x - x / 2, n - i);
            res %= mod;
        }
        memo[x][n] = res;
    }
    //cout << l << " " << r << " " << n << " " << memo[mp(dist, n)] << endl;
    return memo[x][n];
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    // dp O(nm) transisi dp[i][j] = dp[i - 1][j - 1] * 1^2 + dp[i - 1][j - 2] * 2^2 + dp[i - 1][j - 3] * 3^2 + ...
	cout << dnc(m, n) << endl;
    return 0;
}