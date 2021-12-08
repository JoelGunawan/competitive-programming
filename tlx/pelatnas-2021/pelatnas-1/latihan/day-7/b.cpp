#include <bits/stdc++.h>
#define endl "\n"
#define pb push_back
#define ins insert
#define fi first
#define se second
#define mp make_pair
#define ll long long
#define lll __int128
#pragma GCC optimize("Ofast")
using namespace std;
vector<pair<int, int>> edges[(int)1e5 + 1];
int par[17][(int)1e5 + 1], par_dist[17][(int)1e5 + 1], depth[(int)1e5 + 1];
int cur[(int)1e5 + 1], cur_dist[(int)1e5 + 5], cur_size = 0, cur_dist_size = 1;
bool vis[(int)1e5 + 1];
void dfs(int node) {
    vis[node] = 1;
    depth[node] = cur_size;
    int tmp = 1, tmp2 = 0;
    while(cur_size >= tmp) {
        par[tmp2][node] = cur[cur_size - tmp];
        par_dist[tmp2][node] = cur_dist[cur_dist_size - 1] ^ cur_dist[cur_dist_size - tmp - 1];
        tmp *= 2, ++tmp2;
    }
    cur[cur_size++] = node;
    for(auto i : edges[node]) {
        if(!vis[i.fi]) {
            cur_dist[cur_dist_size] = cur_dist[cur_dist_size - 1] ^ i.se;
            ++cur_dist_size;
            dfs(i.fi);
            --cur_dist_size;
        }
    }
    --cur_size;
}
int find_dist(int a, int b) {
    if(depth[a] > depth[b])
        swap(a, b);
    int dist = 0;
    for(int i = 16; i >= 0; --i)
        if(depth[b] - depth[a] >= 1 << i)
            dist ^= par_dist[i][b], b = par[i][b];
    if(a == b)
        return dist;
    for(int i = 16; i >= 0; --i)
        if(par[i][a] != par[i][b]) {
            dist ^= par_dist[i][a] ^ par_dist[i][b];
            a = par[i][a];
            b = par[i][b];
        }
    return par_dist[0][a] ^ par_dist[0][b] ^ dist;
}
int res = 0;
struct dsu {
    int head[(int)1e5 + 1]; multiset<int> vals[(int)1e5 + 1]; int var[(int)1e5 + 1];
    dsu() {
        memset(head, -1, sizeof(head));
        memset(var, 0, sizeof(var));
        for(int i = 0; i <= 1e5; ++i)
            vals[i].insert(0);
    }
    int find_head(int a) {
        while(head[a] != -1)
            a = head[a];
        return a;
    }
    void merge(int a, int b) {
        int x = find_head(a), y = find_head(b);
        // find distance between x and y
        // use lca to find dist between x and y
        int dist = find_dist(x, y);
        if(vals[x].size() < vals[y].size()) {
            // merge ke y
            res -= var[x];
            for(auto i : vals[x]) {
                // tambah result by count
                res += vals[y].count(i ^ dist);
                var[y] += vals[y].count(i ^ dist);
                vals[y].ins(i ^ dist);
            }
            head[x] = y;
            // cari cara buat ngitung answernya yang cepet
        }
        else {
            // merge ke x
            res -= var[y];
            for(auto i : vals[y]) {
                res += vals[x].count(i ^ dist);
                var[x] += vals[x].count(i ^ dist);
                vals[x].ins(i ^ dist);
            }
            head[y] = x;
        }
    }
};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cur_dist[0] = 0;
    int n;
    cin >> n;
    vector<pair<int, pair<int, int>>> urutan(n - 1);
    for(int i = 0; i < n - 1; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        urutan[i] = mp(w, mp(u, v));
        edges[u].pb(mp(v, w));
        edges[v].pb(mp(u, w));
    }
    int p[n - 1];
    for(int i = 0; i < n - 1; ++i)
        cin >> p[i];
    // itung find dist pake binlift
    // sama lca
    dfs(1);
    dsu dsu;
    int ans[n - 1];
    for(int i = n - 2; i >= 0; --i) {
        pair<int, pair<int, int>> cur = urutan[p[i] - 1];
        dsu.merge(cur.se.fi, cur.se.se);
        // output result
        ans[i] = res;
    }
    for(int i = 0; i < n - 1; ++i)
        cout << ans[i] << endl;
    cout << 0 << endl;
    return 0;
}