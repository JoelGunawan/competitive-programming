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
ll mod = 998244353;
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
    ll n;
    ll m;
    cin >> n >> m;
    ll pref = 1;
    ll pos[n + 1];
    memset(pos, 0, sizeof(pos));
    for(ll i = 1; i <= n; ++i) {
        if(i != 1) {
            bool prime = 1;
            ll tmp = sqrt(i);
            for(ll j = 2; j <= tmp; ++j) {
                //cout << i << " " << j << endl;
                if(i % j == 0)
                    prime = 0;
            }
            if(prime)
                pref *= i;
        }
        //cout << pref << endl;
        pos[i] = m / pref;
        pos[i] %= mod;
        assert(pref > 0);
        if(pref > m)
            break;
    }
    // multiply all pos
    ll total = 0, invalid = 0, cur = 1;
    for(ll i = 1; i <= n; ++i) {
        //cout << pos[i] << " ";
        cur = (cur * pos[i]) % mod;
        total += powmod(m % mod, i);
        invalid += cur;
        total %= mod;
        invalid %= mod;
    }
    //cout << endl;
        total -= invalid;
    if(total < 0)
        total += mod;
    cout << total << endl;
    return 0;
}