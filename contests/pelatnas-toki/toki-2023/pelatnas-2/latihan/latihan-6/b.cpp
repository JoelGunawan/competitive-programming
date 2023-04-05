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
const int lim = 4e5 + 5;
vector<int> edges[lim], component[lim];
bool vis[lim];
int timer, disc[lim], low[lim], component_num[lim], component_cnt = 0;
bool valid[lim];
int s[lim], s_size = 0;
set<pair<int, int>> adj, adj2;
vector<pair<int, int>> output;
void dfs(int nd) {
    disc[nd] = low[nd] = timer++;
    s[s_size++] = nd;
    valid[nd] = 1;
    //cout << nd << endl;
    for(auto i : edges[nd]) {
        if(!adj.count(mp(min(nd, i), max(nd, i))))
            continue;
        adj.erase(mp(min(nd, i), max(nd, i)));
        if(disc[i] == -1) {
            dfs(i);
            low[nd] = min(low[nd], low[i]);
            // not back edge
            output.pb(mp(nd, i));
        }
        else if(valid[i]) {
            low[nd] = min(low[nd], disc[i]);
            // back edge
            output.pb(mp(nd, i));
        }
        else
            output.pb(mp(nd, i));
    }
    //cout << nd << " " << disc[nd] << " " << low[nd] << endl;
    if(low[nd] == disc[nd]) {
        ++component_cnt;
        do {
            component[component_cnt].pb(s[s_size - 1]);
            valid[s[s_size - 1]] = 0;
            component_num[s[s_size - 1]] = component_cnt;
            --s_size;
        } while(component[component_cnt].back() != nd);
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    memset(disc, -1, sizeof(disc));
    for(int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        edges[u].pb(v);
        edges[v].pb(u);
        adj.insert(mp(min(u, v), max(u, v)));
        assert(adj.count(mp(min(u, v), max(u, v))) == 1);
    }
    adj2 = adj;
    memset(vis, 0, sizeof(vis));
    dfs(1);
    int idx, ans = 0;
    for(int i = 1; i <= component_cnt; ++i) {
        if(component[i].size() > ans)
            ans = component[i].size(), idx = i;
    }
    adj = adj2;
    cout << ans << endl;
    if(ans == 1) {
        // output random
        for(auto i : adj) 
            cout << i.fi << " " << i.se << endl;
    }
    else {
        // use previous from
        // sisanya itu harus menuju ke cycle arah edgenya
        // bisa pakai dfs
        // untuk tiap edge di cycle, nanti
        // dfs dari cur aja :D
        sort(component[idx].begin(), component[idx].end());
        for(auto i : output) {
            if(binary_search(component[idx].begin(), component[idx].end(), i.fi) && binary_search(component[idx].begin(), component[idx].end(), i.se))
                cout << i.fi << " " << i.se << endl, adj.erase(mp(min(i.fi, i.se), max(i.fi, i.se)));
        }
        // sisanya bfs dr component
        queue<int> q;
        for(auto i : component[idx])
            q.push(i);
        while(q.size()) {
            int nd = q.front();
            q.pop();
            if(vis[nd])
                continue;
            for(auto i : edges[nd]) {
                if(adj.count(mp(min(i, nd), max(i, nd)))) {
                    adj.erase(mp(min(i, nd), max(i, nd)));
                    cout << i << " " << nd << endl;
                    q.push(i);
                }
            }
        }
        for(auto i : adj)
            cout << i.fi << " " << i.se << endl;
    }
    return 0;
}