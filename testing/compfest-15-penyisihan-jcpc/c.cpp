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
vector<pair<int, int>> edges[lim];
int mod = 998244353;
ll one[lim], zero[lim], loc[lim];
bool vis[lim];
void dfs(int nd) {
    vis[nd] = 1;
    //cout << nd << endl;
    //cout.flush();
    for(auto i : edges[nd]) {
        if(!vis[i.fi])
            dfs(i.fi);
        // calculate one and zero
        if(i.se) {
            // one
            ++one[nd];
            one[nd] %= mod;
        }
        else {
            // zero
            loc[nd] += one[nd];
            loc[nd] %= mod;
            ++zero[nd];
            zero[nd] %= mod;
        }
        loc[nd] += loc[i.fi] + (zero[i.fi] * one[nd]);
        zero[nd] += zero[i.fi];
        one[nd] += one[i.fi];
        loc[nd] %= mod;
        zero[nd] %= mod;
        one[nd] %= mod;
    }
}
int main() {
    //ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        int s;
        //cout << "TEST" << endl;
        //cout.flush();
        cin >> s;
        for(int j = 0; j < s; ++j) {
            int x, y;
            cin >> x >> y;
            edges[i].pb(mp(x, y));
        }
    }
    dfs(1);
    cout << loc[1] << endl;
    return 0;
}