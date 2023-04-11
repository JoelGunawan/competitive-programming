#include "dreaming.h"
#include <bits/stdc++.h>
using namespace std;
const int lim = 1e5 + 5;
bool vis[lim];
int maxd[lim], d[lim], res[lim];
vector<pair<int, int>> edges[lim], child[lim];
void get_subtree(int nd) {
    vis[nd] = 1;
    maxd[nd] = d[nd];
    for(auto i : edges[nd]) {
        if(!vis[i.first]) {
            d[i.first] = d[nd] + i.second;
            get_subtree(i.first);
            maxd[nd] = max(maxd[nd], maxd[i.first]);
            child[nd].push_back(i);
        }
    }
    //cout << nd << " " << d[nd] << " " << maxd[nd] << endl;
}
pair<int, int> curmin;
void find(int nd, int par = 0) {
    // find maxd
    // cari max dr semua child
    vector<int> tmp;
    vis[nd] = 1;
    curmin = min(curmin, {max(par, maxd[nd] - d[nd]), nd});
    //cout << "FIND " << nd << " " << maxd[nd] - d[nd] << " " << par << endl;
    for(auto i : child[nd]) {
        tmp.push_back(maxd[i.first] - d[nd]);
    }
    sort(tmp.begin(), tmp.end());
    for(auto i : child[nd]) {
        if(child[nd].size() == 1) {
            find(i.first, par + i.second);
        }
        else {
            if(tmp.back() + d[nd] == maxd[i.first])
                find(i.first, max(tmp[tmp.size() - 2], par) + i.second);
            else
                find(i.first, max(tmp.back(), par) + i.second);
        }
    }
}

int travelTime(int N, int M, int L, int A[], int B[], int T[]) {
    //cout << N << endl;
    for(int i = 0; i < N - 1; ++i) {
        edges[A[i]].push_back({B[i], T[i]});
        edges[B[i]].push_back({A[i], T[i]});
    }
    for(int i = 0; i < N; ++i) {
        if(!vis[i])
            get_subtree(i);
    }
    memset(vis, 0, sizeof(vis));
    vector<pair<int, int>> s;
    for(int i = 0; i < N; ++i) {
        if(!vis[i]) {
            curmin = {2e9, 1e9};
            find(i);
            s.push_back(curmin);
        }
    }
    sort(s.begin(), s.end());
    // semua gabung ke s.back()
    for(int i = 0; i < s.size() - 1; ++i) {
        edges[s[i].second].push_back(make_pair(s.back().second, L));
        edges[s.back().second].push_back(make_pair(s[i].second, L));
        //cout << s[i].first << " " << s[i].second << endl;
    }
    //cout << s.back().first << " " << s.back().second << endl;
    memset(vis, 0, sizeof(vis));
    memset(d, 0, sizeof(d));
    get_subtree(0);
    pair<int, int> mx = {0, 0};
    for(int i = 0; i < N; ++i) {
        mx = max(mx, {d[i], i});
    }  
    memset(vis, 0, sizeof(vis));
    memset(d, 0, sizeof(d));
    get_subtree(mx.second);
    int ret = 0;
    for(int i = 0; i < N; ++i)
        ret = max(ret, d[i]);
    return ret;
}
// buat tiap connected component, cari optimal placement dia supaya maxnya minimum
// max minimum -> inside cc bakal tetep sama
// jadi nanti semua yang kecil akan dihubungin ke yang lebih besar, kemudian cari diameter
// setelah ketemu diameter, nanti dfs buat cari hasil akhir pake dfs yang sama
