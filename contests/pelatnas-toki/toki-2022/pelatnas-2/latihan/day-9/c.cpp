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
struct edge {
    int dest = -1;
    vector<pair<pair<int, int>, int>> t = vector<pair<pair<int, int>, int>>(0);
};
vector<edge> edges[505];
int min_dist[505][245];
bool vis[505][245];
int main() {
    int n, m, t, g;
    cin >> n >> m >> t >> g;
    for(int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        edge tmp, tmp2;
        tmp.dest = v, tmp2.dest = u;
        int ta, tb = -1, c;
        while(true) {
            cin >> ta >> tb >> c;
            tmp.t.pb(mp(mp(ta, tb), c)), tmp2.t.pb(mp(mp(ta, tb), c));
            if(tb == t - 1)
                break;
        }
        if(u != v) {
            edges[u].pb(tmp);
            edges[v].pb(tmp2);
        }
    }
    memset(vis, 0, sizeof(vis));
    for(int i = 0; i < 505; ++i)
        for(int j = 0; j < 245; ++j)
            min_dist[i][j] = 2e9;
    set<pair<int, pair<int, int>>> pq;
    pq.ins(mp((t / 2), mp(0, g)));
    while(pq.size() > 0) {
        int time = (*pq.begin()).fi, nd = (*pq.begin()).se.fi, energy = (*pq.begin()).se.se;
        pq.erase(pq.begin());
        assert(nd >= 0 && nd < n);
        assert(time >= 0);
        //cout << nd << " " << energy << " " << time << endl;
        if(vis[nd][energy])
            continue;
        vis[nd][energy] = 1;
        min_dist[nd][energy] = time;
        pair<int, int> cur_time = mp(time / t, time % t);
        for(auto e : edges[nd]) {
            for(auto segment : e.t) {
                int l = cur_time.fi, r = l + 500, ans = r;
                if(segment.fi.se < cur_time.se)
                    ++l;
                while(l <= r) {
                    int mid = (l + r) / 2;
                    if(((mid * t + segment.fi.se - time) / 2) + energy >= segment.se) {
                        ans = mid, r = mid - 1;
                    }
                    else
                        l = mid + 1;
                }
                int day = ans;
                l = segment.fi.fi, r = segment.fi.se, ans = r;
                while(l <= r) {
                    int mid = (l + r) / 2;
                    if(((day * t + mid - time) / 2) + energy >= segment.se) {
                        ans = mid, r = mid - 1;
                    }
                    else {
                        l = mid + 1;
                    }
                }
                if(day == cur_time.fi)
                    ans = max(ans, cur_time.se);
                int remaining = ((day * t + ans - time) / 2) + energy - segment.se;
                assert(remaining >= 0);
                remaining = min(remaining, g);
                if(!vis[e.dest][remaining])
                    pq.ins(mp(day * t + ans + segment.se, mp(e.dest, remaining)));
                if(ans + 1 <= segment.fi.se) {
                    remaining = ((day * t + ans + 1 - time) / 2) + energy - segment.se;
                    remaining = min(remaining, g);
                    if(!vis[e.dest][remaining])
                        pq.ins(mp(day * t + ans + 1 + segment.se, mp(e.dest, remaining)));
                }
                remaining = ((day * t + t + segment.fi.se - time) / 2) + energy - segment.se;
                remaining = min(remaining, g);
                if(!vis[e.dest][remaining])
                    pq.ins(mp(day * t + t + segment.fi.se + segment.se, mp(e.dest, remaining)));
                if(segment.fi.se != segment.fi.fi) {
                    remaining = ((day * t + t + 1 + segment.fi.se - time) / 2) + energy - segment.se;
                    remaining = min(remaining, g);
                    if(!vis[e.dest][remaining])
                        pq.ins(mp(day * t + t + 1 + segment.fi.se + segment.se, mp(e.dest, remaining)));
                }
                /*
                int tmp = time;
                while((tmp - time) / 2 + energy < segment.se || (tmp % t < segment.fi.fi || tmp % t > segment.fi.se)) {
                    ++tmp;
                }
                int remaining = (tmp - time) / 2 + energy - segment.se;
                // tmp itu waktu berangkat
                if(!vis[e.dest][remaining])
                    pq.ins(mp(tmp + segment.se, mp(e.dest, remaining)));
                */
            }
        }
    }
    int res = 2e9;
    for(int i = 0; i <= g; ++i)
        res = min(res, min_dist[n - 1][i]);
    assert(res != 2e9);
    cout << res - t / 2 << endl;
    return 0;
}