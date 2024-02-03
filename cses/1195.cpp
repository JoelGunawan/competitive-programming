#include <bits/stdc++.h>

#define pb push_back
#define vt vector
#define endl "\n"
#define ll long long
#define mp make_pair
#define fi first
#define se second
using namespace std;

const int MAXN = 1e5 + 5;
const ll INF = 1e18;
int n, m, a, b, w;
ll dist[MAXN], distinv[MAXN], ans = INF;
vt<tuple<int, int, int>> edges;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 1; i < MAXN; ++i) {
        dist[i]=INF; 
		distinv[i]=INF;
    }

    cin >> n >> m;
    vt<pair<int, int>> adj[n + 5];
    vt<pair<int, int>> adjinv[n + 5];

    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> w;
        edges.pb({a, b, w});
        adj[a].pb(mp(b, w));
        adjinv[b].pb(mp(a, w));
    }

    priority_queue<pair<ll, int>> pq, pqinv;

    pq.push(mp(0, 1));
    pqinv.push(mp(0, n));
    
    dist[1] = 0, distinv[n] = 0;

    while (!pq.empty() || !pqinv.empty()) {
        if (!pq.empty()) {
            int a = pq.top().se;
            pq.pop();
            for (auto [b, w] : adj[a]) {
                if (dist[a] + w < dist[b]) {
                    dist[b] = dist[a] + w;
                    pq.push(mp(-dist[b], b));
                }
            }
        }

        if (!pqinv.empty()) {
            int a = pqinv.top().se;
            pqinv.pop();
            for (auto [b, w] : adjinv[a]) {
                if (distinv[a] + w < distinv[b]) {
                    distinv[b] = distinv[a] + w;
                    pqinv.push(mp(-distinv[b], b));
                }
            }
        }
    }

    for (auto [a, b, w] : edges) {
    	//cout << a << " " << b << " " << dist[a] << " " << distinv[b] << endl;
        ans=min(ans, dist[a]+distinv[b]+w / 2);
    }
    cout << ans << endl;
}
