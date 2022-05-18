#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    // k is 2, 3, or 4
    // size 1xk
    // sus small k
    vector<pair<int, int>> ans[n * n * k];
    // k == 2 -> cari any square yang jarak manhattan 2 square lain
    // sweep dari kiri ke kanan
    // sweep dari bawah ke atas
    // biar ga ada case bolong
    // ijin ke toilet
    vector<vector<bool>> vis(n * k + 1, vector<bool>(n * k + 1, 0)), vis2 = vis;
    int last = 0;
    function<bool(int, int)> valid = [&] (int x, int y) -> bool {
        return !(x <= 0 || x > n * k || y <= 0 || y > n * k || vis[x][y] || vis2[x][y]);
    };
    function<vector<pair<int, int>>(int, int)> dfs = [&] (int x, int y) -> vector<pair<int, int>> {
        vector<pair<int, int>> ans = {make_pair(x, y)};
        //cout << x << " " << y << endl;
        vis2[x][y] = 1;
        if(valid(x + 1, y)) {
            vector<pair<int, int>> tmp = dfs(x + 1, y);
            for(auto i : tmp)
                ans.push_back(i);
        }
        if(valid(x - 1, y)) {
            vector<pair<int, int>> tmp = dfs(x - 1, y);
            for(auto i : tmp)
                ans.push_back(i);
        }
        if(valid(x, y - 1)) {
            vector<pair<int, int>> tmp = dfs(x, y - 1);
            for(auto i : tmp)
                ans.push_back(i);
        }
        if(valid(x, y + 1)) {
            vector<pair<int, int>> tmp = dfs(x, y + 1);
            for(auto i : tmp)
                ans.push_back(i);
        }
        return ans;
    };
    vector<pair<int, int>> active;
    for(int i = 1; i <= n * k; ++i)
        for(int j = 1; j <= n * k; ++j) {
            active.push_back(make_pair(i, j));
        }
    bool used[active.size()];
    while(last < n * n * k) {
        // pick a random point
        // dfs that point
        // if dfs size == k
        // put in to one component
        // else
        // don't
        int r = rand();
        r %= active.size();
        while(used[r]) {
            r = rand();
            r %= active.size();
        }
        fill(vis2.begin(), vis2.end(), vector<bool>(n * k + 1, 0));
        vector<pair<int, int>> tmp = dfs(active[r].first, active[r].second);
        //cout << tmp.size() << endl;
        if(tmp.size() != k) {
            tmp = {active[r]};
            cout << "ASK " << active[r].first << " " << active[r].second << endl;
            for(int i = 0; i < k - 1; ++i) {
                int x, y;
                cin >> x >> y;
                tmp.push_back(make_pair(x, y));
            }
        }
        ans[last] = tmp;
        for(auto i : tmp) {
            vis[i.first][i.second] = 1;
            for(int j = 0; j < active.size(); ++j) 
                if(active[j] == i)
                    used[j] = 1;
        }
        ++last;
    }
    // ijin ke toilet
    cout << "ANSWER" << endl;
    for(auto i : ans) {
        for(auto j : i) {
            cout << j.first << " " << j.second << " ";
        }
        cout << endl;
    }
    return 0;
}