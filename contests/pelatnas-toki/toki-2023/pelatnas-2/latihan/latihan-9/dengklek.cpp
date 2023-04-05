#include "dengklek.h"

#include <bits/stdc++.h>
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
const int lim = 2e5 + 5;
bool vis[lim];
vector<int> edges[lim], child[lim];
int par[lim];
vector<pair<int, int>> cur;
int color[lim];
vector<pair<int, int>> group[lim];
int magic = 60;
bool ret_wrong = 0;
void create_tree(int nd = 0) {
    vis[nd] = 1;
    if(cur.size() < magic)
        cur.pb(mp(nd, cur.size()));
    for(auto i : edges[nd]) {
        if(!vis[i])
            child[nd].pb(i), create_tree(i), par[i] = nd;
    }
    // cari edge cur yg connection
    //cout << "NODE " << nd << " " << child[nd].size() << endl;
}
// a.fi -> nd, a.se -> color
void get_ans(int nd, vector<pair<int, int>> a, vector<int> s) {
    // get answer ini cara dapetnya pake
    // finding     
    if(color[nd] == -1) {
        for(int i = 0; i < a.size(); ++i) {
            if(a[i].fi == par[nd])
                ++s[i];
        }
        int del_idx = 0;
        for(int i = 0; i < s.size(); ++i) {
            assert(s[i] >= 1);
            if(s[i] == 1) {
                del_idx = i;
            }
        }
        int del_nd = a[del_idx].fi, del_c = a[del_idx].se;
        // cari edge yang hubungin ke sekarang
        a.erase(a.begin() + del_idx), s.erase(s.begin() + del_idx);
        for(int i = 0; i < a.size(); ++i) {
            int tmp = a[i].fi;
            if(binary_search(child[tmp].begin(), child[tmp].end(), del_nd) || par[tmp] == del_nd) {
                --s[i];
                break;
            }
        }
        a.pb(mp(nd, del_c));
        s.pb(1);
        color[nd] = del_c;
    }
    group[nd] = a;
    for(auto i : child[nd])
        get_ans(i, a, s);
}
void giveHint(int N, int M, std::vector<int> A, std::vector<int> B, long long X, int T) {
    // pertama ubah jadi tree
    // awalnya buat arbitrary collection of 60 connected nodes, misal dfs dari 1 buat dapet 60 connected nodes
    // nanti jalanin algonya
    // kita mau hapus salah satu node yang merupakan leaf (terserah yang mana sih sebenarnya)
    //cout << "INIT" << endl;
    for(int i = 0; i < M; ++i) {
        edges[A[i]].pb(B[i]);
        edges[B[i]].pb(A[i]);
    }
    for(int i = 0; i < N; ++i)
        sort(edges[i].begin(), edges[i].end());
    bool val[60];
    for(ll i = 0; i < 60; ++i) {
        val[i] = (bool)((1ll << i) & X);
    }
    create_tree();
    //cout << "TREE DONE" << endl;
    memset(color, -1, sizeof(color));
    for(auto i : cur)
        color[i.fi] = i.se;
    sort(cur.begin(), cur.end());
    vector<int> tmp;
    par[0] = -1;
    for(int i = 0; i < magic; ++i) {
        // buat vector indegree
        int nd = cur[i].fi, cnt = 0;
        //cout << "NODE " << i << endl;
        for(auto j : child[nd]) {
            if(lb(cur.begin(), cur.end(), mp(j, 0)) != cur.end() && (*lb(cur.begin(), cur.end(), mp(j, 0))).fi == j)
                ++cnt;
        }
        if(lb(cur.begin(), cur.end(), mp(par[nd], 0)) != cur.end() && (*lb(cur.begin(), cur.end(), mp(par[nd], 0))).fi == par[nd])
            ++cnt;
        //cout << i << " " << cnt << endl;
        tmp.pb(cnt);
    }
    //cout << "PROC" << endl;
    get_ans(0, cur, tmp);
    //cout << "FINAL" << endl;
    // karena di 1 udah ada, nanti ngikutin groupnya yg ada di 1
    // dfs dr 1 buat dapetin 60 nodes
    // terus nanti buat tiap node di group itu kita anggep aja groupingnya dia itu seperti skrg
    for(int i = 0; i < N; ++i) {
        writeMessage(i, val[color[i]]);
    }
    //cout << "SUCCESS" << endl;
}
