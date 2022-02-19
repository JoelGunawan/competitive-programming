// header file
#include <bits/stdc++.h>
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
struct disjoint_set {
    int head[200001], size[200001];
    vector<int> required[200001];
    disjoint_set() {
        memset(head, -1, sizeof(head));
        fill(size, size + 200001, 1);
    }
    int find_head(int nd) {
        while(head[nd] != -1)
            nd = head[nd];
        return nd;
    }
    bool merge(int a, int b) {
        int x = find_head(a), y = find_head(b);
        if(x != y) {
            if(size[y] > size[x])
                swap(x, y);
            size[x] += size[y], head[y] = x;
            for(auto i : required[y])
                required[x].pb(i);
        }
        return x != y;
    }
};
disjoint_set dsu;
int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    int d[n + 1], sum = 0;
    for(int i = 1; i <= n; ++i)
        cin >> d[i], sum += d[i];
    if(sum != 2 * n - 2)
        cout << -1 << endl, exit(0);
    vector<pair<int, int>> edges(m);
    for(int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --d[u], -- d[v];
        edges[i] = (mp(u, v));
    }
    for(int i = 0; i < n; ++i)
        if(d[i] < 0)
            cout << -1 << endl, exit(0);
    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j < d[i]; ++j)
            dsu.required[i].pb(i);
    }
    for(auto i : edges) {
        if(!dsu.merge(i.fi, i.se))
            cout << -1 << endl, exit(0);
    }
    bool vis[n + 1];
    memset(vis, 0, sizeof(vis));
    // have a set where we have count of road connections as primary and vector of towns we need to connect as secondary
    vector<pair<int, int>> operations;
    set<pair<int, int>> s;
    for(int i = 1; i <= n; ++i) {
        //cout << dsu.find_head(i) << " " << dsu.required[dsu.find_head(i)].size() << endl;
        if(!vis[dsu.find_head(i)] && dsu.required[dsu.find_head(i)].size())
            s.ins(mp(dsu.required[dsu.find_head(i)].size(), dsu.find_head(i))), vis[dsu.find_head(i)] = 1;
    }
    while(s.size() > 1) {
        int low = (*s.begin()).se, high = (*--s.end()).se;
        //cout << low << " " << high << endl;
        s.erase(s.begin()), s.erase(--s.end());
        operations.pb(mp(dsu.required[low].back(), dsu.required[high].back()));
        --d[dsu.required[low].back()], --d[dsu.required[high].back()];
        dsu.required[low].pop_back(), dsu.required[high].pop_back();
        dsu.merge(low, high);
        if(dsu.required[dsu.find_head(low)].size()) {
            s.ins(mp(dsu.required[dsu.find_head(low)].size(), dsu.find_head(low)));
        }
    }
    for(int i = 1; i <= n; ++i)
        if(d[i] != 0)
            cout << -1 << endl, exit(0);
    for(auto i : operations)
        cout << i.fi << " " << i.se << endl;
    return 0;
}