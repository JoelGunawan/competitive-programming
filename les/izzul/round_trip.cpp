//CSES - Round Trip
#include <bits/stdc++.h>
#include <chrono>
using namespace std;
#define ll long long
#define str string
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define lb lower_bound
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
const int lim = 2e5+10;
ll n, m; ll id;
vector<ll>edges[lim];
bool vis[lim];
vector<ll>path;

bool bfs(ll start, ll finish, ll n, ll pred[], ll dist[]) 
{
    for (int i = 0; i <= n; i++) {
        vis[i] = false;
        dist[i] = INT_MAX;
        pred[i] = -1;
    }
 
    list<ll> q;
    dist[start] = 0;
    vis[start] = 1;
    //vis[start] = true;
    q.pb(start);
    while (!q.empty()) {
        ll u = q.front();
        q.pop_front();
        cout << u << endl;
        for (ll i = 0; i < edges[u].size(); i++) {
            if (vis[edges[u][i]] == false) {
                vis[edges[u][i]] = true;
                dist[edges[u][i]] = dist[u] + 1; 
                pred[edges[u][i]] = u;
                //cout << "OUTPUT " << edges[u][i] << " " << u << endl;
                q.pb(edges[u][i]);
                // found the target
                if (edges[u][i] == finish){
                    for(int i = 1; i <= n; ++i) {
                        //cout << pred[i] << " ";
                        cout << endl;
                    }             
                    ll curr = finish;
                    while (curr != -1) {
                        //cout << curr << endl;
                        path.pb(curr);
                        curr = pred[curr];
                    }
                    reverse(path.begin(), path.end()); // Reverse the path to get the correct order
                    id++;
                    return true;
                }    
            }
        }
    }
    return false;
}


signed main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(ll i = 0; i < m; i++){
        ll u, v;
        cin >> u >> v;
        edges[u].pb(v);
        edges[v].pb(u);
    }
    ll pred[n+1], dist[n+1];
    ll ans = 0;
    for(ll i = 1; i <= n; i++){
        if(bfs(i,i,n,pred,dist)){
            cout << dist[i] << endl;
            for(auto nd : path)
                cout << nd << " ";
            cout << endl;
            break;
        }
        path.clear();
    }  
    if(id == 0)
        cout << "IMPOSSIBLE" << endl;   
}