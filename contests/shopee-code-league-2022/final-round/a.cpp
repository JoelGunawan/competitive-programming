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
const int lim = 2e5 + 1;
ll h[lim];
ll th[21][lim];
int mod = 1e9 + 9, key = 42069;
ll powmod(ll a, ll b) {
    if(b == 0)
        return 1;
    else {
        ll tmp = powmod(a, b / 2);
        tmp = (tmp * tmp) % mod;
        return b & 1 ? (tmp * a) % mod : tmp;
    }
}
// fi -> tujuan node, se -> nomer edge nya
vector<pair<int, int>> edges[lim];
ll submod(ll a, ll b) {
    return (((a - b) % mod) + mod) % mod;
}
int hq(int l, int r) {
    if(l == 0)
        return h[r];
    else {
        return submod(h[r], (h[l - 1] * powmod(powmod(key, r - l + 1), mod - 2)) % mod);
    }
}
int thq(int i, int l, int r) {
    if(l == 0)
        return th[i][r];
    else {
        return submod(th[i][r], th[i][l - 1] * powmod(powmod(key, r - l + 1), mod - 2) % mod);
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    string s;
    cin >> n >> s;
    for(int i = 0; i < n; ++i) {
        if(i == 0)
            h[i] = s[i];
        else
            h[i] = h[i - 1] * key + s[i];
        h[i] %= mod;
    }
    int k;
    cin >> k;
    string a[k];
    for(int i = 0; i < k; ++i)
        cin >> a[i];
    for(int i = 0; i < k; ++i) {
        for(int j = 0; j < a[i].size(); ++j) {
            if(j == 0)
                th[i][j] = a[i][j];
            else
                th[i][j] = th[i][j - 1] * key + a[i][j];
            th[i][j] %= mod;
        }
    }
    // buat bitmask dijkstra
    // ukurannya ga mungkin terlalu banyak
    // shortest path dari 0 ke n
    for(int i = 0; i < k; ++i) {
        for(int j = 0; j <= n - a[i].size(); ++j) {
            if(thq(i, 0, a[i].size() - 1) == hq(j, j + a[i].size() - 1))
                edges[j + a[i].size() - 1].pb(mp(j, i));
        }
    }
    // dijkstra dari n ke 0
    // simpen bitmask used
    // greedy last used terkecil untuk tiap bitmask
    // urut dari mask terkecil?
    // fi -> node, se.fi -> ans, se.se -> mask
    set<pair<int, pair<vector<int>, int>>> dijkstra;
    dijkstra.ins(mp(-n, mp(vector<int>(), 0)));
    bool vis[1 << k];
    memset(vis, 0, sizeof(vis));
    vector<int> ans[1 << k];
    bool is_ans[1 << k];
    while(dijkstra.size() > 0) {
        pair<int, pair<vector<int>, int>> cur = *dijkstra.begin();
        int nd = -cur.fi, mask = cur.se.se;
        vector<int> tmp = cur.se.fi;
        dijkstra.erase(dijkstra.begin());
        if(vis[mask]) {
            continue;
        }
        vis[mask] = 1;
        ans[mask] = tmp;
        if(nd == 0)
            is_ans[mask] = 1;
        for(auto i : edges[nd]) {
            
        }
    }
    return 0;
}