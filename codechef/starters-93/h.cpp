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
vector<int> generate_primes(int n) {
    bool a[n + 1];
    memset(a, 0, sizeof(a));
    vector<int> ret;
    for(int i = 2; i <= n; ++i) {
        if(!a[i]) {
            ret.pb(i);
            for(int j = 2 * i; j <= n; j += i)
                a[j] = 1;
        }
    }
    return ret;
}
int mod = 1e9 + 7;
ll mulmod(ll a, ll b) {
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
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    vector<int> primes = generate_primes(3163);
    ll lcm = 1, gcd = 0;
    int cnt[primes.size()];
    memset(cnt, 0, sizeof(cnt));
    int n;
    cin >> n;
    ll a[n + 1];
    vector<int> additional;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        gcd = __gcd(a[i], gcd);
        for(int j = 0; j < primes.size(); ++j) {
            if(a[i] % primes[j] == 0) {
                int tmp = 0;
                while(a[i] % primes[j] == 0)
                    a[i] /= primes[j], ++tmp;
                cnt[j] = max(cnt[j], tmp);
            }
        }
        if(a[i] > 1) {
            additional.pb(a[i]);
        }
    }
    sort(additional.begin(), additional.end());
    additional.resize(unique(additional.begin(), additional.end()) - additional.begin());
    for(int i = 0; i < primes.size(); ++i)
        lcm = mulmod(lcm, powmod(primes[i], cnt[i]));
    for(auto i : additional)
        lcm = mulmod(lcm, i);
    ll mul = mulmod(lcm, powmod(gcd, mod - 2));
    int q;
    cin >> q;
    while(q--) {
        int x;
        cin >> x;
        cout << mulmod(gcd, powmod(mul, x)) << " " << mulmod(lcm, powmod(mul, x)) << endl;
    }
    return 0;
}