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
ll sqr(ll a) {
    return a * a;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int h[n], w[n];
    for(int i = 0; i < n; ++i)
        cin >> h[i];
    for(int i = 0; i < n; ++i)
        cin >> w[i];
    int pref[n];
    pref[0] = w[0];
    for(int i = 1; i < n; ++i)
        pref[i] = pref[i - 1] + w[i];
    // we choose first and we choose last
    // the problem is we need to choose some number of pillars
    // the factors of choosing a pillar
    // height
    // cost of removing the pillar
    ll dp[n];
    for(int i = 0; i < n; ++i)
        dp[i] = LLONG_MAX;
    dp[0] = 0;
    for(int i = 1; i < n; ++i) {
        for(int j = 0; j < i; ++j) {
            dp[i] = min(dp[i], dp[j] + sqr(h[i] - h[j]) + pref[i - 1] - pref[j]);  
        }
    }
    cout << dp[n - 1] << endl;
    return 0;
}