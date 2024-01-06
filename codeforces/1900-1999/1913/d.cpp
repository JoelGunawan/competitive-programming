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
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int p[n + 1];
        for(int i = 1; i <= n; ++i)
            cin >> p[i];
        // can delete all except min element of subarray
        // which means the least element will always exist
        // dp[i] -> ways of deletion with the last element being i
        // this is literally ksnk 2021 2A
    }
    return 0;
}