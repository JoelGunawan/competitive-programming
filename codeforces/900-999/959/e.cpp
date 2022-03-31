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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin >> n;
    // sqrt
    // 0 -> 0
    // 1 -> 1
    // 2 -> 1
    // 3 -> 2
    // 4 -> 2
    // 5 -> 3

    // 0 -> 0
    // 1 -> 0
    // 2 -> 1
    // 3 -> 1
    // 4 -> 1
    // 5 -> 1
    // 6 -> 2
    // 7 -> 
    // 0 pair 1, 2 pair 3, ...
    // 0 pair 2, 4 pair 6, ...
    // 0 pair 4, 8 pair 12, ...
    // 0 pair 8, 16 pair 24, ...
    // find pref mask
    // val of prefmask * 
    ll res = 0;
    for(int i = 0; i < 56; ++i) {
        if(n >= (1ll << i) + 1)
            res += (1ll << i) * max(0ll, (n - (1ll << i) - 1) / (1ll << (i + 1)) + 1);
        //cout << (1ll << i) << " " << (n - (1ll << i) - 1) / (1ll << (i + 1)) << " " << res << endl;
    }
    cout << res << endl;
    return 0;
}