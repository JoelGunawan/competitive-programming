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
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    // coordinate compress atau pakai map lgsg
    ll a, b;
    map<ll, vector<ll>> edges, inv;
    map<ll, int> indegree;
    while((cin >> a >> b) && a != -1) {
        // buat edge dr a ke b
        edges[a].pb(b);
        inv[b].pb(a);
        ++indegree[b];
    }
    while((cin >> a >> b) && a != -1) {
        // cari jalan dr a ke b
        if(a == b) {
            cout << a << endl;
            continue;
        }
        else if(edges[a].size() == 0) {
            cout << "Starting Node tidak mempunyai Edge" << endl;
            continue;
        }
        else if(inv[b].size() == 0) {
            cout << "Destination Node tidak mungkin diraih" << endl;
            continue;
        }
        // cari shortest path dr a dgn edges dan dr b dengan inv
        map<ll, int> src;
        map<ll, bool> vis;
        queue<pair<int, ll>> q;
        q.push(mp(0, a));
        while(q.size()) {
            int dist = q.front().fi; ll nd = q.front().se;
            q.pop();
            if(vis[nd])
                continue;
            vis[nd] = 1;
            src[nd] = dist;
            //cout << "SOURCE " << nd << " " << dist << endl;
            for(auto i : edges[nd]) {
                if(!vis[i]) {
                    q.push(mp(dist + 1, i));
                }
            }
        }
        if(!vis[b]) {
            cout << "Path tidak ditemukan" << endl;
            continue;
        }
        vis.clear();
        q.push(mp(0, b));
        map<ll, int> dest;
        while(q.size()) {
            int dist = q.front().fi; ll nd = q.front().se;
            q.pop();
            if(vis[nd])
                continue;
            vis[nd] = 1;
            dest[nd] = dist;
            //cout << "DEST " << nd << " " << dist << endl;
            for(auto i : inv[nd]) {
                if(!vis[i]) {
                    q.push(mp(dist + 1, i));
                }
            }
        }
        vector<ll> res;
        ll cur = a;
        while(res.empty() || res.back() != b) {
            //cout << cur << endl;
            ll mx;
            if(res.size() & 1) {
                // highest
                mx = LLONG_MIN;
            }
            else {
                // lowest
                mx = LLONG_MAX;
            }
            for(auto i : edges[cur]) {
                //cout << src[cur] << " " << dest[i] << endl;
                if(src[cur] + dest[i] + 1 == src[b]) {
                    if(res.size() & 1)
                        mx = max(mx, i);
                    else
                        mx = min(mx, i);
                }
            }
            res.pb(cur);
            cur = mx;
        }
        for(int i = 0; i < res.size(); ++i) {
            cout << res[i] << (i != res.size() - 1 ? " -> " : "\n");
        }
    }
    return 0;
}