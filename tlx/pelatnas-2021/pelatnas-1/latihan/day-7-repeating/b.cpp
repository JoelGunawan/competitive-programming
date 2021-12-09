#include <bits/stdc++.h>
#define endl "\n"
#define pb push_back
#define ins insert
#define fi first
#define se second
#define mp make_pair
#define ll long long
#define lll __int128
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
vector<pair<int, int>> edges[(int)1e5 + 1];
bool vis[(int)1e5 + 1];
int dist[(int)1e5 + 1];
void dfs(int node, int val) {
    vis[node] = 1;
    dist[node] = val;
    for(auto i : edges[node])
        if(!vis[i.fi])
            dfs(i.fi, i.se ^ val);
}
ll res = 0;
struct dsu {
    int head[(int)1e5 + 1], size[(int)1e5 + 1]; map<int, int> vals[(int)1e5 + 1];
    ll var[(int)1e5 + 1];
    dsu() {
        memset(head, -1, sizeof(head));
        memset(var, 0, sizeof(var));
        memset(size, 0, sizeof(size));
        for(int i = 0; i <= 1e5; ++i)
            vals[i][0] = 1, size[i] = 1;
    }
    int find_head(int a) {
        while(head[a] != -1)
            a = head[a];
        return a;
    }
    void merge(pair<int, int> a) {
        int x = find_head(a.fi), y = find_head(a.se);
        // find distance between x and y
        // use lca to find distance between x and y
        int distance = dist[x] ^ dist[y];
        if(size[x] < size[y]) {
            // merge ke y
            for(auto i : vals[x]) {
                // tambah result by count
                int &tmp = vals[y][i.fi ^ distance];
                var[y] -= 1ll * tmp * (tmp - 1) / 2;
                res -= 1ll * tmp * (tmp - 1) / 2;
                res -= 1ll * i.se * (i.se - 1) / 2;
                tmp += i.se;
                var[y] += 1ll * tmp * (tmp - 1) / 2;
                res += 1ll * tmp * (tmp - 1) / 2;
            }
            head[x] = y;
            size[y] += size[x];
            // cari cara buat ngitung answernya yang cepet
        }
        else {
            // merge ke x
            for(auto i : vals[y]) {
                int &tmp = vals[x][i.fi ^ distance];
                var[x] -= 1ll * tmp * (tmp - 1) / 2;
                res -= 1ll * tmp * (tmp - 1) / 2;
                res -= 1ll * i.se * (i.se - 1) / 2;
                tmp += i.se;
                var[x] += 1ll * tmp * (tmp - 1) / 2;
                res += 1ll * tmp * (tmp - 1) / 2;
            }
            head[y] = x;
            size[x] += size[y];
        }
    }
};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);  
    int n;
    cin >> n;
    vector<pair<int, int>> urutan(n - 1);
    for(int i = 0; i < n - 1; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        urutan[i] = mp(u, v);
        edges[u].pb(mp(v, w));
        edges[v].pb(mp(u, w));
    }
    int p[n - 1];
    for(int i = 0; i < n - 1; ++i)
        cin >> p[i];
    // itung find distance pake binlift
    // sama lca
    dfs(1, 0);
    dsu dsu;
    ll ans[n - 1];
    for(int i = n - 2; i >= 0; --i) {
        dsu.merge(urutan[p[i] - 1]);
        // output result
        ans[i] = res;
    }
    for(int i = 0; i < n - 1; ++i)
        cout << ans[i] << endl;
    cout << 0 << endl;
    return 0;
}