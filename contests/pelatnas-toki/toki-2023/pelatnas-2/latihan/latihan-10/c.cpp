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
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    // dp bitmask definitely
    // bitmask -> 2^19
    // gabisa pake teknik 3^m
    // harus m2^m (semacam sos)
    // antara 0/1 intersect boleh dijadiin gcd
    // process previous terus nanti coba tiap cyclic gtu
    // pake teknik mirip sos tp dimodif
    int n, x;
    cin >> n >> x;
    // find all prime factors below x
    vector<int> primes;
    for(int i = 2; i <= x; ++i) {
        bool prime = 1;
        for(int j = 2; j <= sqrt(i); ++j) {
            if(i % j == 0) {
                prime = 0;
                break;
            }
        }
        if(prime)
            primes.pb(i);
    }
    ll a[n + 1];
    int to_mask[n + 1];
    memset(to_mask, 0, sizeof(to_mask));
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j < primes.size(); ++j) {
            if(a[i] % primes[j] == 0)
                to_mask[i] += 1ll << j;
        }
    }
    int cnt[1 << primes.size()][primes.size()], b[1 << primes.size()];
    memset(b, 0, sizeof(b));
    memset(cnt, 0, sizeof(cnt));
    for(int i = 1; i <= n; ++i)
        b[to_mask[i]] += 1;
    for(int i = 0; i < 1 << primes.size(); ++i) {
        int cur = b[i];
        for(int j = 0; j < primes.size(); ++j) {
            if((1 << j) & i) {
                cnt[i][j] = cur + cnt[(1 << j) ^ i][j];
            }
            else {
                cnt[i][j] = cur;
            }
            cur = cnt[i][j];
        }
    }
    ll res = 0;
    for(int i = 1; i <= n; ++i) {
        int mask = to_mask[i], inv = ((1 << primes.size()) - 1) ^ mask;
        res += cnt[inv][primes.size() - 1];
        for(int j = 0; j < primes.size(); ++j) {
            if(!((1 << j) & inv)) {
                // ga termasuk inverse mask
                // coba ini
                res += cnt[(1 << j) ^ inv][primes.size() - 1] - cnt[inv][primes.size() - 1];
            }
        }
    }
    cout << res << endl;
    // dapet submasknya, berarti next perlu murni sm mixed
    return 0;
}