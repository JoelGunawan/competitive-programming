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
struct fenwick {
    vector<ll> a;
    fenwick(ll size) {
        a = vector<ll>(size + 5, 0);
    }
    void reset() {
        a = vector<ll>(a.size(), 0);
    }
    void update(ll idx, ll val) {
        ++idx;
        assert(idx != 0);
        while(idx < a.size()) {
            a[idx] += val;
            idx += idx&-idx;
        }
    }
    ll query(ll idx) {
        ++idx;
        ll ret = 0;
        assert(idx >= 0);
        assert(idx < a.size());
        while(idx) {
            ret += a[idx];
            idx -= idx&-idx;
        }
        return ret;
    }
    ll query(ll l, ll r) {
        if(l > a.size() - 2 || l > r)
            return 0;
        else if(r > a.size() - 2)
            r = (ll)a.size() - 2;
        // cout << l << " " << r << endl;
        // cout.flush();
        return l == -1 ? query(r) : query(r) - query(l - 1);
    }
};
ll mod = 998244353;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    ll t;
    cin >> t;
    // cout << "HI" << endl;
    // cout.flush();
    while(t--) {
        ll n, k;
        cin >> n >> k;
        ll p[n], q[k];
        // cout << "FIRST 2 DONE" << endl;
        // cout.flush();
        for(ll i = 0; i < n; ++i)
            cin >> p[i];
        for(ll i = 0; i < k; ++i)
            cin >> q[i];
        // cout << "BEFORE DECLARE" << endl;
        // cout.flush();
        fenwick bit1(2 * n + 5), bit2(k + 5);
        ll res = 0;
        // cout << "TEST" << endl;
        // cout.flush();
        for(ll i = 0; i < k; ++i) {
            // calculate internal, can use fenwick as well
            res += bit2.query(q[i] + 1, k);
            bit2.update(q[i], 1);
        }
        // cout << "TEST" << endl;
        // cout.flush();
        res %= mod;
        res = (res * n) % mod;
        //cout << "INTERNAL " << res << endl;
        for(ll i = 0; i < n; ++i) {
            // calculate for each segment
            ll less[20];
            less[0] = p[i];
            ll tmp = res;
            for(ll j = 1; j < 20; ++j) {
                if(j >= k)   
                    break;
                less[j] = p[i] / (1 << j) + 1;
                res += bit1.query(less[j], less[j - 1] - 1) * (1ll * (k - j) * (k - j + 1) / 2);
                res %= mod;
            }
            //cout << "ADD LESS " << i << " " << res - tmp << endl;
            ll more[20];
            more[0] = p[i];
            tmp = res;
            for(ll j = 1; j < 20; ++j) {
                more[j] = 1ll * p[i] * (1 << j);
                if(more[j] > 8 * n)
                    break;
                // cout << more[j] << endl;
                if(j > k) {
                    // cout << bit1.query(more[j - 1] + 1, more[j]) << " " << 1ll * k * k << endl;
                    res += bit1.query(more[j - 1] + 1, more[j]) * (1ll * k * k);
                }
                else {
                    //cout << bit1.query(more[j - 1] + 1, more[j]) << " " << (1ll * k * (j - 1) + 1ll * k * (k + 1) / 2 - 1ll * (j - 1) * j / 2) << endl;
                    res += bit1.query(more[j - 1] + 1, more[j]) * (1ll * k * (j - 1) + 1ll * k * (k + 1) / 2 - 1ll * (j - 1) * (j) / 2);
                }
                res %= mod;
            }
            //cout << "ADD MORE " << i << " " << res - tmp << endl;
            bit1.update(p[i], 1);
        }
        cout << res << endl;
    }
    return 0;
}