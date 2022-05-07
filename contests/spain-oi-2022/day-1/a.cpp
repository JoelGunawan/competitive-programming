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
vector<int> edges[5];
bool vis[5];
int dist[5][5];
void tc() {
    int n, m;
    cin >> n >> m;
    int a[m];
    for(int i = 0; i < m; ++i)
        cin >> a[i];
    vector<pair<int, int>> e;
    for(int i = 0; i < n; ++i) {
        for(int j = i + 1; j < n; ++j)
            e.pb(mp(i, j));
    }
    for(int i = 0; i < 1 << e.size(); ++i) {
        memset(dist, -1, sizeof(dist));
        memset(vis, 0, sizeof(vis));
        for(int j = 0; j < n; ++j) {
            edges[j].clear();  
        }
        for(int j = 0; j < n; ++j) {
            if((1 << j) & i)
                edges[e[j].fi].pb(e[j].se), edges[e[j].se].pb(e[j].fi);
        }
        // try to simulate
        for(int j = 0; j < n; ++j) {
            memset(vis, 0, sizeof(vis));
            queue<pair<int, int>> q;
            q.push(mp(j, 0));
            while(q.size() > 0) {
                int nd = q.front().fi, d = q.front().se;
                q.pop();
                if(vis[nd])
                    continue;
                dist[j][nd] = d;
                vis[nd] = 1;
                for(auto i : edges[nd]) {
                    if(!vis[i])
                        q.push(mp(i, d + 1));
                }
            }
        }
        bool ans = 1;
        for(int j = 0; j < n; ++j)
            ans &= vis[j];
        //cout << int(ans) << endl;
        for(int j = 0; j < n; ++j) {
            // simulate mulai dari j
            bool exists[n];
            memset(exists, 0, sizeof(exists));
            exists[j] = 1;
            for(int k = 0; k < m; ++k) {
                vector<int> cur;
                for(int l = 0; l < n; ++l)
                    if(exists[l])
                        cur.pb(l);
                for(auto i : cur) {
                    for(int l = 0; l < n; ++l) {
                        if(dist[i][l] == a[k])
                            exists[l] = 1;
                    }
                }
            }
            bool cool = 1;
            for(int j = 0; j < n; ++j) {
                cool &= exists[j];
            }
            if(cool) {
                ans = 0;
            }
        }
        if(ans) {
            cout << "NO" << endl;
            vector<pair<int, int>> ans;
            for(int j = 0; j < n; ++j) {
                if((1 << j) & i)
                    ans.pb(e[j]);
            }
            cout << ans.size() << endl;
            for(auto i : ans)
                cout << i.fi << " " << i.se << endl;
            return;
        }
    }
    cout << "SI" << endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--)
        tc();
    // maintain count how many of each distance
    // kita cek untuk tiap transisi distance
    // bermasalah -> cross transisi
    return 0;
}