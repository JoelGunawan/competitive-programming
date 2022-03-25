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
bool adj[2005][2005], vis[4005], active[4005];
vector<int> edges[4005];
int t = 0, disc[4005], low[4005], component_number[4005], component_cnt = 0;
stack<int> s;
void dfs(int nd) {
    //cout << nd << endl;
    vis[nd] = 1;
    low[nd] = disc[nd] = t++;
    active[nd] = 1;
    s.push(nd);
    for(auto i : edges[nd]) {
        if(!vis[i]) {
            dfs(i);
            low[nd] = min(low[nd], low[i]);
        }
        else if(active[i]) {
            low[nd] = min(low[nd], disc[i]);
        }
    }
    if(low[nd] == disc[nd]) {
        // pop from stack while != nd
        while(s.size() > 0 && s.top() != nd) {
            component_number[s.top()] = component_cnt;
            active[s.top()] = 0;
            s.pop();
        }
        s.pop();
        active[nd] = 0;
        component_number[nd] = component_cnt++;
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    // case node pasti merupakan color 3 (tidak terhubung dengan 1 dan 2)
    // x = 1 -> (!x or !x)
    // 2 node u, v tidak bisa warna 1/2 sekaligus (!u or !v)
    // 2 node u, v tidak bisa warna 3 sekaligus (u or v)
    // 0 -> warna 3
    // 1 -> warna 1/2
    for(int i = 3; i <= n; ++i) {
        // harus warna 3
        if(!(adj[i][1] || adj[i][2]))
            edges[i].pb(i + 2000);
        for(int j = i + 1; j <= n; ++j) {
            if(!adj[i][j]) {
                // kalo ga ada edge berarti gabisa warna 3 sekaligus
                edges[i + 2000].pb(j);
                edges[j + 2000].pb(i);
                if((adj[i][1] && adj[j][1]) || (adj[i][2] && adj[j][2])) {
                    // kalo gabisa warna 1/2 sekaligus
                    // karena ga ada edge antara u dan v
                    // DAN u dan v sama" merupakan neighbor 1 atau u dan v merupakan neighbor 2
                    edges[i].pb(j + 2000);
                    edges[j].pb(i + 2000);
                }
            }
        }
    }
    for(int i = 3; i <= n; ++i)
        if(!vis[i]) 
            dfs(i);
    for(int i = 2003; i <= 2000 + n; ++i)
        if(!vis[i])
            dfs(i);
    /*
    for(int i = 3; i <= n; ++i) {
        for(auto j : edges[i])
            cout << j << " ";
        cout << endl;
    }
    for(int i = 3; i <= n; ++i) {
        for(auto j : edges[i + 2000])
            cout << j << " ";
        cout << endl;
    }
    */
    for(int i = 3; i <= n; ++i) {
        //cout << component_number[i] << " " << component_number[i + 2000] << endl;
        if(component_number[i] == component_number[i + 2000]) {
            cout << "impossible" << endl;
            return 0;
        }
    }
    vector<int> one, two;
    for(int i = 3; i <= n; ++i) {
        if(component_number[i] < component_number[i + 2000]) {
            if(adj[i][1])
                one.pb(i);
            else
                two.pb(i);
        }
    }
    cout << "1 ";
    for(auto i : one)
        cout << i << " ";
    cout << endl;
    cout << "2 ";
    for(auto i : two)
        cout << i << " ";
    cout << endl;
    return 0;
}