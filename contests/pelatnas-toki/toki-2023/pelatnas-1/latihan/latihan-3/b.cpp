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
struct triangle {
    int l, r;
    ll cross = 0;
};
ll cp(pair<ll, ll> a, pair<ll, ll> b) {
    return a.fi * b.se - a.se * b.fi;
}
class Compare {
    public:
        bool operator() (pair<ll, triangle> a, pair<ll, triangle> b) {
            return a.fi > b.fi;
        }
};
map<pair<int, int>, bool> vis;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n, u;
    cin >> n >> u;
    priority_queue<pair<ll, triangle>, vector<pair<ll, triangle>>, Compare> pq;
    pair<int, int> a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i].fi >> a[i].se;
    // masuk ke pq
    for(int i = 0; i < n; ++i) {
        triangle tmp;
        tmp.l = i, tmp.r = (i + 2) % n;
        ll cur = 0;
        for(int j = 0; j < 3; ++j) {
            cur += cp(a[(i + j) % n], a[(i + ((j + 1) % 3)) % n]);
        }
        tmp.cross = cur;
        pq.push(mp(abs(cur), tmp));
    }
    vector<ll> ans;
    while(ans.size() < u && pq.size()) {
        triangle tri = pq.top().se; ll area = pq.top().fi;
        pq.pop();
        // /cout << tri.l << " " << tri.r << " " << area << endl;
        if(vis[mp(tri.l, tri.r)])
            continue;
        vis[mp(tri.l, tri.r)] = 1;
        ans.pb(area);
        // cek neighbouring
        int newl = (tri.l - 1 + n) % n;
        int newr = (tri.r + 1) % n;
        if(!vis[mp(tri.l, newr)]) {
            // right tambah 1
            triangle cur = tri;
            cur.cross -= cp(a[cur.r], a[cur.l]);
            cur.cross += cp(a[cur.r], a[newr]);
            cur.cross += cp(a[newr], a[cur.l]);
            cur.r = newr;
            pq.push(mp(abs(cur.cross), cur));
        }
        if(!vis[mp(newl, tri.r)]) {
            // left kurang 1
            triangle cur = tri;
            cur.cross -= cp(a[cur.r], a[cur.l]);
            cur.cross += cp(a[newl], a[cur.l]);
            cur.cross += cp(a[cur.r], a[newl]);
            cur.l = newl;
            pq.push(mp(abs(cur.cross), cur));
        }
    }
    cout << ans.back() << endl;
    return 0;
}