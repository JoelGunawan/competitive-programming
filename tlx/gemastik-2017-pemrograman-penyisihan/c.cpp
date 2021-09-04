#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define pb push_back
using namespace std;
int capacity[505][505], source = 0, writer = 100, company = 200, sink = 500;
vector<int> adj[505];
int maxflow(vector<int> &parent)
{
    fill(parent.begin(), parent.end(), -1);
    // create a queue for dfs implementation
    queue<pair<int ,int>> q;
    q.push({source, 1e9});
    // we memo the parents of each node, so that when we reach the sink, 
    //we can invert the flow by finding the parents of the sink until we get to the source node
    while(q.size())
    {
        int cur = q.front().first, flow = q.front().second;
        q.pop();
        for(int next : adj[cur])
        {
            if(parent[next] == -1 && capacity[cur][next])
            {
                parent[next] = cur;
                int newflow = min(flow, capacity[cur][next]);
                if(next == sink)
                    return newflow;
                q.push({next, newflow});
            }
        }
    }
    return 0;
}
void test_case()
{
    for(int i = 0; i < 505; ++i)
        adj[i].clear();
    memset(capacity, 0, sizeof(capacity));
    int n;
    cin >> n;
    vector<int> s(n + 1), p(n + 1);
    for(int i = 1; i <= n; ++i)
    {
        cin >> s[i];
        // edge between source and writer
        capacity[source][i] = s[i];
        adj[source].pb(i);
        adj[i].pb(source);
        // edge between writer and writer soal
        capacity[i][i + writer] = s[i];
        adj[i].pb(i + writer);
        adj[i + writer].pb(i);
        // edge between writer soal and sink
        capacity[i + writer][sink] = 1;
        adj[i + writer].pb(sink);
        adj[sink].pb(i + writer);
    }
    for(int i = 1; i <= n; ++i)
    {
        cin >> p[i];
        for(int j = 1; j <= p[i]; ++j)
        {
            int v; cin >> v;
            // add edge between writer and perusahaan
            adj[i].pb(company + v);
            adj[company + v].pb(i);
            capacity[i][company + v] = s[i];
            // add edge between perusahaan and sink
            adj[company + v].pb(sink);
            adj[sink].pb(company + v);
            capacity[company + v][sink] = 1;
        }
    }
    vector<int> parent(505);
    int flow = 0;
    while(int newflow = maxflow(parent))
    {
        flow += newflow;
        int cur = sink;
        while(cur != source)
        {
            int prev = parent[cur];
            capacity[prev][cur] -= newflow;
            capacity[cur][prev] += newflow;
            cur = prev;
        }
    }
    cout << flow << endl;
}
int main()
{
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--)
        test_case();
    return 0;
}