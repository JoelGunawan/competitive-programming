#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ll long long
using namespace std;
using namespace __gnu_pbds;
const int lim = 1e5 + 5;
int mod = 1e9 + 7;
bool win[lim], rwin[lim];
int rwincnt[lim], wincnt[lim];
vector<int> child[lim], edges[lim];
bool vis[lim];
ll powmod(ll a, ll b) {
    if(b == 0) 
        return 1;
    else {
        ll tmp = powmod(a, b / 2);
        tmp = (tmp * tmp) % mod;
        return b & 1 ? (tmp * a) % mod : tmp;
    }
}
void dfs1(int nd) {
    win[nd] = 0;
    vis[nd] = 1;
    for(auto i : edges[nd]) {
        if(!vis[i]) {
            child[nd].push_back(i);
            dfs1(i);
            win[nd] |= !win[i];
        }
    }
    if(win[nd]) {
        int lcnt = 0;
        for(auto i : child[nd])
            if(!win[i])
                ++lcnt;
        if(lcnt == 1) {
            for(auto i : child[nd])
                if(!win[i])
                    wincnt[nd] += wincnt[i];
        }
    }
    else {
        // any child bisa diganti jadi win
        // nanti count of yg bs di modif dr lose jd win
        for(auto i : child[nd])
            wincnt[nd] += wincnt[i];
        // karena node ini jg boleh
        ++wincnt[nd];
    }
}
void dfs2(int nd, bool par_state, int par_win) {
    par_state ^= 1;
    rwin[nd] = win[nd] | par_state;
    // klo misal blum win, coba cek par_statenya
    int lcnt = par_state;
    for(auto i : child[nd]) {
        if(!win[i])
            ++lcnt;
    }
    if(lcnt == 0) {
        // then ini pasti l (win klo dr parent doang), terus berarti turunin par state lgsg aja
        int tmp = par_win + wincnt[nd];
        for(auto i : child[nd])
            dfs2(i, par_state, tmp - wincnt[i]);
    }
    else if(lcnt == 1) {
        // klo yg statenya l, dr parentnya ambil par_state krn defaultnya lose, cmn bs dpt dr par_state
        // sisanya win
        if(par_state) {
            // par losing, aka only losing way is to parent
            for(auto i : child[nd]) 
                dfs2(i, 1, par_win);
        }
        else {
            // only losing way is to child
            for(auto i : child[nd]) {
                if(!win[i])
                    dfs2(i, par_state, par_win + 1);
                else
                    dfs2(i, 1, 0);
            }
        }
    }
    else {
        // then ini pasti w, berarti lgsg turunin win aja
        for(auto i : child[nd]) {
            dfs2(i, 1, lcnt > 2 ? 0 : par_win);
        }
    }
    if(rwin[nd]) {
        int lcnt = par_state;
        for(auto i : child[nd])
            if(!win[i])
                ++lcnt;
        if(lcnt == 1) {
            if(par_state) {
                // berarti dr par gantinya
                rwincnt[nd] = par_win;
            }   
            else {
                // berarti dr child gantinya
                // aka ttp sama :D
                rwincnt[nd] = wincnt[nd];
            }
        }
    }
    else {
        // ambil dr tiap edge
        rwincnt[nd] = wincnt[nd] + par_win;
    }
}
int main() {
    // d = 1 -> buat dp reroot, check if a node is winning or losing if rooted in that node
    int n; ll d;
    cin >> n >> d;
    for(int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    dfs1(1);
    dfs2(1, 1, 0);
    //for(int i = 1; i <= n; ++i)
    //    cout << rwincnt[i] << " ";
    //cout << endl;
    // cek dr node mana aja yg bs pengaruhin nilai 1
    ll lose = 0, win = 0, cnt = 0;
    for(int i = 1; i <= n; ++i) {
        if(!rwin[i])
            ++lose, cnt += rwincnt[i];
        else
            ++win;
    }
    cnt %= mod;
    for(int i = 0; i < d - 1; ++i) {
        ll nlose = 0, nwin = 0;
        nlose = (cnt * win) % mod;
        nwin = powmod(1ll * n * n, i + 1) - nlose;
        nwin %= mod;
        if(nwin < 0)
        nwin += mod;
        win = nwin;
        lose = nlose;
    }
    //cout << cnt << endl;
    if(rwin[1])
        cout << ((powmod((n * n) % mod, d) - 1ll * lose * rwincnt[1]) % mod + mod) % mod << endl;
    else
        cout << (1ll * rwincnt[1] * lose) % mod << endl;
}