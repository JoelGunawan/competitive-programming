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
const int lim = 2e5 + 5;
lll fact[lim], inv[lim];
int mod = 998244353;
lll smod = 2305843009213693951;
lll powmod(lll a, lll b) {
    if(b == 0)
        return 1;
    else {
        lll tmp = powmod(a, b >> 1);
        tmp = (tmp * tmp) % smod;
        return b & 1 ? (tmp * a) % smod : tmp;
    }
}
lll combinmod(lll a, lll b) {
    assert(a < lim);
    assert(a >= b && a >= 0 && b >= 0);
    if(a < 0 || b < 0 || a < b)
        return 1;
    return ((((fact[a] * inv[b]) % smod) * inv[a - b]) % smod);
}
ll pm(ll a, ll b) {
    if(b == 0)
        return 1;
    else {
        ll tmp = pm(a, b / 2);
        tmp = (tmp * tmp) % mod;
        return b & 1 ? (tmp * a) % mod : tmp;
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    ll n, m, d;
    cin >> n >> m >> d;
    if(m == 1) {
        if(d == 1)
            cout << 1 << endl;
        else
            cout << -1 << endl;
        return 0;
    }
    else if(m == 2) {
        if(d <= n) {
            cout << ((pm(2, d - 1)) + 1) % mod << endl;
        }
        else
            cout << -1 << endl;
        return 0;
    }
    fact[0] = 1, inv[0] = 1;
    for(lll i = 1; i <= 2e5; ++i)
        fact[i] = (fact[i - 1] * (lll)i) % smod, inv[i] = powmod(fact[i], smod - 2);
    // make ith permutation from d
    if(d == 1) {
        if(n >= m - 1) {
            cout << pm(2, m - 1) << endl;
        }
        else
            cout << -1 << endl;
        return 0;
    }
    ll zero_cnt = 1;
    --d;
    while(d > combinmod(m + zero_cnt - 2, zero_cnt)) {
        d -= combinmod(m + zero_cnt - 2, zero_cnt);
        ++zero_cnt;
    }
    // have zero count, just find order
    int cur_pos = 2;
    // posisi sekarang itu posisi ke berapa, coba dri sblm udah used berapa
    // tiap index -> tambah 0 atau tambah 1
    // tambah 0 -> tidak tambah d
    // tambah 1 -> tambah d
    lll tmp = 0;
    ll size = m + zero_cnt - 1;
    if(size > n) {
        cout << -1 << endl;
        return 0;
    }
    int unused_zero = zero_cnt, unused_one = size - 1 - zero_cnt;
    string res = "1";
    while(cur_pos <= size) {
        if(combinmod(size - cur_pos, unused_zero - 1) + tmp < d) {
            res += '1';
            tmp += combinmod(size - cur_pos, unused_zero - 1);
        }
        else {
            res += '0';
            --unused_zero;
        }
        ++cur_pos;
    };
    ll cnt = 1, ans = 0;
    for(int i = res.size() - 1; i >= 0; --i) {
        if(res[i] == '1') {
            ans += cnt;
            ans %= mod;
        }
        cnt *= 2;
        cnt %= mod;
    }
    ans += 1;
    cout << ans % mod << endl;
    return 0;
}