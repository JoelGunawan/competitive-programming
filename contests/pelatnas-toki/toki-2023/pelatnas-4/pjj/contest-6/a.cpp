#include <bits/stdc++.h>
#define mp make_pair
#define fi first
#define endl "\n"
#define se second
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
const int lim = 505;
vector<pair<int, int>> edges[lim];
int alt[lim];
bool vis[lim];
int main() {
    int v, e, s, t;
    scanf("%d%d%d%d", &v, &e, &s, &t);
    for(int i = 1; i <= e; ++i) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        edges[a].push_back({b, c});
        edges[b].push_back({a, c});
    }
    // kita coba di tiap node, shortest path dr T ke nd dan shortest path dr S ke nd
    int sdist[v + 1], tdist[v + 1];
    memset(sdist, -1, sizeof(sdist));
    memset(tdist, -1, sizeof(tdist));
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(mp(0, s));
    memset(vis, 0, sizeof(vis));
    while(pq.size()) {
        int dist = pq.top().fi, nd = pq.top().se;
        pq.pop();
        if(vis[nd])
            continue;
        vis[nd] = 1;
        sdist[nd] = dist;
        for(auto i : edges[nd]) {
            if(!vis[i.fi])
                pq.push(mp(dist + i.se, i.fi));
        }
    }
    // yg t harus simpen backtrack supaya tau dimana edge previousnya
    // nanti tiap node dijkstra ke t tanpa menggunakan closest edge 
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> bt;
    memset(vis, 0, sizeof(vis));
    bt.push(mp(0, mp(t, -1)));
    int nx[v + 1];
    memset(nx, -1, sizeof(nx));
    int tcnt[v + 1];
    memset(tcnt, 0, sizeof(tcnt));
    while(bt.size()) {
        int dist = bt.top().fi, nd = bt.top().se.fi, pre = bt.top().se.se;
        bt.pop();
        if(tdist[nd] == dist)
            ++tcnt[nd];
        if(vis[nd])
            continue;
        vis[nd] = 1;
        nx[nd] = pre;
        tdist[nd] = dist;
        tcnt[nd] = 1;
        //cout << nd << " " << tdist[nd] << endl;
        for(auto i : edges[nd]) {
            if(!vis[i.fi])
                bt.push(mp(dist + i.se, mp(i.fi, nd)));
        }
    }
    memset(alt, -1, sizeof(alt));
    alt[t] = 0;
    for(int i = 1; i <= v; ++i) {   
        if(tcnt[i] > 1) {
            alt[i] = tdist[i];
        }
        else if(i != t && sdist[i] != -1 && tdist[i] != -1 && nx[i] != -1) {
            //cout << "FIND ALT " << i << endl;
            pair<int, int> disallow = mp(min(i, nx[i]), max(i, nx[i]));
            int dist[v + 1];
            fill(dist, dist + v + 1, 1e9);
            dist[i] = 0;
            pair<int, int> mn;
            bool done[v + 1];
            memset(done, 0, sizeof(done));
            for(int it = 1; it <= v; ++it) {
                mn = mp((int)1e9, (int)1e9);
                for(int j = 1; j <= v; ++j) {
                    if(!done[j])
                        mn = min(mn, mp(dist[j], j));
                }
                if(mn.fi == 1e9)
                    break;
                if(mn.se == t) {
                    alt[i] = mn.fi;
                    break;
                }
                done[mn.se] = 1;
                for(auto j : edges[mn.se]) {
                    // transition to every other node
                    if(!done[j.fi] && mp(min(mn.se, j.fi), max(mn.se, j.fi)) != disallow) {
                        dist[j.fi] = min(dist[j.fi], mn.fi + j.se);
                    }
                }
            }
        }
    }
    //for(int i = 1; i <= v; ++i)
    //    cout << alt[i] << " ";
    //cout << endl;
    int l = 1, r = 5e6, ans = -1;
    int dist[v + 1];
    while(l <= r) {
        int mid = (l + r) / 2;
        // dfs with upper bound set to mid for alternate value
        // dfs dr S
        fill(dist, dist + v + 1, 1e9);
        memset(vis, 0, sizeof(vis));
        bool can = 0;
        dist[s] = 0;
        for(int it = 1; it <= v; ++it) {
            pair<int, int> mn = mp((int)1e9, (int)1e9);
            for(int i = 1; i <= v; ++i) {
                if(!vis[i]) {
                    mn = min(mn, mp(dist[i], i));
                }
            }
            if(mn.fi > mid)
                break;
            vis[mn.se] = 1;
            if(alt[mn.se] == -1 || dist[mn.se] + alt[mn.se] > mid)
                continue;
            if(mn.se == t) {
                can = 1;
                break;
            }
            for(auto i : edges[mn.se]) {
                if(!vis[i.fi] && dist[mn.se] + i.se <= mid)
                    dist[i.fi] = min(dist[i.fi], dist[mn.se] + i.se);
            }
        }
        if(can) {
            r = mid - 1, ans = mid;
        }
        else
            l = mid + 1;
    }
    //assert(ans != -1);
    printf("%d", ans);
}