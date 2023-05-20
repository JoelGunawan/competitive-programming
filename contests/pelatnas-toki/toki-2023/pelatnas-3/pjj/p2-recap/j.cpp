#include <bits/stdc++.h>
using namespace std;
const int lim = 1e5 + 5;
vector<int> edges[lim];
bool vis[lim];
int depth[lim], subtree[lim], ett[lim], ti = 1;
// arr simpan di depth x posisi ett brp aja
vector<int> arr[lim];
void dfs(int nd) {
    vis[nd] = 1;
    ett[nd] = ti++;
    subtree[nd] = 1;
    arr[depth[nd]].push_back(ett[nd]);
    for(auto i : edges[nd]) {
        if(!vis[i]) {
            depth[i] = depth[nd] + 1;
            dfs(i);
            subtree[nd] += subtree[i];
        }
    }
}
struct fenwick {
    long long a[lim];
    fenwick() {
        memset(a, 0, sizeof(a));
    }
    void upd(int idx, long long val) {
        while(idx < lim) {
            a[idx] += val;
            idx += idx&-idx;
        }
    }
    long long q(int idx) {
        long long ret = 0;
        while(idx) {
            ret += a[idx];
            idx -= idx&-idx;
        }
        return ret;
    }
};
int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    dfs(1);
    vector<pair<int, int>> pending;
    fenwick bit;
    for(int q = 0; q < m; ++q) {
        int op;
        cin >> op;
        if(op == 1) {
            int l, y;
            cin >> l >> y;
            // fi dist se amount
            pending.push_back({l, y}); 
            if(pending.size() >= sqrt(m)) {
                // proc
                long long add[n];
                memset(add, 0, sizeof(add));
                for(auto i : pending)
                    add[i.first] += i.second;
                for(int i = 0; i < n; ++i) {
                    if(add[i]) {
                        for(auto j : arr[i])
                            bit.upd(j, add[i]);
                    }
                }
                pending.clear();
            }
        }
        else {
            int l, r;
            cin >> l;
            r = ett[l] + subtree[l] - 1, l = ett[l];
            long long res = 0;
            for(auto i : pending) {
                res += 1ll * (upper_bound(arr[i.first].begin(), arr[i.first].end(), r) - lower_bound(arr[i.first].begin(), arr[i.first].end(), l)) * i.second;
            }
            res += bit.q(r) - bit.q(l - 1);
            cout << res << endl;
        }
    }
}