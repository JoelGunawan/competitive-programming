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
const int lim = sqrt(1e9);
vector<int> primes;
void sieve() {
    bool prime[100000];
    memset(prime, 1, sizeof(prime));
    for(int i = 2; i <= lim; ++i) {
        if(prime[i]) {
            for(int j = 2 * i; j <= lim; j += i)
                prime[j] = 0;
        }
    }
    for(int i = 2; i <= lim; ++i)
        if(prime[i])
            primes.pb(i);
}
void tc() {
    int n;
    cin >> n;
    int a[n + 1];
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    // banyak factors -> 9
    set<int> used;
    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j < primes.size(); ++j) {
            if(primes[j] * primes[j] > a[i])
                break;
            if(a[i] % primes[j] == 0) {
                if(used.count(primes[j])) {
                    cout << "YES" << endl;
                    return;
                }
                used.ins(primes[j]);
                while(a[i] % primes[j] == 0)
                    a[i] /= primes[j];
            }
        }
        if(a[i] > 1) {
            if(used.count(a[i])) {
                cout << "YES" << endl;
                return;
            }
            used.ins(a[i]);
        }
    }
    cout << "NO" << endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    sieve();
    int t;
    cin >> t;
    while(t--)
        tc();
    return 0;
}