#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
using namespace std;
int mod = 1e9 + 7;
ll powmod(ll a, ll b) {
    if(b == 0)
        return 1;
    else {
        ll tmp = powmod(a, b >> 1);
        tmp = (tmp * tmp) % mod;
        return b & 1 ? (tmp * a) % mod : tmp;
    }
}
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
struct sparse_table {
    int a[16][1 << 16];
    int log2[1 << 16];
    sparse_table() {
        memset(a, 0, sizeof(a));
        log2[0] = 0, log2[1] = 0;
        for(int i = 2; i < 1 << 16; ++i)
            log2[i] = log2[i >> 1] + 1;
    }
    void build(vector<int> input) {
        for(int i = 0; i < input.size(); ++i)
            a[0][i] = input[i];
        for(int i = 1; i < 16; ++i) {
            for(int j = 0; j < 1 << 16; ++j) {
                a[i][j] = gcd(a[i - 1][j], a[i - 1][j + (1 << (i - 1))]);
            }
        }
    }
    int query(int l, int r) {
        int tmp = log2[(r - l + 1)];
        return gcd(a[tmp][l], a[tmp][r - (1 << tmp) + 1]);
    }
};
const int lim = 1e5 + 5;
ll fact[lim], inv[lim];
ll mul(ll a, ll b) {
    return (a * b) % mod;
}
ll add(ll a, ll b) {
    return (a + b) % mod;
}
ll combinmod(ll a, ll b) {
    if(a < b || a < 0 || b < 0)
        return 0;
    else
        return mul(fact[a], mul(inv[b], inv[a - b]));
}
ll sub(ll a, ll b) {
    a -= b;
    if(a < 0)
        a += mod;
    return a;
}
int main() {
    string subsoal;
    int n, k;
    cin >> subsoal >> n >> k;
    vector<int> a(n + 1, 0);
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    // do GCD borders, use stars and bars method + hockey stick identity
    // k = 1 -> do every border, just count, no combin
    // final obs: do hockey stick ident, use hockey stick ident as prefsum (kind of)
    fact[0] = 1, inv[0] = 1;
    for(int i = 1; i <= 1e5; ++i) {
        fact[i] = (fact[i - 1] * i) % mod;
        inv[i] = powmod(fact[i], mod - 2);
    }
    sparse_table sp;
    sp.build(a);
    ll res = 0;
    for(int i = 1; i <= n; ++i) {
        // find points where gcd is decreasing, for those points, put in vector
        // O(nlog(n)log^2(a[i])) -> find points
        // O(nklog(mod)log(a[i])) -> calculate combin values
        // find moving points and the respective gcd
        vector<pair<int, int>> vec;
        // find first point where gcd changes
        int c = i, cgcd = a[i];
        while(c <= n) {
            int l = c, r = n, ans = c;
            while(l <= r) {
                int mid = (l + r) >> 1;
                if(sp.query(i, mid) == cgcd)
                    l = mid + 1, ans = mid;
                else
                    r = mid - 1;
            }
            cout << c << " " << cgcd << endl;
            vec.push_back(mp(c, cgcd));
            cgcd = sp.query(i, ans + 1);
            c = ans + 1;
        }
        reverse(vec.begin(), vec.end());
        for(int j = 0; j <= k - 1; ++j) {
            // try j on left
            ll pr = 0;
            for(auto p : vec) {
                //if(n - p.fi + 1 >= k - j - 1)
                res = add(res, mul(mul(combinmod(i - 1, j), p.se), combinmod(n - p.fi, k - j - 1)));
            }
            cout << endl;
        }
    }
    cout << res << endl;
    return 0;
}