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
    int n, m;
    cin >> n >> m;
    vector<int> edges[n + 5];
    for(int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        edges[u].pb(v);
        edges[v].pb(u);
    }
    vector<pair<int, int>> v;
    for(int i = 1; i <= n; ++i) {
        v.pb(mp(edges[i].size(), i));
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    vector<int> cur;
    bool vis[n + 5];
    memset(vis, 0, sizeof(vis));
    for(auto i : v) {
        for(auto j : edges[i.se])
            vis[j] = 1;
        bool invalid = 0;
        for(auto j : cur) {
            if(!vis[j])
                invalid = 1;
        }
        for(auto j : edges[i.se])
            vis[j] = 0;
        if(invalid)
            break;
        else
            cur.pb(i.se);
    }
    // this is maximum clique
    // find other nodes that connect to all main nodes except for 1
    // if the one they are not connected to has cur.size() - 1 edges
    // therefore that is an additional way to do it
    bool chosen[n + 5];
    memset(chosen, 0, sizeof(chosen));
    for(auto i : cur)
        chosen[i] = 1;
    for(int i = 1; i <= n; ++i) {
        for(auto j : edges[i]) {
            if(!chosen[i] && !chosen[j]) {
                assert(false);
                return;
            }
        }
    }
    int mxway = 1;
    for(int i = 1; i <= n; ++i) {
        if(!chosen[i] && edges[i].size() == cur.size() - 1) {
            assert(edges[i].size() == cur.size() - 1);
            for(auto j : edges[i]) {
                vis[j] = 1;
            }
            int novis = -1;
            for(auto j : cur) {
                if(!vis[j])
                    novis = j;
            }
            assert(novis != -1);
            if(edges[novis].size() == cur.size() - 1)
                ++mxway;
            for(auto j : edges[i]) {
                vis[j] = 0;
            }
        }
    }
    int lowercnt = 0;
    for(auto i : cur) {
        if(edges[i].size() == cur.size() - 1)
            ++lowercnt;
    }
    if(lowercnt) {
        cout << mxway << " " << lowercnt << endl;
        //assert(mxway == 1 || lowercnt == 1);
        return;
    }
    // gada yg lower, berarti nnti cari yg count neighbornya cmn 1
    int mnway = 1;
    for(auto i : cur) {
        if(edges[i].size() == cur.size())
            ++mnway;
    }
    //assert(mxway == 1);
    cout << mxway << " " << mnway << endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--)
        tc();
    return 0;
}