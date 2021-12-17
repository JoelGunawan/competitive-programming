#include <bits/stdc++.h>
#define endl "\n"
#define pb push_back
#define fi first
#define se second
#define ll long long
#define mp make_pair
#define lb lower_bound
using namespace std;
int maxi(int a, int b, int c) {
    return max(a, max(b, c));
}
int mini(int a, int b, int c) {
    return min(a, min(b, c));
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> edges[n + 1];
    for(int i = 0; i < n + 1; ++i)
        edges[i] = vector<int>();
    for(int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        edges[u].pb(v);
        edges[v].pb(u);
    }
    int subtree[n + 1]; memset(subtree, 0, sizeof(subtree));
    bool vis[n + 1]; memset(vis, 0, sizeof(vis));
    function<int(int)> get_subtree = [&] (int node) -> int {
        vis[node] = 1;
        subtree[node] = 1;
        for(auto i : edges[node])
            if(!vis[i])
                subtree[node] += get_subtree(i);
        return subtree[node];
    };
    get_subtree(1);
    int res = INT_MAX;
    multiset<int> cur;
    memset(vis, 0, sizeof(vis));
    function<void(int)> dfs = [&] (int node) -> void {
        vis[node] = 1;
        if(cur.size() != 0) {
            // cari di cur yang paling mendekati
            int mid = (n - subtree[node]) / 2 + subtree[node];
            // cari yang paling mendekati mid
            if(cur.lb(mid) != cur.end())
                res = min(res, maxi(subtree[node], *cur.lb(mid) - subtree[node], n - *cur.lb(mid)) - mini(subtree[node], *cur.lb(mid) - subtree[node], n - *cur.lb(mid)));
            if(cur.lb(mid) != cur.begin())
                res = min(res, maxi(subtree[node], *--cur.lb(mid) - subtree[node], n - *--cur.lb(mid)) - mini(subtree[node], *--cur.lb(mid) - subtree[node], n - *--cur.lb(mid)));
        }
        cur.insert(subtree[node]);
        for(auto i : edges[node])
            if(!vis[i])
                dfs(i);
        cur.erase(cur.find(subtree[node]));
    };
    dfs(1);
    memset(vis, 0, sizeof(vis));
    for(int i = 1; i <= n; ++i)
        cur.insert(subtree[i]);
    dfs = [&] (int node) -> void {
        vis[node] = 1;
        cur.erase(cur.find(subtree[node]));
        if(cur.size() != 0) {
            int mid = (n - subtree[node]) / 2;
            if(cur.lb(mid) != cur.end())
                res = min(res, maxi(subtree[node], *cur.lb(mid), n - subtree[node] - *cur.lb(mid)) - mini(subtree[node], *cur.lb(mid), n - subtree[node] - *cur.lb(mid)));
            if(cur.lb(mid) != cur.begin())
                res = min(res, maxi(subtree[node], *--cur.lb(mid), n - subtree[node] - *--cur.lb(mid)) - mini(subtree[node], *--cur.lb(mid), n - subtree[node] - *--cur.lb(mid)));
        }
        for(auto i : edges[node])
            if(!vis[i])
                dfs(i);
        cur.insert(subtree[node]);
    };
    dfs(1);
    cout << res << endl;
    return 0;
}