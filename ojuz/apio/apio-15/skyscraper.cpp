#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define mp make_pair
#define fi first
#define lb lower_bound
#define se second
#define endl "\n"
using namespace std;
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    int blk = 50;
    vector<int> weights[n];
    int init = -1, initp = -1, target = -1;
    for(int i = 1; i <= m; ++i) {
        int b, p;
        cin >> b >> p;
        if(i == 1)
            init = b, initp = p;
        else if(i == 2)
            target = b;
        // b -> pos
        // p -> multiple
        weights[b].push_back(p);
    }
    // gaperlu cek semua cukup cek yg ada weights
    // kalo udh proc weight jg gperlu
    // kalo <= blk maka memo tiap pair int modulo dalam vector
    // kalo > blk maka cek manual
    // doge cmn boleh gerak dr ori node (gaboleh meet di tengah)
    // hence cukup dijkstra dengan 1 origin, terus klo intersect lainnya bs langsung dijkstra aja
    // tiap node ada theoretically n^2 dijkstra state yg mgkn?
    // tp yg high modulo itu sparse, jadi bs simpan manual pakai sorted vector/semacamnya
    priority_queue<pair<int, pair<int, pair<int, int>>>, vector<pair<int, pair<int, pair<int, int>>>>, greater<pair<int, pair<int, pair<int, int>>>>> pq;
    // fi -> dist
    // se.fi -> idx
    // se.se.fi -> current p
    // se.se.se -> tanda dr atas/bawah
    // guna -> reduce double counting
    //cout << init << " " << initp << endl;
    pq.push(mp(0, mp(init, mp(initp, -1))));
    int d[n + 1];
    map<int, bool> vis[n];
    memset(d, -1, sizeof(d));
    // cek ada yg bs sampai ke target atau tidak, kalo tidak langsung output false
    // kalo iya, maka ada pembuktian min path tidak sepanjang itu?
    while(pq.size()) {
        int dist = pq.top().fi, idx = pq.top().se.fi, curp = pq.top().se.se.fi, tanda = pq.top().se.se.se;
        pq.pop();
        //cout << dist << " " << idx << " " << curp << endl;
        if(vis[idx][curp])
            continue;
        if(d[idx] == -1)
            d[idx] = dist;
        d[idx] = min(d[idx], dist);
        for(auto i : weights[idx]) {
            if(!vis[idx][i] && i != curp) {
                if(i > blk) {
                    int tmp = idx + i;
                    while(tmp < n && !weights[tmp].size())
                        tmp += i;
                    if(tmp < n && !vis[tmp][i])
                        pq.push(mp(dist + (tmp - idx) / i, mp(tmp, mp(i, 0))));
                    tmp = idx - i;
                    while(tmp >= 0 && !weights[tmp].size())
                        tmp -= i;
                    if(tmp >= 0 && !vis[tmp][i]) 
                        pq.push(mp(dist + (idx - tmp) / i, mp(tmp, mp(i, 1))));
                }
                else {
                    if(idx + i < n && !vis[idx + i][i])
                        pq.push(mp(dist + 1, mp(idx + i, mp(i, 0))));
                    if(idx - i >= 0 && !vis[idx - i][i])
                        pq.push(mp(dist + 1, mp(idx - i, mp(i, 1))));
                }
                vis[idx][i] = 1;
            }
        }
        weights[idx].clear();
        //cout << idx << " " << curp << endl;
        if(!vis[idx][curp]) {
            vis[idx][curp] = 1;
            //cout << dist << " " << idx << " " << curp << endl;
            if(curp > blk) {
                int tmp = idx + curp;
                if(tanda != 1) {
                    while(tmp < n && !weights[tmp].size())
                        tmp += curp;
                    if(tmp < n && !vis[tmp][curp])
                        pq.push(mp(dist + (tmp - idx) / curp, mp(tmp, mp(curp, 0))));
                }
                if(tanda != 0) {
                    tmp = idx - curp;
                    while(tmp >= 0 && !weights[tmp].size())
                        tmp -= curp;
                    if(tmp >= 0 && !vis[tmp][curp]) 
                        pq.push(mp(dist + (idx - tmp) / curp, mp(tmp, mp(curp, 1))));
                }
            }
            else {
                if(idx + curp < n && !vis[idx + curp][curp])
                    pq.push(mp(dist + 1, mp(idx + curp, mp(curp, 0))));
                if(idx - curp >= 0 && !vis[idx - curp][curp])
                    pq.push(mp(dist + 1, mp(idx - curp, mp(curp, 1))));
            }
        }
        if(idx == target)
            break;
    }
    cout << d[target] << endl;
}