#include <bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    priority_queue<pair<int, int>> nodes;
    bool used[n]; memset(used, 0, sizeof(used));
    vector<vector<pair<int, int>>> a(n, vector<pair<int, int>>());
    ll total = 0;
    for(int i = 0; i < m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        total += w;
        --u, --v;
        a[u].pb({-w, v});
        a[v].pb({-w, u});
    }
    for(int i = 0; i < a[0].size(); ++i)
        nodes.push({a[0][i].first, a[0][i].second});
    used[0] = 1;
    ll res = 0;
    while(nodes.size() > 0)
    {
        pair<int, int> cur = nodes.top();
        nodes.pop();
        if(used[cur.second])
            continue;
        used[cur.second] = 1;
        res += (-cur.first);
        for(int i = 0; i < a[cur.second].size(); ++i)
            nodes.push({a[cur.second][i].first, a[cur.second][i].second});
    }
    cout << total - res << endl;
    return 0;
}