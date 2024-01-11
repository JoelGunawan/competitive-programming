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
int mod = 998244353;
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
        // stack of prev indexes
        vector<int> v;
        ll vsum = 0;
        ll dp[n + 1];
        p[0] = 0;
        memset(dp, 0, sizeof(dp));
        ll pref[n + 1];
        memset(pref, 0, sizeof(pref));
        pref[0] = 1;
        dp[0] = 1;
        for(int i = 1; i <= n; ++i) {
            while(v.size() && p[i] < p[v.back()]) {
                // v should have indices such that min(p[v.back() ... i] == p[v.back()])
                vsum -= dp[v.back()];
                v.pop_back();
            }
            if(v.size())
                dp[i] = (vsum + pref[i - 1] - pref[v.back()]) % mod;
            else
                dp[i] = (vsum + pref[i - 1]) % mod;
            pref[i] = (pref[i - 1] + dp[i]) % mod;
            v.pb(i);
            vsum += dp[i];
        }
        int suff[n + 1];
        ll res = 0;
        for(int i = n; i >= 1; --i) {
            suff[i] = i == n ? p[i] : min(suff[i + 1], p[i]);
            if(suff[i] == p[i]) {
                res = (res + dp[i]) % mod;
            }
        }
        res += mod;
        res %= mod;
        cout << res << endl;
    }
    return 0;
}