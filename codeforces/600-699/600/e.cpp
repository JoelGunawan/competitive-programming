// header file
#include <bits/stdc++.h>
// pragma
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
// macros
#define endl "\n"
#define ll long long
#define mp make_pair
#define ins insert
#define lb lower_bound
#define pb push_back
#define ub upper_bound
#define lll __int128
#define fi first
#define se second
using namespace std;
const int lim = 1e5 + 5;
vector<int> edges[lim];
int c[lim];
ll ans[lim];
bool vis[lim];
struct disjoint_set {
    int head[lim], size[lim], val[lim];
    ll res[lim];
    disjoint_set() {
        memset(head, -1, sizeof(head));
        memset(val, 0, sizeof(val));
        memset(res, 0, sizeof(res));
        fill(size, size + lim, 1);
    }
    set<pair<int, int>> a[lim];
    int find_head(int nd) {
        while(head[nd] != -1)
            nd = head[nd];
        return nd;
    }
    bool merge(int x, int y) {
        x = find_head(x), y = find_head(y);
        if(x != y) {
            if(size[x] < size[y])
                swap(x, y);
            size[x] += size[y], head[y] = x;
            if(val[x] == val[y])
                res[x] += res[y];
            else if(val[x] < val[y])
                val[x] = val[y], res[x] = res[y];
            for(auto i : a[y]) {
                if(a[x].lb(mp(i.fi, 0)) != a[x].end() && (*a[x].lb(mp(i.fi, 0))).fi == i.fi) {
                    pair<int, int> tmp = mp(i.fi, i.se + (*a[x].lb(mp(i.fi, 0))).se);
                    a[x].erase(a[x].lb(mp(i.fi, 0)));
                    if(tmp.se > val[x]) {
                        val[x] = tmp.se;
                        res[x] = i.fi;
                    }
                    else if(tmp.se == val[x])
                        res[x] += i.fi;
                    a[x].ins(tmp);
                }
                else
                    a[x].ins(i);
            }
        }
        return x != y;
    }
};
disjoint_set dsu;
void dfs(int nd) {
    vis[nd] = 1;
    vector<int> child;
    dsu.a[nd].ins(mp(c[nd], 1));
    dsu.res[nd] = c[nd];
    dsu.val[nd] = 1;
    for(auto i : edges[nd])
        if(!vis[i])
            dfs(i), dsu.merge(nd, i);
    ans[nd] = dsu.res[dsu.find_head(nd)];
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> c[i];
    for(int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        edges[u].pb(v);
        edges[v].pb(u);
    }
    dfs(1);
    for(int i = 1; i <= n; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}