#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define LIM 50000
#define endl "\n"
using namespace std;
vector<pair<int, int>> edges[LIM];
int dist[LIM], depth[LIM], bin_lift[LIM][16];
bool vis[LIM];
vector<int> cur_bin_lift;
void dfs(int node, int cur_dist, int d)
{
    dist[node] = cur_dist;
    vis[node] = 1;
    depth[node] = d;
    int tmp = 1, tmp_2 = 0;
    while(tmp <= cur_bin_lift.size())
    {
        bin_lift[node][tmp_2] = cur_bin_lift[cur_bin_lift.size() - tmp];
        tmp *= 2, ++tmp_2;
    }
    cur_bin_lift.pb(node);
    for(auto i : edges[node])
    {
        if(!vis[i.fi])
            dfs(i.fi, cur_dist + i.se, d + 1);
    }
    cur_bin_lift.pop_back();
}
int lca(int a, int b)
{
    if(depth[a] > depth[b])
        swap(a, b);
    // find lowest common ancestor using binlift
    // which will take around O((logn)^2)
    for(int i = 15; i >= 0; --i)
        if(depth[b] - depth[a] >= 1 << i)
            //cout << "DEPTH " << depth[a] << " " << depth[b] << " ";
            b = bin_lift[b][i];
    if(a == b)
        return a;
    for(int i = 15; i >= 0; --i)
        if(bin_lift[b][i] != -1 && bin_lift[a][i] != -1 && bin_lift[b][i] != bin_lift[a][i])
            a = bin_lift[a][i], b = bin_lift[b][i];
    return bin_lift[a][0];

}
int find_ans(vector<int> a)
{
    int total_lca = a[0];
    for(int i = 0; i < a.size(); ++i)
        total_lca = lca(total_lca, a[i]);
    int highest_lca = depth[total_lca], x, y;
    for(int i = 0; i < a.size(); ++i)
        for(int j = i + 1; j < a.size(); ++j)
        {
            if(depth[lca(a[i], a[j])] > highest_lca)
            {
                highest_lca = depth[lca(a[i], a[j])];
                x = a[i], y = a[j];
            }
        }
    if(highest_lca != depth[total_lca])
    {
        a.erase(find(a.begin(), a.end(), x));
        a.erase(find(a.begin(), a.end(), y));
        a.pb(lca(x, y));
        return dist[x] + dist[y] - 2 * dist[lca(x, y)] + find_ans(a);
    }
    else
    {
        int res = 0;
        for(int i = 0; i < a.size(); ++i)
            res += dist[a[i]] - dist[total_lca];
        return res;
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(bin_lift, -1, sizeof(bin_lift));
    int v;
    cin >> v;
    for(int i = 0; i < v - 1; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges[u].pb({v, w});
        edges[v].pb({u, w});
    }
    dfs(0, 0, 0);
    /*
    for(int i = 0; i < v; ++i)
        cout << depth[i] << " ";
    cout << endl;
    for(int i = 0; i < v; ++i)
    {
        for(int j = 0; j < 5; ++j)
            cout << bin_lift[i][j] << " ";
        cout << endl;
    }
    */
    int q;
    cin >> q;
    while(q--)
    {
        vector<int> tmp(5);
        for(int i = 0; i < 5; ++i)
            cin >> tmp[i];
        cout << find_ans(tmp) << endl;
    }
    return 0;
}