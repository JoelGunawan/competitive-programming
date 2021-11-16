#include <bits/stdc++.h>
#define pb push_back
#define ins insert
#define endl "\n"
using namespace std;
vector<int> e[5 * (int)1e4 + 1], rev[5 * (int)1e4 + 1];
vector<int> cur;
vector<vector<int>> scc;
bool vis[5 * (int)1e4 + 1];
int scc_number[5 * (int)1e4 + 1];
stack<int> s;
void dfs(int node)
{
    vis[node] = 1;
    cur.pb(node);
    for(auto i = rev[node].begin(); i != rev[node].end(); ++i)
        if(!vis[*i])
            dfs(*i);
}
void fillStack(int node)
{
    vis[node] = 1;
    for(auto i = e[node].begin(); i != e[node].end(); ++i)
        if(!vis[*i])
            fillStack(*i);
    s.push(node);
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        e[u].pb(v);
        rev[v].pb(u);
    }
    for(int i = 1; i <= n; ++i)
        if(!vis[i])
            fillStack(i);
    memset(vis, 0, sizeof(vis));
    while(!s.empty())
    {
        int v = s.top(); s.pop();
        if(!vis[v])
        {
            dfs(v);
            scc.pb(cur);
            cur.clear();
        }
    }
    // fill the SCC number
    for(int i = 0; i < scc.size(); ++i)
        for(auto j = scc[i].begin(); j != scc[i].end(); ++j)
            scc_number[*j] = i;
    // check whether it is possible with the current SCC
    int cur_scc = scc_number[1];
    bool vis_scc[scc.size()]; memset(vis_scc, 0, sizeof(vis_scc));
    bool ans = 1;
    vector<int> scc_order = {cur_scc};
    for(int i = 1; i <= n; ++i)
    {
        if(scc_number[i] == cur_scc)
            continue;
        else if(!vis_scc[scc_number[i]])
            cur_scc = scc_number[i], vis_scc[scc_number[i]] = 1, scc_order.pb(cur_scc);
        else
        {
            ans = 0;
            break;
        }
    }

    if(!ans)
    {
        cout << "NO" << endl;
        return 0;
    }
    
    // check what scc order we have to go through
    // and check whether it is possible
    // if it is not then output NO
    for(int i = 0; i < scc_order.size() - 1; ++i)
    {
        ans = 0;
        for(int j = 0; j < scc[scc_order[i]].size(); ++j)
        {
            // find node that goes to the next scc
            for(auto k = e[scc[scc_order[i]][j]].begin(); k != e[scc[scc_order[i]][j]].end(); ++k)
                if(scc_number[*k] == scc_order[i + 1])
                    ans = 1;
        }
        if(!ans)
            break;
    }
    if(ans)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}