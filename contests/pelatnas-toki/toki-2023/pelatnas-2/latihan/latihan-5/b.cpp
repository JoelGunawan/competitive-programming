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
int mod = 420691273;
ll f(ll a) {
    if(a < 0)
        return (a % mod) + mod;
    else
        return a % mod;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
    int n;
    cin >> n;
    string s;
    cin >> s;
    // buat prefix dan suffix
    // buat hashing array
    ll key = rnd() % mod;
    ll pref[n + 1];
    pref[0] = 0;
    for(int i = 1; i <= n; ++i) {
        pref[i] = (key * pref[i - 1]) + s[i - 1], pref[i] %= mod;
        //cout << pref[i] << " ";
    }
    //cout << endl;
    ll pow[n + 1];
    pow[0] = 1;
    for(int i = 1; i <= n; ++i)
        pow[i] = pow[i - 1] * key, pow[i] %= mod;
    int pr = 1, cur_found = 0;
    for(int i = 1; i <= n / 2; ++i) {
        // cek dr 1 .. i dan n - i + 1 ... n
        //cout << pr << " " << i << " " << n - i + 1 << " " << n - pr + 1 << endl;
        //cout << f(pref[i] - pref[pr - 1] * pow[i - pr + 1]) << " " << f(pref[n - pr + 1] - pref[n - i] * pow[i - pr + 1]) << endl;
        if(f(pref[i] - pref[pr - 1] * pow[i - pr + 1]) == f(pref[n - pr + 1] - pref[n - i] * pow[i - pr + 1])) {
            cur_found += 2, pr = i + 1;
        }
    }
    if(pr != n / 2 + 1 || n & 1)
        ++cur_found;
    cout << cur_found << endl;
    return 0;
}