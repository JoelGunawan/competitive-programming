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
int p[3] = {998244353, (int)1e9 + 7, (int)1e9 + 9};
ll powmod(ll a, ll b, ll mod) {
    if(b == 0)
        return 1;
    else {
        ll tmp = powmod(a, b >> 1, mod);
        tmp = (tmp * tmp) % mod;
        return b & 1 ? (tmp * a) % mod : tmp;
    }
}
ll inv(ll a, ll b) {
    return powmod(a, b - 2, b);
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<pair<char, ll>> a;
    for(int i = 0; i < n; ++i) {
        char x; int y;
        cin >> x >> y;
        if(a.size() > 0 && x == a.back().fi)
            a.back().se += y;
        else
            a.pb(mp(x, y));
    }
    int m;
    cin >> m;
    vector<pair<char, ll>> b;
    for(int i = 0; i < m; ++i) {
        char x; int y;
        cin >> x >> y;
        if(b.size() > 0 && x == b.back().fi)
            b.back().se += y;
        else
            b.pb(mp(x, y));
    }
    // we have a condensed form
    // now we need to determine the hashing
    // do special case for if b.size() == 1 and b.size() == 2
    if(b.size() == 1) {
        ll res = 0;
        for(auto i : a) {
            if(i.fi == b.back().fi) {
                res += max(0ll, i.se - b.back().se + 1);
            }
        }
        cout << res << endl;
    }
    else if(b.size() == 2) {
        ll res = 0;
        for(int i = 0; i < a.size() - 1; ++i) {
            if(a[i].fi == b[0].fi && a[i].se >= b[0].se && a[i + 1].se >= b[1].se)
                ++res;
        }
        cout << res << endl;
    }
    else {
        // get polynomial hasing of s and t
        // how to polynomial hash?
        // there's 2 types of characters
        // and there's count
        // val^count * key^x
        // use 42069 as key
        ll res = 0;
        int key = 42069;
        ll ahash[a.size() + 1][3];
        ll bhash[3];
        memset(ahash, 0, sizeof(ahash));
        memset(bhash, 0, sizeof(bhash));
        for(int i = 0; i < a.size(); ++i)
            for(int j = 0; j < 3; ++j)
                ahash[i + 1][j] = ((ahash[i][j] * key) % p[j] + powmod(a[i].fi, a[i].se, p[j])) % p[j];
        for(int i = 1; i < b.size() - 1; ++i)
            for(int j = 0; j < 3; ++j)
                bhash[j] = ((bhash[j] * key) % p[j] + powmod(b[i].fi, b[i].se, p[j])) % p[j];
        for(int i = 0; i + b.size() - 1 < a.size(); ++i) {
            bool valid = 1;
            if(a[i].fi != b[0].fi || a[i].se < b[0].se || a[i + b.size() - 1].fi != b[b.size() - 1].fi || a[i + b.size() - 1].se < b[b.size() - 1].se)
                valid = 0;
            for(int j = 0; j < 3; ++j) {
                // query between i + 1 to i + b.size() - 2
                ll l = i + 1, r = i + b.size() - 2;
                //cout << ahash[r + 1][j] << " " << ahash[l][j] << endl;
                ll cur = ahash[r + 1][j] - (ahash[l][j] * powmod(key, r - (l - 1), p[j])) % p[j];
                cur %= p[j];
                cur += p[j];
                cur %= p[j];
                //cout << cur << " " << bhash[j] << endl;
                if(cur != bhash[j])
                    valid = 0;
            }
            if(valid)
                ++res;
        }
        cout << res << endl;
    }
    return 0;
}