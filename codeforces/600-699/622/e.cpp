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
const int lim = 5e5 + 5;
struct disjoint_set {
    // nanti merge masing-masing vektor dr child, tiap child vektor segmentnya ditambah 1
    int pad[lim], h[lim], sz[lim];
    // fi -> r
    // se -> l
    set<pair<int, int>> s[lim];
    disjoint_set() {
        memset(h, -1, sizeof(h));
        fill(sz, sz + lim, 1);
        memset(pad, 0, sizeof(pad));
    }
    int fh(int nd) {
        return h[nd] == -1 ? nd : h[nd] = fh(h[nd]);
    }
    bool merge(int x, int y) {
        x = fh(x), y = fh(y);
        if(x != y) {
            if(sz[x] < sz[y])
                swap(x, y);
            h[y] = x;
            sz[x] += sz[y];
            // buat kode logic untuk merge vektor
            for(auto i : s[y]) {
                // merge segment ini ke segment x
                pair<int, int> cur = i;
                cur.fi += pad[y], cur.se += pad[y];
                // insert di tengah dua segment -> this is general case
                // segment kanan kosong ->
                cur.fi -= pad[x], cur.se -= pad[x];
                while(cur.fi >= cur.se) {
                    // cek right segment from cur
                    // ada right atau tdk?
                    // ada left atau tdk?
                    // cek lower bound, klo misal section skrg itu pure intersect sama segment lain, berarti 
                    if(s[x].lb(mp(cur.se, -1e9)) == s[x].end()) {
                        // berarti dr l ke atas gada segment
                        // lgsg insert aja
                        // di pos l - 1 ada end of other segment
                        if(s[x].lb(mp(cur.se - 1, -1e9)) != s[x].end()) {
                            // append ke last segment
                            pair<int, int> tmp = *--s[x].end();
                            s[x].erase(--s[x].end());
                            cur.se = tmp.se;
                        }
                        s[x].ins(cur);
                        cur.fi = cur.se - 1;
                        // lgsg habis
                    }
                    else {
                        // cari di s[x] yg di kiri kanannya
                        // misal segment skrg l, r
                        // yg di kiri itu berarti segment yg left nya ada lebih dr cur.se
                        // kalo misal cur.se itu kosong, berarti lgsg insert aja di cur.se sampe ketemu atasnya
                        // left of nxt segment is bigger than cur.se, berarti cur.se empty
                        if((*s[x].lb(mp(cur.se, -1e9))).se > cur.se) {
                            // berarti insert dr cur.se sampe natap atas
                            // coba extend left klo misal left nya nempel
                            pair<int, int> tmp = *s[x].lb(mp(cur.se, -1e9));
                            //cout << "DEB " << cur.se << " " << cur.fi << " " << (*s[x].lb(mp(cur.se - 1, -1e9))).fi << endl;
                            if(s[x].lb(tmp) != s[x].begin() && (*s[x].lb(mp(cur.se - 1, -1e9))).fi == cur.se - 1) {
                                //cout << "HERE" << endl;
                                pair<int, int> tmp = *s[x].lb(mp(cur.se - 1, -1e9));
                                cur.se = tmp.se;
                                s[x].erase(tmp);
                            }
                            //cout << cur.se << " " << cur.fi << endl;
                            if(cur.fi < tmp.se - 1) {
                                // lgsg insert both independently
                                s[x].ins(cur);
                                cur.fi = cur.se - 1;
                            }
                            else {
                                // insert both as one, terus nnti yg sisa dibiarin
                                pair<int, int> tmp2 = mp(tmp.fi, cur.se);
                                s[x].erase(tmp);
                                s[x].ins(tmp2);
                                cur.se = tmp.se;
                            }
                        }
                        else {
                            // cur.se ga empty, berarti nnti di append di rightnya segment
                            auto l = s[x].lb(mp(cur.se, -1e9)), r = l;
                            ++r;
                            if(r == s[x].end()) {
                                pair<int, int> cl = *l;
                                s[x].erase(cl);
                                s[x].ins(mp(cl.fi + cur.fi - cur.se + 1, cl.se));
                                cur.fi = cur.se - 1;
                            }
                            else {
                                pair<int, int> cl = *l, cr = *r;
                                int empty_dist = cr.se - cl.fi - 1;
                                if(cur.fi - cur.se + 1 >= empty_dist) {
                                    // gabung l dan r
                                    s[x].erase(cl);
                                    s[x].erase(cr);
                                    s[x].ins(mp(cr.fi, cl.se));
                                    cur.se += empty_dist;
                                }
                                else {
                                    s[x].erase(cl);
                                    s[x].ins(mp(cl.fi + cur.fi - cur.se + 1, cl.se));
                                    cur.fi = cur.se - 1;
                                }
                            }
                        }
                    }
                }
            }
        }
        return x != y;
    }
};
vector<int> edges[lim]; 
bool vis[lim];
disjoint_set dsu;
void dfs(int nd) {
    vis[nd] = 1;
    int child = 0;
    for(auto i : edges[nd]) {
        if(!vis[i]) {
            dfs(i);
            dsu.pad[dsu.fh(i)]++;
            dsu.merge(i, nd);
            ++child;
        }
    }
    if(child == 0) {
        dsu.s[nd].ins(mp(1, 1));
    }
    //cout << "OUTPUT SEGMENTS " << nd << endl;
    //for(auto i : dsu.s[dsu.fh(nd)])
    //    cout << i.se + dsu.pad[dsu.fh(nd)] << "  " << i.fi + dsu.pad[dsu.fh(nd)] << endl;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        edges[u].pb(v);
        edges[v].pb(u);
    }
    vis[1] = 1;
    int res = 0;
    for(auto i : edges[1]) {
        dfs(i);
        //cout << "UP TO RES " << i << endl;
        for(auto j : dsu.s[dsu.fh(i)]) {
            res = max(res, j.fi + dsu.pad[dsu.fh(i)]);
        }
    }
    // buat merge segments of active, nanti kalo ada konflik, dimundurin aja
    // if they are touching immediately merge them :D
    cout << res << endl;
    return 0;
}