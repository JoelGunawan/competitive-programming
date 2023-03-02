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
int mod = 998244353;
ll ans = 0;
/*
struct disjoint_set {
    int head[lim], size[lim];
    disjoint_set() {
        memset(head, -1, sizeof(head));
        fill(size, size + lim, 1);
    }
    int fh(int nd) {
        while(head[nd] != -1)
            nd = head[nd];
        return nd;
    }
    bool merge(int x, int y) {
        x = fh(x), y = fh(y);
        if(x != y) {
            if(size[x] < size[y])
                swap(x, y);
            ans -= (1ll * size[y] * size[y] - 1);
            ans -= (1ll * size[x] * size[x] - 1);
            size[x] += size[y];
            head[y] = x;
            ans += (1ll * size[x] * size[x] - 1);
            ans %= mod;
        }
        return x != y;
    }
};
*/
const int lim = 1e6 + 5;
ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
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
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n;
    cin >> n;
    // semua a sama -> black or white
    ll fact[lim];
    fact[0] = 1;
    for(int i = 1; i < lim; ++i)
        fact[i] = (1ll * fact[i - 1] * i) % mod;
    int a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    int cnt = 0;
    for(int i = 1; i <= a[0]; ++i) {
        if(gcd(i, a[0]) == 1) {
            ++cnt;
        }
    }
    int cnt2 = 0;
    int cur = 0;
    ll total = 0;
    for(int i = 0; i < n; ++i) {
        if(a[i] == 1) {
            ++cnt2;
            if(i != 0 && a[i] == a[i - 1])
                ++cur;
            else {
                cur = 1;
            }
        }
        else {
            if(i != 0 && a[i] != a[i - 1]) {
                total += (1ll * cur * cur) - 1;
                total %= mod;
                cur = 1;
            }
        }
    }
    total += (1ll * cur * cur) - 1;
    total %= mod;
    if(cnt2 == 0 || cnt2 == n)
        cout << ((((fact[(int)1e6] * powmod(a[0], mod - 2)) % mod) * cnt) % mod * (((1ll * n * n) % mod) - 1)) % mod << endl;
    else {
        ll tmp = ((((((fact[(int)1e6] * powmod(2, mod - 2)) % mod)) % mod * (((1ll * n * n) % mod) - 1)) % mod) + (((((fact[(int)1e6] * powmod(2, mod - 2)) % mod)) % mod) * total)) % mod;
        tmp %= mod;
        tmp += mod;
        tmp %= mod;
        cout << tmp << endl;
    }
    /*
    int a[n + 1];
    vector<pair<int, int>> m;
    for(int i = 1; i <= n; ++i) {
        // find prime factorization
        cin >> a[i];
        int tmp = a[i];
        // cari first factorial yang bisa habis membagi prime factorization dari a[i]
        vector<pair<int, int>> primes;
        for(int j = 2; j <= sqrt(tmp); ++j) {
            if(tmp % j == 0) {
                int cnt = 0;
                while(tmp % j == 0)
                    tmp /= j, ++cnt;
                primes.pb(mp(j, cnt));
            }
        }
        if(tmp > 1)
            primes.pb(mp(tmp, 1));
        // find earliest factorial yang undivide
        int smallest = 1e6;
        for(auto i : primes) {
            int l = 1, r = 1e6, ans = 1;
            while(l <= r) {
                int mid = (l + r) / 2;
                int res = 0;
                ll tmp = i.fi;
                while(tmp <= mid) {
                    res += mid / tmp;
                    tmp *= i.fi;
                }
                if(res < i.se)
                    l = mid + 1, ans = mid;
                else
                    r = mid - 1;
            }
            cout << "PRIME " << i.fi << " " << ans << endl;
            smallest = min(smallest, ans);
        }
        m.pb(mp(smallest, i));
    }
    sort(m.begin(), m.end());
    reverse(m.begin(), m.end());
    int cur_time = 1e6;
    ll res = 0;
    bool black[n + 5];
    memset(black, 0, sizeof(black));
    disjoint_set dsu;
    for(auto i : m) {
        black[i.se] = 1;
        res += 1ll * (cur_time - i.fi) * ans;
        res %= mod;
        cout << i.fi << " " << ans << endl;
        if(black[i.se + 1])
            dsu.merge(i.se, i.se + 1);
        if(black[i.se - 1])
            dsu.merge(i.se, i.se - 1);
        cur_time = i.fi;
    }   
    cout << (res + 1ll * cur_time * ans) % mod << endl;
    */
    return 0;
}