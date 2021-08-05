#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
using namespace std;
int mod = 1e9 + 7;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(n);
    vector<ll> counter(n, 0); vector<int> depth(n, -1); vector<bool> used(n, 0);
    for(int i = 0; i < m; ++i)
    {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        --tmp1; --tmp2;
        edges[tmp1].push_back(tmp2);
        edges[tmp2].push_back(tmp1);
    }
    counter[0] = 1; depth[0] = 0;
    // start at the node 0 and go through each node. If it has been visited at the same depth, we can add to it, else we skip
    // first is starting node, second is ending node, third is depth
    queue<tuple<int, int, int>> q;
    for(int i = 0; i < edges[0].size(); ++i)
        q.push(make_tuple(0, edges[0][i], 1));
    while(q.size() > 0)
    {
        if(get<2>(q.front()) > depth[get<1>(q.front())] && depth[get<1>(q.front())] != -1)
        {
            q.pop();
            continue;
        }
        // add the edges into the path if it has not been added
        if(!used[get<1>(q.front())])
        {
            used[get<1>(q.front())] = 1;
            depth[get<1>(q.front())] = get<2>(q.front());
            for(int i = 0; i < edges[get<1>(q.front())].size(); ++i)
                q.push(make_tuple(get<1>(q.front()), edges[get<1>(q.front())][i], get<2>(q.front()) + 1));
        }
        // add the path
        counter[get<1>(q.front())] += counter[get<0>(q.front())];
        counter[get<1>(q.front())] %= mod;
        q.pop();
    }
    cout << counter[n - 1] << endl;
    return 0;
}