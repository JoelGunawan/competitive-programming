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
    int n;
    cin >> n;
    int a[n];
    ll total_sum = 0;
    for(int i = 0; i < n; ++i)
        cin >> a[i], total_sum += a[i];
    ll res = LLONG_MAX;
    for(int i = 0; i < (1 << n); ++i) {
        ll cur = 0;
        for(int j = 0; j < n; ++j) {
            if((1 << j) & i)
                cur += a[j];
        }
        res = min(res, abs(cur - abs(total_sum - cur)));
    }
    cout << res << endl;
    return 0;
}