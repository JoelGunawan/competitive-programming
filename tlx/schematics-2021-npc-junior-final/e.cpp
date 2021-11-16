#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ins insert
#define lll __int128
#define endl "\n"
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#pragma GCC optimize("Ofast")
using namespace std;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> edge[n + 1];
    for(int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        edge[a].pb(b);
        edge[b].pb(a);
    }
    // O(2 * M) BFS
    // bfs for each connected component
    bool even[n + 1], odd[n + 1], vis[n + 1], ans = 0;
    memset(even, 0, sizeof(even)); memset(odd, 0, sizeof(odd)); memset(vis, 0, sizeof(vis));
    for(int i = 1; i <= n; ++i)
    {
        if(ans)
            break;
        else if(!vis[i])
        {
            // do bfs
            vis[i] = 1;
            queue<pair<int, bool>> q;
            for(int j = 0; j < edge[i].size(); ++j)
                q.push({edge[i][j], 1});
            while(q.size() > 0)
            {
                int node = q.front().first; bool is_odd = q.front().second;
                q.pop();
                vis[node] = 1;
                if(is_odd)
                    odd[node] = 1;
                else
                    even[node] = 1;
                if(odd[node] && even[node])
                {
                    ans = 1;
                    break;
                }
                for(int j = 0; j < edge[node].size(); ++j)
                {
                    if(is_odd)
                    {
                        if(!even[edge[node][j]])
                            q.push({edge[node][j], 0});
                    }
                    else
                    {
                        if(!odd[edge[node][j]])
                            q.push({edge[node][j], 1});
                    }
                }
            }
        }
    }
    if(ans)
        cout << "Ya" << endl;
    else
        cout << "Tidak" << endl;
}
int main()
{
    fast_io();
    solve();
    return 0;
}