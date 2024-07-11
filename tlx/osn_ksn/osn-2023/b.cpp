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
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> edges[n + 5];
    for(int j = 1; j <= m; ++j) {
        int u, v;
        cin >> u >> v;
        edges[u].pb(v);
        edges[v].pb(u);
    }
    for(int i = 1; i <= n; ++i) {
        sort(edges[i].begin(), edges[i].end());
    }
    ll res = 0;
    // // cerr << "TST" << endl;
    for(int i = 1; i <= n; ++i) {
        // find left first and right first
        int l = 0, r = n + 1;
        if(lb(edges[i].begin(), edges[i].end(), i) != edges[i].begin())
            l = *--lb(edges[i].begin(), edges[i].end(), i);
        if(ub(edges[i].begin(), edges[i].end(), i) != edges[i].end())
            r = *ub(edges[i].begin(), edges[i].end(), i);
        // within l, r
        res += 1ll * (i - l) * (r - i);
        // cerr << "DEB " << i << " " << (i - l) * (r - i) << " ";
        if(l != 0) {
            int cl = 0, cr = r;
            if(ub(edges[l].begin(), edges[l].end(), l) != edges[l].end())
                cr = min(cr, *ub(edges[l].begin(), edges[l].end(), l));
            if(lb(edges[l].begin(), edges[l].end(), l) != edges[l].begin())
                cl = *--lb(edges[l].begin(), edges[l].end(), l);
            if(lb(edges[i].begin(), edges[i].end(), l) != edges[i].begin())
                cl = max(cl, *--lb(edges[i].begin(), edges[i].end(), l));
            if(cr == i) {
                if(ub(edges[l].begin(), edges[l].end(), i) != edges[l].end())
                    cr = min(r, *ub(edges[l].begin(), edges[l].end(), i));
                else
                    cr = r;
            }
            if(cr > i)
                res += 1ll * (l - cl) * (cr - i);
            // cerr << 1ll * (l - cl) * (cr - i) << " ";
        }
        if(r != n + 1) {
            int cl = l, cr = n + 1;
            if(ub(edges[r].begin(), edges[r].end(), r) != edges[r].end())
                cr = *ub(edges[r].begin(), edges[r].end(), r);
            if(ub(edges[i].begin(), edges[i].end(), r) != edges[i].end())
                cr = min(cr, *ub(edges[i].begin(), edges[i].end(), r));
            if(lb(edges[r].begin(), edges[r].end(), r) != edges[r].begin())
                cl = max(cl, *--lb(edges[r].begin(), edges[r].end(), r));
            if(cl == i) {
                if(lb(edges[r].begin(), edges[r].end(), i) != edges[r].begin())
                    cl = max(l, *--lb(edges[r].begin(), edges[r].end(), i));
                else
                    cl = l;
            }
            if(cl < i) 
                res += 1ll * (cr - r) * (i - cl);
            // cerr << 1ll * (cr - r) * (i - cl) << endl;
            // cerr << "VALS " << i << " " << r << " " << cl << " " << cr << endl;
        }
    }
    cout << res << endl;
    return 0;
}