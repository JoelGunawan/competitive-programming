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
const int lim = 2e5 + 5;
vector<int> edges[lim];
vector<int> child[lim];
vector<ll> pre[lim][40];
vector<ll> suff[lim][40];
int par[lim], index_in_par[lim];
bool vis[lim];
void get_info(int nd) {
    vis[nd] = 1;
    for(auto i : edges[nd]) {
        if(!vis[i]) {
            get_info(i);
            par[i] = nd;
            child[nd].pb(i);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n, l;
    cin >> n >> l;
    for(int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        edges[u].pb(v);
        edges[v].pb(u);
    }
    get_info(1);
    int h[n + 1];
    for(int i = 1; i <= n; ++i) {
        cin >> h[i];
    }
    for(int i = 1; i <= n; ++i) {
        sort(child[i].begin(), child[i].end());
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j < edges[i].size(); ++j) {
            index_in_par[edges[i][j]] = j;
        }
    }
    int q;
    cin >> q;
    // create multiplication segment tree but only need to be 40*N?
    // problems -> MLE/TLE
    // excluding index k for given reach to child
    // subtask 1: brute force
    // subtask 2 and 3: segment tree build only 6N memory should be very doable
    // subtask 4: just find whether it can be reached or not
    // subtask 5: just find count because only one type
    while(q--) {
        int t;
        cin >> t;
        if(t == 1) {
            // update Dk parents
            // find product sisa x excluding child tertentu
            // O(40log)
        }
        else {
            // go to 40 parents and query
            // O(40log)
        }
    }
    return 0;
}