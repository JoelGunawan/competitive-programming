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
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        int a[n];
        for(int i = 0; i < n; ++i)
            cin >> a[i];
        // bsta
        // min range
        // that is possible
        // find shortest array possible such that it fulfills requirements
        // we can merge 2 arrays if we have too much
        // x -> in range
        // x = ceil((n + k) / 2)
        int min_dist = 1e9, l, r;
        int b[n];
        for(int i = 0; i < n; ++i)
            b[i] = a[i];
        sort(b, b + n);
        // the amount of in range has to be k more than not in range
        // n - (not in range) = (not in range) + k
        // n = 2 * (not in range) + k
        // 2 * (not in range) = n - k
        // not in range = (n - k) / 2
        // in range = n - not in range
        // in range = n - (n - k) / 2
        // in range = n / 2 + k / 2
        // in range = (n + k) / 2
        // we ceil because we can't have less
        for(int i = 1; i <= n; ++i) {
            
            
        }
    }
    return 0;
}