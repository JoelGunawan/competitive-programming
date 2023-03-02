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
int mod = 1e9 + 7;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    ll n, ha, hb;
    cin >> n >> ha >> hb;
    ll a[n + 1];
    a[0] = -1e18;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    if(ha < hb)
        swap(ha, hb);
    // ha besar, hb kecil
    for(int i = 3; i <= n; ++i) {
        if(a[i] - a[i - 2] < hb) {
            cout << 0 << endl;
            return 0;
        }
    }
    ll dp[n + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    ll pr[n + 1];
    memset(pr, 0, sizeof(pr));
    pr[0] = 1;
    int inval = 0, can = 0;
    for(int i = 1; i <= n; ++i) {
        // ambil dari previous few dp
        // gaboleh ambil dari yg ada inval
        while(can < n && a[can + 1] <= a[i] - ha)
            ++can;
        if(inval > can)
            dp[i] = 0;
        else {
            dp[i] += pr[can];
            if(inval != 0)
                dp[i] -= pr[inval - 1];
        }
        //cout << can << " " << inval << " " << dp[i] << endl;
        dp[i] %= mod;
        pr[i] = pr[i - 1] + dp[i];
        pr[i] %= mod;
        if(a[i] - a[i - 1] < hb)
            inval = i - 1;
    }
    ll res = 0;
    for(int i = inval; i <= n; ++i) {
        res += dp[i];
    }
    res %= mod;
    res += mod;
    res %= mod;
    cout << res << endl;
    return 0;
}