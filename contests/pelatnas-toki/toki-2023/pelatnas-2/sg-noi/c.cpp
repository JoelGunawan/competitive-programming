#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ll long long
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    // dijkstra by [len][in_a_row]
    // n^2 sol
    int n, m;
    cin >> n >> m;
    // fi -> dist
    // se.fi -> node
    // se.se -> disc
    // obs bagus: semua edge weightnya 1
    // sus...
    // berarti ada properti khusus dmn bs pake bfs
    // introducing 1 new node every increase...
    // can do by using help of src dist and ori dist
    // nanti dari tiap node check merging dr node yang sebelumnya dipake yang mungkin
    // cari src_dist yg minimum dan ori_dist yg minimum dr previous node
    // bisa dapet
    // binser 
    // alien trick on dijkstra?
    // build dari lebih rendah
    // cari jalan ke x dimana x merupakan max height
    // cost ke i + cost ke j
    // buat tc garis lurus
    int h[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> h[i];
    vector<int> edges[n + 1];
    for(int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        edges[a].pb(b);
        edges[b].pb(a);
    }
    ll src_dist[n + 1], ori_dist[n + 1];
    ll res = 1e18;
    // use trick to only do dijkstra once, save previous maximum height as part of the dijkstra
    // then one can only use nodes 
    // bsta maximum height used?
    // or do ternary search?
    // no
    for(int i = 1; i <= n; ++i) {
        // set h[i] as max height
        memset(ori_dist, -1, sizeof(ori_dist));
        memset(src_dist, -1, sizeof(src_dist));
        // multisource?
        // no?
        // start from 0
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
        pq.push(mp(0, 1));
        while(pq.size()) {
            ll dist = pq.top().fi, nd = pq.top().se;
            //cout << nd << " " << dist << endl;
            pq.pop();
            if(src_dist[nd] != -1)
                continue;
            src_dist[nd] = dist;
            for(auto j : edges[nd]) {
                if(src_dist[j] == -1 && h[j] <= h[i]) {
                    pq.push(mp(dist + max(1ll, h[j] - dist), j));
                }
            }
        }     
        pq.push(mp(0, n));
        while(pq.size()) {
            ll dist = pq.top().fi, nd = pq.top().se;
            //cout << nd << " " << dist << endl;
            pq.pop();
            if(ori_dist[nd] != -1)
                continue;
            ori_dist[nd] = dist;
            for(auto j : edges[nd]) {
                if(ori_dist[j] == -1 && h[j] <= h[i]) {
                    pq.push(mp(dist + max(1ll, h[j] - dist), j));
                }
            }
        }
        if(ori_dist[i] != -1 && src_dist[i] != -1)
            res = min(res, ori_dist[i] + src_dist[i]);
    }
    cout << res << endl;
}