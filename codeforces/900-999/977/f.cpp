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
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n;
    cin >> n;
    int a[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    map<int, vector<int>> b;
    int dp[n + 1], pr[n + 1];
    for(int i = 1; i <= n; ++i) {
        b[a[i]].pb(i);
        if(b[a[i] - 1].empty())
            dp[i] = 1, pr[i] = -1;
        else
            dp[i] = dp[b[a[i] - 1].back()] + 1, pr[i] = b[a[i] - 1].back();
        //cout << dp[i] << " ";
    }
    //cout << endl;
    pair<int, int> mx = mp(0, 0);
    for(int i = 1; i <= n; ++i) {
        mx = max(mx, mp(dp[i], i));
    }
    int cur_idx = mx.se;
    vector<int> res;
    while(cur_idx != -1) {
        //cout << cur_idx << endl;
        res.pb(cur_idx);
        cur_idx = pr[cur_idx];
    }
    reverse(res.begin(), res.end());
    cout << res.size() << endl;
    for(auto i : res)
        cout << i << " ";
    cout << endl;
    return 0;
}