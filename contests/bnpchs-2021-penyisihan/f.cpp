#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lll __int128
#define ulll unsigned __int128
#define pb push_back
#define ins insert
#define lb lower_bound
#define ub upper_bound
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
using namespace std;
const int limit = 5 * 1e4 + 1;
bool used[limit];
vector<int> edges[limit], reverse_edges[limit];
stack<int> s;
void fill_stack(int node)
{
    used[node] = 1;
    for(int i = 0; i < edges[node].size(); ++i)
        if(!used[edges[node][i]])
            fill_stack(edges[node][i]);
    s.push(node);
}
set<int> dfs(int node)
{
    set<int> res;
    used[node] = 1;
    res.ins(node);
    for(int i = 0; i < reverse_edges[node].size(); ++i)
        if(!used[reverse_edges[node][i]])
        {
            set<int> cur = dfs(reverse_edges[node][i]);
            for(auto it = cur.begin(); it != cur.end(); ++it)
                res.insert(*it);
        }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, u, v;
    cin >> n >> m;
    for(int i = 0; i < m; ++i)
    {
        cin >> u >> v;
        edges[u].pb(v);
        reverse_edges[v].pb(u);
    }
    fill_stack(1);
    for(int i = 1; i <= n; ++i)
        if(!used[i])
        {
            cout << "NO" << endl;
            return 0;
        }
    memset(used, 0, sizeof(used));
    vector<set<int>> scc;
    while(s.size() > 0)
    {
        int cur = s.top();
        s.pop();
        if(!used[cur])
            scc.push_back(dfs(cur));
    }
    // go through each scc
    return 0;
}