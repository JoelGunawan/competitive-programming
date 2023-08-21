// header file
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// pragma
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
// macros
//#define endl "\n"
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
    //ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    // ett aja
    vector<int> edges[n + 1];
    bool vis[n + 1];
    int par[n + 1];
    memset(par, -1, sizeof(par));
    memset(vis, 0, sizeof(vis));
    int cur = 1;
    while(cur != n) {
        int k;
        cin >> k;
        for(int i = 0; i < k; ++i) {
            int x;
            cin >> x;
            if(!vis[cur])
                edges[cur].pb(x);
        }
        vis[cur] = 1;
        int nxt = par[cur];
        for(auto i : edges[cur]) {
            if(!vis[i]) {
                nxt = i;
                par[i] = cur;
                break;
            }
        }
        cur = nxt;
        cout << cur << endl;
    }
    string buang;
    cin >> buang;
    return 0;
}