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
ll mod = 1e9 + 7;
ll sqr(ll a) {
    a %= mod;
    return (a * a) % mod;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    // find amount of paths terus dikali sama pairingnya
    // dibagi ke beberapa kasus
    // distance even
    // dist/2 harus node yg beda
    // distance odd
    // find count of ways
    // terus nanti kalo udah ketemu count of ways di tiap node
    // susahnya intersect di jalan
    // cari edges dimana dia intersect di jalan
    // dijkstra 2 source, cari dist / 2 nya itu di jalan atau di edgenya
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    vector<pair<int, int>> edges[n + 1];
    for(int i = 1; i <= m; ++i) {
        int u, v, t;
        cin >> u >> v >> t;
        edges[u].pb(mp(v, t));
        edges[v].pb(mp(u, t));
    }
    ll dist1[n + 1], dist2[n + 1];
    ll ways1[n + 1], ways2[n + 1];
    memset(ways1, 0, sizeof(ways1));
    memset(ways2, 0, sizeof(ways2));
    memset(dist1, -1, sizeof(dist1));
    memset(dist2, -1, sizeof(dist2));
    priority_queue<pair<ll, pair<int, int>>, vector<pair<ll, pair<int, int>>>, greater<pair<ll, pair<int, int>>>> pq;
    pq.push(mp(0, mp(x, 0)));
    ways1[0] = 1, ways2[0] = 1;
    while(pq.size()) {
        ll dist = pq.top().fi; int nd = pq.top().se.fi, pr = pq.top().se.se;
        pq.pop();
        if(dist1[nd] != -1) {
            if(dist == dist1[nd])
                ways1[nd] += ways1[pr], ways1[nd] %= mod;
            continue;
        }
        ways1[nd] = ways1[pr];
        dist1[nd] = dist;
        for(auto i : edges[nd]) {
            pq.push(mp(dist + i.se, mp(i.fi, nd)));
        }
    }
    pq.push(mp(0, mp(y, 0))); 
    while(pq.size()) {
        ll dist = pq.top().fi; int nd = pq.top().se.fi, pr = pq.top().se.se;
        pq.pop();
        if(dist2[nd] != -1) {
            if(dist == dist2[nd])
                ways2[nd] += ways2[pr], ways2[nd] %= mod;
            continue;
        }
        ways2[nd] = ways2[pr];
        dist2[nd] = dist;
        for(auto i : edges[nd]) {
            pq.push(mp(dist + i.se, mp(i.fi, nd)));
        }
    }
    // disini done udh ada semua dist
    // no multi edge -> ez mode yay :D
    ll tot = dist1[y];
    ll inval = 0;
    for(int i = 1; i <= n; ++i) {
        // cek tiap neighboring edgenya dia
        //cout << "OUT " << tot << " " << dist1[i] << " " << dist2[i] << endl;
        if(tot % 2 == 0 && dist1[i] == tot / 2 && dist2[i] == tot / 2) {
            // berarti any path that goes through this node is invalid
            //cout << "IN " << i << endl;
            inval += sqr(ways1[i] * ways2[i]);
            inval %= mod;
        }
        else {
            // kasus lain itu berarti di jalan, berarti harus cek tiap edge
            // cek tiap edge
            for(auto j : edges[i]) {
                if(tot & 1) {
                    if(dist1[i] <= tot / 2 && dist2[j.fi] <= tot / 2 && dist1[i] + dist2[j.fi] + j.se == tot) {
                        inval += sqr(ways1[i] * ways2[j.fi]);
                        inval %= mod;
                    }
                }
                else {
                    if(dist1[i] < tot / 2 && dist2[j.fi] < tot / 2 && dist1[i] + dist2[j.fi] + j.se == tot) {
                        inval += sqr(ways1[i] * ways2[j.fi]);
                        inval %= mod;
                    }
                }
            }
        }
    }
    inval = sqr(ways1[y]) - inval;
    inval %= mod;
    inval += mod;
    inval %= mod;
    cout << inval << endl;
    return 0;
}