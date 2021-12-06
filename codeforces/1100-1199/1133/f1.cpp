#include <bits/stdc++.h>
#define endl "\n"
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
struct dsu
{
    int head[2 * (int)1e5 + 1], size[2 * (int)1e5 + 1];
    dsu()
    {
        memset(head, -1, sizeof(head));
        fill(size, size + 2 * (int)1e5 + 1, 1);
    }
    bool merge(int a, int b)
    {
        int x = find_head(a), y = find_head(b);
        if(x != y)
        {
            if(size[x] > size[y])
                size[x] += size[y], head[y] = x;
            else
                size[y] += size[x], head[x] = y;
        }
        return x != y;
    }
    int find_head(int node)
    {
        while(head[node] != -1)
            node = head[node];
        return node;
    }
};
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> edges[n + 1];
    for(int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        edges[u].pb(v);
        edges[v].pb(u);
    }
    int max_index, max_size = 0;
    for(int i = 1; i <= n; ++i)
        if(edges[i].size() > max_size)
            max_index = i, max_size = edges[i].size();
    dsu res;
    vector<pair<int, int>> output;
    for(int i = 0; i < edges[max_index].size(); ++i)
    {
        res.merge(edges[max_index][i], max_index);
        output.pb(mp(edges[max_index][i], max_index));
    }
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 0; j < edges[i].size(); ++j)
        {
            if(res.merge(i, edges[i][j]))
                output.pb(mp(i, edges[i][j]));
        }
    }
    for(int i = 0; i < output.size(); ++i)
        cout << output[i].fi << " " << output[i].se << endl;

    return 0;
}