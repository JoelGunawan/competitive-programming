#include <bits/stdc++.h>
using namespace std;
long long k;
const int lim = 2e5 + 5;
vector<int> edges[lim];
int a[lim], ans[lim];
bool vis[lim], active[lim];
bool check(int node, int batas) {
    // vis -> dikunjungi/belum
    // active -> aktif/bukan
    // ans -> di node ke-i maksimum operasi berapa?
    vis[node] = 1;
    active[node] = 1;
    ans[node] = 1;
    bool tmp = 0;
    for(auto i : edges[node]) {
        if(active[i])
            return 1;
        else if(a[i] <= batas) {
            if(!vis[i])
                tmp |= check(i, batas);
            ans[node] = max(ans[node], ans[i] + 1);
        }
    }
    active[node] = 0;
    if(ans[node] >= k)
        return 1;
    return tmp;
}
int main() {
    int n, m;
    cin >> n >> m >> k;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    for(int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
    }
    int l = 1, r = 1e9, res = -1;
    while(l <= r) {
        int mid = (l + r) / 2;
        bool tmp = 0;
        memset(vis, 0, sizeof(vis));
        memset(active, 0, sizeof(active));
        memset(ans, 0, sizeof(ans));
        for(int i = 1; i <= n; ++i) {
            if(!vis[i] && a[i] <= mid)
                tmp |= check(i, mid);
        }
        if(tmp)
            r = mid - 1, res = mid;
        else
            l = mid + 1;
    }
    cout << res << endl;
}