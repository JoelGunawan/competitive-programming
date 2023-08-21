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
const int lim = 2e3 + 5;
int dp[lim][lim], n, a[lim];
int solve(int l, int r) {
    if(dp[l][r] != -1)
        return dp[l][r];
    if(l >= r)
        return dp[l][r] = 0;
    if(a[l] == a[r]) {
        return dp[l][r] = 1 + solve(l + 1, r - 1);
    }
    else {
        return dp[l][r] = max(solve(l + 1, r), solve(l, r - 1));
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    memset(dp, -1, sizeof(dp));
    cin >> n;
    vector<int> tmp;
    for(int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        if(tmp.empty() || x != tmp.back())
            tmp.pb(x);
    }
    for(int i = 0; i < tmp.size(); ++i)
        a[i + 1] = tmp[i];
    n = tmp.size();
    cout << n - 1 - solve(1, n) << endl;
    return 0;
}