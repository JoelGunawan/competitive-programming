#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
bool comp(pair<long long, int> a, pair<long long, int> b) {
    return b < a;
}
bool comp2(pair<long long, pair<int, int>> a, pair<long long, pair<int, int>> b) {
    return b < a;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, s, t, u, v;
    cin >> n >> m >> s >> t >> u >> v;
    // buat dijkstra 2 state
    // 1 state n 1 state 3 options
    // option 1 -> belum pakai s->t
    // option 2 -> lagi pakai s->t closing to s
    // option 3 -> lagi pakai s-> t closing ke t
    // option 4 -> sudah pakai s->t
    long long dist[n + 1][4];
    memset(dist, -1, sizeof(dist));
    vector<pair<int, int>> edges[n + 1];
    for(int i = 1; i <= m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        edges[a].push_back({b, c});
        edges[b].push_back({a, c});
    }
    // dijkstra mulai dari u 0 ke v 
    // terserah v pakai yg mana
    long long sdist[n + 1], tdist[n + 1];
    memset(sdist, -1, sizeof(sdist));
    memset(tdist, -1, sizeof(tdist));
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, function<bool(pair<long long, int>, pair<long long, int>)>> pq(comp);
    pq.push({0, s});
    while(pq.size()) {
        long long d = pq.top().first; int nd = pq.top().second;
        pq.pop();
        if(sdist[nd] != -1)
            continue;
        //cout << nd << " " << d << endl;
        sdist[nd] = d;
        for(auto i : edges[nd]) {
            if(sdist[i.first] == -1) {
                pq.push({d + i.second, i.first});
            }
        }
    }
    pq.push({0, t});
    while(pq.size()) {
        long long d = pq.top().first; int nd = pq.top().second;
        pq.pop();
        if(tdist[nd] != -1)
            continue;
        //cout << nd << " " << d << endl;
        tdist[nd] = d;
        for(auto i : edges[nd]) {
            if(tdist[i.first] == -1) {
                pq.push({d + i.second, i.first});
            }
        }
    }
    long long act = sdist[t];
    priority_queue<pair<long long, pair<int, int>>, vector<pair<long long, pair<int, int>>>, function<bool(pair<long long, pair<int, int>>, pair<long long, pair<int ,int>>)>> dijkstra(comp2);
    dijkstra.push(make_pair(0, make_pair(u, 0)));
    while(dijkstra.size()) {
        long long d = dijkstra.top().first; int nd = dijkstra.top().second.first, opt = dijkstra.top().second.second;
        dijkstra.pop();
        if(dist[nd][opt] != -1) 
            continue;
        dist[nd][opt] = d;
        //cout << nd << " " << opt << " " << d << endl;
        if(opt == 0) {
            // jadinya bisa try to use opt
            // atau bs continue to use 0
            for(auto i : edges[nd]) {
                if(dist[i.first][0] == -1) {
                    dijkstra.push(make_pair(d + i.second, make_pair(i.first, 0)));
                }
            }
            for(auto i : edges[nd]) {
                if(dist[i.first][1] == -1 && tdist[nd] + sdist[i.first] + i.second == act) {
                    dijkstra.push(make_pair(d,  make_pair(i.first, 1)));
                }
            }
            for(auto i : edges[nd]) {
                if(dist[i.first][2] == -1 && tdist[i.first] + sdist[nd] + i.second == act) {
                    dijkstra.push(make_pair(d, make_pair(i.first, 2)));
                }
            }
        }
        else if(opt == 3) {
            // jadi cmn coba edge biasa aja
            for(auto i : edges[nd]) {
                if(dist[i.first][3] == -1) {
                    dijkstra.push(make_pair(d + i.second, make_pair(i.first, 3)));
                }
            }
        }
        else if(opt == 1) {
            // coba 1 to 1
            // sama coba 1 to 3
            for(auto i : edges[nd]) {
                if(dist[i.first][1] == -1 && tdist[nd] + sdist[i.first] + i.second == act) {
                    dijkstra.push(make_pair(d,  make_pair(i.first, 1)));
                }
            }
            for(auto i : edges[nd]) {
                if(dist[i.first][3] == -1) {
                    dijkstra.push(make_pair(d + i.second, make_pair(i.first, 3)));
                }
            }
        }
        else if(opt == 2) {
            for(auto i : edges[nd]) {
                if(dist[i.first][2] == -1 && tdist[i.first] + sdist[nd] + i.second == act) {
                    dijkstra.push(make_pair(d, make_pair(i.first, 2)));
                }
            }
            for(auto i : edges[nd]) {
                if(dist[i.first][3] == -1) {
                    dijkstra.push(make_pair(d + i.second, make_pair(i.first, 3)));
                }
            }
        }
    }
    long long tmp = 1e18;
    for(int i = 0; i < 4; ++i) {
        if(dist[v][i] != -1)
            tmp = min(tmp, dist[v][i]);
    }
    cout << tmp << endl;
}