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
typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const int lim = 2e5 + 5;
vector<int> edges[lim];
vector<pair<int, int>> mx[lim];
bool vis[lim];
void dfs1(int nd) {
    vis[nd] = 1;
    mx[nd].pb(mp(0, nd));
    for(auto i : edges[nd]) {
        if(!vis[i]) {
            dfs1(i);     
            mx[nd].pb(mp(mx[i][0].fi + 1, mx[i][0].se));
        }
    }
    sort(mx[nd].begin(), mx[nd].end());
    reverse(mx[nd].begin(), mx[nd].end());
    //cout << "DEB " << nd << endl;
    //for(auto i : mx[nd])
    //    cout << i.fi << " " << i.se << endl;
} 
struct triplet {
    int cnt = 0, a = -1, b = -1, c = -1;
    bool operator<(const triplet &rhs) const{
        return cnt < rhs.cnt;
    }
};
triplet ans;
void dfs2(int nd, pair<int, int> par) {
    vis[nd] = 1;
    if(par.se != 0) {
        // get ans
        if(mx[nd].size() > 1) {
            triplet e;
            e.cnt = mx[nd][0].fi + mx[nd][1].fi + par.fi;
            e.a = mx[nd][0].se;
            e.b = mx[nd][1].se;
            e.c = par.se;
            if(mx[nd].size() == 2) {
                ans = max(ans, e);
                //cout << "NORM " << nd << " " << e.cnt << " " << e.a << " " << e.b << " " << e.c << endl;
            }
            else {
                triplet f;
                f.cnt = mx[nd][0].fi + mx[nd][1].fi + mx[nd][2].fi;
                f.a = mx[nd][0].se;
                f.b = mx[nd][1].se;
                f.c = mx[nd][2].se;
                ans = max(ans, max(e, f));
                //cout << "SPEC " << nd << " " << max(e.cnt, f.cnt) << endl;
                //cout << e.cnt << " " << e.a << " " << e.b << " " << e.c << endl;
                //cout << f.cnt << " " << f.a << " " << f.b << " " << f.c << endl;
            }
        }
    }
    else {
        if(mx[nd].size() > 2) {
            triplet f;
            f.cnt = mx[nd][0].fi + mx[nd][1].fi + mx[nd][2].fi;
            f.a = mx[nd][0].se;
            f.b = mx[nd][1].se;
            f.c = mx[nd][2].se;
            ans = max(ans, f);
        }
    }
    for(auto i : edges[nd]) {
        if(!vis[i]) {
            pair<int, int> tmp = {0, 0};
            if(par.se != 0)
                tmp = mp(par.fi + 1, par.se);
            if(mx[i][0].se == mx[nd][0].se) {
                tmp = max(tmp, mp(mx[nd][1].fi + 1, mx[nd][1].se));
            }
            else
                tmp = max(tmp, mp(mx[nd][0].fi + 1, mx[nd][0].se));
            dfs2(i, tmp);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n;
    cin >> n;
    // buat dp node dimana kita simpan longest path to parent, longest path to each child
    // nanti 
    for(int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        edges[u].pb(v);
        edges[v].pb(u);
    }
    dfs1(1);
    memset(vis, 0, sizeof(vis));
    dfs2(1, mp(0, 0));
    cout << ans.cnt << endl << ans.a << " " << ans.b << " " << ans.c << endl;
    return 0;
}