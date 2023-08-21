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
ll fact[2005], inv[2005];
int mod = 998244353;
ll mul(ll a, ll b) {
    return (a * b) % mod;
}
ll powmod(ll a, ll b) {
    if(b == 0)
        return 1;
    else {
        ll tmp = powmod(a, b >> 1);
        tmp = (tmp * tmp) % mod;
        return b & 1 ? (tmp * a) % mod : tmp;
    }
}
ll combinmod(ll a, ll b) {
    if(a < b)
        return 0;
    return mul(fact[a], mul(inv[b], inv[a - b]));
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    fact[0] = inv[0] = 1;
    for(int i = 1; i <= 2000; ++i)
        fact[i] = mul(fact[i - 1], i), inv[i] = powmod(fact[i], mod - 2);
    int n, m, s;
    cin >> n >> m >> s;
    int a[m][n + 1];
    for(int i = 1; i < m; ++i) {
        for(int j = 1; j <= n; ++j)
            cin >> a[i][j];
    }
    // m n
    // consider baseline k nya berapa, terus wktu di bawah tambah introduce 1 new, 2 new, possibilitynya berapa
    int mn[n + 1];
    fill(mn, mn + n + 1, 1e9);
    map<int, int> b;
    for(int i = 1; i < m; ++i) {
        for(int j = 1; j <= n; ++j)
            mn[a[i][j]] = min(mn[a[i][j]], j);
    }
    // nnti rank itu i.fi paling tinggi
    // klo tambah, berarti nanti juga rank nya berkurang
    vector<int> v;
    for(int i = 1; i <= n; ++i)
        v.pb(i);
    int ans[n + 1];
    memset(ans, 0, sizeof(ans));
    do {
        for(int i = n; i >= 1; --i) {
            int cnt = 0;
            for(int j = 1; j <= n; ++j) {
                if(mn[j] <= i || v[j - 1] <= i)
                    ++cnt;
            }
            if(cnt <= s) {
                for(int j = 1; j <= n; ++j) {
                    if(mn[j] <= i || v[j - 1] <= i)
                        ++ans[j];
                }
                break;
            }
        }
    } while(next_permutation(v.begin(), v.end()));
    for(int i = 1; i <= n; ++i)
        cout << mul(ans[i], inv[n]) << " ";
    cout << endl;
    return 0;
}