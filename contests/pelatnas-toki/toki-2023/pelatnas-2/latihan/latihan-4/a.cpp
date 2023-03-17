// header file
#include <bits/stdc++.h>
// macros
#pragma GCC optimize("Ofast")
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
const int lim = 1e5 + 5;
vector<int> pr[lim];
pair<int, int> cur[316 * lim + 1], res[(int)316 + 5 * lim + 1];
bool vis[lim];
int dist[lim], input[lim];
vector<pair<int, int>> p[lim];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    // coba kita buat multiset
    // nanti model kita itu bakal sparse, dia propagate ke atas cuma kalo ke delete
    // kalo ke delete, kita coba cari maximum keduanya
    // nanti kyk semacam di propagate, karena kita handle query by ascending T
    // coba buat Q = 1 dlu
    int n, m, q;
    cin >> n >> m >> q;
    for(int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        pr[v].pb(u);
    }
    // cek pending itu dari node mana aja, nanti kalo pendingnya kepake, kita refresh pendingnya
    // di refresh pendingnya -> cari second max
    // O(N)? O(log)?
    // kyknya O(N)
    // PAKAI TOPOSORTTTT !!!!!
    // Q = 1 -> bfs balik
    // cari longest path dr x ke y in O(log) time
    // cari yang connected
    // cari yang in degree 0
    // cari yang paling jauh
    // kalo in degree 0 gada, hapus biar dapet yg baru
    // maintain binlift, terus kyk cari klo node skrg collide, cari yg 1 di bawahnya, kalo gada berarti cari yg 2 di bawahnya
    // dfs from 0, sort edges by distance from t
    int blk = sqrt(n);
    for(int i = 1; i <= n; ++i) {
        // cek every previous, terus masukking yang maks berapa aja
        // sort every position, put into set of pending pairs
        int cur_sz = 1, res_sz = 0;
        cur[0] = mp(-1, i);
        for(auto j : pr[i]) {
            res_sz = 0;
            int idx1 = 0, idx2 = 0;
            while(idx1 < cur_sz || idx2 < p[j].size()) {
                if(idx2 == p[j].size() || (idx1 < cur_sz && cur[idx1] > p[j][idx2]))
                    res[res_sz++] = cur[idx1++];
                else
                    res[res_sz++] = p[j][idx2++];
            }   
            for(int k = 0; k < res_sz; ++k)
                cur[k] = res[k];
            cur_sz = res_sz;
        }
        for(int j = 0; j < cur_sz; ++j) {
            if(p[i].size() == blk)
                break;
            else {
                if(!vis[cur[j].se]) {
                    vis[cur[j].se] = 1;
                    p[i].pb(mp(cur[j].fi + 1, cur[j].se));
                }
            }
        }
        for(auto j : p[i])
            vis[j.se] = 0;
    }
    
    for(int i = 1; i <= q; ++i) {
        int t, y;
        cin >> t >> y;
        for(int j = 0; j < y; ++j)
            cin >> input[j], vis[input[j]] = 1;
        int cur_idx = 0;
        if(y < blk) {
            //cout << t << endl;
            //for(auto j : p[t])
            //    cout << j.fi << " " << j.se << endl;
            int res = -1;
            for(auto j : p[t]) {
                if(cur_idx == y || !vis[j.se])
                    res = max(res, j.fi);
                //cout << j.fi << " " << j.se << endl;
            }
            cout << res << endl;
        }
        else {
            // naive
            memset(dist, -1, sizeof(dist));
            dist[t] = 0;
            int res = -1;
            cur_idx = y - 1;
            for(int i = t; i >= 1; --i) {
                if(dist[i] == -1)
                    continue;
                for(auto j : pr[i]) {
                    dist[j] = max(dist[j], dist[i] + 1);
                }
                if(cur_idx == -1 || !vis[i])
                    res = max(res, dist[i]);
            }
            cout << res << endl;
            //mxdist.ins(mp(dist[1], 1));
            
        }
        for(int j = 0; j < y; ++j)
            vis[input[j]] = 0;
    }
    return 0;
}