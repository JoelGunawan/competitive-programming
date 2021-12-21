#include <bits/stdc++.h>
#define ll long long
#define pb push_back
//#define endl "\n"
#pragma GCC optimize("Ofast")
using namespace std;
struct dsu{
    int head[20001], size[20001];
    void build()
    {
        memset(head, -1, sizeof(head));
        for(int i = 0; i <= 20000; ++i)
            size[i] = 1;
    }
    int find_head(int node)
    {
        if(head[node] == -1)
            return node;
        else
            return find_head(head[node]);
    }
    void merge(int x, int y)
    {
        x = find_head(x), y = find_head(y);
        if(x != y)
        {
            if(size[x] > size[y])
                size[x] += size[y], head[y] = x;
            else
                size[y] += size[x], head[x] = y;
        }
    }
};
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> concrete[n + 1], cobble[n + 1];
    set<pair<bool, pair<int, int>>> roads;
    dsu final_graph, concrete_only;
    final_graph.build(), concrete_only.build();
    for(int i = 0; i < m; ++i)
    {
        int u, v, c;
        cin >> u >> v >> c;
        if(c)
            concrete[u].pb(v), concrete[v].pb(u);
        else
            cobble[u].pb(v), cobble[v].pb(u);
        roads.insert({c, {u, v}});
    }
    vector<pair<bool, pair<int, int>>> ans;
    stack<int> dfs;
    dfs.push(1);
    bool vis[n + 1]; memset(vis, 0, sizeof(vis));
    while(dfs.size() > 0)
    {
        int cur = dfs.top(); dfs.pop();
        if(vis[cur])
            continue;
        vis[cur] = 1;
        for(auto it = concrete[cur].begin(); it != concrete[cur].end(); ++it)
            dfs.push(*it);
        for(auto it = cobble[cur].begin(); it != cobble[cur].end(); ++it)
            dfs.push(*it);
    }
    bool no_solution = 0;
    for(int i = 1; i <= n; ++i)
        if(!vis[i])
            no_solution = 1;
    if(no_solution)
        cout << "no solution" << endl, exit(0);
    for(int i = 1; i <= n; ++i)
    {
        for(auto it = concrete[i].begin(); it != concrete[i].end(); ++it)
            if(concrete_only.find_head(i) != concrete_only.find_head(*it))
                concrete_only.merge(i, *it);
    }   
    //cout << "TEST" << endl;
    for(int i = 1; i <= n; ++i)
    {
        for(auto it = cobble[i].begin(); it != cobble[i].end(); ++it)
            if(concrete_only.find_head(i) != concrete_only.find_head(*it))
                ans.pb({0, {i, *it}}), final_graph.merge(i, *it), concrete_only.merge(i, *it);
    }
    if(ans.size() > k)
        cout << "no solution" << endl, exit(0);
    for(int i = 1; i <= n; ++i)
    {
        for(auto it = cobble[i].begin(); it != cobble[i].end(); ++it)
        {
            if(ans.size() < k && final_graph.find_head(i) != final_graph.find_head(*it))
                ans.pb({0, {i, *it}}), final_graph.merge(i, *it);
        }
    }
    if(ans.size() != k)
        cout << "no solution" << endl, exit(0);
    for(int i = 1; i <= n; ++i)
    {
        for(auto it = concrete[i].begin(); it != concrete[i].end(); ++it)
            if(final_graph.find_head(i) != final_graph.find_head(*it))
                ans.pb({1, {i, *it}}), final_graph.merge(i, *it);
    }
    if(ans.size() != n - 1)
        cout << "no solution" << endl, exit(0);
    for(int i = 0; i < ans.size(); ++i)
    {
        if(roads.find(ans[i]) == roads.end())
            swap(ans[i].second.first, ans[i].second.second);
        cout << ans[i].second.first << " " << ans[i].second.second << " " << (int)ans[i].first << endl;
    }
    return 0;
}