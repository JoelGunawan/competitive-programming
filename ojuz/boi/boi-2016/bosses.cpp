#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> edges[n + 1];
    for(int i = 1; i <= n; ++i) {
        int k;
        cin >> k;
        for(int j = 0; j < k; ++j) {
            int x;
            cin >> x;
            edges[x].push_back(i);
        }
    }
    int res = 1e9;
    bool vis[n + 1];
    for(int i = 1; i <= n; ++i) {
        memset(vis, 0, sizeof(vis));
        queue<pair<int, int>> q;
        q.push({i, 1});
        int cur = 0, cnt = 0;
        while(q.size()) {
            int nd = q.front().first, dist = q.front().second;
            q.pop();
            if(vis[nd])
                continue;
            ++cnt;
            vis[nd] = 1;
            cur += dist;
            for(auto j : edges[nd]) {
                if(!vis[j])
                    q.push({j, dist + 1});
            }
        }
        if(cnt == n)
            res = min(res, cur);
 
    }
    cout << res << endl;
}