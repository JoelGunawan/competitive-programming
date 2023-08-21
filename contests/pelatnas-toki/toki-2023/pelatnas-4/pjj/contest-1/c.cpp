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
struct frac {
    ll top, bottom;
};
bool larger(frac a, frac b) {
    return (lll)a.top * b.bottom < (lll)b.top * a.bottom;
}
const int lim = 2e5 + 5;
vector<int> fact[lim];
int check(int x, int y) {
    // get factors of x
    int tot = 0;
    //cout << "CHECK" << endl;
    //cout << x << " " << fact[x].size() << endl;
    for(int i = 0; i < (1 << fact[x].size()); ++i) {
        int cur = 1, on = 0;
        for(int j = 0; j < fact[x].size(); ++j) {
            if((1 << j) & i) {
                cur *= fact[x][j];
                ++on;
            }
        }
        if(on & 1)
            tot -= y / cur;
        else
            tot += y / cur;
    }
    //cout << x << " " << y << " " << tot << endl;
    //cout << "CHECKDONE" << endl;
    return tot;
}
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
lll gcd(lll a, lll b) {
    return b == 0 ? a : gcd(b, a % b);
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    cout << fixed << setprecision(15);
    ll n, k;
    cin >> n >> k;
    // when extending with a new elem x, it introduces exactly phi(x) new elements
    // make a function that checks count of relative prime to x less than y (if y is bigger than x just set to x)
    // nanti binser di mana, use a large prime number (mis 1e9 + 7) as divisor
    // use first prime larger than n
    // binser di tengah", is it bigger or smaller
    bool prime[lim];
    memset(prime, 1, sizeof(prime));
    for(int i = 2; i < lim; ++i) {
        if(prime[i]) {
            fact[i].pb(i);
            for(int j = 2 * i; j < lim; j += i)
                fact[j].pb(i), prime[j] = 0;
        }
    }
    ll l = 0, r = 1e18;
    while(l <= r) {
        ll mid = (l + r) / 2.0;
        ll total = 0;
        vector<pair<int, int>> possible;
        frac f;
        f.top = mid, f.bottom = 1e18;
        for(int i = 2; i <= n; ++i) {
            // cari jumlah yg kurang dr mid
            int l = 1, r = i - 1, cnt = 0;
            while(l <= r) {
                int m = (l + r) / 2;
                // kalo kurang dr m
                //cout << "OUTPUT " << tmp << " " << mid << endl;
                frac x;
                x.top = m;
                x.bottom = i;
                if(larger(x, f)) {
                    cnt = m;
                    l = m + 1;
                }
                else
                    r = m - 1;
            }
            // dapet cnt nya berapa
            int act = check(i, cnt);
            total += act;
            if(act) {
                possible.pb(mp(i, cnt));
            }
        }
        //cout << mid << " " << total << endl;
        if(total == k) {
            vector<frac> res;
            for(auto i : possible) {
                int div = i.fi, cnt = i.se;
                while(gcd(div, cnt) > 1)
                    --cnt;
                res.pb(frac());
                res.back().top = cnt, res.back().bottom = div;
            }
            sort(res.begin(), res.end(), larger);
            //for(auto i : res)
            //    cout << i.top << " " << i.bottom << endl;
            cout << res.back().top << " " << res.back().bottom << endl;
            return 0;
        }
        if(total > k)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return 0;
}