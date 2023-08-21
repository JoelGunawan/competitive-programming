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
void tc() {
    int n, k;
    cin >> n >> k;
    int c[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> c[i];
    vector<int> a[k + 1];
    for(int i = 1; i <= k; ++i)
        a[i].pb(0);
    for(int i = 1; i <= n; ++i) {
        a[c[i]].pb(i);
    }
    for(int i = 1; i <= k; ++i)
        a[i].pb(n + 1);
    int res = 1e9;
    for(int i = 1; i <= k; ++i) {
        vector<int> tmp;
        for(int j = 1; j < a[i].size(); ++j)
            tmp.push_back(a[i][j] - a[i][j - 1]);
        sort(tmp.begin(), tmp.end());
        int x = tmp.back();
        tmp.pop_back();
        //cout << "DEB " << x << endl;
        tmp.push_back(x / 2);
        tmp.push_back(x - x / 2);
        int mx = 0;
        for(auto j : tmp)
            mx = max(mx, j);
        res = min(res, mx);
    }
    cout << res - 1 << endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        tc();
    }
    return 0;
}