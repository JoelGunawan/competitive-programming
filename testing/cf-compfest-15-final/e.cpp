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
    int n;
    cin >> n;
    int a[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    // process all indegree 0, later the remaining will be cycles
    // create edge from i to a[i]
    vector<int> edges[n + 1];
    queue<int> q;
    int in[n + 1];
    memset(in, 0, sizeof(in));
    for(int i = 1; i <= n; ++i)
        edges[i].pb(a[i]);
    vector<int> inv[n + 1];
    for(int i = 1; i <= n; ++i) {
        for(auto j : edges[i])
            inv[j].pb(i), ++in[j];
    }
    for(int i = 1; i <= n; ++i)
        if(inv[i].empty())
            q.push(i);
    bool circled[n + 1];
    memset(circled, 0, sizeof(circled));
    // traverse all indegree 0
    bool vis[n + 1];
    memset(vis, 0, sizeof(vis));
    while(q.size()) {
        int cur = q.front();
        q.pop();
        vis[cur] = 1;
        bool inv_dead = 0;
        for(auto j : inv[cur])
            inv_dead |= !circled[j]; 
        // child ada not circled, sekarang harus circled
        if(inv_dead)
            circled[cur] = 1;
        for(auto i : edges[cur]) {
            --in[i];
            if(!in[i])
                q.push(i);
        }
    }
    // yg belum visited, itu pasti merupakan bagian dr cycle
    vector<int> unvis;
    for(int i = 1; i <= n; ++i) {
        if(!vis[i])
            unvis.pb(i);
    }
    for(auto i : unvis) {
        if(!vis[i]) {
            vector<int> cycle;
            cycle.pb(i);
            while(a[cycle.back()] != i)
                cycle.pb(a[cycle.back()]);
            // mulai dari salah satu yg harus circled
            // klo gada yg harus circled, bebas
            int mc = -1;
            for(auto j : cycle) {
                int inv_dead = 0;
                for(auto k : inv[j])
                    inv_dead += !circled[k];
                if(inv_dead > 1) {
                    mc = j;
                    break;
                }
            }
            vector<int> tmp, tmp2;
            bool found_mc = 0;
            for(auto j : cycle) {
                if(j == mc)
                    found_mc = 1;
                if(found_mc)
                    tmp.pb(j);
                else
                    tmp2.pb(j);
            }
            for(auto j : tmp2)
                tmp.pb(j);
            cycle = tmp;
            //for(auto j : cycle)
            //    cout << j << " ";
            //cout << endl;
            for(auto j : cycle) {
                vis[j] = 1;
                bool inv_dead = 0;
                for(auto k : inv[j])
                    inv_dead |= !circled[k];
                if(inv_dead)
                    circled[j] = 1;
            }
        }
    }
    for(int i = 1; i <= n; ++i) {
        if(circled[i]) {
            bool inv_dead = 0;
            for(auto j : inv[i]) {
                inv_dead |= !circled[j];
            }
            if(!inv_dead) {
                cout << -1 << endl;
                return 0;
            }
        }
    }
    // nanti dfs per cycle, cari apa bisa atau ngga
    // tiap cycle, cek odd/even
    // klo both and even ada required indegree, berarti -1
    // klo cmn salah satu, berarti circle nya di parity itu
    // klo none, berarti any works
    vector<int> nc;
    for(int i = 1; i <= n; ++i) {
        if(!circled[i])
            nc.pb(i);
    }
    cout << nc.size() << endl;
    for(auto i : nc)
        cout << a[i] << " ";
    cout << endl;
    return 0;
}