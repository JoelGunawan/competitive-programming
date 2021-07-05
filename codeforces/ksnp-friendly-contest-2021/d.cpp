#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#pragma GCC optimize("O3")
#pragma GCC target("avx2")
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<bool> visited(n + 1, 0);
    vector<vector<pair<int, int>>> arr(n + 1, vector<pair<int, int>>());
    for(int i = 0; i < m; ++i)
    {
        int a, b, w;
        cin >> a >> b >> w;
        arr[a].push_back(make_pair(-w, b));
        arr[b].push_back(make_pair(-w, a));
    }
    // try to make a minimum spanning tree
    // select an arbritary node
    priority_queue<pair<int, int>> a;
    for(int i = 0; i < arr[1].size(); ++i)
        a.push(arr[1][i]);
    visited[1] = 1;
    int largestedge = 0;
    ll res = 0;
    while(a.size() > 0)
    {
        // process the current one
        if(visited[a.top().second])
        {
            a.pop();
            continue;
        }
        pair<int, int> x = a.top();
        a.pop();
        res += -x.first;
        visited[x.second] = 1;
        for(int i = 0; i < arr[x.second].size(); ++i)
            a.push(arr[x.second][i]);
        largestedge = max(largestedge, -x.first);
    }
    int index = 0;
    for(int i = 1; i < visited.size(); ++i)
        if(!visited[i])
        {
            index = i;
            break;
        }
    if(!index)
    {
        // we need to find the way of making the tree as minimum as possible
    }
    else
    {
        visited[index] = 1;
        for(int i = 0; i < arr[index].size(); ++i)
            a.push(arr[index][i]);
        while(a.size() > 0)
        {
            if(visited[a.top().second])
            {
                a.pop();
                continue;
            }
            pair<int, int> x = a.top();
            a.pop();
            res += -x.first;
            visited[x.second] = 1;
            for(int i = 0; i < arr[x.second].size(); ++i)
                a.push(arr[x.second][i]);
        }
        bool ans = 1;
        for(int i = 1; i < visited.size(); ++i)
            if(!visited[i])
                ans = 0;
        if(ans)
            cout << res << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}