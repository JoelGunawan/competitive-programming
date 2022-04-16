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
const int lim = 200005;
vector<int> edges[lim];
bool vis[lim];
int pre[lim], o[lim], s;
void dfs(int nd, int p, int origin) {
    if(nd == s)
        return;
    if(vis[nd] && o[nd] != origin) {
        cout << "Possible" << endl;
        vector<int> a, b;
        int tmp = nd;
        while(a.size() == 0 || a.back() != s) {
            a.pb(tmp);
            tmp = pre[tmp];
        }
        b.pb(nd);
        tmp = p;
        while(b.back() != s) 
            b.pb(tmp), tmp = pre[tmp];
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        cout << a.size() << endl;
        for(auto i : a)
            cout << i << " ";
        cout << endl;
        cout << b.size() << endl;
        for(auto i : b)
            cout << i << " ";
        cout << endl;
        exit(0);
    }
    else if(vis[nd])
        return;
    vis[nd] = 1, o[nd] = origin;
    pre[nd] = p;
    for(auto i : edges[nd]) {
        dfs(i, nd, origin);
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m >> s;
    // dfs from s
    for(int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        edges[u].pb(v);
    }
    vis[s] = 1;
    for(auto i : edges[s]) {
        dfs(i, s, i);
    }
    cout << "Impossible" << endl;
    return 0;
}