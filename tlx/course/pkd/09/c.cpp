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
const int lim = 1e4 + 5;
map<string, vector<string>> edges;
map<string, bool> vis;
map<string, string> pr;
void dfs(string nd) {
    vis[nd] = 1;
    for(auto i : edges[nd]) {
        if(!vis[i]) {
            pr[i] = nd;
            dfs(i);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    // pi -> ci
    // coba dfs dr a ke b atau dr b ke a
    for(int i = 1; i <= m; ++i) {
        string p, c;
        cin >> p >> c;
        edges[p].pb(c);
    }
    string a, b;
    cin >> a >> b;
    dfs(a);
    if(vis[b]) {
        string tmp = b;
        vector<string> x;
        while(true) {
            x.pb(tmp);
            if(tmp == a)
                break;
            tmp = pr[tmp];
        }
        reverse(x.begin(), x.end());
        for(auto i : x)
            cout << i << endl;
        return 0;
    }
    vis.clear();
    pr.clear();
    dfs(b);
    if(vis[a]) {
        string tmp = a;
        vector<string> x;
        while(true) {
            x.pb(tmp);
            if(tmp == b)
                break;
            tmp = pr[tmp];
        }
        reverse(x.begin(), x.end());
        for(auto i : x)
            cout << i << endl;
        return 0;
    }
    cout << "TIDAK MUNGKIN" << endl;
    return 0;
}