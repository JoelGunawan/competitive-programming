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
const int lim = 2e5 + 5;
struct fenwick {
    ll a[lim];
    fenwick() {
        memset(a, 0, sizeof(a));
    }
    void upd(int idx, int val) {
        assert(idx != 0);
        while(idx < lim) {
            a[idx] += val;
            idx += idx&-idx;
        }
    }
    ll q(int idx) {
        ll ret = 0;
        while(idx) {
            ret += a[idx];
            idx -= idx&-idx;
        }
        return ret;
    }
    ll q(int l, int r) {
        return q(r) - q(l - 1);
    }
};
ll lcm(ll a, ll b) {
    return a * b / __gcd(a, b);
}
ll get(ll n) {
    return (n * (n + 1) * (2 * n + 1) / 6 + n * (n + 1) / 2) / 2;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    // if any of i, j is outside of the factors of k, it is a valid triplet
    int t;
    cin >> t;
    fenwick bit;
    vector<pair<int, int>> v;
    while(t--) {
        // get factors of k, salah satu dr i atau j harus di luar faktor, sisanya bebas
        // invalid -> both merupakan faktor k
        int l, r;
        cin >> l >> r;
        v.pb(mp(l, r));
        /*
        ll res = 0;
        vector<int> factors[r + 1];
        for(int i = 1; i <= r; ++i) {
            for(int j = 2 * i; j <= r; j += i)
                factors[j].pb(i);
        }
        for(int i = l + 2; i <= r; ++i) {
            int cnt = 0;
            for(auto j : factors[i]) {
                //cout << "DEB " << i << " " << j << endl;
                // mis 6
                // 4 3 6
                // lcm -> 12
                // sum -> 13
                // 36
                // 18 24 36
                // x/2 2x/3 x
                // 2x/3 2x/5 x
                if(j >= l)  
                    ++cnt;
            }
            int can = i - l;
            //cout << can << " " << cnt << endl;
            // lcm ga nambah
            ll lama = res;
            // can -> bisa dihitung O(1)
            // cnt -> harus dihitung O(N)?, try precompute
            // edge case -> bisa dihitung O(1)
            res += 1ll * can * (can - 1) / 2 - 1ll * cnt * (cnt - 1) / 2;
            // lcm nambah
            if(i % 6 == 0 && i / 3 * 2 >= l && i / 2 >= l)
                --res;
            if(i % 15 == 0 && 2 * i / 3 >= l && 2 * i / 5 >= l)
                --res;
            ll brute = 0;
            for(int j = l; j < i; ++j) {
                for(int k = j + 1; k < i; ++k) {
                    if(lcm(lcm(i, j), k) >= i + j + k) {
                        ++brute;
                    }
                    else if(i % 15 == 0)
                        cout << i << " " << j << " " << k << endl;
                }
            }
            //cout << lama + brute << " " << res << endl;
            if(lama + brute != res) {
                cout << i << endl;
            } 
        }
        cout << res << endl;
        */
    }
    vector<pair<int, int>> c = v;
    sort(v.begin(), v.end());
    int l = 1;
    int cnt[lim];
    memset(cnt, 0, sizeof(cnt));
    for(int i = 1; i < lim; ++i) {
        for(int j = 2 * i; j < lim; j += i) {
            ++cnt[j];
            bit.upd(j, cnt[j] - 1);
        }
    }
    vector<ll> ans;
    for(auto i : v) {
        while(l < i.fi) {
            for(int j = 2 * l; j < lim; j += l) {
                bit.upd(j, -cnt[j] + 1);
                --cnt[j];
            }
            ++l;
        }
        // sum of n * (n - 1) / 2
        // jadi (n^2-n)/2
        // n^2 -> n(n+1)(2n+1)/6
        // n -> n^2+n/2
        ll out = get(i.se - i.fi - 1) - bit.q(i.fi + 2, i.se);
        //cout << get(i.se - i.fi - 1) << endl;
        // pen1 -> tiap kelipatan 6 dr 2l
        // pen2 -> tiap kelipatan 15 dr 5/2l?
        int check1 = 0, check2 = 0;
        for(int x = i.fi; x <= i.se; ++x) {
            if(x % 6 == 0 && x / 3 * 2 >= l && x / 2 >= l)
                ++check1;
            if(x % 15 == 0 && 2 * x / 3 >= l && 2 * x / 5 >= l)
                ++check2;
        }
        int pen1 = i.se / 6 - (2 * i.fi - 1) / 6, pen2 = i.se / 15 - (5 * i.fi / 2 + ((5 * i.fi) & 1) - 1) / 15;
        //cout << check1 << " " << pen1 << " " << check2 << " " << pen2 << endl;
        pen1 = max(pen1, 0);
        pen2 = max(pen2, 0);
        //cout << out << " " << pen1 << " " << pen2 << endl;
        ans.pb(out - pen1 - pen2);
    }
    for(auto p : c) {
        int idx = lb(v.begin(), v.end(), p) - v.begin();
        cout << ans[idx] << endl;
    }
    return 0;
}