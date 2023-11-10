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
    int n, k, c;
    cin >> n >> k >> c;
    pair<int, int> a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i].fi >> a[i].se;
    int cnt[n + 1];
    memset(cnt, 0, sizeof(cnt));
    // fi -> rank
    // se -> id
    vector<pair<int, int>> ans;
    bool taken[n];
    memset(taken, 0, sizeof(taken));
    for(int i = 0; i < n; ++i) {
        if(cnt[a[i].se] < c && ans.size() < k)
            ans.pb(mp(i, a[i].fi)), ++cnt[a[i].se], taken[i] = 1;
    }
    for(int i = 0; i < n; ++i) {
        if(!taken[i] && ans.size() < k) {
            ans.pb(mp(i, a[i].fi));
        }
    }
    //cout << ans.size() << endl;
    sort(ans.begin(), ans.end());
    for(auto i : ans)
        cout << i.se << endl;
    return 0;
}