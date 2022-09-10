// header file
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
const int lim = 3e5 + 5;
int a[lim], cnt[lim], mod = 998244353;
vector<int> edges[lim];
bool vis[lim];
struct disjoint_set {
    int head[lim], size[lim];
    ll sum[lim];
    map<int, ll> m[lim];
    disjoint_set() {
        memset(head, -1, sizeof(head)), fill(size, size + lim, 1), memset(sum, 0, sizeof(sum));
    }
    int find_head(int nd) {
        while(head[nd] != -1)
            nd = head[nd];
        return nd;
    }
    void merge(int x, int y) {
        x = find_head(x), y = find_head(y);
        if(x != y) {
            if(size[x] < size[y])
                swap(x, y);
            head[y] = x, size[x] += size[y];
            if(m[x].size() < m[y].size())
                swap(m[x], m[y]);
            sum[x] += sum[y];
            sum[x] %= mod;
            for(auto i : m[y]) {
                if(m[x][i.fi] != 0) {
                    // kurangi prev
                    // tambah gabungan
                    sum[x] -= 1ll * i.se * (m[x][i.fi] * (m[x][i.fi] - 1));
                    sum[x] %= mod;
                    sum[x] -= 1ll * m[x][i.fi] * (i.se * (i.se - 1));
                    sum[x] %= mod;
                    sum[x] -= 1ll * m[x][i.fi] * i.se * (cnt[i.fi] - m[x][i.fi] - i.se);
                    sum[x] %= mod;
                    if(sum[x] < 0)
                        sum[x] += mod;
                    m[x][i.fi] += i.se;
                }
                else
                    m[x][i.fi] += i.se;
            }
        }
    }
};
disjoint_set dsu;
ll dfs(int nd) {
    vis[nd] = 1;
    ll ans = 0;
    for(auto i : edges[nd]) {
        if(!vis[i]) {
            ans += dfs(i);
            ans %= mod;
            dsu.merge(nd, i);
        }
    }
    ans += dsu.sum[dsu.find_head(nd)];
    ans %= mod;
    if(ans < 0)
        ans += mod;
    return ans;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    for(int i = 1; i <= n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        edges[u].pb(v);
        edges[v].pb(u);
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = 2; j <= sqrt(a[i]); ++j) {
            if(a[i] % j == 0) {
                ++cnt[j];
                ++dsu.m[i][j];
                while(a[i] % j == 0)
                    a[i] /= j;
            }
        }
        if(a[i] > 1) {
            ++cnt[a[i]];
            ++dsu.m[i][a[i]];
        }
    }
    for(int i = 1; i <= n; ++i) {
        for(auto j : dsu.m[i]) {
            dsu.sum[i] += 1ll * (cnt[j.fi] - 1) * (cnt[j.fi] - 2) >> 1;
            dsu.sum[i] %= mod;
        }
    }
    cout << dfs(1) % mod << endl;
    return 0;
}