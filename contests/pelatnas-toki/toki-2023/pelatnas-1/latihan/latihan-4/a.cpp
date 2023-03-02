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
const int lim = 1e5 + 5;
vector<int> child[lim];
int dfs(int nd) {
    int res = 0;
    vector<int> a;
    for(auto i : child[nd]) {
        a.pb(dfs(i));
    }
    sort(a.begin(), a.end(), greater<int>());
    for(int i = 0; i < a.size(); ++i)
        res = max(res, a[i] + i + 1);
    return res;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 2; i <= n; ++i) {
        int x;
        cin >> x;
        child[x].pb(i);
    }
    cout << dfs(1) << endl;
    return 0;
}