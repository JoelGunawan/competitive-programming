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
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef tree<ll, null_type, less<ll>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const ll N = 20;
long long GCD(long long a, long long b) { return (b == 0) ? a : GCD(b, a % b); }
inline long long LCM(long long a, long long b) { return a / GCD(a, b) * b; }
inline long long normalize(long long x, long long mod) { x %= mod; if (x < 0) x += mod; return x; }
struct GCD_type { long long x, y, d; };
GCD_type ex_GCD(long long a, long long b)
{
    if (b == 0) return {1, 0, a};
    GCD_type pom = ex_GCD(b, a % b);
    return {pom.y, pom.x - a / b * pom.y, pom.d};
}
ll testCases;
ll t;
long long a[N], n[N], ans, lowcm;
ll get_crt(vector<pair<ll, ll>> arr) {
    t = arr.size();
    for(ll i = 1; i <= arr.size(); i++) a[i] = arr[i - 1].fi, n[i] = 2 * arr[i - 1].se, normalize(a[i], n[i]);
    ans = a[1];
    lowcm = n[1];
    for(ll i = 2; i <= t; i++)
    {
        auto pom = ex_GCD(lowcm, n[i]);
        ll x1 = pom.x;
        ll d = pom.d;
        if((a[i] - ans) % d != 0) return -1e9;
        ans = normalize(ans + x1 * (a[i] - ans) / d % (n[i] / d) * lowcm, lowcm * n[i] / d);
        lowcm = LCM(lowcm, n[i]); // you can save time by replacing above lowcm * n[i] /d by lowcm = lowcm * n[i] / d
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    ll q;
    cin >> q;
    for(;q--;) {
        ll n, m, x, y;
        cin >> n >> m >> x >> y;
        if(n < m)
            swap(n, m), swap(x, y);
        /*
        if(n % m == 0) {
            // manual
            ll oriy = y;
            y %= 2 * m;
            if(y == 0)
                y = 2 * m;
            if(y > m)
                y = 2 * m - y;
            if(y != x)
                cout << 0 << endl;
            else {
                ll tmp = 4 * (oriy / 2 * m);
                if(oriy % (2 * m) >= 1)
                    ++tmp;
                if(oriy % (2 * m) >= m && m != 1)
                    ++tmp;
                if(oriy % (2 * m) >= m + 1)
                    ++tmp;
                tmp %= 9;
                if(tmp == 0)
                    tmp = 9;
                cout << tmp << endl;
            }
        }
        */
        ll lowx = x, highx = 2 * n - x + 1, lowy = y, highy = 2 * m - y + 1, totalmoves = 1ll * n * m / GCD(n, m);
        if((lowx&1)==(lowy&1)) {
            // pair lowx with lowy
            ll ans = get_crt({mp(lowx, n), mp(lowy, m)});
            if(ans != -1e9) {
                ans %= lowcm;
                if(ans <= 0)
                    ans += lowcm;
                if(ans <= totalmoves) {
                    ll tmpx = 2 * (ans / (2 * n));
                    if(ans % (2 * n) >= 1)
                        ++tmpx;
                    if(ans % (2 * n) >= n + 1)
                        ++tmpx;
                    ll tmpy = 2 * (ans / (2 * m));
                    if(ans % (2 * m) >= 1)
                        ++tmpy;
                    if(ans % (2 * m) >= m + 1)
                        ++tmpy;
                    tmpx += tmpy;
                    --tmpx;
                    tmpx %= 9;
                    if(tmpx == 0)
                        tmpx = 9;
                    cout << tmpx << endl;
                    continue;
                }
            }
            if(ans != -1e9) {
                ans = get_crt({mp(highx, n), mp(highy, m)});
                ans %= lowcm;
                if(ans <= 0)
                    ans += lowcm;
                if(ans <= totalmoves) {
                    ll tmpx = 2 * (ans / (2 * n));
                    if(ans % (2 * n) >= 1)
                        ++tmpx;
                    if(ans % (2 * n) >= n + 1)
                        ++tmpx;
                    ll tmpy = 2 * (ans / (2 * m));
                    if(ans % (2 * m) >= 1)
                        ++tmpy;
                    if(ans % (2 * m) >= m + 1)
                        ++tmpy;
                    tmpx += tmpy;
                    --tmpx;
                    tmpx %= 9;
                    if(tmpx == 0)
                        tmpx = 9;
                    cout << tmpx << endl;
                    continue;
                }
            }
            cout << 0 << endl;
        }   
        else {
            // pair lowx with highy
            ll ans = get_crt({mp(lowx, n), mp(highy, m)});
            if(ans != -1e9) {
                ans %= lowcm;
                if(ans <= 0)
                    ans += lowcm;
                if(ans <= totalmoves) {
                    ll tmpx = 2 * (ans / (2 * n));
                    if(ans % (2 * n) >= 1)
                        ++tmpx;
                    if(ans % (2 * n) >= n + 1)
                        ++tmpx;
                    ll tmpy = 2 * (ans / (2 * m));
                    if(ans % (2 * m) >= 1)
                        ++tmpy;
                    if(ans % (2 * m) >= m + 1)
                        ++tmpy;
                    tmpx += tmpy;
                    --tmpx;
                    tmpx %= 9;
                    if(tmpx == 0)
                        tmpx = 9;
                    cout << tmpx << endl;
                    continue;
                }
            }
            ans = get_crt({mp(highx, n), mp(lowy, m)});
            if(ans != -1e9) {
                ans %= lowcm;
                if(ans <= 0)
                    ans += lowcm;
                if(ans <= totalmoves) {
                    ll tmpx = 2 * (ans / (2 * n));
                    if(ans % (2 * n) >= 1)
                        ++tmpx;
                    if(ans % (2 * n) >= n + 1)
                        ++tmpx;
                    ll tmpy = 2 * (ans / (2 * m));
                    if(ans % (2 * m) >= 1)
                        ++tmpy;
                    if(ans % (2 * m) >= m + 1)
                        ++tmpy;
                    tmpx += tmpy;
                    --tmpx;
                    tmpx %= 9;
                    if(tmpx == 0)
                        tmpx = 9;
                    cout << tmpx << endl;
                    continue;
                }
            }
            cout << 0 << endl;
        }
    }
    return 0;
}