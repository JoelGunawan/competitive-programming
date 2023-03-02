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
int mod = 998000027;
ll powmod(ll a, ll b) {
    if(b == 0)
        return 1;
    else {
        ll tmp = powmod(a, b >> 1);
        tmp = (tmp * tmp) % mod;
        return b & 1 ? (tmp * a) % mod : tmp;
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n;
    cin >> n;
    int a[n + 1], b[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    for(int i = 1; i <= n; ++i)
        cin >> b[i];
    // for each number from a to b, determine minimum largest modulo required to get between the 2 numbers
    int dp[205][205];
    for(int i = 0; i < 205; ++i)
        for(int j = 0; j < 205; ++j)
            dp[i][j] = 1e3;
    for(int i = 0; i <= 200; ++i)
        dp[i][i] = 0;
    for(int i = 1; i <= 200; ++i) {
        for(int j = 0; j <= i; ++j) {
            for(int k = 1; k <= i; ++k) {
                dp[i][j] = min(dp[i][j], max(k, dp[i % k][j]));
            }
        }
    }
    for(int i = 1; i <= n; ++i) {
        if(dp[a[i]][b[i]] > 200)
            cout << -1 << endl, exit(0);
    }
    set<int> possible_nums[n + 1];
    int correct = 0;
    bool done[205];
    memset(done, 0, sizeof(done));
    ll ans = 0;
    for(int i = 1; i <= n; ++i) {
        if(a[i] == b[i]) {
            ++correct;
            done[i] = 1;
            continue;
        }
        possible_nums[i].ins(a[i]);
    }
    while(correct < n) {
        // choose number with largest modulo minimum modulo requirements
        // add possible numbers
        int mx = 0;
        for(int i = 1; i <= n; ++i) {
            if(!done[i]) {
                int mn = 1e9;
                for(auto j : possible_nums[i])
                    mn = min(mn, dp[j][b[i]]);
                mx = max(mx, mn);
            }
        }
        ans += powmod(2, mx);
        for(int i = 1; i <= n; ++i) {
            if(!done[i]) {
                vector<int> ne;
                for(auto j : possible_nums[i]) {
                    ne.pb(j % mx);
                }
                for(auto j : ne) {
                    if(j == b[i]) {
                        possible_nums[i].clear();
                        done[i] = 1;
                        ++correct;
                        break;
                    }
                    possible_nums[i].ins(j);
                }
            }
        }
    }   
    cout << ans % mod << endl;
    // for each set of numbers, we need to consider what the largest minimum required is
    return 0;
}