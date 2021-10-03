#include <bits/stdc++.h>
#define ll long long
#define lll __int128
#define pb push_back
using namespace std;
int previous[(int)1e5 + 1];
vector<int> edges[(int)1e5 + 1];
void dfs(int node)
{
    for(int i = 0; i < edges[node].size(); ++i)
    {
        if(edges[node][i] != previous[node])
            previous[edges[node][i]] = node, dfs(edges[node][i]);
    }
}
int main()
{
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    if(n - 1 == m)
    {
        // 37 point solution
        // find the ONLY PATH from a to b
        // use dfs algo and use previous nodes
        int u, v, w;
        for(int i = 0; i < m; ++i)
        {
            cin >> u >> v >> w;
            edges[u].pb({v});
            edges[v].pb({u});
        }
        dfs(a);
        int curnode = b;
        set<int> num; num.insert(b);
        while(curnode != a)
        {
            curnode = previous[curnode];
            num.insert(curnode);
        }
        for(int i = 0; i < n; ++i)
            if(num.find(i + 1) == num.end())
                cout << 0.0 << endl;
            else
                cout << 2.0 << endl;
    }
    else
    {
        // use bfs
    }
    return 0;
}