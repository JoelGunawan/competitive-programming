#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

set<int> used;
vector<long long> low, high;
vector<vector<int>> edges;
vector<int> l, r;

void dfs(int node)
{
    used.insert(node);
    low[node] = 0, high[node] = 0;
    for(int i = 0; i < edges[node].size(); ++i)
    {
        int cur = edges[node][i];
        if(used.find(cur) != used.end())
            continue;
        if(low[cur] == -1)
            dfs(cur);
        low[node] += max(abs(l[node - 1] - r[cur - 1]) + high[cur], abs(l[node - 1] - l[cur - 1]) + low[cur]);
        high[node] += max(abs(r[node - 1] - r[cur - 1]) + high[cur], abs(r[node - 1] - l[cur - 1]) + low[cur]);
    }
    used.erase(node);
}

void test_case()
{
    int n;
    cin >> n;
    l = vector<int>(n); r = vector<int>(n);
    low = vector<long long>(n + 1, -1); high = vector<long long>(n + 1, -1);
    edges = vector<vector<int>>(n + 1, vector<int>());

    for(int i = 0; i < n; ++i)
        cin >> l[i] >> r[i];
    for(int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    dfs(1);
    cout << max(low[1], high[1]) << endl;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
        test_case();
    return 0;
}