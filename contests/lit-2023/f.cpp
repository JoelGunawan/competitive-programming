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
struct Edge {
    int req, tgt; double  a, b, c;
    Edge(ll d, ll e, double f, double g, double h) {
        req = d, tgt = e, a = f, b = g, c = h;
    }
};
void tc() {
    // find min cost for coffee of size 1
    ll n, m, v;
    cin >> n >> m >> v;
    string s;
    cin >> s;
    s = " " + s;
    const long double inf = 1e50; 
    long double cost[n + 1];
    for(int i = 1; i <= n; ++i)
        cost[i] = inf;
    for(int i = 1; i <= n; ++i) {
        if(s[i] == '1')
            cost[i] = 1;
    }
    vector<Edge> edges[n + 1];
    for(int i = 1; i <= m; ++i) {
        double a, b, c;
        int x, y, z;
        cin >> a >> x >> b >> y >> c >> z;
        edges[x].pb(Edge(y, z, a, b, c));
        edges[y].pb(Edge(x, z, b, a, c));
    }
    // always reduce
    // therefore just set "1" as base, then use pq to order queries by min cost
    // fi -> cost
    // se -> node
    priority_queue<pair<long double, ll>, vector<pair<long double, ll>>, greater<pair<long double, ll>>> pq; 
    for(int i = 1; i <= n; ++i) {
        for(auto j : edges[i]) {
            if(cost[i] != -1 && cost[j.req] != -1) {
                //cout << i << " " << j.req << " " << j.tgt << endl;
                pq.push(mp((cost[i] * j.a + cost[j.req] * j.b) / j.c, j.tgt));
            }
        }
    }
    cout << fixed << setprecision(15);
    int cnt[n + 1];
    memset(cnt, 0, sizeof(cnt));
    vector<double> vals[n + 1];
    while(pq.size()) {
        double c = pq.top().fi; ll nd = pq.top().se;
        // kalau lebih dri 10^24 jadiin 0
        // masalahnya -> cek hasil perkalian lebih dri 10^24 atau tdk
        //cout << c << " " << nd << endl;
        pq.pop();
        if(c >= cost[nd])
            continue;
        //cout << "PROCESS" << endl;
        cost[nd] = c;
        vals[nd].pb(c);
        ++cnt[nd];
        if(cnt[nd] > 100000) {
            // calculate asymptote using 5k data points
            long double ans = 0;
            for(int i = 1; i < vals[nd].size(); ++i) {
                long double diff = (vals[nd][i] - vals[nd][i - 1]) / vals[nd][i];
                ans = ans + (vals[nd][0] * diff) / (1 - diff) / vals[nd].size();
            }
            cost[nd] = ans;
            continue;
        }
        // kalau cost[nd] > 1e24 -> just set to 0
        for(auto j : edges[nd]) {
            if(cost[j.req] != -1 && (cost[nd] * j.a + cost[j.req] * j.b) / j.c < cost[j.tgt]) {
                pq.push(mp((cost[nd] * j.a + cost[j.req] * j.b) / j.c, j.tgt));
            }
        }
    }
    //for(int i = 1; i <= n; ++i)
    //    cout << cost[i] < < " ";
    //cout << endl;
    //cout << 1e18 / 1e30 << endl;
    if(cost[1] == inf)  
        cout << 0 << endl;
    else if(cost[1] == 0 || 1e18 / cost[1] > inf)
        cout << -1 << endl;
    else
        cout << v / cost[1] << endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) 
        tc();
    return 0;
}